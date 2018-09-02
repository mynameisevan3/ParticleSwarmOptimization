
/*=====================================
    Particle Swarm Optimization
    Serial Main
    mtj@cogitollc.com
    Used and Modified with Permission
    Evan William Gretok
  =====================================
    Copyright (c) 2003-2005 Charles River Media.  All rights reserved.

    Redistribution and use in source and binary forms, with or
    without modification, is hereby granted without fee provided
    that the following conditions are met:

      1.  Redistributions of source code must retain the above
          copyright notice, this list of conditions and the
          following disclaimer.
      2.  Redistributions in binary form must reproduce the above
          copyright notice, this list of conditions and the
          following disclaimer in the documentation and/or other
          materials provided with the distribution.
      3.  Neither the name of Charles River Media nor the names of
          its contributors may be used to endorse or promote products
          derived from this software without specific prior
          written permission.

    THIS SOFTWARE IS PROVIDED BY CHARLES RIVER MEDIA AND CONTRIBUTORS
    'AS IS' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CHARLES
    RIVER MEDIA OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARAY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  =====================================*/


// Inclusions
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include "fitness.h"
#include "init.h"
#include "pso.h"
#include "swarm.h"


// Main
int main( int argc, char *argv[] ) {

  // Acceleration and dt Constants
  double     c1            = 0.25;  // Global Weight
  double     c2            = 1.0;   // Local Weight
  double     dt            = 0.1;   // Delta Factor for Position Change
  int        display       = 0;     // Flag to Display Debug Text
  int        i             = 0;     // Loop Iteration
  int        numParticles  = 0;     // Number of Particles
  int        numIterations = 0;     // Number of Iterations
  particle_t gbest;                 // Global Best Particle Tracker
  // Timing Measures
  double     jobStart      = 0;     // Job Clock Start Time
  double     initStart     = 0;     // Initialization Start Time
  double     initEnd       = 0;     // Initialization End Time
  double     swarmStart    = 0;     // Swarm Start Time
  double     swarmEnd      = 0;     // Swarm End Time
  double     cleanupStart  = 0;     // Cleanup Start Time
  double     cleanupEnd    = 0;     // Cleanup End Time
  double     jobEnd        = 0;     // Job Clock End Time
  // Timing Results
  double     initTime      = 0;     // Program Time for Initialization
  double     swarmTime     = 0;     // Program Time for Particle Swarm Operation
  double     cleanupTime   = 0;     // Program Time for Cleanup
  double     overheadTime  = 0;     // Overhead Time Not Accounted For
  double     jobTime       = 0;     // Total Program Time

  // Parse Input Parameters
  if( argc != 7 ) {
    fprintf( stderr, "\nWrong number of arguments.\n" );
    printf( "Usage: %s <global> <local> <delta> <particles> <iterations> <display>\n", argv[0] );
    printf( "  Global     - weight placed on moving toward global best particle.\n" );
    printf( "  Local      - weight placed on the best that this particle has discovered already.\n" );
    printf( "  Delta      - desired factor for position change amount.\n" );
    printf( "  Particles  - number of particles to swarm.\n" );
    printf( "  Iterations - number of steps to conduct swarm.\n" );
    printf( "  Display    - 1 displays debug text, 0 just displays time values for raw data tables.\n" );
    printf( "Example: ./swarmS 0.5 0.5 0.1 12 100 1\n\n");
    return -1;
  } else {
    // Takes n as that is specifically mentioned in the assignment.
    c1            = atof( argv[1] );
    c2            = atof( argv[2] );
    dt            = atof( argv[3] );
    numParticles  = atoi( argv[4] );
    numIterations = atoi( argv[5] );
    display       = atoi( argv[6] );
  }

  // Intro Text
  if( display ) {
    printf( "\n   = = =  Particle Swarm Optimization  = = =   \n\n" );
  }

  // Set Job Start Timer
  jobStart = omp_get_wtime( );

  // Initialize Swarm Components
  if( display ) {
    printf( "Initializing Swarm Components...\n" );
  }
  initStart = omp_get_wtime( );
  // Create Arrays Dynamically Based on Input Parameters
  particle_t particles[numParticles];
  particle_t pbest[numParticles];
  // Seed Random Number Generator
  srand( time( NULL ) );
  // Initialize Swarm
  initPopulation( &numParticles, particles, pbest, &gbest );
  initEnd   = omp_get_wtime( );

  // Perform Particle Swarm Operation
  if( display ) {
    printf( "Performing %d Particle Swarm for %d Iterations...\n",
              numParticles, numIterations                          );
  }
  swarmStart = omp_get_wtime( );
  for( i = 0; i < numIterations; i++ ) {
    // moveSwarm is here left as a serial-only method.
    moveSwarm( &c1, &c2, &dt, &numParticles, particles, pbest, &gbest );
  }
  swarmEnd   = omp_get_wtime( );

  // Display Optimum Data
  if( display ) {
    printf( "Best of %lf Found at ( %lf, %lf )\n",
              gbest.fitness, gbest.position.x,
              gbest.position.y                     );
  }

  // Cleanup Swarm
  if( display ) {
    printf( "Cleaning Up Swarm...\n" );
  }
  cleanupStart = omp_get_wtime( );
  closePopulation( &numParticles, particles );
  cleanupEnd   = omp_get_wtime( );

  // Final Tasks
  if( display ) {
    printf( "Operation Complete!\n" );
  }

  // Final Timing Component
  jobEnd       = omp_get_wtime( );                              // End Full Program Clock
  initTime     = initEnd    - initStart;                        // Calculate Initialization Time
  swarmTime    = swarmEnd   - swarmStart;                       // Calculate Swarm Time
  cleanupTime  = cleanupEnd - cleanupStart;                     // Calculate Cleanup Time
  jobTime      = jobEnd     - jobStart;                         // Calculate Overall Time
  overheadTime = jobTime - initTime - swarmTime - cleanupTime;  // Calculate Overhead Time

  // Handle Displaying All Timing Data
  if( display ) {  // Messages only when display is 1.
    printf( "=== Timing Data ===\n  Initialize:\t\t" );
    printf( "%0.9lf\n", initTime );
    printf( "  Swarm:\t\t" );
  }
  printf( "%0.9lf ", swarmTime );
  if( display ) {
    printf( "\n  Cleanup:\t\t" );
    printf( "%0.9lf\n", cleanupTime );
    printf( "  Overhead:\t\t" );
    printf( "%0.9lf\n", overheadTime );
    printf( "  Total Job Time:\t" );
    printf( "%0.9lf\n\n", jobTime );
  }

  return 0;
}



// End mainSerial.c  - EWG SDG

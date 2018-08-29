
/*=====================================
    Particle Swarm Optimization
    Main
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
  double     c2            = 1.0;   // Personal Weight
  double     dt            = 0.1;   // Delta
  int        i             = 0;     // Loop Iteration
  int        numParticles  = 0;     // Number of Particles
  int        numIterations = 0;     // Number of Iterations
  particle_t gbest;                 // Global Best Particle Tracker

  // Parse Input Parameters
  if( argc != 5 ) {
    // Warn if nothing was passed.
    printf( "WARNING - You passed no parameters for c1, c2, particle count, or timesteps!\n" );
    return -1;
  } else {
    // Takes n as that is specifically mentioned in the assignment.
    c1            = atof( argv[1] );
    c2            = atof( argv[2] );
    numParticles  = atoi( argv[3] );
    numIterations = atoi( argv[4] );
  }

  // Create Arrays Dynamically Based on Input Parameters
  particle_t particles[numParticles];
  particle_t pbest[numParticles];

  // Seed Random Number Generator
  srand( time( NULL ) );

  // Initialize Swarm
  initPopulation( &numParticles, particles, pbest, &gbest );

  // Perform Particle Swarm Operation
  for( i = 0; i < numIterations; i++ ) {
    moveSwarm( &c1, &c2, &dt, &numParticles, particles, pbest, &gbest );
    printf( "%lg\n", gbest.fitness );
  }

  // Cleanup Swarm
  closePopulation( &numParticles, particles );

  return 0;
}



// End main.c  - EWG SDG

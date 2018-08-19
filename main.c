
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
  double c1            = 0.25;
  double c2            = 1.0;
  double dt            = 0.1;
  int    numParticles  = 0;
  int    numIterations = 0;
  // Global Best Particle
  particle_t gbest;

  // Parse Input Parameters
  // Global weight c1, personal weight c2, numParticles, and numIterations.
  // Ensures parameters were indeed passed.
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

  // Create arrays in main dynamically based on input parameters.
  particle_t particles[numParticles];
  particle_t pbest[numParticles];

  int iter;

//  extern void initPopulation( particle_t* particles, particle_t* pbest );
//  extern void moveSwarm( particle_t* particles, particle_t* pbest );
//  extern void closePopulation( particle_t* particles );

  // Seed the random number generator.
  srand( time( NULL ) );

  // Initialize the swarm.
  initPopulation( &numParticles, particles, pbest, &gbest );

  // Perform NUM_ITERATIONS number of iterations.
  for( iter = 0; iter < numIterations; iter++ ) {

    moveSwarm( &c1, &c2, &dt, &numParticles, particles, pbest, &gbest );
    printf( "%lg\n", gbest.fitness );

  }

  // Cleanup the swarm .
  closePopulation( &numParticles, particles );

  return 0;
}



// End main.c  - EWG SDG

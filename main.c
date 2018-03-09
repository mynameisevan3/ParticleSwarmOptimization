
/*============================================================
    Particle Swarm Optimization Main Function
    mtj@cogitollc.com
    Used and Modified with Permission by Evan William Gretok
  ============================================================*/

  
// Inclusions
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include "pso.h"


// Global Variables

// Acceleration and dt Constants
double c1 = 0.25;
double c2 = 1.0;
double dt = 0.1;


// Main
int main( int argc, char *argv[] ) {

  // Parse Input Parameters
  // Global weight c1, personal weight c2, MAX_PARTICLES, and NUM_ITERATIONS.
  // Ensures parameters were indeed passed.
  if( argc == 5 ) {  
    // Takes n as that is specifically mentioned in the assignment.
    c1              = atof( argv[1] );
    c2              = atof( argv[2] );
    MAX_PARTICLES   = atoi( argv[3] );
    NUM_ITERATIONS  = atoi( argv[4] );
  } else {  
    // Warn if nothing was passed.
    printf( "WARNING - You passed no parameters for c1, c2, particle count, or timesteps!\n" );    
  }

  // Create arrays in main dynamically based on input parameters.
  particle_t particles[MAX_PARTICLES];
  particle_t pbest[MAX_PARTICLES];

  int iter;

  extern void initPopulation( particle_t* particles, particle_t* pbest );
  extern void moveSwarm( particle_t* particles, particle_t* pbest );
  extern void closePopulation( particle_t* particles );

  extern particle_t gbest;

  // Seed the random number generator.
  srand( time( NULL ) );

  // Initialize the swarm.
  initPopulation( particles, pbest );

  // Perform NUM_ITERATIONS number of iterations.
  for (iter = 0 ; iter < NUM_ITERATIONS ; iter++) {

    moveSwarm( particles, pbest );
    printf( "%lg\n", gbest.fitness );

  }

  // Cleanup the swarm .
  closePopulation( particles );

  return 0;
}

/*
 * Copyright (c) 2003-2005 Charles River Media.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, is hereby granted without fee provided
 * that the following conditions are met:
 *
 *   1.  Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the
 *       following disclaimer.
 *   2.  Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the
 *       following disclaimer in the documentation and/or other
 *       materials provided with the distribution.
 *   3.  Neither the name of Charles River Media nor the names of
 *       its contributors may be used to endorse or promote products
 *       derived from this software without specific prior
 *       written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY CHARLES RIVER MEDIA AND CONTRIBUTORS
 * 'AS IS' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CHARLES
 * RIVER MEDIA OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARAY, OR CONSEQUENTIAL DAMAGES 
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

 
 
// END main.c  - EWG SDG
 
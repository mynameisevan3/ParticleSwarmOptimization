
/*=====================================
    Particle Swarm Optimization
    Initialization Functions
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
#include <string.h>
#include <fcntl.h>
#include "fitness.h"
#include "init.h"
#include "pso.h"


// Definitions
#define MAX_FILENAME	80

// Array of particles within the solution space definitions moved to main.

void storePbest( int *index, particle_t *particles, particle_t *pbest, particle_t *gbest ) {
  // Save the particle to its personal best.
  memcpy( (void *)( pbest + ( *index ) ), (void *)( particles + ( *index ) ), sizeof( *particle_t ) );
  // If this pbest is better than gbest, save it.
  if( ( ( pbest + ( *index) ) -> fitness ) > ( gbest -> fitness ) ) {
    gbest -> position.x = ( pbest + ( *index ) ) -> position.x;
    gbest -> position.y = ( pbest + ( *index ) ) -> position.y;
    gbest -> fitness    = ( pbest + ( *index ) ) -> fitness;
  }
  return;
}

// initPopulation - Initialize files, positions, and velocities for each particle.
void initPopulation( int *numParticles, particle_t *particles, particle_t *pbest, particle_t *gbest ) {
  int  i = 0;
  char filename[ MAX_FILENAME + 1 ];

  gbest -> fitness = (double)( -9999.0 );

  for( i = 0; i < ( *numParticles ); i++ ) {

    // Initialize the Output File Pointer
    sprintf( filename, "particle%02d.txt", i );
    particles[i].fp = fopen( filename, "w" );

    // Initialize Particle Starting Point and Fitness.
    ( particles + i ) -> position.x = getPoint( );
    ( particles + i ) -> position.y = getPoint( );
    ( particles + i ) -> fitness    = checkFitness( &( particles + i ) -> position.x, &( particles + i ) -> position.y );
    // Initialize Particle Dimensional Velocity
    ( particles + i ) -> velocity.x = ( getSRand( ) / (double)10.0 );
    ( particles + i ) -> velocity.y = ( getSRand( ) / (double)10.0 );

    // Since this is the only fitness value, store this as pbest.
    storePbest( &i, particles, pbest, gbest );

    // Store Position to Particle Trace File
    fprintf( ( particles + i ) -> fp, "%lg, %lg, %lg\n",
             ( particles + i ) -> position.x,
             ( particles + i ) -> position.y,
             ( particles + i ) -> fitness );
  }
  return;
}


// closePopulation - close files for each particle.
void closePopulation( int *numParticles, particle_t *particles ) {
  int i = 0;
  for( i = 0; i < ( *numParticles ); i++ ) {
    fclose( ( particles + i ) -> fp );
  }
  return;
}



// End init.c  - EWG SDG

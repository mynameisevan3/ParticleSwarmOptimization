
/*=====================================
    Particle Swarm Optimization
    Swarm Functions
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
#include "fitness.h"
#include "pso.h"
#include "swarm.h"


// Function Implementations

// moveParticle - conducts the...movement of...particles...
void moveParticle( int *i, double *c1, double *c2, double *dt, particle_t *particles, particle_t *pbest, particle_t *gbest ) {

  // Update the Position of the Particle
  ( particles + *i ) -> position.x += ( ( particles + *i ) -> velocity.x * ( *dt ) );
  ( particles + *i ) -> position.y += ( ( particles + *i ) -> velocity.y * ( *dt ) );

  // Calculate Fitness Over Desired Range
  if ( ( ( particles + *i ) -> position.x > ( X_MIN ) ) &&
       ( ( particles + *i ) -> position.x < ( X_MAX ) ) &&
       ( ( particles + *i ) -> position.y > ( Y_MIN ) ) &&
       ( ( particles + *i ) -> position.y < ( Y_MAX ) )    ) {
    ( particles + *i ) -> fitness = checkFitness( &( ( particles + *i ) -> position.x ), &( ( particles + *i ) -> position.y ) );
  }

  // Write Particle Position and Fitness to Trace File
  fprintf( ( particles + *i ) -> fp, "%lg, %lg, %lg\n",
           ( particles + *i ) -> position.x,
           ( particles + *i ) -> position.y,
           ( particles + *i ) -> fitness                 );

  // Update Velocity Vector of Particle.
  ( ( particles + *i ) -> velocity.x ) +=
    ( ( *c1 * getSRand( ) * ( ( gbest -> position.x ) - ( ( particles + *i ) -> position.x ) ) ) +
      ( *c2 * getSRand( ) * ( ( ( pbest + *i ) -> position.x ) - ( ( particles + *i ) -> position.x ) ) ) );

  ( ( particles + *i ) -> velocity.y ) +=
    ( ( *c1 * getSRand( ) * ( ( gbest -> position.y ) - ( ( particles + *i ) -> position.y ) ) ) +
      ( *c2 * getSRand( ) * ( ( ( pbest + *i ) -> position.y ) - ( ( particles + *i ) -> position.y ) ) ) );

  return;
}


// moveSwarm - serially conduct movement of each particle in the swarm.
void moveSwarm( double *c1, double *c2, double *dt, int *numParticles,
                 particle_t *particles, particle_t *pbest, particle_t *gbest ) {
  int j = 0;

  // Move Each Particle in the Swarm
  for( j = 0; j < ( *numParticles ); j++ ) {
    moveParticle( &j, c1, c2, dt, particles, pbest, gbest );
    if( ( ( particles + j ) -> fitness ) > ( ( pbest + j ) -> fitness ) ) {
      storePbest( &j, particles, pbest, gbest );
    }
  }

  return;
}



// END swarm.c  - EWG SDG

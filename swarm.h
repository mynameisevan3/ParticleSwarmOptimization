
/*=====================================
    Particle Swarm Optimization
    Swarm Functions Header
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


// Include Guard
#ifndef __SWARM_H__
#define __SWARM_H__


// Inclusions
#include <stdlib.h>
#include "init.h"


// Function Prototypes
void moveParticle( int *i, double *c1, double *c2, double *dt, particle_t *particles, particle_t *pbest, particle_t *gbest );
void moveSwarm( double *c1, double *c2, double *dt, int *numParticles, particle_t *particles, particle_t *pbest, particle_t *gbest );
void moveSwarmS( double *c1, double *c2, double *dt, int *numParticles, particle_t *particles, particle_t *pbest, particle_t *gbest );


// End Include Guard
#endif



// END pso.h  - EWG SDG

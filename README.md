
# ParticleSwarmOptimization

This repository contains an implementation of a particle swarm optimization program given and modified as an assignment for the CS 1783 Artificial Intelligence Programming course at the University of Pittsburgh at Johnstown.


## Build

This application can be built by simply running the ```make``` command from within this directory.


## Usage

The particle swarm optimization application can be run using the following command.

(Cotinue changes here.)

```./swarm <global> <local> <delta> <particles> <iterations> <cores> <display>```

The parameters that follow apply.

+ Global     - weight placed on moving toward the global best particle.
+ Local      - weight placed on the best that this particle has discovered already.
+ Delta      - desired factor for position change amount.
+ Particles  - number of particles to swarm.
+ Iterations - number of steps to conduct swarm.
+ Cores      - number of cores to utilize for parallel operation.
+ Display    - 1 displays debug text, 0 just displays time values for raw data tables.

Example:  ```./swarm 0.5 0.5 0.01 12 1000 4 1```

The serial baseline can be run in the same manner as mandelbrotS without the cores parameter, like so:

```./swarm 0.75 0.25 0.02 5 800 0```


## Swarm Position Outputs

A file is generated for each particle.  This file contains position information for the particle at each step.  This information can be plotted within the same range as the investigated function to observe the particles' movements and the effects of the global and local weight constants.


## Automated Data Acquisition

Scripts designed to automate the process of acquiring execution time and power data on the facsimiles are included.  Both scripts default to one thousand runs and parallelize to four cores.

For parallel execution data, run the included swarmRun using ```./swarmRun.sh```.  It will build and run the program and output all data to swarmOut.txt.

For the serial baseline, run the included swarmBase using ```./swarmBase.sh```.  It will build and run the program and output all serial baseline timings to swarmBase.txt.

For power measures, run the included swarmPower using ```./swarmPower.sh```.  It will run the iterations on one, then two, then three, and so on, cores for more stable per-core power measures.

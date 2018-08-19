
# ParticleSwarmOptimization

This repository contains an implementation of a particle swarm optimization program given and modified as an assignment for the CS 1783 Artificial Intelligence Programming course at the University of Pittsburgh at Johnstown.


## Build

This application can be built by simply running the ```make``` command from within this directory.


## Usage

The particle swarm optimization application can be run using the following command.

(Cotinue changes here.)

```./mandelbrot <output> <x/y> <cores> <display>```

The parameters that follow apply.


+ Output  - a .ppm image to output with the fractal.
+ X/Y     - width and height of image in pixels.
+ Cores   - number of cores to utilize for parallel operation.
+ Display - 1 displays debug text, 0 just displays time values for raw data tables.

Example:  ```./mandelbrot output.ppm 2048 4 0```

The serial baseline can be run in the same manner as mandelbrotS without the cores parameter, like so:

```./mandelbrotS output.ppm 2048 0```


## Conversion

One may convert from .ppm images using the Unix terminal command:

```convert <filenameIn>.<extensionIn> <filenameOut>.<extensionOut>```


## Automated Data Acquisition

Scripts designed to automate the process of acquiring execution time and power data on the facsimiles are included.  Both scripts default to one thousand runs and parallelize to four cores.

For parallel execution data, run the included mandelbrotRun using ```./mandelbrotRun.sh```.  It will build and run the program and output all data to mandelbrotOut.txt.

For the serial baseline, run the included mandelbrotBase using ```./mandelbrotBase.sh```.  It will build and run the program and output all serial baseline timings to mandelbrotBase.txt.

For power measures, run the included mandelbrotPower using ```./mandelbrotPower.sh```.  It will run the iterations on one, then two, then three, and so on, cores for more stable per-core power measures.

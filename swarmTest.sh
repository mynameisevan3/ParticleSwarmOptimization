
#!/bin/sh

# Simple Tests of Particle Swarm Parallelization

# Variable Definitions
a=1
aEnd=16
aInc=1
aMult=1
b=100
bEnd=10001
bInc=0
bMult=10

# Header
echo "Particle Swarm Parallelization Test"
# Header for File
echo                                        > $outfile.txt
echo "Particle Swarm Parallelization Test" >> $outfile.txt
echo                                       >> $outfile.txt

# Make Program
make clean
make
echo

# Initial Test Run - shows which values are which.
./swarm 0.5 0.5 0.1 12 3000 4 1

# Automated Run Loop with Varying Core Utilization
while [ $a -lt $aEnd ]
do
  while [ $b -lt $bEnd ]
  do
    # Remove Previous Output Images
    rm particle*.txt

    # Run Application
    echo "Run with $a Cores for $b Iterations"
    #p=$(./swarm 0.5 0.5 0.1 12 3000 $cores 0)

    # Iterate Loop
    b=$((b*bMult+bInc))
  done
  a=$((a*aMult+aInc))
done



# End swarmPower.sh  - EWG SDG

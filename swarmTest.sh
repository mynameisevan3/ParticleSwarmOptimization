
#!/bin/sh

# Simple Tests of Particle Swarm Parallelization

# Variable Definitions
aStart=1
aEnd=4
aInc=1
aMult=1
bStart=1
bEnd=1
bInc=1
bMult=1

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
for a in `seq $aStart $aEnd`
do
  echo " "
  echo "Running with $cores Cores..."
  iteration=0
  final=100
  while [ $iteration -lt $final ]
  do
    # Remove Previous Output Images
    rm particle*.txt

    # Run Application
    p=$(./swarm 0.5 0.5 0.1 12 3000 $cores 0)

    # Indicate Status
    echo "Iteration $iteration $p"

    # Iterate Loop
    iteration=$((iteration+1))
  done
done



# End swarmPower.sh  - EWG SDG

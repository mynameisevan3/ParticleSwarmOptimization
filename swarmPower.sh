
#!/bin/sh

# Automation of Particle Swarm Power Measure Collection

# Variable Definitions
coreStart=1
coreEnd=4

# Header
echo "Particle Swarm Power Measure Run"
# No File Generation Here - Just for Power Measures

# Make Program
make clean
make
echo

# Command Structure Echo for Verification (may remove)
echo "./swarm 0.5 0.5 0.1 12 3000 4 1"

# Initial Test Run - shows which values are which.
./swarm 0.5 0.5 0.1 12 3000 4 1

# Automated Run Loop with Varying Core Utilization
for cores in `seq $coreStart $coreEnd`
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

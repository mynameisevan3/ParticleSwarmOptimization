
#!/bin/sh

# Automation of Particle Swarm Parallel Execution Data Collection

# Variable Definitions
outfile=swarmOut

# Header for File
echo                                        > $outfile.txt
echo "Particle Swarm Data Acquisition Run" >> $outfile.txt
echo                                       >> $outfile.txt

# Make Program
make clean                                 >> $outfile.txt
make                                       >> $outfile.txt
echo                                       >> $outfile.txt

# Initial Test Run - shows which values are which.
./swarm 0.5 0.5 0.1 12 3000 4 1            >> $outfile.txt
echo                                       >> $outfile.txt

# Job Start Time
echo -n "Job Start "                       >> $outfile.txt
date                                       >> $outfile.txt

# Automated Run Loop with Varying Core Utilization
iteration=0
final=1000
while [ $iteration -lt $final ]
do
  # Remove Previous Output Images
  rm particle*.txt

  # Collect Data
  a=$(./swarm 0.5 0.5 0.1 12 3000 1 0)     >> $outfile.txt
  b=$(./swarm 0.5 0.5 0.1 12 3000 2 0)     >> $outfile.txt
  c=$(./swarm 0.5 0.5 0.1 12 3000 3 0)     >> $outfile.txt
  d=$(./swarm 0.5 0.5 0.1 12 3000 4 0)     >> $outfile.txt
  echo "$iteration $a $b $c $d"            >> $outfile.txt

  # Indicate Status
  echo "Iteration $iteration $a $b $c $d"

  # Iterate Loop
  iteration=$((iteration+1))
done

# Job End Time
echo -n "Job Completion "                  >> $outfile.txt
date                                       >> $outfile.txt
echo                                       >> $outfile.txt



# End swarmRun.sh  - EWG SDG

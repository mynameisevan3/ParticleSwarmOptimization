
#!/bin/sh

# Automation of Particle Swarm Serial Execution Data Collection

# Variable Definitions
outfile=swarmBase

# Header for File
echo                                                        > $outfile.txt
echo "Particle Swarm Serial Baseline Data Acquisition Run" >> $outfile.txt
echo                                                       >> $outfile.txt

# Make Program
make clean                                                 >> $outfile.txt
make                                                       >> $outfile.txt
echo                                                       >> $outfile.txt

# Initial Test Run - shows which values are which.
./swarmS 0.5 0.5 0.1 12 3000 1                             >> $outfile.txt
echo                                                       >> $outfile.txt

# Job Start Time
echo -n "Job Start "                                       >> $outfile.txt
date                                                       >> $outfile.txt

# Automated Run Loop with Varying Core Utilization
iteration=0
final=1000
while [ $iteration -lt $final ]
do
  # Remove Previous Output
  rm particle*.txt

  # Collect Data
  s=$(./swarmS 0.5 0.5 0.1 12 3000 0)                      >> $outfile.txt
  echo "$iteration $s"                                     >> $outfile.txt

  # Indicate Status
  echo "Iteration $iteration $s"

  # Iterate Loop
  iteration=$((iteration+1))
done

# Job End Time
echo -n "Job Completion "                                  >> $outfile.txt
date                                                       >> $outfile.txt
echo                                                       >> $outfile.txt



# End swarmBase.sh  - EWG SDG

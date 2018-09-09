
#!/bin/sh

# Simple Tests of Particle Swarm Parallelization

# Variable Definitions
average=0
outfile=testResults
outerLoopIndex=0
outerLoopStart=1
outerLoopEnd=5
outerLoopMult=1
outerLoopInc=1
innerLoopIndex=0
innerLoopStart=100
innerLoopEnd=10001
innerLoopMult=10
innerLoopInc=0
resultLoopIndex=0
resuLoopStart=1
resultLoopEnd=11
results=$((resultLoopEnd-1))
result=0
sum=0

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

# Automated Testing Loop
outerLoopIndex=$((outerLoopStart))
while [ $outerLoopIndex -lt $outerLoopEnd ]
do

  innerLoopIndex=$((innerLoopStart))
  while [ $innerLoopIndex -lt $innerLoopEnd ]
  do

      # Display Current Iteration
      echo "Run with $outerLoopIndex Cores for $innerLoopIndex Iterations"

      # Loop to Collect Multiple Results
      resultLoopIndex=$((resultLoopStart))
      sum=0
      while [ $resultLoopIndex -lt $resultLoopEnd ]
      do
        # Remove Previous Output
        rm particle*.txt

        # Run Application
        result=$(./swarm 0.5 0.5 0.1 12 $innerLoopIndex $outerLoopIndex 0)
        sum=$(echo "$sum+$result" | bc)

        # Echo Result for Testing
        echo "$outerLoopIndex-$innerLoopIndex-$resultLoopIndex: $result $sum"

        resultLoopIndex=$((resultLoopIndex+1))
      done

      # Calculate Average and Output to File
      echo "$sum and $results"
      average=$(echo "$sum/$results" | bc -l)
      echo "$outerLoopIndex $innerLoopIndex $average" >> $outfile.txt

      # Echo Average and Output to File
      echo "$outerLoopIndex-$innerLoopIndex: $average"

    innerLoopIndex=$((innerLoopIndex*innerLoopMult+innerLoopInc))
  done

  outerLoopIndex=$((outerLoopIndex*outerLoopMult+outerLoopInc))
done



# End swarmPower.sh  - EWG SDG


################################################################
# Makefile for Particle Swarm Optimization Program
################################################################

CFLAGS  += -Wall -Wextra -fopenmp -O2
LDFLAGS += -lm
POBJS   += mainOMP.o init.o fitness.o swarm.o
SOBJS   += mainSerial.o init.o fitness.o swarm.o

################################################################
# Make all

all:	swarm swarmS

################################################################
# Make Swarm (Parallel)

swarm: $(POBJS) pso.h
	$(CC) $(CFLAGS) $(POBJS) $(LDFLAGS) -o $@

################################################################
# Make Swarm (Serial Baseline)

swarmS: $(SOBJS) pso.h
	$(CC) $(CFLAGS) $(SOBJS) $(LDFLAGS) -o $@

################################################################

.c.o:
	$(CC) -c $(CFLAGS) $<

################################################################
# Make Clean

clean:
	rm -f swarm swarmS *.o particle??.txt

.PHONY: clean

################################################################



# End Makefile for Particle Swarm Optimization Application  - EWG SDG

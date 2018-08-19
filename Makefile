
################################################################
# Makefile for Particle Swarm Optimization Program
################################################################

CC = gcc
CFLAGS = -Wall -Wextra -fopenmp -O2
OBJS =	main.o init.o fitness.o swarm.o

################################################################
# Make all

all:	swarm

################################################################
# Make Swarm

swarm: $(OBJS) pso.h
	$(CC) -o swarm $(OBJS) -lm


################################################################

.c.o:
	$(CC) $(CFLAGS) $<

################################################################
# Make Clean

clean:
	rm -f swarm *.o particle??.txt

.PHONY: clean

################################################################



# END MAKEFILE  - EWG SDG

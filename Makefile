
################################################################
# Makefile for Particle Swarm Optimization Program
################################################################

CFLAGS  += -Wall -Wextra -fopenmp -O2
LDFLAGS += -lm
OBJS    += main.o init.o fitness.o swarm.o

################################################################
# Make all

all:	swarm

################################################################
# Make Swarm

swarm: $(OBJS) pso.h
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@


################################################################

.c.o:
	$(CC) -c $(CFLAGS) $<

################################################################
# Make Clean

clean:
	rm -f swarm *.o particle??.txt

.PHONY: clean

################################################################



# END MAKEFILE  - EWG SDG

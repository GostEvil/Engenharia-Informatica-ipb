CC=gcc
CFLAGS=-Wall
#OPT=
OPT=-O0
LFLAGS=-pthread

EXECUTABLES = $(patsubst %.c,%.exe,$(wildcard *.c))

all: $(EXECUTABLES)

%.exe: %.c
	$(CC) $(CFLAGS) $(OPT) $< -o $@ $(LFLAGS) 

clean:
	rm -f *.exe *.o

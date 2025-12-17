
CC=gcc
CFLAGS=-Wall -lm
EXECUTABLES = $(patsubst %.c,%.exe,$(wildcard *.c))

all: $(EXECUTABLES)

%.exe: %.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -f *.exe *.o

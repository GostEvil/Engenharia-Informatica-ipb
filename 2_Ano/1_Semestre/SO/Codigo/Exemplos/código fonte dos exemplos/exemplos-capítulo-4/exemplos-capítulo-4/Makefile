
CC=gcc
CFLAGS=-Wall
EXECUTABLES = $(patsubst %.c,%.exe,$(wildcard *.c))

all: $(EXECUTABLES)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.exe *.o myfile

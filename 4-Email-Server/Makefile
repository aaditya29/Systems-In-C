flags=-O2 -Wall -std=c2x
ldflags=-lbu

.PHONY: all clean

all: clean pigeon

pigeon: pigeon.o
	cc $(flags) $^ -o $@ $(ldflags)

pigeon.o: pigeon.c pigeon.h
	cc $(flags) -c $<

clean:
	rm -f *.o pigeon
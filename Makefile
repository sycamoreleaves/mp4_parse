.PHONY:clean all
CC = gcc
CFLAGS = -Wall
BIN = mp4_parse

all: $(BIN)

mp4_parse:mp4_parse.o util.o
	$(CC) -o $@ mp4_parse.c util.o $(CFLAGS)

util.o:util.c
	$(CC) -c -o $@ util.c $(CFLAGS)

clean:
	rm -f *.o $(BIN)
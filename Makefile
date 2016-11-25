## Makefile

CC = gcc
CFLAGS = -Wall -g
OBJS = concurrency.o

concurrent: $(OBJS)
	$(CC) -g -o concurrent $(OBJS)

concurrency.o: concurrency.c functions.h
	$(CC) -c -g concurrency.c
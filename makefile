\CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: binaryTree main.c binaryTree.h
	$(CC) $(CFLAGS) main.c binaryTree.o -o tree

binaryTree: binaryTree.c binaryTree.h
	$(CC) $(CFLAGS)  -c binaryTree.c -o binaryTree.o

run:
	./tree input.txt

clean:
	rm *.o tree

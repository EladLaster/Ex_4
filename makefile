all:prog1

CC = gcc
FLAGS = -Wall -g

prog1: main.o Graphs.o Shortest_Path.o
	$(CC) $(FLAGS) main.o Graphs.o Shortest_Path.o -o prog1

main.o: main.c Graphs.h
	$(CC) $(FLAGS) -c main.c -o main.o

Graphs.o: Graphs.c Graphs.h
	$(CC) $(FLAGS) -c Graphs.c -o Graphs.o

Shortest_Path.o: Shortest_Path.c Graphs.h
	$(CC) $(FLAGS) -c Shortest_Path.c -o Shortest_Path.o

clean:
	rm -f *.o prog1

.PHONY: clean all
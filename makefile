all:graph

CC = gcc
FLAGS = -Wall -g

graph: main.o graph.o algo.o
	$(CC) $(FLAGS) main.o graph.o algo.o -o graph

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c -o main.o

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c -o graph.o

algo.o: algo.c graph.h
	$(CC) $(FLAGS) -c algo.c -o algo.o

clean:
	rm -f *.o prog1

.PHONY: clean all

all:graph

CC = gcc
FLAGS = -Wall -Werror -g -std=c99

graph: main.o graph.o dijkstra.o TCP.o
	$(CC) $(FLAGS) main.o graph.o dijkstra.o TCP.o -o graph

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c -o main.o

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c -o graph.o

dijkstra.o: dijkstra.c graph.h
	$(CC) $(FLAGS) -c dijkstra.c -o dijkstra.o

TCP.o: TCP.c graph.h
	$(CC) $(FLAGS) -c TCP.c -o TCP.o

clean:
	rm -f *.o graph

.PHONY: clean all
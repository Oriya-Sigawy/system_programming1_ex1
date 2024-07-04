CC=gcc
AR=ar 
CFLAGS= -Wall -g
.PHONY: all clean
all: my_graph my_Knapsack
my_Knapsack: my_Knapsack.c
	$(CC) $(CFLAGS) $^ -o $@
my_graph: my_graph.o mymatlib.a
	$(CC) $(CFLAGS) $^ -o $@
mymatlib.a: my_mat.o
	$(AR) -rcs $@ $<
my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c $<
my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f *.o *.a my_graph
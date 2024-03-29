all: calc

calc: main.o menu.o operations.o
	gcc main.o menu.o operations.o -o calc

main.o: main.c menu.h
	gcc -c main.c -o main.o

menu.o: menu.c menu.h
	gcc -c menu.c -o menu.o

operations.o: operations.c operations.h
	gcc -c operations.c -o operations.o 

rebuild: clean all

clean:
	rm -rf *.o calc
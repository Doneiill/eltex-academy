all: rights

rights: main.o menu.o
	gcc main.o menu.o -o rights

main.o: main.c menu.h
	gcc -c main.c -o main.o

menu.o: menu.c menu.h
	gcc -c menu.c -o menu.o

rebuild: clean all

clean:
	rm -rf *.o rights
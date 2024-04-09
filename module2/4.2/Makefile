all: queue

queue: main.o queue.o

main.o: main.c queue.h
	gcc -c main.c -o main.o

queue.o: queue.c queue.h
	gcc -c queue.c -o queue.o

rebuild: clean all

clean:
	rm -rf *.o queue
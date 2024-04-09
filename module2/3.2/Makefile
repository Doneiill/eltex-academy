all: ipaddr

ipaddr: main.o func.o
	gcc main.o func.o -o ipaddr

main.o: main.c func.h
	gcc -c main.c -o main.o

func.o: func.c func.h
	gcc -c func.c -o func.o

rebuild: clean all

clean:
	rm -rf *.o ipaddr
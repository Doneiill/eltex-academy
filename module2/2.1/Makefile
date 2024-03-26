all: phone

phone: main.o person.o menu.o line.o contacts.o job.o
	gcc main.o person.o menu.o line.o contacts.o job.o -o phone

main.o: main.c line.h menu.c
	gcc -c main.c -o main.o

person.o: person.c person.h
	gcc -c person.c -o person.o

menu.o: menu.c menu.h
	gcc -c menu.c -o menu.o

line.o: line.c line.h
	gcc -c line.c -o line.o

contacts.o: contacts.c contacts.h
	gcc -c contacts.c -o contacts.o

job.o: job.c job.h
	gcc -c job.c -o job.o

rebuild: clean all

clean:
	rm -rf *.o phone
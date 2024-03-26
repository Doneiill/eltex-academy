#ifndef PERSON_H_
#define PERSON_H_

#include <string.h>

typedef struct Person
{
    char first_name[20];
    char second_name[20];
    char father_name[20];
} Person;

Person* SetPerson(Person* item, char first_name[], char second_name[], char father_name[]);

#endif
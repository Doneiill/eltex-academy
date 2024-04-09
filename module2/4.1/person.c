#include "person.h"

Person* SetPerson(Person* item, char first_name[], char second_name[], char father_name[])
{
    strncpy(item->first_name, first_name, 20);
    strncpy(item->second_name, second_name, 20);
    strncpy(item->father_name, father_name, 20);
    return item;
}
#ifndef LINE_H_
#define LINE_H_

#include "person.h"
#include "job.h"
#include "contacts.h"

typedef struct Line
{
    Person person;
    Job job;
    Contacts contacts;
} Line;

void LineInit(Line* item);
void CopyLine(Line* item, Line* second);

#endif
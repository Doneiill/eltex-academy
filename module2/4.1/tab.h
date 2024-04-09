#ifndef TAB_H_
#define TAB_H_

#include "line.h"

typedef struct Tab
{
    struct Tab* next;
    struct Tab* prev;
    int pos, size;
    Line item;
} Tab;


#endif
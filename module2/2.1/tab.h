#ifndef TAB_H_
#define TAB_H_

#include "line.h"

typedef struct Tab
{
    int length;
    Line table[20];
} Tab;


#endif
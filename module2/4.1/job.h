#ifndef JOB_H_
#define JOB_H_

#include <string.h>

typedef struct Job
{
    char company[20];
    char position[20];
} Job;

Job* SetJob(Job* item, char company[], char position[]);

#endif
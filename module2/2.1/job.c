#include "job.h"

Job* SetJob(Job* item, char company[], char position[])
{
    strncpy(item->company, company, 20);
    strncpy(item->position, position, 20);

    return item;
}
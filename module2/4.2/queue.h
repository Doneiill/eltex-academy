#ifndef QUEUE_H_
#define QUEUE_H_
#define BUFF_SIZE 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue
{
    int data;
    int priority;
    struct Queue* next;
    struct Queue* prev;
} Queue;

Queue* QueueInit();
Queue* Enqueue(Queue* head, int data, int priority);
int Menu();
int InputChoise(int* choise);
Queue* Dequeue(Queue* head);
Queue* DequeueFithPriority(Queue* head, int priority);
Queue* DequeueNoLessPriority(Queue* head, int priority);
Queue* MessageGeneration(Queue* queue, int count);
void PrintQueue(Queue* queue);

#endif
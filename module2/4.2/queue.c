#include "queue.h"

int Menu()
{
    int choise;
    printf("\nSelect an action:\n");
    printf("1. Dequeue first element\n");
    printf("2. Dequeue first element with priority\n");
    printf("3. Dequeue first element no less priority\n");
    printf("4. Exit\n");
    InputChoise(&choise);
    return choise;
}

int InputChoise(int* choise)
{
    char input[BUFF_SIZE] = {};
    *choise = 0;
    fgets(input, BUFF_SIZE, stdin);
    for(int i = 0; input[i] != '\n'; i++)
    {
        if(input[i] < '0' || input[i] > '9')
        {
            printf("Wrong choise!\n");
            return 0;
        }
        *choise *= 10;
        *choise += input[i] - '0';
    }
    
    return *choise;
}

Queue* QueueInit()
{
    Queue* item = malloc(sizeof(Queue));
    item->data = 0;
    item->priority = 0;
    item->next = NULL;
    item->prev = NULL;
    return item;
}

Queue* Enqueue(Queue* head, int data, int priority)
{
    Queue* item = QueueInit();
    item->data = data;
    item->priority = priority;
    if(head->data == 0 && head->priority == 0 && head->next == NULL)
    {
        head->data = data;
        head->priority = priority;
    }
    else if(head->priority > priority)
    {
        item->next = head;
        head->prev = item;
        head = item;
    }
    else
    {
        for(Queue* temp = head; temp != NULL; temp = temp->next)
        {
            if (temp->next != NULL && temp->next->priority > priority)
            {
                item->next = temp->next;
                item->next->prev = item;
                item->prev = temp;
                temp->next = item;
                break;
            }
            else if(temp->next == NULL)
            {
                temp->next = item;
                item->prev = temp;
                break;
            }
        }
    }
    return head;
}

Queue* MessageGeneration(Queue* queue, int count)
{
    srand(time(NULL));
    for(int i = 1; i < count + 1; i++)
    {
        queue = Enqueue(queue, i, rand()%256);
    }
    return queue;
}

Queue* Dequeue(Queue* head)
{
    Queue* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Queue* DequeueFithPriority(Queue* head, int priority)
{
    for(Queue* temp = head; temp != NULL; temp = temp->next)
    {
        if(temp->priority == priority)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            break;
        }
    }
    return head;
}

Queue* DequeueNoLessPriority(Queue* head, int priority)
{
    for(Queue* temp = head; temp != NULL; temp = temp->next)
    {
        if(temp->priority >= priority)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            break;
        }
    }
    return head;
}

void PrintQueue(Queue* queue)
{
    for(Queue* temp = queue; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
    printf("\n");
    for(Queue* temp = queue; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->priority);
    }
}
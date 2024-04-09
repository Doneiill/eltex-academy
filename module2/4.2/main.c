#include "queue.h"

int main()
{
    //int a, b;
    int choise, count;
    Queue* queue = QueueInit();
    //printf("%d %d %p", queue->data, queue->priority, queue->next);
    /*for(int i = 0; i < 5; i++)
    {
        scanf("%d %d", &a, &b);
        printf("\nazazaz\n");
        queue = Enqueue(queue, a, b);
    }*/
    printf("Enter count of messages: ");
    count = InputChoise(&count);
    queue = MessageGeneration(queue, count);
    PrintQueue(queue);
    while(1)
    {
        choise = Menu();
        int priority = 0;
        if(choise == 4) break;
        switch(choise)
        {
            case 1:
                queue = Dequeue(queue);
                PrintQueue(queue);
                break;

            case 2:
                printf("Enter priority: ");
                priority = InputChoise(&priority);
                queue = DequeueFithPriority(queue, priority);
                PrintQueue(queue);
                break;

            case 3:
                printf("Enter priority: ");
                priority = InputChoise(&priority);
                queue = DequeueNoLessPriority(queue, priority);
                PrintQueue(queue);
                break;

            default:
                printf("Wrong choise!");
                break;
        }
    }
    
    return 0;
}
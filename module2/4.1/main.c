#include <stdio.h>
#include "line.h"
#include "menu.h"

int main()
{
    Tab* table = InitNode();
    int choise;
    while(1)
    {
        choise = Menu();
        if(choise == 6) break;
        switch(choise)
        {
            case 1:
                PrintTable(table);
                break;

            case 2:
                int number;
                printf("Enter number of line: ");
                scanf("%d", &number);
                PrintInfo(table, number);
                break;

            case 3:
                table = AddLine(table);
                break;
            case 4:
                ChangeLine(table);
                break;
            case 5:
                table = RemLine(table);
                break;

            default:
                printf("Wrong choise!\n");
        }
    }
    FreeTab(table);
    
    
    return 0;
}
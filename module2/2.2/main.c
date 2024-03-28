#include <stdio.h>
#include "menu.h"

int main()
{
    int choise;
    char input_arr[40] = {};
    float x = 0, y = 0;
    while(1)
    {
        Menu();
        InputChoise(&choise);
        if(choise == 0) break;
        switch(choise)
        {
            case 1:
                if(Input(1, &x, &y))
                {
                    printf("Result: %lf", Sum(x, y));
                }
                break;
            case 2:
                if(Input(1, &x, &y))
                {
                    printf("Result: %lf", Dif(x, y));
                }
                break;
            case 3:
                if(Input(1, &x, &y))
                {
                    printf("Result: %lf", Mul(x, y));
                }
                break;
            case 4:
                if(Input(1, &x, &y))
                {
                    if(y != 0 && x == (int)x && y == (int)y)
                    {
                        printf("Result: %d", DivCel(x, y));
                    }
                    else   
                    {
                        printf("Wrong numbers!");
                    }
                }
                break;
            case 5:
                if(Input(1, &x, &y))
                {
                    if(y != 0)
                    {
                        printf("Result: %lf", Div(x, y));
                    }
                    else   
                    {
                        printf("Wrong numbers!");
                    }
                }
                break;
            case 6:
                if(Input(1, &x, &y))
                {
                    if(y != 0 && x == (int)x && y == (int)y)
                    {
                        printf("Result: %d", Ost(x, y));
                    }
                    else   
                    {
                        printf("Wrong numbers!");
                    }
                }
                break;
            case 7:
                if(Input(1, &x, &y))
                {
                    if(y >= 0 && y == (int)y)
                        printf("Result: %lf", Step(x, y));
                    else
                        printf("Wrong numbers!");
                }
                break;
            case 8:
                if(Input(1, &x, &y))
                {
                    printf("Result: %lf%%", WhatPercent(x, y));
                }
                break;
            case 9:
                if(Input(1, &x, &y))
                {
                    printf("Result: %lf", HowMuchInPercent(x, y));
                }
                break;
            default:
                printf("Wrong choise!");
        }
    }
    


    return 0;
}
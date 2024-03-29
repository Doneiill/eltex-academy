#include <stdio.h>
#include "menu.h"

int main()
{
    int choise;
    float x, y;
    while(1)
    {
        float (*func)(float, float) = Input(&choise, &x, &y);
        PrintResult(x, y, func);
        /*switch (choise)
        {
        case 1:
            PrintResult(x, y, Sum);
            break;
        case 2:
            PrintResult(x, y, Dif);
            break;
        case 3:
            PrintResult(x, y, Mul);
            break;
        case 4:
            PrintResult(x, y, DivCel);
            break;
        case 5:
            PrintResult(x, y, Div);
            break;
        case 6:
            PrintResult(x, y, Ost);
            break;
        case 7:
            PrintResult(x, y, Step);
            break;
        case 8:
            PrintResult(x, y, WhatPercent);
            break;
        case 9:
            PrintResult(x, y, HowMuchInPercent);
            break;
        
        default:
            break;
        }*/
    }
    
    return 0;
}
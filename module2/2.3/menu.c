#include "menu.h"

void Menu()
{
    printf("\n\n0. Exit\n");
    printf("1. Summ\n");
    printf("2. Difference\n");
    printf("3. Multiply\n");
    printf("4. Integer division\n");
    printf("5. Division\n");
    printf("6. Remainder\n");
    printf("7. Exponentiation\n");
    printf("8. What persent (result %%)\n");
    printf("9. What persent (second input %%)\n");
    printf("Enter your choise: ");
}

float (*Input(int* choise, float* a, float* b))(float first, float second)
{
    char string[40] = {};
    fgets(string, 40, stdin);
    if(string[0] < '0' || string[0] > '9')
    {
        printf("Wrong numbers!");
        return 0;
    }
    *a = *b = 0;
    int second;
    float factor = 0.1;
    for(int i = 0; string[i] != ' '; i++)
    {
        while(string[i] != '.' && string[i] != ' ')
        {
            if(string[i] < '0' || string[i] > '9')
            {
                printf("Wrong numbers!");
                return 0;
            }
            *a *= 10;
            *a += string[i] - '0';
            i++;
        }
        if(string[i] == '.')
        {
            i++;
            while(string[i]!= ' ')
            {
                if(string[i] < '0' || string[i] > '9')
                {
                    printf("Wrong numbers!");
                    return 0;
                }
                *a += (string[i] - '0') * factor;
                factor *= 0.1;
                i++;
            }
        }
        second = i;
        i--;
    }
    
    if(string[second+1] == '+')
    {
        *choise = 1;
    }
    else if(string[second+1] == '-')
    {
        *choise = 2;
    }
    else if(string[second+1] == '*')
    {
        *choise = 3;
    }
    else if(string[second+1] == '/')
    {
        if(string[second+2] == '/')
        {
            *choise = 4;
            second++;
        }
        else
            *choise = 5;
    }
    else if(string[second+1] == '%')
    {
        *choise = 6;
    }
    else if(string[second+1] == '^')
    {
        *choise = 7;
    }
    else if(string[second+1] == '$')
    {
        if(string[second+2] == '%')
        {
            *choise = 8;
            second++;
        }
        else
            *choise = 9;
    }
    second+=2;
    factor = 0.1;
    for(int i = second + 1; string[i] != '\n'; i++)
    {
        while(string[i] != '.' && string[i] != '\n')
        {
            if(string[i] < '0' || string[i] > '9')
            {
                printf("Wrong numbers!");
                return 0;
            }
            *b *= 10;
            *b += string[i] - '0';
            i++;  
        }
        if(string[i] == '.')
        {
            i++;
            while(string[i]!= '\n')
            {
                if(string[i] < '0' || string[i] > '9')
                {
                    printf("Wrong numbers!");
                    return 0;
                }
                *b += (string[i] - '0') * factor;
                factor *= 0.1;
                i++;
            }
        }
        i--;
    }
    switch(*choise)
    {
        case 1: 
            return Sum;
        case 2: 
            return Dif;
        case 3: 
            return Mul;
        case 4: 
            return DivCel;
        case 5: 
            return Div;
        case 6: 
            return Ost;
        case 7: 
            return Step;
        case 8: 
            return WhatPercent;
        case 9: 
            return HowMuchInPercent;
    }
}

int InputChoise(int* choise)
{
    char input[20] = {};
    *choise = 0;
    fgets(input, 20, stdin);
    for(int i = 0; input[i] != '\n'; i++)
    {
        if(input[i] < '0' || input[i] > '9')
        {
            printf("Wrong choise!");
            return 0;
        }
        *choise *= 10;
        *choise += input[i] - '0';
    }
    
    return *choise;
}


void PrintResult(float a, float b, float (*func) (float a, float b))
{
    printf("Result: %lf\n", func(a, b));
}
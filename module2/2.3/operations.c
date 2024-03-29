#include "operations.h"

float Sum(float first, float second)
{
    float res = first + second;
    return res;
}

float Dif(float first, float second)
{
    return first-second;
}

float Mul(float first, float second)
{
    return first*second;
}

float DivCel(float first, float second)
{
    return (int)first/(int)second;
}

float Div(float first, float second)
{
    return first/second;
}

float Ost(float first, float second)
{
    return (int)first%(int)second;
}

float Step(float first, float second)
{
    float res = 1;
    for(int i = 0; i< (int)second; i++)
    {
        res *= first;
    }
    return res;
}


float WhatPercent(float first, float second)
{
    return second*100.0/first*1.0;
}


float HowMuchInPercent(float first, float second)
{
    return first/100.0*second;
}


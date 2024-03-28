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

int DivCel(int first, int second)
{
    return first/second;
}

float Div(float first, float second)
{
    return first/second;
}

int Ost(int first, int second)
{
    return first%second;
}

float Step(float first, int second)
{
    float res = 1;
    for(int i = 0; i< second; i++)
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


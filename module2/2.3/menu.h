#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include "operations.h"

void Menu();
float (*Input(int* choise, float* a, float* b))(float first, float second);
int InputChoise(int* choise);
void PrintResult(float a, float b, float (*func) (float a, float b));

#endif
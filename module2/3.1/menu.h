#ifndef MENU_H_
#define MENU_U_
#define BUFF_SIZE 20

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

void Menu();
int InputChoise(int* choise);
int InputRights(char* arr);
void RightsToBits(char* string, char* bits);
char DecToBin(int num, char* arr, int size);
void StringToUInt(char* arr, unsigned int *bits);
void UIntToString(unsigned int bits, char* arr);
void UIntToLetters(unsigned int bits, char* arr);
void UIntToInt(unsigned int bits, char* arr);
void UIntToBits(unsigned int bits, char* arr);
void BinToDec(unsigned int bits, int* num);
int Power(int num, int step);
int ChangeRights(unsigned int* bits);
int SetRightsInChar(unsigned int* bits, unsigned int rights);
void PrintRights(unsigned int int_bits);

#endif
#ifndef FUNC_H_
#define FUNC_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define BUFF_SIZE 20

unsigned int GenIP();
unsigned int StringToUint(char* string);
unsigned int MaskToUInt(int mask);
int CheckSubNet(unsigned int ip_addr, unsigned int ip_gate, unsigned int mask);
#endif
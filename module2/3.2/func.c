#include "func.h"

unsigned int GenIP()
{
    int byte;
    unsigned int result = rand();
    if(rand() % 2) result |= 1 << 31;
    return result;
}


unsigned int StringToUint(char* string)
{
    int iter = 0, next = 0, byte = 0;
    unsigned int result = 0;
    char temp[3];
    for(int i = 0; i<4; i++)
    {
        iter = 0;
        for(int j = next; string[j] != '.' && string[j] != 0; j++)
        {
            temp[iter] = string[j];
            iter++;
            next = j;
        }
        if(i != 3) next += 2;
        byte = atoi(temp);
        for(int j = 0; j < 8; j++)
        {
            if(byte % 2 == 1) result |= 1 << ((3 - i) * 8 + j);
            byte /= 2;
        }
        byte = 0;
        strncpy(temp, "", 3);
    }
    return result;
}

unsigned int MaskToUInt(int mask)
{
    unsigned int result = 0;
    for(int i = 0; i < mask; i++)
    {
        result |= 1 << (31 - i);
    }
    return result;
}

int CheckSubNet(unsigned int ip_addr, unsigned int ip_gate, unsigned int mask)
{
    return (ip_addr & mask) == (ip_gate & mask);
}
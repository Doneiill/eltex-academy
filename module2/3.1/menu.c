#include "menu.h"

void Menu()
{
    printf("1. Access rights to bits\n");
    printf("2. Filename to rights\n");
    printf("3. Change rights\n");
}

int InputChoise(int* choise)
{
    char input[BUFF_SIZE] = {};
    *choise = 0;
    fgets(input, BUFF_SIZE, stdin);
    for(int i = 0; input[i] != '\n'; i++)
    {
        if(input[i] < '0' || input[i] > '9')
        {
            printf("Wrong choise!\n");
            return 0;
        }
        *choise *= 10;
        *choise += input[i] - '0';
    }
    
    return *choise;
}


int InputRights(char* arr)
{
    char string[BUFF_SIZE];
    fgets(string, BUFF_SIZE, stdin);
    if (string[0] != '-' && string[0] != 'r' && (string[0] < '0' || string[0] > '7'))
        return 0;
    if(string[0] >=  '0' && string[0] <= '7')
    {
        if(string[1] < '0' || string[1] > '7' || string[2] < '0' || string[2] > '7')
            return 0;
    }
    else
    {
        if(string[1] != 'w' && string[1] != '-') return 0;
        if(string[2] != 'x' && string[2] != '-') return 0;
        if(string[3] != 'r' && string[3] != '-') return 0;
        if(string[4] != 'w' && string[4] != '-') return 0;
        if(string[5] != 'x' && string[5] != '-') return 0;
        if(string[6] != 'r' && string[6] != '-') return 0;
        if(string[7] != 'w' && string[7] != '-') return 0;
        if(string[8] != 'x' && string[8] != '-') return 0;
    }
    strncpy(arr, string, BUFF_SIZE);
    return 1;
}


void RightsToBits(char* string, char* bits)
{
    if(string[0] >= '0' && string[0] <= '7')
    {
        char temp[3];
        DecToBin(string[0] - '0', temp, 3);
        strncpy(bits, temp, 3);
        strncpy(temp,"000",3);
        DecToBin(string[1] - '0', temp, 3);
        strncpy(&bits[3], temp, 3);
        strncpy(temp,"000",3);
        DecToBin(string[2] - '0', temp, 3);
        strncpy(&bits[6], temp, 3);
        strncpy(temp,"000",3);
    }
    else
    {
        for(int i = 0; i < 9; i++)
        {
            if(string[i] != '-')
                bits[i] = '1';
            else bits[i] = '0';
        }
    }
}

char DecToBin(int num, char* arr, int size)
{
    for(int i = size - 1; num; i--)
    {
        arr[i] = num % 2 + '0';
        num /= 2;
    }
}


void StringToUInt(char* arr, unsigned int *bits)
{
    *bits = 0;
    unsigned int iterator = 1;
    for(int i = 8; i >= 0; i--)
    {
        if(arr[i] == '1') *bits |= iterator;
        iterator *= 2;
    }

}


void UIntToString(unsigned int bits, char* arr)
{
    char string[BUFF_SIZE];
    int size = 0;
    for(int i = 0; i < 9; i++)
    {
        string[i] = bits%2 + '0';
        bits/=2;
        size = i;
    }
    for(int i = size; i >= 0; i--)
    {
        arr[size-i] = string[i];
    }
    arr[size] = '\0';
}


void UIntToLetters(unsigned int bits, char* arr)
{
    for(int i = 3; i > 0; i--)
    {
        if(bits % 2 == 1) arr[i*3-1] = 'x';
        else arr[i*3-1] = '-';
        bits /= 2;
        if(bits % 2 == 1) arr[i*3-2] = 'w';
        else arr[i*3-2] = '-';
        bits /= 2;
        if(bits % 2 == 1) arr[i*3-3] = 'r';
        else arr[i*3-3] = '-';
        bits /= 2;
    }
}


void BinToDec(unsigned int bits, int* num)
{
    int stepen = 1;
    for(int i = 0; i < 3; i++)
    {
        int counter = 0;
        for(int j = 0; j < 3; j++)
        {
            *num += Power(2, counter) * (bits%2) * stepen;
            bits /= 2;
            counter ++;
        }
        stepen *= 10;
    }
}


int Power(int num, int step)
{
    int result = 1;
    for(int i = 0; i < step; i++)
    {
        result *= num;
    }
    return result;
}



char RightsOfFile()
{
    
}


int ChangeRights(unsigned int *bits)
{
    char string[BUFF_SIZE];
    char s_bits[BUFF_SIZE];
    unsigned int rights = 0;
    fgets(string, BUFF_SIZE, stdin);
    int u = 0, g = 0, o = 0, a = 0, plus = 0, minus = 0, equal = 0, r = 0, w = 0, x = 0;
    if(string[0] >= '0' && string[0] <= '7' && string[1] >= '0' && string[1] <= '7' && string[2] >= '0' && string[2] <= '7' && string[4] == 0)
    {
        RightsToBits(string, s_bits);
        StringToUInt(s_bits, bits);
    }
    else
    {
        int size = 0;
        if(string[size] == '+' || string[size] == '-' || string[size] == '=')
        {
            a = 1;
            rights |= 1 << 6;
            rights |= 1 << 9;
            rights |= 1 << 8;
            rights |= 1 << 7;
        }
        else
        {
            for(int i = 0; string[i] != '+' && string[i] != '-' && string[i] != '='; i++)
            {
                if(string[i] == 'u' && u == 0) {u = 1; rights |= 1 << 9;}
                else if(string[i] == 'g' && g == 0) {g = 1; rights |= 1 << 8;}
                else if(string[i] == 'o' && o == 0) {o = 1; rights |= 1 << 7;}
                else if(string[i] == 'a' && a == 0) {o = 1; rights |= 1 << 6; rights |= 1 << 9; rights |= 1 << 8; rights |= 1 << 7;}
                else return 0;
                size = i;
            }
            size++;
        }
        if (string[size] == '+') {plus = 1; rights |= 1 << 5;}
        else if (string[size] == '-') {minus = 1; rights |= 1 << 4;}
        else if (string[size] == '=') {equal = 1; rights |= 1 << 3;}
        else return 0;
        for(int i = size + 1; string[i] != '\n'; i++)
        {
            if(string[i] == 'r' && r == 0) {r = 1; rights |= 1 << 2;}
            else if(string[i] == 'w' && w == 0) {w = 1; rights |= 1 << 1;}
            else if(string[i] == 'x' && x == 0) {x = 1; rights |= 1;}
            else return 0;
        }
        SetRightsInChar(bits, rights);
    }
    
}

int SetRightsInChar(unsigned int* bits, unsigned int rights)
{
    if(rights & (1 << 5))
    {
        if(rights & (1 << 9))
        {
            if(rights & (1 << 2)) *bits |= 1 << 8;
            if(rights & (1 << 1)) *bits |= 1 << 7;
            if(rights & 1) *bits |= 1 << 6;
        }
        if(rights & (1 << 8))
        {
            if(rights & (1 << 2)) *bits |= 1 << 5;
            if(rights & (1 << 1)) *bits |= 1 << 4;
            if(rights & 1) *bits |= 1 << 3;
        }
        if(rights & (1 << 7))
        {
            if(rights & (1 << 2)) *bits |= 1 << 2;
            if(rights & (1 << 1)) *bits |= 1 << 1;
            if(rights & 1) *bits |= 1;
        }
    }
    else if(rights & (1 << 4))
    {
        if(rights & (1 << 9))
        {
            if(rights & (1 << 2)) *bits &= ~(1 << 8);
            if(rights & (1 << 1)) *bits &= ~(1 << 7);
            if(rights & 1) *bits &= ~(1 << 6);
        }
        if(rights & (1 << 8))
        {
            if(rights & (1 << 2)) *bits &= ~(1 << 5);
            if(rights & (1 << 1)) *bits &= ~(1 << 4);
            if(rights & 1) *bits &= ~(1 << 3);
        }
        if(rights & (1 << 7))
        {
            if(rights & (1 << 2)) *bits &= ~(1 << 2);
            if(rights & (1 << 1)) *bits &= ~(1 << 1);
            if(rights & 1) *bits &= ~1;
        }
    }
    else if(rights & (1 << 3))
    {
        if(rights & (1 << 9))
        {
            *bits &= ~(1 << 8);
            *bits &= ~(1 << 7);
            *bits &= ~(1 << 6);
            if(rights & (1 << 2)) *bits |= 1 << 8;
            if(rights & (1 << 1)) *bits |= 1 << 7;
            if(rights & 1) *bits |= 1 << 6;
        }
        if(rights & (1 << 8))
        {
            *bits &= ~(1 << 5);
            *bits &= ~(1 << 4);
            *bits &= ~(1 << 3);
            if(rights & (1 << 2)) *bits |= 1 << 5;
            if(rights & (1 << 1)) *bits |= 1 << 4;
            if(rights & 1) *bits |= 1 << 3;
        }
        if(rights & (1 << 7))
        {
            *bits &= ~(1 << 2);
            *bits &= ~(1 << 1);
            *bits &= ~1;
            if(rights & (1 << 2)) *bits |= 1 << 2;
            if(rights & (1 << 1)) *bits |= 1 << 1;
            if(rights & 1) *bits |= 1;
        }
    }
    else return 0;
    return 1;
}


void PrintRights(unsigned int int_bits)
{
    char string[BUFF_SIZE] = {};
    UIntToLetters(int_bits, string);
    printf("%s\n", string);
    strncpy(string, "", 20);
    int result = 0;
    BinToDec(int_bits, &result);
    printf("%d\n", result);
    UIntToString(int_bits, string);
    printf("%s\n", string);
}
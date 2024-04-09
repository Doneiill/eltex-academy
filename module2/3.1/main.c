#include "menu.h"

int main()
{
    char string[BUFF_SIZE] = {}, bits[BUFF_SIZE], output[BUFF_SIZE], file_name[BUFF_SIZE];
    unsigned int int_bits = 0;
    int choice;
    while(1)
    {
        Menu();
        InputChoise(&choice);
        switch (choice)
        {
        case 1:
            InputRights(string);
            RightsToBits(string, bits);
            StringToUInt(bits, &int_bits);
            UIntToString(int_bits, string);
            printf("%s\n", string);
            break;

        case 2:
            fgets(file_name, BUFF_SIZE, stdin);
            for(int i = 0; i < BUFF_SIZE; i++)
            {
                if(file_name[i] == '\n') 
                {
                    file_name[i] = 0;
                    break;
                }
            }
            struct stat info;
            stat(file_name, &info);
            int_bits = info.st_mode;
            int_bits &= 0b0000000111111111;
            PrintRights(int_bits);
            break;
        case 3:
            if(ChangeRights(&int_bits))
                PrintRights(int_bits);
            else printf("Wrong Rights!\n");
            break;
        
        default:
            break;
        }
    }
    

    return 0;
}
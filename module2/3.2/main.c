#include "func.h"

int main(int argc, char* argv[])
{
    char s_gate_ip_addr[BUFF_SIZE], s_ip_addr[BUFF_SIZE], s_mask[BUFF_SIZE];
    int mask, count, count_our = 0;
    unsigned int ip_addr, gate_ip_addr;
    float percent;

    strncpy(s_gate_ip_addr, argv[1], BUFF_SIZE);
    mask = atoi(argv[2]);
    count = atoi(argv[3]);
    gate_ip_addr = StringToUint(s_gate_ip_addr);
    srand(time(NULL));
    
    for(int i = 0; i < count; i++)
    {
        ip_addr = GenIP(i);
        if(CheckSubNet(ip_addr, gate_ip_addr, MaskToUInt(mask))) 
        {
            count_our++;
        }
    }
    percent = count_our * 100.0 / count;

    printf("\nCount of our packets: %d", count_our);
    printf("\nCount of not our packets: %d", count - count_our);
    printf("\nPercentage of our packets: %.2lf%%\n", percent);

    return 0;
}
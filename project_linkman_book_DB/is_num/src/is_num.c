/***************************************************************
Function :       is_nnum
Description:     判断字符为0~9 
Calls :          1.is_num   
Called by :      2.add_information
Input :          1.src       原字符串
Return :         SUCCESS
Others:          none
****************************************************************/

#include "../../include/my_head.h"

int is_num(char *src)
{
    int i = 0;
    while(*(src + i) != '\0')
    {
        if((*(src + i) < '0' || *(src + i) > '9') && *(src + i) != ' ')
	{
	    printf(RED"\n\t\t\tIt is not a number ! Please input again :\n");
	    printf(YELLOW"\n\t\t\t");
	    gets(src);
	    is_num(src);
	}
        
        i++;
    }
    return SUCCESS;
}

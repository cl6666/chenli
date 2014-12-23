/***************************************************************
Function :       str_com
Description:     比较字符串大小 
Calls :          none
Called by :      1.sort_linkman
                 2.display_search
		 3.delete_linkman
Input :          1.str
                 2.src
Return :         1         str > src
                 0         str = src
		 -1        str < src
Others:          none
****************************************************************/

#include "../../include/my_head.h"

int str_com(char *str,char *src)
{
    while(*str != '\0')
    {
        if(*str > *src)
	{
	    return 1;
	}

	if(*str < *src)
	{
	    return -1;
	}
	str ++;
	src ++;
    }
    if(*str == '\0')
    {
        if(*src == '\0')
	{
	    return 0;
	}
	return -1;
    }
}

/******************************************************************************
Function :       is_ID_exit
Description:     判断ID唯一存在 
Calls :          1.str_com         比较字符串
Called by :      insert_linkman
Input :          1.head
                 2.newnode
Return :         none
Others:          none
*******************************************************************************/

#include "../../include/my_head.h"

void is_ID_exit(Link *head,char *ID)
{
    Link temp = (*head)->next->next;
    int i = 0;
    while(temp != *head)
    {
        if(str_com(temp->ID,ID) == 0)
	{
	    printf(RED"\n\t\t\tThe ID has been exited !Please input again:\n");
	    printf(YELLOW"\n\t\t\t");       //重新输入ID
	    gets(ID);
	    if(strlen(ID) < 10)
	    {
	        for(i = strlen(ID); i < 9; i ++)
		{
		    *(ID) = ' ';
		}
		*(ID + i) = '\0';
	    }
	    is_ID_exit(head,ID);
	}
        temp = temp->next;
    }
}

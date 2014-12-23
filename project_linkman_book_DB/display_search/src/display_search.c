/***************************************************************
Function :       display_search
Description:     显示联系人
Calls :          1.str_com      compare string
Called by :      insert_linkman
Input :          1.name
                 2.head
                 3.newnode
Return :         show_times
Others:          none
****************************************************************/

#include "../../include/my_head.h"

int display_search(Link *head,char *name,Link *newnode)
{
    int show_times = 0;
    Link temp = (*head)->next;
    
    while(temp != *head)
    {
        
	if(str_com(temp->name,name) == 0)
	{
	    printf(BROWN"\t\t\tThe linkman you want:\n\n"NONE);
            
	    printf(WHITE"\t\t\tID : %5s\n"NONE,temp->ID);
	    printf(YELLOW"\t\t\tName    : %13s   \t Phone   : %14s\  
	           \n\t\t\tAddress : %10s    Co-tele : %11s\n\n"NONE,
	           temp->name,temp->phone,temp->address,temp->Cotel);
	    show_times ++;
	}
	temp = temp->next;
    }
    return show_times;
}

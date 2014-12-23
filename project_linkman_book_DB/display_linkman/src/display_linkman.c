/***************************************************************
Function :       display_linkman 
Description:     显示联系人
Calls :          1.choose_action
Called by :      2.choose_action
Input :          1.head
                 2.newnode
Return :         none
Others:          none
****************************************************************/

#include "../../include/my_head.h"

void display_linkman(Link *head,Link *newnode)
{
    Link temp = (*head)->next;
    system("reset");
    printf("\n");
    printf(BROWN"\t\t\t\t\t      -LINKMAN-\n\n");
    
    while(temp != *head)
    {
        printf(WHITE"\t\t\tID : %s\n"NONE,temp->ID);
	printf(YELLOW"\t\t\tName    : %s \t Phone   : %s\  
	       \n\t\t\tAddress : %s    Co-tele : %s\n\n"NONE,
	       temp->name,temp->phone,temp->address,temp->Cotel);
	temp = temp->next;
    }
}

/***************************************************************
Function :       search_linkman
Description:     查找联系人
Calls :          1.display_search     显示被查找联系人
                 2.choose_action      选择下一功能
Called by :      choose_action
Input :          1.head
                 2.newnode
Return :         none
Others:          none
****************************************************************/

#include "../../include/my_head.h"

void search_linkman(Link *head,Link *newnode)
{
    int i = 0;
    char name[15];
    
    system("reset");
    printf("\n\n\n");
    printf(WHITE"\t\t\tPlease input the name you want : ");
    scanf("%s",name);
    getchar();
    printf("\n");
    
    if(strlen(name) < 15)
    {
        for(i = strlen(name); i < 14; i ++)
	{
	    *(name + i) = ' ';
	}
	*(name + i) = '\0';
    }

    if(display_search(head,name,newnode) == 0 )
    {
        printf(RED"\t\t\tThe linkman you want doesn't exit !\n");
    }
    
}

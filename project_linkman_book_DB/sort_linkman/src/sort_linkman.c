/******************************************************
Function :       sort_linkman
Description:     联系人按姓名排序 
Calls :          1.str_com        比较字符串
Called by :      insert_linkman
Input :          1.head
Return :         SUCCESS
Others:          none
******************************************************/

#include "../../include/my_head.h"

int sort_linkman(Link *head)
{
    Link str = (*head)->next;
    Link temp = str->next;
    
    if(temp == *head)
    {
        return SUCCESS; 
    }
    
    while(temp != *head)
    {
        if(str_com(str->name,temp->name) > 0)
	{
	    (str->prior)->next  = temp;
	    temp->prior = str->prior;

	    str->next = temp->next;
	    (temp->next)->prior = str;

	    temp->next = str;
	    str->prior = temp;
	}
	str = temp;
        temp = str->next;
    }
    
    return SUCCESS;
}

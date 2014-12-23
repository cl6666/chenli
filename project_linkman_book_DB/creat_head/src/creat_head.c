/***************************************************************
Function :       creat_head
Description:     创建链头 
Calls :          1.is_malloc_ok   判断空间申请成功
Called by :      main
Input :          1.head
Return :         none
Others:          none
****************************************************************/

#include "../../include/my_head.h"

void creat_head(Link *head)
{
    *head = (Link)malloc(sizeof(Linkman));
    is_malloc_ok(head);

    (*head)->next = *head;
    (*head)->prior = *head;
}

/***************************************************************
Function :       is_malloc_ok
Description:     判断空间申请结果
alls :           none
Called by :      1.creat_head
                 2.insert_linkman
Input :          1.node
Return :         none
Others:          none
****************************************************************/

#include "../../include/my_head.h"

void is_malloc_ok(Link * node)
{
    if(*node == NULL)
    {
        printf(RED"FOUND FAILED !\n");
	exit(NO_SUCCESS);
    }
}

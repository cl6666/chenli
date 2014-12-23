/***************************************************************
Function :       print_interface
Description:     显示主界面
Calls :          none
Called by :      1.main
                 2.choose_action
Input :          none
Return :         none
Others:          none
****************************************************************/
 
#include "../../include/my_head.h"

void print_interface()
{
    int i = 0;
    system("reset");

    printf(YELLOW"\n\n\n");
    printf("\t\t\t=====================================================\n");
    
    for(i = 0; i < 1; i ++)
    {
        printf("\t\t\t~~\t\t\t\t\t\t   ~~\n");
    }

    printf("\t\t\t~~\t\t  --Linkman Book--\t\t   ~~\n");
    for(i = 0; i < 1; i ++)
    {
        printf("\t\t\t~~\t\t\t\t\t\t   ~~\n");
    }
    printf("\t\t\t~~\t    *Insert\t\t*Display\t   ~~\n");

    for(i = 0; i < 2; i ++)
    {
        printf("\t\t\t~~\t\t\t\t\t\t   ~~\n");
    }
    printf("\t\t\t~~\t    *Search\t\t*Delete\t\t   ~~\n");
    
    for(i = 0; i < 2; i ++)
    {
        printf("\t\t\t~~\t\t\t\t\t\t   ~~\n");
    }
    printf("\t\t\t~~\t    *Exit  \t\t*Help   \t   ~~\n");
    
    for(i = 0; i < 1; i ++)
    {
        printf("\t\t\t~~\t\t\t\t\t\t   ~~\n");
    }

    printf("\t\t\t~~\t\t\t\t   VERSION : 3.0   ~~\n");
    printf("\t\t\t=====================================================\n",NONE);
    
 
}


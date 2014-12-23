/***************************************************************
Function :       help
Description:     使用说明 
Calls :          none
Called by :      main
Input :          1.head
                 2.newnode
Return :         none
Others:          none
****************************************************************/

#include "../../include/my_head.h"

void help(Link *head,Link *newnode)
{
    system("reset");
    printf("\n\n\n");
    printf(BROWN"\n\t\t\tHOW TO USE :\n"NONE);
    printf(YELLOW"\n\t\t\tINSERT : insert a new linkman to the book ,the ID is the only ; \n");
    printf("\n\t\t\tSEARCH : search a linkman who has been inserted(according to name) ;\n");
    printf("\n\t\t\tDELETE : delete a linkman according to name , \
           \n\t\t\t        if the name is not only ,according to the ID ;\n");
    printf("\n\t\t\tRETURN : return to the menu ;\n");
    printf("\n\t\t\tEXIT   : exit the Linkman Book .\n"NONE);
    printf("\n");
    
}



/***************************************************************
Function :       add_information
Description:     添加联系人信息
Calls :          1.is_ID_exit   判断ID唯一
                 2.is_num       判断数字
Called by :      insert_linkman
Input :          1.head
                 2.newnode
Return :         SUCCESS
Others:          none
****************************************************************/

#include "../../include/my_head.h"

int add_information(sqlite3 * db,Link *head,Link *newnode)
{
    int i = 0;

    system("reset");                        //清屏
    printf("\n\n\n");

    /*输入ID*/

    printf(YELLOW"\t\t\tPlease input the ID : ");
    gets((*newnode)->ID);
    
    /*ID长度固定*/
    
    if(strlen((*newnode)->ID) < 10 )
    {
        for(i = strlen((*newnode)->ID); i < 9;i ++)
        {
            *((*newnode)->ID + i) = ' ';
        }
        *((*newnode)->ID + i) = '\0';
    }
    is_ID_exit(head,(*newnode)->ID);        //联系人ID唯一
    is_num((*newnode)->ID);                 //ID为数字
    printf("\n");


   /*输入姓名*/

    printf(YELLOW"\t\t\tPlease input the name : ");
    gets((*newnode)->name);
    
    /*姓名长度固定*/
    
    if(strlen((*newnode)->name) < 15 )
    {
        for(i = strlen((*newnode)->name); i < 14;i ++)
        {
            *((*newnode)->name + i) = ' ';
        }
        *((*newnode)->name + i) = '\0';
    }
    printf("\n");


    /*输入联系电话*/

    printf(YELLOW"\t\t\tPlease input the phone : ");
    gets((*newnode)->phone);
    is_num((*newnode)->phone);              //联系人电话为数字
    
    /*个人电话长度固定*/

    if(strlen((*newnode)->phone) < 15 )
    {
        for(i = strlen((*newnode)->phone); i < 14;i ++)
        {
            *((*newnode)->phone + i) = ' ';
        }
        *((*newnode)->phone + i) = '\0';
    }
    printf("\n");


    /*输入公司电话*/

    printf(YELLOW"\t\t\tPlease input the Co-telephone : ");
    gets((*newnode)->Cotel);
    is_num((*newnode)->Cotel);              //公司电话为数字
    
    /*公司电话长度固定*/

    if(strlen((*newnode)->Cotel) < 15 )
    {
        for(i = strlen((*newnode)->Cotel); i < 14;i ++)
        {
            *((*newnode)->Cotel + i) = ' ';
        }
        *((*newnode)->Cotel + i) = '\0';
    }
    printf("\n");


    /*输入住址*/

    printf(YELLOW"\t\t\tPlease input the address : ");
    gets((*newnode)->address);
    printf("\n"NONE);

    /*地址信息长度固定*/

    if(strlen((*newnode)->address) < 20 )
    {
        for(i = strlen((*newnode)->address); i < 19;i ++)
        {
            *((*newnode)->address + i) = ' ';
        }
        *((*newnode)->address + i) = '\0';
    }
    
    return SUCCESS;
}

/***************************************************************
Function :       insert_linkman
Description:     添加联系人 
Calls :          1.is_malloc_ok       判断空间申请结果
                 2.add_information    添加联系人信息
		 3.sort_linkman       所有联系人按姓名排序
		 4.choose_action      选择功能
Called by :      choose_action
Input :          1.head
                 2.newnode
Return :         SUCCESS
Others:          none
****************************************************************/

#include "../../include/my_head.h"

int insert_linkman(sqlite3 * db,Link *head, Link *newnode)
{
    char sql[MAX];
    int rc = 0;
    char * errmsg = NULL;

    *newnode = (Link)malloc(sizeof(Linkman));
    is_malloc_ok(newnode);

    (*newnode)->next = (*head)->next;
    (*head)->next->prior = *newnode;

    (*head)->next = *newnode;
    (*newnode)->prior = *head;
    add_information(db,head,newnode);       //输入新建联系人信息
   
    
    /*保存联系人信息至数据库*/

    sprintf(sql,"insert into test(id,name,phone,Co_tel,address)values('%s','%s','%s','%s','%s')",\
           (*newnode)->ID,(*newnode)->name,(*newnode)->phone,(*newnode)->Cotel,\
	   (*newnode)->address);
    rc = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    
    /*插入数据库失败*/

    if(rc != SQLITE_OK)
    {
        printf(RED"\n\t\t\tInsert into database failed \n");
    }

    sort_linkman(head);

    system("reset");
    printf("\n\n\n");
    printf(YELLOW"\t\t\tSAVED!\n"NONE);
    choose_action(db,head,newnode);
    
    return SUCCESS;
}

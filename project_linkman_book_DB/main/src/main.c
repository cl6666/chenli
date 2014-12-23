/**********************************************************************************
Copyright (C), 1998 ~ 2014 ,NJIT
Filename :          linkman_book
Author :            陈莉
Version :           1.0
Date :              08/08/2014
Description:        通讯录信息的录入，查找，删除，显示
Function list:      1.creat_head()       创建通讯录
                    2.print_interface()  主界面
		    3.choose_action()    功能选择
History :           none
***********************************************************************************/

#include "../../include/my_head.h"

int main()
{   
 
    int rc = 0;
    sqlite3 * db = NULL;
    char sql[MAX];
    char * errmsg[MAX];

    /*进入主界面*/

    system("reset");
    printf(YELLOW"\n\t\t\t\t  Welcome to use the Linkman Book ! ");

    print_interface();
    
    /*打开数据库*/

    rc = sqlite3_open("linkeman_book.db",&db);
    if(rc != SQLITE_OK)
    {
        printf(RED"\n\t\t\tOpen database failed !\n"NONE);
    }

    /*向数据库中插入表*/
    
    sprintf(sql,"create table test(id text primary key,name text,phone text,Co_tel text,\
    address text)");
    rc = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    
    /*该表名在数据库中已存在*/

    if(rc != SQLITE_OK)
    {
        printf(YELLOW"\n\t\t\tThe test has been in the database . \n"NONE);
    }
    
    Link head = NULL;
    creat_head(&head);

    Link newnode = NULL ;
    
    /*读取数据库中原有数据*/
    
    int i = 0;
    int pnrow = 0;
    int pncloumn = 0;
    char ** Result = NULL;
    sprintf(sql,"select * from test");

    sqlite3_get_table(db,sql,&Result,&pnrow,&pncloumn,&errmsg);
    
    for(i = 1; i <= pnrow ; i ++)
    {
        newnode = (Link)malloc(sizeof(Linkman));
	insert_old_linkman(db,Result,i,pncloumn,&head,&newnode);
    }
    
    sort_linkman(&head);
    choose_action(db,&head,&newnode);         

    return 0;
}

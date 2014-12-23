/***************************************************************
Function :       delete_linkman
Description:     删除联系人 
Calls :          1.display_search   显示被删除联系人
                 2.choose_action    选择功能
Called by :      choose_action
Input :          1.head
                 2.newnode
Return :         SUCCESS
Others:          none
****************************************************************/

#include "../../include/my_head.h"

int delete_linkman(sqlite3 * db,Link * head,Link * newnode)
{
    int result = 0;
    int i = 0;
    char del_name[10];
    char del_ID[10];
    char decision = '\0';
    char sql[MAX];
    int rc = 0;
    char * errmsg = NULL;

    Link temp = (*head)->next;

    system("reset");
    printf(WHITE"\n\n\n\n\t\t\tPlease enter the name you want to delete :");
    gets(del_name);
   
    if(strlen(del_name) < 15)
    {
        for(i = strlen(del_name); i < 14; i ++)
	{
	    *(del_name + i) = ' ';
	}
	*(del_name + i) = '\0';
    }
    printf("\n");
    
    /*按姓名查找被删除联系人*/

    result = display_search(head,del_name,newnode);

    /*被删除联系人不存在*/
    
    if(result == 0)
    {
        printf(RED"\n\t\t\tThe linkman doesn't exit !\n"NONE);
	choose_action(db,head,newnode);
	
	return SUCCESS;
    }

    if(result == 1)
    {
	while(temp != *head)
        {
	    if(str_com(temp->name,del_name) == 0)
            {
                printf(YELLOW"\n\t\t\tAre you sure to delete the linkman ?(Y/N)");
          	scanf("%c",&decision);                     //确认删除
		if(decision == 'Y' || decision == 'y')
		{
		    (temp->prior)->next = temp->next;
	            (temp->next)->prior = temp->prior;
		    
         	    free(temp);
		    temp = NULL;
                    
                    /*从数据库删除联系人信息*/

		    sprintf(sql,"delete from test where name = '%s'",del_name);
		    rc = sqlite3_exec(db,sql,0,0,&errmsg);
		    system("reset");
		    
                    /*删除数据库信息失败*/

		    if(rc != SQLITE_OK)
		    {
		        printf(RED"\n\t\t\tDelete from datebase failed !\n"NONE);
		    }

		    printf(YELLOW"\n\t\t\tREMOVE SUCCESS !\n"NONE);
		    choose_action(db,head,newnode);
		}
	        else
	        {
	            choose_action(db,head,newnode);
	            return SUCCESS;
	        }
	    }
	        temp = temp->next;
	}
	
    }

    /*该姓名联系人不唯一存在，按ID选择删除*/
    
    if(result > 1)
    {
        printf(WHITE"\n\t\t\tPlease enter the ID you want to delete : ");
        gets(del_ID);                                 //输入被删除联系人ID
	if(strlen(del_ID) < 10)
	{
	    for(i = strlen(del_ID) ; i < 9; i ++)
	    {
	        *(del_ID + i) = ' ';
	    }
	    *(del_ID + i) = '\0';
	}

	while(temp != *head)
        {
	    /*显示该联系人信息*/
	    if(str_com(temp->ID,del_ID) == 0)
	    {
	        printf(WHITE"\t\t\tID : %s\n"NONE,temp->ID);
	        printf(YELLOW"\t\t\tName : %13s\t\tPhone: %14s\  
	               \n\t\t\tAddress : %10s\t\tCo-tele : %11s\n\n"NONE,
	               temp->name,temp->phone,temp->address,temp->Cotel);
		
		printf(YELLOW"\n\t\t\tAre sure to delete the linkman ?(Y/N)");
		scanf("%c",&decision);                              //确认删除
	        getchar();
                
		if(decision == 'Y' || decision == 'y')
                {
		    (temp->prior)->next = temp->next;
		    (temp->next)->prior = temp->prior;

		    free(temp);
		    temp = NULL;

		    /*删除数据库该联系人信息*/

		    sprintf(sql,"delete from test where id = '%s'",del_ID);
		    rc = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
		    
		    system("reset");
		    
                    /*数据库信息删除失败*/

		    if(rc != SQLITE_OK)
		    {
		        printf(RED"\n\t\t\tDelete from database failed !\n"NONE);
	            }

		    printf(YELLOW"\n\t\t\tREMOVE SUCCESS !\n"NONE);
                    
		    choose_action(db,head,newnode);
                    return SUCCESS;
	        }
		else
		{
		    choose_action(db,head,newnode);
		    return SUCCESS;
		}
            }
	    temp = temp->next;
        }

	printf(RED"\n\t\t\tThe linkman you want doesn't exit !\n"NONE);
	choose_action(db,head,newnode);

	return SUCCESS;
    }
    return SUCCESS;
}

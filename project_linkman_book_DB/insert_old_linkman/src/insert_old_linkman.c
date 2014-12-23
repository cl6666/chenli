/**********************************************************************************
Function :          insert_old_linkman
Calls :             read_file
Calls by :          main
Description:        读取文件linkman中原有联系人
Input :             1.fd
                    2.head
		    3.newnode
Return :            none
Others :            none
***********************************************************************************/

#include "../../include/my_head.h"

void insert_old_linkman(sqlite3 *db,char **Result,int pnrow,int pncloumn,Link * head,Link *newnode)
{
    /*向链表插入结点*/

    *newnode = (Link)malloc(sizeof(Linkman));
    is_malloc_ok(newnode);

    (*newnode)->next = (*head)->next;
    ((*head)->next)->prior = *newnode;

    (*head)->next = *newnode;
    (*newnode)->prior = *head;
    
    /*读入原有联系人信息*/

    strcpy((*newnode)->ID,Result[pnrow * pncloumn + 0]);
    strcpy((*newnode)->name,Result[pnrow * pncloumn + 1]);
    strcpy((*newnode)->phone,Result[pnrow * pncloumn + 2]);
    strcpy((*newnode)->Cotel,Result[pnrow * pncloumn + 3]);
    strcpy((*newnode)->address,Result[pnrow * pncloumn + 4]);
}

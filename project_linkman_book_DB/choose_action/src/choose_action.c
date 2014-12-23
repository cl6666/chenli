/******************************************************************************************
Function :       choose_action
Description:     选择功能
Calls :          1.insert_linkman      添加联系人
                 2.search_linkman      查找联系人
		 3.delete_linkman      删除联系人
		 4.display_linkman     显示联系人
		 5.return              返回主界面
		 6.exit                退出程序
Input :          1.head
                 2.newnode
Return :         none
Others:          none
*******************************************************************************************/

#include "../../include/my_head.h"

void choose_action(sqlite3 *db,Link *head,Link *newnode)
{
    char choose[10];
    int result = 0;
    
    printf(PURPLE"\n\t\t\tFUNCTION  LIST:\n"NONE);
    printf(PURPLE"\n\t\t\t*INSERT  *DELETE  *SEARCH  *DISPLAY  *RETURN  *HELP \
                  \n\t\t\t*EXIT\n\n"NONE);
    printf(WHITE"\n\t\t\tPlease choose the function : ");
    scanf("%s",choose); 
    getchar();
    printf("\n");

    result = choose2int(choose);
    switch (result)
    {
        case INSERT:
            {
	        insert_linkman(db,head,newnode);
	        break;
            }
        case DELETE:
            {
	        delete_linkman(db,head,newnode);
	        break;
	    }
        case SEARCH:
            {
	        search_linkman(head,newnode);
		choose_action(db,head,newnode);
	        break;
	    }   
        case DISPLAY:
            {
		display_linkman(head,newnode);
		choose_action(db,head,newnode);
	        break;
	    }
        case RETURN:
            {
	     	print_interface();
		choose_action(db,head,newnode);
		break;
	    }  
	case HELP:
	    {
	        help(head,newnode);
		choose_action(db,head,newnode);
		break;
	    }
        case EXIT:
	    {
	        sqlite3_close(db);
		system("reset");
		printf("\n\n\n");
		printf(YELLOW"\n\t\t\t    ＴＨＡＮＫ ＹＯＵ ＦＯＲ ＹＯＵ ＭＡＫＩＮＧ\n");
		sleep(1);
		system("reset");

		exit(SUCCESS);
	    }
	default:
            {
	        printf(RED"\n\t\t\tPlease choose the right function!\n"NONE);
		choose_action(db,head,newnode);
		break;
	    }
    }
}

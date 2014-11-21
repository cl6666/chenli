/*************************************************
  Function:       ins_wait
  Description:    insert a car to wait queue
  Calls:          my_strcpy
  Called By:      main
  Input:          head: the head pointer of stoping stack
                  rear: the rear pointer of stoping stack
  Output:         
  Return:         SUCCESS: insert success
*************************************************/
#include "../../include/my_typedef.h"

int ins_wait(str_wait **head, str_wait **rear, char * car_num)
{
    str_wait * temp;
    str_wait * newcar;

    newcar = (str_wait *)malloc(sizeof(str_wait));              //add a new node to wait queue
    newcar->next = NULL;

    if(NULL == newcar)                                          //if malloc is success
    {
        printf("malloc error!\n");
    }
    my_strcpy(newcar->num,car_num);

    if((NULL == *head)&&(NULL == *rear))                        //insert the first node
    {
		
        *rear = newcar;
        *head = newcar;


        return SUCCESS;
    }

    temp = *rear;                                               //insert new node
    temp->next = newcar;
    *rear = newcar;
}

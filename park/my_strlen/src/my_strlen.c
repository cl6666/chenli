/*************************************************
  Function:       my_strlen
  Description:    measure the length of waiting queue 
  Calls:          no
  Called By:      main
  Input:          head: the head pointer of stoping stack
                  rear: the rear pointer of stoping stack
  Output:         no
  Return:         the length of waiting queue
*************************************************/
#include "../../include/my_typedef.h"

int my_strlen(str_wait * head, str_wait * rear)
{
	int len = 1;                                      //the length of waiting queue
	str_wait * temp;

	if((NULL == head)&&(NULL == rear))
	{
		return 0;
	}
	else if((head == rear)&&(NULL != head))
	{
		return 1;
	}
	temp = head;

	while(temp != rear)                               //traverse waiting queue
	{
		len++;
		temp = temp->next;
	}
	
	return len;
}
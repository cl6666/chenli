/*************************************************
  Function:       init_wait
  Description:    initialize wait queue
  Calls:          no
  Called By:      main
  Input:          &head: the address of stoping stack head pointer
                  &rear: the address of stoping stack rear pointer
  Output:         no
  Return:         no
*************************************************/
#include "../../include/my_typedef.h"

void init_wait(str_wait ** head, str_wait ** rear)
{
    *head = NULL;
    *rear = NULL;
}

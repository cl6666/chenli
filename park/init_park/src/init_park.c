/*************************************************
  Function:       init_park
  Description:    initialize park stack
  Calls:          no
  Called By:      main
  Input:          park:    the head pointer of parking stack
  Output:         no
  Return:         no
*************************************************/
#include "../../include/my_typedef.h"

void init_park(str_park * park)
{
    park->top = -1;
}

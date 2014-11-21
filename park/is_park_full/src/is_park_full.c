/*************************************************
  Function:       is_park_full
  Description:    detection if the parking stack is full
  Calls:          no
  Called By:      car_park
  Input:          park:      the head pointer of parking stack
  Output:         no
  Return:         PARK_FULL: the parking stack if full
*************************************************/
#include "../../include/my_typedef.h"

int is_park_full(str_park * park)
{
    if(PARK_SIZE - 1 == park->top)                    //if the parking stack is full
    {
        return PARK_FULL;
    }
}

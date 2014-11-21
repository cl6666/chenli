/*************************************************
  Function:       init_park
  Description:    insert a car to park stack
  Calls:          my_strcpy
  Called By:      main
  Input:          park:    the head pointer of parking stack
  Output:         no
  Return:         PARK_SUCCESS: park success
                  PARK_FULL;    park is full
*************************************************/
#include "../../include/my_typedef.h"


int car_park(str_park *park,  char *car_num)
{
    if(PARK_FULL != is_park_full(park))                         //if the parking is full
    {
        park->top++;                                            //insert a car to park stack
        my_strcpy(park->car[park->top].num, car_num);
        time(&park->car[park->top].time_in);
        return PARK_SUCCESS;
    }

    
    return PARK_FULL;
}

/*************************************************
  Function:       my_strcpy
  Description:    copy str_source to str_mid
  Calls:          no
  Called By:      ins_wait;
                  car_park;
				  main;
  Input:          str_mid:    copy mid
                  str_source: copy source
  Output:         no
  Return:         CP_SUCCESS: copy success
*************************************************/
#include "../../include/my_typedef.h"

int my_strcpy(char *str_mid, char *str_source)
{
    while('\0' != *str_source)                        //traverse source string
    {
        *str_mid = *str_source;

        str_mid++;
        str_source++;

    }
    *str_mid = '\0';                                  //add end mark

    return CP_SUCCESS;
}

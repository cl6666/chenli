/*************************************************
  Function:       my_strcmp
  Description:    compare if str1 and str2 are the same
  Calls:          no
  Called By:      main
  Input:          str1,str2 :the strings to compare
  Output:         no
  Return:         0: strings are same
                  1: strings are not same
*************************************************/
#include "../../include/my_typedef.h"

int my_strcmp(char *str1,char *str2)
{
    int i;
    int len;
    int len1;
    int len2;

    len1 = strlen(str1);
    len2 = strlen(str2);

    len = (len1 > len2)?len1:len2;                              //Taking the maximum length

    if(len1 != len2)                                            //The string is not the same length
    {
        return 0;
    }

    for(i = 0; i < len; i++)
    {
        if((str1[i] != str2[i]) &&(str1[i] - 32 != str2[i]))    //Different character
        {
            return 0;
        }
    }

    return 1;
}

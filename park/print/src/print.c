/*************************************************
  Function:       print
  Description:    Output parking information
  Calls:          no
  Called By:      main
  Input:          park: the head pointer of stoping stack
                  len:  the length of waiting queue
  Output:         parking information
  Return:         no
*************************************************/
#include "../../include/my_typedef.h"

void print(str_park * park, int len)
{
    int i = 0;
    time_t timenow;

    printf("\t\t%d cars in the park\n",park->top + 1);
    printf("\t     car num\tElapsed time\t\t\n");
    printf("\t -------------------------------\n");
    
    for(i = 0; i < 10; i++)                                          //output the figure of park
    {
        if(i <= park->top)                       			         //output the information of park 
        {
            time(&timenow);
            printf("\t|\t%s\t%5.2f\t\t|\n",park->car[i].num, difftime(timenow, park->car[i].time_in));
        }
        else
        {
            printf("\t|\t\t\t\t|\n");
        }
    }

    printf("\n\nThere are %d cars waiting\n", len);
}

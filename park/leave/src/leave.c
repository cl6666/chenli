/*************************************************
  Function:       leave
  Description:    Take a car from the parking stack
  Calls:          init_park:
  Called By:      main
  Input:          park:    the head pointer of parking stack 
                  giveway: the head pointer of parking stack
  Output:         car information
  Return:         FAIL:    can't find the appoint car
*************************************************/
#include "../../include/my_typedef.h"

int leave(str_park * park, str_park * giveway)
{
    int i = 0;
    float temp_time;
    char car_num[20];
    time_t timenow;
    str_park * temp;

    temp = park;

    printf("Please input your car number:\n");
    scanf("%s",car_num);

    init_park(giveway);
	

    for(i = temp->top; i >= 0; i--)                             //traverse parking stack
    {
        if(0 == my_strcmp(temp->car[i].num, car_num))           //look for appoint car
        {
            if(0 == i)
            {
                return FAIL;                                    //can`t find appoint car
            }
			
            giveway->top++;
            giveway->car[giveway->top] = temp->car[i];          //push in waiting stack

        }
        else
        {
            break;
        }
    }


    time(&timenow);
    printf("Thank you for using our parking\n");
    printf("License plate number:    %s\n",temp->car[i].num);
    printf("parking time:            %s",ctime(&(temp->car[i].time_in)));
    printf("leave time:              %s",ctime(&timenow));
    printf("Residence time:         %5.2f\n", temp_time = difftime(timenow, temp->car[i].time_in));
    printf("charge:                 %5.2f", temp_time/600);

    for(; giveway->top > -1; i++,giveway->top--)
    {
        temp->car[i] = giveway->car[giveway->top];              //return parking stack
    }

    park->top--;

}

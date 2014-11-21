#include "../../include/my_typedef.h"

int main()
{
    int temp;
    int len;
    char car_num[20];
    char order[10];
    str_park * park;                                            //parking stack head pointer
    str_park * giveway;                                         //giveway stack head pointer
    str_wait * head = NULL;                                     //wait queue head pointer
    str_wait * rear = NULL;                                     //wait queue rear pointer
    str_wait * temp_wait = NULL;

    park = (str_park *)malloc(sizeof(str_park));
    if(NULL == park)
    {
	    printf("malloc error!");
	    exit(FULL);
    }

    giveway = (str_park *)malloc(sizeof(str_park));
    if(NULL == giveway)
    {
	    printf("malloc error!");
	    exit(FULL);
    }

    init_park(park);                                            //initialize park stack
    init_park(giveway);                                         //initialize park stack

    while(1)
    {
        system("reset");                                        //Clear the screen
        surface();                                              //welcome page

        scanf("%s",order);

        if(0 != my_strcmp(order, "PARK"))                       //parking function
        {
            system("reset");
            printf("Please input your car num:\n");
            scanf("%s", car_num);

            temp = car_park(park, car_num);

            if(PARK_FULL != temp)                               //if park is full
            {
                printf("\nparking success!\n");
            }
            else
            {
                len = my_strlen(head,rear);
                printf("\nWaiting queue have % d car, whether to wait?(Y/N)\n",len);
                scanf("%s",order);
                if(0 != my_strcmp(order,"Y"))
                {
                    ins_wait(&head, &rear, car_num);            //insert to wait queue
                    printf("\nentered a waiting queue success!\n");
                }
                else
                {
                    continue;
                }
            }
			
            printf("\n\nPlease input anything to return homepage\n");
            scanf("%s",order);
            continue;
        }
        else if(0 != my_strcmp(order, "DISPLAY"))               //display function
        {
            system("reset");

            len = my_strlen(head,rear);
            print(park,len);

            printf("\n\nPlease input anything to return homepage\n");
            scanf("%s",order);
            continue;
        }
        else if(0 != my_strcmp(order, "GETCAR"))                //leave function
        {
            system("reset");

            len = my_strlen(head,rear);
            print(park,len);                                    //input the information of park

            temp = leave(park, giveway);

	    if(FAIL == temp)
	    {
	        printf("\ncan't find appoint car!please check your input\n");
                printf("\n\nPlease input anything to return homepage\n");
                scanf("%s",order);
		continue;
	    }

            if(0 != len)                                        //if wait queue is not empty, get a car form wati queue
            {
                temp_wait = head;

                my_strcpy(car_num, temp_wait->num);
                head = head->next;
                free(temp_wait);

                car_park(park,car_num);
				
                if(1 == len)
                {
                    init_wait(&head, &rear);
                }
            }

            printf("\n\nPlease input anything to return homepage\n");
            scanf("%s",order);
            continue;
        }
        else if(0 != my_strcmp(order, "QUIT"))                  //quit function
        {
            system("reset");
            exit(1);
        }
        else
        {
            system("reset");
            printf("input error!Please input anything to return homepage\n");
            scanf("%s",order);
            continue;
        }
    }

    return 0;
}

#include <stdio.h>
#include <time.h>

#define PARK_SIZE 10

enum park_return
{
    SUCCESS,FAIL,FULL,
    PARK_SUCCESS,PARK_FAIL,PARK_FULL,
    CP_FAIL,CP_SUCCESS
};

struct car
{
    char num[20];
    time_t time_in;
};
typedef struct car str_car;

struct park_gallery
{
    struct car car[PARK_SIZE];
    int top;
};
typedef struct park_gallery str_park;

struct wait_gallery
{
    char num[20];
    struct wait_gallery *next;
};
typedef struct wait_gallery str_wait;


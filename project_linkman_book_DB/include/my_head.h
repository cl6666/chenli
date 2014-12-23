#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

struct linkman
{
    char ID[10];
    char name[15];
    char phone[15];
    char Cotel[15];
    char address[20];

    struct linkman * next;
    struct linkman *prior;
};

typedef struct linkman Linkman;
typedef struct linkman * Link;

#define MAX 200

enum FUN
{
    INSERT ,
    DELETE ,
    SEARCH ,
    DISPLAY ,
    RETURN ,
    HELP ,
    EXIT
};



#define SUCCESS 0
#define NO_SUCCESS 1
#define NO_FIND -1
#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"

void is_malloc_ok(Link *node);
void is_ID_exit(Link *head,char *ID);
void creat_head(Link *head);
void search_linkman(Link *head,Link *newnode);
void choose_action(sqlite3 *db,Link *head,Link *newnode);
void display_linkman(Link *head,Link *newnode);
void print_interface();
void help(Link *head,Link *newnode);
void insert_old_linkman(sqlite3 *db,char **Result,int pnrow,int pncloumn,Link *head,Link *newnode);

int display_search(Link *head,char *name,Link *newnode);
int delete_linkman(sqlite3 *db,Link *head,Link *newnode);
int choose2int(char *src);
int is_num(char *src);
int add_information(sqlite3 *db,Link *head,Link *newnode);
int insert_linkman(sqlite3 *db,Link *head,Link *newnode);
int sort_linkman(Link *head);
int str_com(char *str,char *src);




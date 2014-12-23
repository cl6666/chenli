/***************************************************************
Function :       choose2int
Description:     转换被选择功能为数字 
Calls :          none
Called by :      choose_action
Input :          1.src        被选择功能
Return :         INSERT / DELETE / SEARCH / DISPLAY /RETURN /
                 EXIT / NO_FIND
Others:          none
****************************************************************/
 
#include "../../include/my_head.h"

int choose2int(char *src)
{
    if(str_com(src,"INSERT") == 0)
    {
        return INSERT;
    }
    
    if(str_com(src,"DELETE") == 0)
    {
        return DELETE;
    }
    
    if(str_com(src,"SEARCH") == 0)
    {
        return SEARCH;
    }
    
    if(str_com(src,"DISPLAY") == 0)
    {
        return DISPLAY;
    }
    
    if(str_com(src,"RETURN") == 0)
    {
        return RETURN;
    }
      
    if(str_com(src,"HELP") == 0)
    {
        return HELP;
    }

    if(str_com(src,"EXIT") == 0)
    {
        return EXIT;
    }

    return NO_FIND;
}

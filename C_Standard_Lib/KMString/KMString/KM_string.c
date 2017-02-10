//
//  KMString.c
//  KMString
//
//  Created by 周祺华 on 2017/2/10.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include "KM_string.h"

char * KM_strcpy(char *dest, char *src)
{
    char *ret = dest;
    while ((*dest++ = *src++))
        ;
    
    return ret;
}

int KM_strcmp(char *dest, char *src)
{
    for ( ; *dest == *src; dest++, src++)
        if (*dest == '\0')
            return 0; // two same strings
    
    return *dest - *src; // calculate diff
}

char * KM_strcat(char *dest, char *src)
{
    char *ret = dest;
    
    while (*dest) // move to the end of dest
        dest++;
    
    while ((*dest++ = *src++)) // strcpy
        ;
    
    return ret;
}

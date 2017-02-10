//
//  main.c
//  KMString
//
//  Created by 周祺华 on 2017/2/10.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>
#include "KM_string.h"

int main(int argc, const char * argv[]) {
    
    char s[20] = "hello ";
    char *t = "world";
    char u[20] = "???";
    
    printf("s:\"%s\", t:\"%s\", u:\"%s\"\n", s, t, u);
    
    printf("KM_strcpy u from t: \"%s\"\n", KM_strcpy(u, t));
    
    printf("KM_strcmp u and  t: %d\n", KM_strcmp(t, u));

    printf("KM_strcat s with t: \"%s\"\n", KM_strcat(s, t));
    
    return 0;
}

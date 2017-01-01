//
//  main.c
//  Asm_C_Hybird
//
//  Created by 周祺华 on 2017/1/1.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x;
    char *mesg = "hello world!";
    int *p;
    asm
    {
        mov dword ptr [x],233
        lea eax,[mesg];
        mov dword ptr [p],eax
    }
    
    printf("x=%d\n",x);
    printf("*p=%s\n",*p);
    getchar();
    return 0;
}

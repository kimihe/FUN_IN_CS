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
    
    // In Windows' IDE, such as Microsoft Visual Studio, you may need to use "_ams" instead.
    asm
    {
        mov dword ptr [x],233
        lea eax,[mesg];
        mov dword ptr [p],eax
    }
    
    printf("x=%d\n",x);
    printf("*p=%s\n",*p);// This line may cause a crash.
    getchar();
    return 0;
}

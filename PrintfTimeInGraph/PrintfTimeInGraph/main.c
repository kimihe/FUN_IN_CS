//
//  main.c
//  PrintfTimeInGraph
//
//  Created by 周祺华 on 2017/1/1.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>
void show_time();
int main()
{
    printf(" Now showing current time of your system~\n");
    do {
        show_time();
        printf("press any key to continue...(q to quit)\n");
    }while(getchar() != 'q');
    return 0;
}

void show_time()
{
    int i;
    for(i=447; i>=0; i--)
    {
        if(i % 64 == 0)
        {
            putchar('\n');
        }
        else
        {
            char t = __TIME__[7 - i/8%8];
            char a = ">'txiZ^(~z?"[t - 48] + 1;
            int shift = ";;;====~$::199"[(i*2&8) | (i/64)];
            if((i & 2) == 0)
                shift /= 8;
            shift = shift % 8;
            char b = a >> shift;
            putchar(32 | (b & 1));
        }
    }
}

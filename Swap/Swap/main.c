//
//  main.c
//  Swap
//
//  Created by 周祺华 on 2017/1/6.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>

void swapInteger(int *x, int *y) {
    // 指向同一个地址就不要异或，否则永远为0
    if (*x == *y) {
        return;
    }
    
    // Trick
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main(int argc, const char * argv[]) {
    
    int x = 2;
    int y = 3;
    
    int a = 233;
    int b = 233;
    
    int c = 23333;
    
    swapInteger(&x, &y);
    printf("x=%d, y=%d\n", x, y);
    
    swapInteger(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    
    swapInteger(&c, &c);
    printf("c=%d\n", c);
    
    return 0;
}

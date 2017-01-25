//
//  main.c
//  CountBitOne
//
//  Created by 周祺华 on 2017/1/25.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>


/**
 normal way

 @param x binary number
 @return count of bit one
 */
int bitcount1(int32_t x)
{
    int count;
    for (count = 0; x != 0; x >>= 1) {
        if (x & 0x01) {
            count++;
        }
    }
    return count;
}


/**
 more effective

 @param x binary number
 @return count of bit one
 */
int bitcount2(int32_t x)
{
    int count;
    for (count = 0; x != 0; x &= (x-1)) {
        count ++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    const int32_t x = (1<<11)-1;

    printf("bit count1: %d\n", bitcount1(x));
    
    printf("bit count2: %d\n", bitcount2(x));
    
    return 0;
}


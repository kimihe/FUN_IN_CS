//
//  main.c
//  NumberExpression
//
//  Created by 周祺华 on 2017/1/8.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>


/**
 判断两个无符号数uint32_t相加，是否会溢出

 @param x 数字1
 @param y 数字2
 @return 无溢出时返回1，否则返回0
 */
uint32_t uadd_ok(uint32_t x, uint32_t y) {
    uint32_t sum = x+y;
    return sum >= x;
}


/**
 判断两个有符号数int32_t(补码)相加，是否会溢出
 
 @param x 数字1
 @param y 数字2
 @return 无溢出时返回1，否则返回0
 */
int32_t tadd_ok(int32_t x, int32_t y) {
    int32_t sum = x+y;
    int32_t neg_over = x < 0 && y < 0 && sum >= 0;
    int32_t pos_over = x >= 0&& y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}


/**
 二进制表示：产生若干0开头，length个1结尾的掩码

 @param length 1的个数
 @return 掩码
 */
int64_t generateMask(int64_t length) {
    return (1<<length)-1;
}


int main(int argc, const char * argv[]) {

    printf("UINT32_MAX: %u\n", UINT32_MAX);
    
    int res = uadd_ok(1, 1);
    printf("res: %u\n", res);
    res = uadd_ok(65536*65536-1, 0);
    printf("res: %u\n", res);
    res = uadd_ok(65536*65536-1, 1);
    printf("res: %u\n\n\n", res);
    
    
    

    
    printf("INT32_MAX: %d\n", INT32_MAX);
    printf("INT32_MIN: %d\n", INT32_MIN);
    
    res = tadd_ok((1<<31)-1, 0);// Do not use 65536*65536-1, but U can use 2147483647
    printf("res: %d\n", res);
    res = tadd_ok((1<<31)-1, 1);
    printf("res: %d\n", res);
    res = tadd_ok(-(1<<31), 0);
    printf("res: %d\n", res);
    res = tadd_ok(-(1<<31), -1);
    printf("res: %d\n", res);
    
    return 0;
}



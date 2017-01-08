//
//  main.c
//  NumberExpression
//
//  Created by 周祺华 on 2017/1/8.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>


/**
 判断两个无符号数相加，是否会溢出

 @param x 数字1
 @param y 数字2
 @return 无溢出时返回1
 */
int unsignedAdd_ok(unsigned x, unsigned y) {
    unsigned sum = x+y;
    return sum >= x;
}


/**
 判断两个有符号数(补码)相加，是否会溢出
 
 @param x 数字1
 @param y 数字2
 @return 无溢出时返回1
 */
int tadd_ok(int x, int y) {
    int sum = x+y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0&& y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}


/**
 二进制表示：产生若干0开头，length个1结尾的掩码

 @param length 1的个数
 @return 掩码
 */
int64_t generateMask(int length) {
    return (1<<length)-1;
}


int main(int argc, const char * argv[]) {

    int res = unsignedAdd_ok(1, 1);
    printf("res: %d\n", res);
    res = unsignedAdd_ok(65536*65536-1, 0);
    printf("res: %d\n", res);
    res = unsignedAdd_ok(65536*65536-1, 1);
    printf("res: %d\n", res);
    
    
//    res = tadd_ok(65536/2-1, 0);
//    printf("res: %d\n", res);
//    res = tadd_ok(65536/2-1, 1);
//    printf("res: %d\n", res);
//    res = tadd_ok(-65536/2, 0);
//    printf("res: %d\n", res);
//    res = tadd_ok(-65536/2, -1);
//    printf("res: %d\n", res);
    
    
    return 0;
}

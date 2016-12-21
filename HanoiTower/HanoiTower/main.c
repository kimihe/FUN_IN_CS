//
//  main.c
//  HanoiTower
//
//  Created by 周祺华 on 2016/12/20.
//  Copyright © 2016年 周祺华. All rights reserved.
//

#include <stdio.h>

/* ignore!
// 汉诺塔编号：ABC三个柱子
typedef enum _ColumnType{
    A = 65,
    B,
    C
}ColumnType;

// 某一根柱子的编号信息
typedef struct _char {
    ColumnType type;
}char;
 */



long long step = 1;
int diskNumber = 0;

/**
 递归解决底盘上方n-1个小圆盘的移动

 @param n 连带底盘一共要解决n个圆盘叠加的汉诺塔问题
 @param from 一堆圆盘移动前的起始柱子
 @param to 目标柱子
 @param tmp 中间临时暂存上方n-1个圆盘的柱子
 */
void hanoi(unsigned int n, char from, char to, char tmp);

/**
 移动底盘，同时我们最关键的就是在移动底盘的过程中打印出每一步的移动详情

 @param n 底盘的编号(从上到下汉诺塔圆盘的编号为: 1, 2, 3, ..., n)
 */
void moveBottom(unsigned int n, char from, char to);


int main(int argc, const char * argv[]) {
    // insert code here...
    
    printf("请输入圆盘个数:\n");
    while (scanf("%d",&diskNumber) != EOF) {

        if (diskNumber < 0) {
            break;
        }
        
        if (diskNumber > 16) {
            printf("数字太大!");
            break;
        }
        
        hanoi(diskNumber, 'A', 'C', 'B');
        printf("请输入圆盘个数:\n");
        step = 1;
    }
    
    return 0;
}

void hanoi(unsigned int n, char from, char to, char tmp) {
    if (n == 0) {
        return;
    }
    
    if (n == 1) {
        moveBottom(n, from, to);
        return;
    }
    
    hanoi(n-1, from, tmp, to);
    moveBottom(n, from, to);
    hanoi(n-1, tmp, to, from);
}

void moveBottom(unsigned int n, char from, char to){
    printf("Step%lld: Move %d from %c to %c.\n", step, n, from, to);
    
    step++;
}


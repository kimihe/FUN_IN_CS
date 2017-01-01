//
//  main.c
//  FigureGenerator
//
//  Created by 周祺华 on 2017/1/1.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>

#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x)) // square
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) // cube root
unsigned char GR(int,int);
unsigned char BL(int,int);
void pixel_write(int,int);
FILE *fp;

//i,j范围是0-1023，三原色根据不同i,j返回一个unsigned char，其值为0-255之间。
//祝玩的愉快
unsigned char RD(int i,int j)
{
#define r(n)(rand()%n)
    static char c[1024][1024];
    return!c[i][j]?c[i][j]=!r(999)?r(256):RD((i+r(2))%1024,(j+r(2))%1024):c[i][j];
}// YOUR CODE HERE
unsigned char GR(int i,int j)
{
    static char c[1024][1024];
    return!c[i][j]?c[i][j]=!r(999)?r(256):GR((i+r(2))%1024,(j+r(2))%1024):c[i][j];
}// YOUR CODE HERE
unsigned char BL(int i,int j)
{
    static char c[1024][1024];
    return!c[i][j]?c[i][j]=!r(999)?r(256):BL((i+r(2))%1024,(j+r(2))%1024):c[i][j];
}// YOUR CODE HERE


int main()
{
    fp = fopen("MathPic.ppm","wb");
    fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
    for(int j=0;j<DIM;j++)
        for(int i=0;i<DIM;i++)
            pixel_write(i,j);
    fclose(fp);
    return 0;
}
void pixel_write(int i, int j)
{
    static unsigned char color[3];
    color[0] = RD(i,j)&255;
    color[1] = GR(i,j)&255;
    color[2] = BL(i,j)&255;
    fwrite(color, 1, 3, fp); 
}

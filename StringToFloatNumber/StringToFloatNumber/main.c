//
//  main.c
//  StringToFloatNumber
//
//  Created by 周祺华 on 2017/2/5.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

double floatValue(char s[])
{
    double val, power;
    int exp, i, sign;
    
    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    
    sign = (s[i] == '-')? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == '.')
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    val = sign * val / power;
    
    if (s[i] == 'e' || s[i] == 'E') { // also deal with format: 31415e-4 and 0.031415E2
        
        sign = (s[++i] == '-')? -1 : 1; // notice use s[++i] instead of s[i++], actually it's equal to: i++; s[i]...
        if (s[i] == '-' || s[i] == '+')
            i++;
        
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        
        if (sign == 1)
            while (exp--) { // positive exponent
                val *= 10;
            }
        else
            while (exp--) { // negative exponent
                val /= 10;
            }
    }
    
    return val;
}

int main(int argc, const char * argv[]) {
    
    char f1[] = "-233.333\0";
    char f2[] = "+0.233\0";
    char f3[] = "+1.234567e5\0";
    char f4[] = "-12345E-5\0";
    
    printf("Float value of string \"%s\" is: %f\n", f1, floatValue(f1));
    printf("Float value of string \"%s\" is: %f\n", f2, floatValue(f2));
    printf("Float value of string \"%s\" is: %f\n", f3, floatValue(f3));
    printf("Float value of string \"%s\" is: %f\n", f4, floatValue(f4));
    return 0;
}

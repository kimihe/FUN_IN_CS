//
//  main.c
//  StrToNum_NumToStr
//
//  Created by 周祺华 on 2017/1/29.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// take "int" as an example
int integerValue(char s[]) {
    
    int i = 0;
    int n = 0;
    
    for (i = 0; isspace(s[i]); i++) {
        ; // escape blanks
    }
    
    int sign = (s[i] == '-')? -1 : 1; // '-': nagetive; '+' and else: positive;
    
    if (s[i] == '+' || s[i] == '-') { // escape sign
        i++;
    }
    
    for (n = 0; isdigit(s[i]); i++) { // stop while s[i] is not a digit
        n = 10*n + (s[i] - '0');
    }
    
    return sign*n;
}


// reverse a char array
void reverse(char s[]) {
    
    for (long i = 0, j = strlen(s)-1; i < j; i++, j--) {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void stringWithInteger(int n, char s[]) {
    
    int sign = n;
    int i = 0;
    
    do {
        s[i++] = abs(n%10) + '0';
    } while ((n /= 10) != 0);
    
    if (sign < 0) {
        s[i++] = '-';
    }
    
    s[i++] = '\0';
    reverse(s); // reverse this char string
}

int main(int argc, const char * argv[]) {
    
    const int num = -(1<<31);
    char s[129];
    
    stringWithInteger(num, s);
    printf("String with integer %d is: (string)\"%s\"\n", num, s);
    
    printf("Integer value of string \"%s\" is: (integer)%d\n", s, integerValue(s));
    
    return 0;
}

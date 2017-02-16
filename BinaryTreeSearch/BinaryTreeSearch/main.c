//
//  main.c
//  BinaryTreeSearch
//
//  Created by 周祺华 on 2017/2/16.
//  Copyright © 2017年 周祺华. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define USE_DEBUG 1


typedef struct tnode *TreePtr;

typedef struct tnode {
    int number;
    long count;
    TreePtr left;
    TreePtr right;
} TreeNode;

TreePtr talloc()
{
    return (TreePtr)malloc(sizeof(TreeNode));
}

TreePtr addTree(TreePtr p, int number)
{
    if (p == NULL) {
        p = talloc();
        p->number = number;
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if (number == p->number)
        p->count++;
    else if (number < p->number)
        p->left = addTree(p->left, number);
    else
        p->right = addTree(p->right, number);
    
    return p;
}

void treePrint(TreePtr p)
{
    if (p) {
        treePrint(p->left);
        printf("Number: %4d, Count: %4ld\n", p->number, p->count);
        treePrint(p->right);
    }
}

int getNumber()
{
#if USE_DEBUG
    static int i = 0;
    return i;
#endif

    
    int c;
    char buf[20];
    char *w = buf;
    
    while (isspace(c = getchar()))
        ;
    
    while ((c = getchar()) != EOF) {
        if (isdigit(c))
            *w = c;
        else {
            *w = '\0';
            return atoi(buf);
        }
        w++;
    }
    
    *w = '\0';
    return atoi(buf);
}


int main(int argc, const char * argv[]) {
    
#if USE_DEBUG
    TreePtr root = NULL;
    int number = 0;
    while (number < 11) {
        root = addTree(root, number);
        number++;
    }
    
    number = 5;
    while (number < 11) {
        root = addTree(root, number);
        number++;
    }
    
    number = 9;
    while (number < 11) {
        root = addTree(root, number);
        number++;
    }
    
    treePrint(root);
    
#else
    
    TreePtr root = NULL;
    int number;
    while ((number = getNumber()) < 11)
        root = addTree(root, number);
    treePrint(root);
    
#endif
    return 0;
}

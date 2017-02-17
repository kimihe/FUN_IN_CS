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

#define USE_DEBUG 0


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

int main(int argc, const char * argv[]) {
    
    TreePtr root = NULL;
    int number;
    int res;
    
    printf("Please input integer numbers.\n"
           "Any non-numeric chars will end inputing.\n\n: ");
    while( (res = scanf("%d", &number)) != EOF) {
        
#if USE_DEBUG
        printf("this: %d\n", number);
#endif
        
        if (res != 1)
            break;
        
        root = addTree(root, number);
    }
#if USE_DEBUG
    printf("end\n");
#endif
    
    treePrint(root);
    return 0;
}

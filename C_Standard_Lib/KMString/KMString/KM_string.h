//
//  KMString.h
//  KMString
//
//  Created by 周祺华 on 2017/2/10.
//  Copyright © 2017年 周祺华. All rights reserved.
//




/*
 Practice in C string functions
 Usage is same as <String.h>
*/


#ifndef KMString_h
#define KMString_h


/**
 For KM_strcpy: dest need to have enough sapce to store src

 @param dest destination
 @param src source
 @return destination
 */
char * KM_strcpy(char *dest, char *src);

/**
 For KM_strcmp:compare two strings
 
 @param dest destination
 @param src source
 @return return 0 if two strings are same, otherwise return diff between two chars mismatched the first time
 */
int KM_strcmp(char *dest, char *src);

/**
 For KM_strcat: dest need to have enough sapce to store src
 
 @param dest destination
 @param src source
 @return destination
 */
char * KM_strcat(char *dest, char *src);

#endif /* KMString_h */

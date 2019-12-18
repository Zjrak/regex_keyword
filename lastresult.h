#ifndef _LASTRESULT_H_
#define _LASTRESULT_H_

#include<sys/types.h>
#include<boost/regex.hpp>
#include<string>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<iostream>
#include <ctype.h>
using namespace std;
bool key_match(string result_split, char* keywords);
bool pattern_t(char* input, string pattern, char* keywords1, char* keywords2);
bool pattern_o(char* input, string pattern, char* keywords1, char* keywords2);
bool pattern_5_7(char* input, string pattern, char* keywords1, char* keywords2);
int EVENT_GetRelation(char *sen, char* keywords1, char* keywords2, int* type);


#endif

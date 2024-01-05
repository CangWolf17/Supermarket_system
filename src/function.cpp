//
// Created by calfVong on 2024/1/3.
//
#include "head.h"

bool isDigitStr(string s){
    int len = s.length();
    int i = 0;

    for(i = 0;i<len;i++)
        if (isdigit(s[i])) // 调用isdigit函数，判断传入字符是否为数字，如果是则返回0
            return false;
    return true;
}

int strTurnNum(string s){
    int len = s.length();
    int i = 0;
    int num = 0;

    for(i = 0;i < len; i++){
        num*=10;
        num+=s[i] - '0';
    }

    return num;
}


float strTurnFloatNum(string s) {
    int len = s.length();
    int i = 0;
    float num = 0;

    for (i = 0; i < len; i++) {
        if(s[i] == '.')
            break;
        num *= 10;
        num += s[i] - '0';
    }

    i++;
    for(;i<len;i++) {
        num += s[i] - '0';
        num *= 0.1;
    }

    return num;
}
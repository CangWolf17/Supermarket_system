//
// Created by calfVong on 2024/1/3.
//
#include "head.h"

bool isDigitStr(string s) {
    int len = s.length();
    int i = 0;

    for (i = 0; i < len; i++)
        if (isdigit(s[i])) // ����isdigit�������жϴ����ַ��Ƿ�Ϊ���֣�������򷵻�0
            return false;
    return true;
}

int strTurnNum(string s) {
    int num;
    istringstream ss(s);
    ss >> num;
    return num;
}

void pause() {
    system("pause");
}

void cls() {
    system("cls");
}
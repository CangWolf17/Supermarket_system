//
// Created by calfVong on 2024/1/3.
//
#include "head.h"

bool isDigitStr(string s) {
    int len = s.length();
    int i;

    for (i = 0; i < len; i++)
        if (!(isdigit(s[i]))) // ����isdigit�������жϴ����ַ��Ƿ�Ϊ���֣�������򷵻�0
            return false;
    return true;
}

int strTurnNum(const string& s) {
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

void goto_xy(int x,int y){ //����goto_xy������ʵ�ָ�ʽ����
    int xx=0x0b;
    HANDLE hOutput;
    COORD loc;
    loc.X=x;
    loc.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,loc);
}
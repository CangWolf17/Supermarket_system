//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_WELCOMEPAGE_H
#define SUPERMARKET_SYSTEM_WELCOMEPAGE_H

#include "string"
using namespace std;

class users{
public:
    string name;            // �û���ʵ����
    string userID;          // �û�id
    string userPwd;         // ����
    int userLevel;          // �û�Ȩ��
};

users login();

#endif //SUPERMARKET_SYSTEM_WELCOMEPAGE_H

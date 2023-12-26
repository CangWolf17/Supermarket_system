//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_WELCOMEPAGE_H
#define SUPERMARKET_SYSTEM_WELCOMEPAGE_H

#include "string"
using namespace std;

struct users{
    string name;            // 用户真实姓名
    string userID;        // 用户id
    string userPwd;         // 密码
    int userLevel;          // 用户权限
};

void login();

#endif //SUPERMARKET_SYSTEM_WELCOMEPAGE_H

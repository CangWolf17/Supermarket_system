//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// 用于包含其他头文件的区域
#include "login/WelcomePage.h"

// 使用类和类继承来控制用户对应的权限组和可执行的权限操作
// 创建类
class customer{
public:
    // 存放成员函数



};

class keeper: public customer{
public:




};

class cashier: public keeper{
public:




};



class admin: public cashier{
public:




};

#endif //SUPERMARKET_SYSTEM_HEAD_H

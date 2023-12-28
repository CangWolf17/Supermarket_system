//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// 用于包含其他头文件的区域
#include "vector"
#include "login/WelcomePage.h"

// 创建类
// 创建用于显示屏幕内容的类
class Display{
    void loginPage();           // 登录界面
    void welcomePage();         // 欢迎界面


};

// 创建用户信息的类
class Users{
public:
    string name;            // 用户真实姓名
    string userID;          // 用户id
    string userPwd;         // 密码
    int userLevel;          // 用户权限
};

// 创建货物的类
class Goods{
public:
    int id;                     // 商品编号
    string name;                // 商品名称
    string species;             // 商品种类
    float purchasePrice;        // 商品进价
    float sellPrice;            // 商品单价
    int quantity;               // 商品数量
    int lessLimit;              // 商品数量提醒阈值
    string measure;             // 商品的计量单位
    string remark = "无";       // 备注

    // 创建成员函数
    void read(vector<Goods> &goods);           // 传入一个Goods数组，读取文件中的货物信息并存入数组
    void write(vector<Goods> &goods);          // 传入一个Goods数组，将数组覆盖存储到文件中

};

// 创建销售记录的类
class SellLog{






};

// 使用类和类继承来控制用户对应的权限组和可执行的权限操作
class Customer{
public:
    // 存放成员函数
    // Users类权限
    void users_reg();

    // Goods类权限
    void goods_buy();
    void goods_find();

    // SellLog类权限
    void sellLog_receipt();

};

class Keeper: public Customer{
public:

    void goods_data();
    void goods_add();
    void goods_del();
    void goods_addKind();
    void goods_delKind();

};

class Cashier: public Keeper{
public:

    void users_del();

    void goods_sell();

    void sellLog_data();

};



class Admin: public Cashier{
public:

    void users_edit();
    void users_create();
    void users_adminDel();



};

#endif //SUPERMARKET_SYSTEM_HEAD_H

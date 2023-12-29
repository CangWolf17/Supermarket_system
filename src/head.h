//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// 用于包含其他头文件的区域
#include "vector"
#include "login/WelcomePage.h"

// 创建类
// 创建用户信息的类
class Users{
public:
    string name;            // 用户真实姓名
    string userID;          // 用户id
    string userPwd;         // 密码
    int userLevel;          // 用户权限

    // 创建成员函数
    void read(vector<Users> &users);
    void save(vector<Users> &users);

    void reg();
    void del();
    void edit();
    void create();
    void adminDel();
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
    void save(vector<Goods> &goods);          // 传入一个Goods数组，将数组覆盖存储到文件中

    void buy();
    void find();
    void data();
    void add();
    void del();
    void addKind();
    void delKind();
    void sell();
};

// 创建销售记录的类
class SellLog{
public:
    long long transactionID;    // 交易编号
    string time;                // 交易时间
    int id;                     // 商品编号
    string name;                // 商品名称
    string species;             // 商品种类
    float sellPrice;            // 商品单价
    int quantity;               // 交易商品数量
    float price;                // 交易总价
    string measure;             // 商品的计量单位

    // 创建成员函数
    void read(vector<SellLog> &sellLogs);
    void save(vector<SellLog> &sellLogs);

    void newLog();
    void receipt();
    void data();

};

// 创建用于显示屏幕内容的类
class Display{
public:
    void loginPage();           // 登录界面
    void welcomePage();         // 欢迎界面
    void showGoods(vector<Goods> &goods);           // 商品信息展示

};

#endif //SUPERMARKET_SYSTEM_HEAD_H

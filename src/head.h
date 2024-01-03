//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// 用于包含其他头文件的区域
#include "vector"
#include "login/WelcomePage.h"
#include "string"

// 定义全局函数
// 目的是为了避免重复造轮子

bool isDigitStr(string s); // 用于检查传入的字符串是否全部为数字，如果是则返回true
int strTurnNum(string s); // 用于将字符串转换为数字的函数，返回值为转换后的数字

// 创建类
// 创建用户信息的类
class Users{
public:
    string name;            // 用户真实姓名
    string id;          // 用户id
    string pwd;         // 密码
    int level;          // 用户权限

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
    void search(vector<Goods> &goods, string s, Goods &find_goods); // 查找商品，能找到就把商品信息存入形参find_goods，找不到就将其的id设置为-1
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
    float profit;               // 交易利润
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

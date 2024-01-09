//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// 用于包含其他头文件的区域
#include "fstream"
#include "iostream"
#include "map"
#include "ctime"
#include "windows.h"
#include "sstream"
#include "vector"
#include "vector"
#include "login/WelcomePage.h"
#include "string"
#include "sysinfoapi.h"
#include "iomanip"
#include "algorithm"

#define BLANKSPACE "   "

// 定义全局函数
// 目的是为了避免重复造轮子

bool isDigitStr(string s);       // 用于检查传入的字符串是否全部为数字，如果是则返回true
int strTurnNum(string s);        // 用于将字符串转换为数字的函数，返回值为转换后的数字
void pause();             // 暂停函数，暂停黑窗口并显示按任意键继续
void cls();               // 清屏函数

// 创建类
// 创建用户信息的类
class Users {
public:
    string name; // 用户真实姓名
    string id;   // 用户id
    string pwd;  // 密码
    int level;   // 用户权限


    // 创建成员函数
    static void read(vector<Users> &users);

    static void save(vector<Users> &users);

    static void search(vector<Users> &users, string s, Users &find_user);      // 查找用户
    static void add(vector<Users> &users, int level);                    // 添加用户函数
    static void del(vector<Users> &users);                      // 删除用户，需要传入用户id
    static void pwdedit(vector<Users> &users, Users currentUser);              // 修改密码
    static void edit(vector<Users> &users, int i, int kind, string new_value); // 指定待修改的元素下标，种类，值
};

// 创建销售记录的类
class Bills {
public:
    int transactionID; // 交易编号
    SYSTEMTIME time;         // 交易时间
    int id;                  // 商品编号
    string name;             // 商品名称
    string species;          // 商品种类
    float sellPrice;         // 商品单价
    int quantity;            // 交易商品数量
    float price;             // 交易总价
    float profit;            // 交易利润
    string measure;          // 商品的计量单位

    // 创建成员函数
    static void read(vector<Bills> &bills);

    static void save(vector<Bills> &bills);

    static void receipt(vector<Bills> market);

    static void data(vector<Bills> &bills);

    static void analyzeSales(vector<Bills> &bills);
};

// 创建货物的类
class Goods {
public:
    int id;               // 商品编号
    string name;          // 商品名称
    string species;       // 商品种类
    float purchasePrice;  // 商品进价
    float sellPrice;      // 商品单价
    int quantity;         // 商品数量
    int lessLimit;        // 商品数量提醒阈值
    string measure;       // 商品的计量单位

    // 创建成员函数
    static void read(vector<Goods> &goods); // 传入一个Goods数组，读取文件中的货物信息并存入数组
    static void save(vector<Goods> &goods); // 传入一个Goods数组，将数组覆盖存储到文件中

    static void search(vector<Goods> &goods, string s, Goods &find_goods);
    // 查找商品，能找到就把商品信息存入形参find_goods，找不到就将其的id设置为-1
    // 传入的string s可以是商品id也可以是商品名

    static void trade(vector<Bills> bills, vector<Goods> &goods,
                      vector<Bills> &new_bills); // 交易函数，无论买卖操作都进行调用，用于扣除库存
    static void edit(vector<Goods> &goods, int i, int kind, string new_value); // 商品编辑函数，用于编辑商品指定内容
    static void add(vector<Goods> &goods); // 商品添加函数
    static void del(vector<Goods> &goods); // 商品删除函数

};

// 创建用于显示屏幕内容的类
class Display {
public:
    static void loginPage();   // 登录界面
    static void welcomePage(Users user); // 欢迎界面

    static void customMenu();                             // 顾客菜单界面
    static void customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice);

    static void customGoodsData(vector<Goods> &goods, vector<Bills> &market); // 顾客商品目录
    static void customSearch(vector<Goods> &goods, vector<Bills> &market);    // 顾客搜索商品
    static void customMarket(vector<Bills> market);                           // 顾客购物车

    static void keeperMenu();
    static void keeperSearch(vector<Goods> &goods);
    static void keeperLimit(vector<Goods> &goods);

    static void cashierMenu();
    static void cashierMarket(vector<Bills> &market);
    static void cashierTrade(vector<Goods> &goods, vector<Bills> &market);

    static void goods_data(vector<Goods> &goods); // 所有的商品信息展示
    static void goods_edit(vector<Goods> &goods); // 商品编辑

    static void adminMenu(); // 管理员总菜单
    static void adminUsers(vector<Users> users); // 用户菜单
    static void adminGoodsMenu(); // 货物菜单
};

#endif // SUPERMARKET_SYSTEM_HEAD_H

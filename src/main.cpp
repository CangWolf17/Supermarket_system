//
// Created by calfVong on 2023/12/22.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#include "head.h"

using namespace std;

// 主函数，保持为登陆界面模块
int main(){
    enum authority{
        customer = 0, keeper, cashier, admin
    };  // 枚举 使用户权限可视为单词

    // 实例化对象，初始化程序
    Display display;            // 实例化一个对象用于调用成员函数
    Goods goodsFunc;
    Users usersFunc;
    SellLog sellFunc;

    vector<Users> users;        // 申请类数组，数组都以s结尾
    vector<Goods> goods;
    vector<SellLog> sellLogs;

    goodsFunc.read(goods);       // 读取文件中的数据并存入数组
    usersFunc.read(users);
    sellFunc.read(sellLogs);

    // 主函数开始执行
    Users user = login();       // 调用login函数实现登录，同时返回一个包含用户数据的users对象

    // 程序结束自动保存数据
    // usersFunc.save(users);
    goodsFunc.save(goods);
    sellFunc.save(sellLogs);

    return 0;
}
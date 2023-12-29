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

    Display display;            // 实例化一个Display对象
    Users user = login();       // 调用login函数实现登录，同时返回一个包含用户数据的users对象
    Goods goodsFunc;    // 创建一个goodsfunc用于调用成员函数

    vector<Goods> goods;            // 申请一个goods数组
    goodsFunc.read(goods);       // 读取goods文件中的数据并存入数组


    return 0;
}
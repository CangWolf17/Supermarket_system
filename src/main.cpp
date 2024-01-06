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
int main()
{
    enum authority {
        customer = 0,
        keeper,
        cashier,
        admin
    }; // 枚举 使用户权限可视为单词

    // 实例化对象，初始化程序
    Display display; // 实例化一个对象用于调用成员函数

    vector<Users> users; // 申请类数组，数组都以s结尾
    vector<Goods> goods;
    vector<Bills> bills;

    Goods::read(goods); // 读取文件中的数据并存入数组
    Users::read(users);
    Bills::read(bills);


    // 主函数开始执行

    // 登录
    Users user = login(); // 调用login函数实现登录，同时返回一个包含用户数据的users对象
    // 菜单选择
    int menuChoice[3] = {-1, 0, 0};

    switch (user.level) {
        display.welcomePage();
        case customer: {
            vector<Bills> market; // 一个bills数组用来当作购物车
            while (menuChoice[0]) {
                display.customMenu(goods);
                cin >> menuChoice[0];
                switch (menuChoice[0]) {
                    case 1: { // 1 商品目录
                        display.customGoodsData(goods, market);
                        break;
                    }
                    case 2: { // 2 搜索商品
                        display.customSearch(goods, market);
                        break;
                    }
                    case 3:{// 3 购物车
                        cout << "您的购物车内容：" << endl;
                        for (const auto& bill : market) {
                            cout << "商品名称: " << bill.name << ", 商品数量: " << bill.quantity << ", 商品单价: "
                            << bill.sellPrice << ", 总价: " << bill.price << ", 计量单位: " << bill.measure << endl;
                        }
                        break;
                    }
                    case 4: { // 4 结算
                        if (market.empty()) {
                            cout << "购物车中还未添加商品哦！";
                        } else {
                            cout << "是否确认结算？(y/n)：";
                            char choice;
                            cin >> choice;
                            if (choice == 'y')
                                Goods::trade(bills, goods, market);
                            else
                                menuChoice[0] = -1;
                            cout << "是否打印小票？(y/n)：";
                            cin >> choice;
                            if (choice == 'y')
                                Bills::receipt(market);
                        }
                    }
                    case 5: {
                        Users::pwdedit(users, user);
                        menuChoice[0] = -1;

                    }
                    case 0:
                        break;
                    default:
                        cout << "请输入有效值！ ";
                        cin >> menuChoice[0];
                        menuChoice[0] = -1;
                }
            }


            break;
        }
        case keeper: {
            break;
        }
        case cashier: {
            break;
        }

        case admin: {
            break;
        }
    }


    // 程序结束自动保存数据
    Users::save(users);
    Goods::save(goods);
    Bills::save(bills);

    return 0;
}
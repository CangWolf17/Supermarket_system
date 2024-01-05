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
    Bills billFunc;

    vector<Users> users;        // 申请类数组，数组都以s结尾
    vector<Goods> goods;
    vector<Bills> bills;

    goodsFunc.read(goods);       // 读取文件中的数据并存入数组
    usersFunc.read(users);
    billFunc.read(bills);


    // 主函数开始执行

    // 登录
    Users user = login();       // 调用login函数实现登录，同时返回一个包含用户数据的users对象
    // 菜单选择
    int menuChoice[3] = {-1,0,0};

    switch (user.level) {
        case customer: {
            vector<Bills> custom_bills; // 一个bills数组用来当作购物车
            while(menuChoice[0]){
                display.customMenu();
                cin>>menuChoice[0];
                switch (menuChoice[0]) {
                    case 1: { // 1 商品目录
                        display.customGoodsData();
                        break;
                    }
                    case 2: {
                        Goods find_goods;
                        string find_name = display.customSearch();
                        goodsFunc.search(goods,find_name,find_goods);
                        display.customSearchResult();
                        break;
                    }
                    case 3:
                    case 4:
                    case 5:
                    case 0:
                        break;
                    default:
                        cout<<"请输入有效值！ ";
                        cin>>menuChoice[0];
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

        case admin:{



            break;
        }
    }







    // 程序结束自动保存数据
    usersFunc.save(users);
    goodsFunc.save(goods);
    billFunc.save(bills);

    return 0;
}
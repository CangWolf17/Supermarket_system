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
            system("title customer");
            // 用while保持菜单
            while (menuChoice[0]) {
                display.customMenu();
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
                    case 3: {// 3 购物车
                        display.customMarket(market);

                        cout << "是否要修改或删除内容？（取消：0，修改：1，删除：2）：";
                        int choice;
                        cin >> choice;

                        // 购物车操作
                        switch (choice) {
                            case 1: {
                                int goodsChoice, quantityChoice;
                                cout << "请输入要修改的商品编号：";
                                cin >> goodsChoice;
                                bool cond = false;
                                for (int i = 0; i < market.size(); i++) {
                                    if (market[i].id == goodsChoice) {
                                        market.erase(market.begin() + i); // 直接删除，重新创建
                                        Goods buy_goods;
                                        buy_goods.id = goodsChoice;
                                        for (int j = 0; j < goods.size(); j++)
                                            if (goods[i].id == buy_goods.id)
                                                buy_goods = goods[i];
                                        display.customTrade(buy_goods, goods, market, 'y');
                                        cond = true;
                                        break;
                                    }
                                }
                                if (!cond) {
                                    cout << "输入的商品编号有误..." << endl;
                                    choice = 0;
                                }
                                menuChoice[0] = -1;
                                break;
                            }
                            case 2: {
                                int goodsChoice;
                                cout << "请输入要删除的商品编号：";
                                cin >> goodsChoice;
                                bool cond = false;
                                for (int i = 0; i < market.size(); i++) {
                                    if (market[i].id == goodsChoice) {
                                        market.erase(market.begin() + i);
                                        cout << "购物车中的商品已删除" << endl;
                                        cond = true;
                                    }
                                }

                                if (!cond) {
                                    cout << "输入的商品编号有误..." << endl;
                                    choice = 0;
                                }
                                menuChoice[0] = -1;
                                break;
                            }
                            default:{
                                menuChoice[0] = -1;
                                break;
                            }
                        }
                    }
                    case 4: { // 4 结算
                        cls();
                        if (market.empty()) {
                            cout << "购物车中还未添加商品哦！";
                        } else {
                            // 展示购物车内容
                            display.customMarket(market);

                            // 结算
                            cout << endl << "是否确认结算？(y/n)：";
                            char choice;
                            cin >> choice;
                            if (choice == 'y')
                                Goods::trade(bills, goods, market);
                            else
                                menuChoice[0] = -1;

                            // 小票打印
                            cout << "是否打印小票？(y/n)：";
                            cin >> choice;
                            if (choice == 'y')
                                Bills::receipt(market);
                        }
                        menuChoice[0] = -1;
                        break;
                    }
                    case 5: { // 5 修改密码
                        Users::pwdedit(users, user);
                        menuChoice[0] = -1;
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "请输入有效值！ ";
                        menuChoice[0] = -1;
                        cin >> menuChoice[0];
                }
            }
            break;
        }

        case keeper:{
            system("title keeper");

            while (menuChoice[0]) {
                cls();
                display.keeperLimit(goods);
                cout<<endl;
                display.keeperMenu();

                cin >> menuChoice[0];
                switch (menuChoice[0]) {
                    case 1: {
                        display.goods_data(goods);
                        break;
                    } // 1 商品详情
                    case 2: {
                        display.keeperSearch(goods);
                        break;
                    } // 2 搜索商品
                    case 3: {
                        display.goods_edit(goods);
                        break;
                    } // 3 编辑商品
                    case 4: {
                        Goods::add(goods);
                        break;
                    } // 4 添加商品
                    case 5: {
                        Goods::del(goods);
                        break;
                    } // 5 删除商品
                    case 6: { // 6 修改密码
                        Users::pwdedit(users, user);
                        menuChoice[0] = -1;
                        break;
                    } // 6 修改密码
                    case 0:
                        break;
                    default:
                        cout << "输入值无效！请重新输入：";
                        cin >> menuChoice[0];
                        break;
                }
            }
            break;
        }


        case cashier: {
            system("title cashier");
            vector<Bills> market; // 一个bills数组用来当作购物车

            while(menuChoice[0]) {
                if(market.empty())
                    cout<<"当前购物车为空。"<<endl;
                else
                    display.cashierMarket(market);

                display.cashierMenu();
                cin >> menuChoice[0];

                switch (menuChoice[0]) {
                    case 1: {
                        display.cashierTrade(goods,market);
                        break;
                    } // 1 销售商品
                    case 2: {
                        cls();
                        if (market.empty()) {
                            cout << "���ﳵ�л�δ������ƷŶ��";
                        } else {
                            // չʾ���ﳵ����
                            display.cashierMarket(market);

                            // ����
                            cout << endl << "�Ƿ�ȷ�Ͻ��㣿(y/n)��";
                            char choice;
                            cin >> choice;
                            if (choice == 'y')
                                Goods::trade(bills, goods, market);
                            else
                                menuChoice[0] = -1;

                            // СƱ��ӡ
                            cout << "�Ƿ��ӡСƱ��(y/n)��";
                            cin >> choice;
                            if (choice == 'y')
                                Bills::receipt(market);
                        }
                        menuChoice[0] = -1;
                        break;
                    } // 2 购物结算
                    case 3: {
                        break;
                    } // 3 查看销售记录
                    case 4: {
                        Users::pwdedit(users, user);
                        menuChoice[0] = -1;
                        break;
                    } // 4 修改密码
                    case 0:
                        break;
                    default:
                        cout << "输入值无效！请重新输入：";
                        cin >> menuChoice[0];
                        menuChoice[0] = -1;
                }
            }
            break;
        }


        case admin: {
            cin >> menuChoice[0];
            switch (menuChoice[0]) {
                default:
                    cout << "输入值无效！请重新输入：";
                    cin >> menuChoice[0];
                    menuChoice[0] = -1;
            }
            break;
        }
    }


    // 程序结束自动保存数据
    Users::save(users);
    Goods::save(goods);
    Bills::save(bills);

    cout<<"感谢您的使用，再见！";
    system ("pause");
    return 0;
}
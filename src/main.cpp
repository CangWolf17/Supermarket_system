//
// Created by calfVong on 2023/12/22.
//

#include "head.h"

using namespace std;

// 主函数，保持为登陆界面模块
int main() {
    enum authority {
        customer = 0,
        keeper,
        cashier,
        admin
    }; // 枚举 使用户权限可视为单词

    vector<Users> users; // 实例化数组
    vector<Goods> goods;
    vector<Bills> bills;

    Goods::read(goods); // 读取文件中的数据并存入数组
    Users::read(users);
    Bills::read(bills);


    // 主函数开始执行

    // 登录
    Users user = login(); // 调用login函数实现登录，同时返回一个包含用户数据的users对象
    if (user.name == "NOTFOUND")
        user = login();
    if (user.id == "reg")
        Users::add(users, 0);
    else if (user.id == "0") {
        user.name = "visitor";
        user.level = 0;
    }

    // 欢迎页面展示
    Display::welcomePage(user);
    // 菜单选择
    int menuChoice = -1;

    switch (user.level) {
        case customer: {
            vector<Bills> market; // 一个bills数组用来当作购物车
            system("title customer");
            // 用while保持菜单
            while (menuChoice) {
                cls();
                Display::customMenu();
                cin >> menuChoice;

                switch (menuChoice) {
                    case 1: { // 1 商品目录
                        Display::customGoodsData(goods, market);
                        pause();
                        break;
                    }
                    case 2: { // 2 搜索商品
                        Display::customSearch(goods, market);
                        pause();
                        break;
                    }
                    case 3: {// 3 购物车
                        Display::customMarket(market);

                        cout << "是否要修改或删除内容？（取消：0，修改：1，删除：2）：";
                        int choice;
                        cin >> choice;

                        // 购物车操作
                        switch (choice) {
                            case 1: {
                                int goodsChoice;
                                cout << "请输入要修改的商品编号：";
                                cin >> goodsChoice;

                                if (!Display::customMarketEdit(goods,market,goodsChoice)) {
                                    cout << "输入的商品编号有误..." << endl;
                                    choice = 0;
                                    pause();
                                }
                                menuChoice = -1;
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
                                menuChoice = -1;
                                break;
                            }
                            default: {
                                menuChoice = -1;
                                break;
                            }
                        }
                        break;
                    }
                    case 4: { // 4 结算
                        cls();
                        if (market.empty()) {
                            cout << "购物车中还未添加商品哦！";
                        } else {
                            // 展示购物车内容
                            Display::customMarket(market);

                            // 结算
                            cout << endl << "是否确认结算？(y/n)：";
                            char choice;
                            cin >> choice;
                            if (choice == 'y') {
                                Goods::trade(bills, goods, market);
                                market.clear();
                                // 小票打印
                                cout << "是否打印小票？(y/n)：";
                                cin >> choice;
                                if (choice == 'y') {
                                    Bills::receipt(market);
                                }
                                market.clear();
                            } else {
                                menuChoice = -1;
                                break;
                            }
                            menuChoice = -1;
                            break;
                        }
                        case 5: { // 5 修改密码
                            if (user.id != "0") {
                                Users::pwdedit(users, user);
                                menuChoice = -1;
                            }
                            else{
                                cout<<"您不能修改游客身份的密码！请退出后注册！"<<endl;
                                menuChoice = -1;
                            }
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "请输入有效值！ ";
                        menuChoice = -1;
                        cin >> menuChoice;
                    }
                }
            }
            break;
        }

        case keeper: {
            system("title keeper");

            while (menuChoice) {
                cls();
                Display::keeperLimit(goods);
                cout << endl;
                Display::keeperMenu();

                cin >> menuChoice;
                switch (menuChoice) {
                    case 1: {
                        Display::goods_data(goods);
                        break;
                    } // 1 商品详情
                    case 2: {
                        Display::keeperSearch(goods);
                        break;
                    } // 2 搜索商品
                    case 3: {
                        Display::goods_edit(goods);
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
                        menuChoice = -1;
                        break;
                    } // 6 修改密码
                    case 0:
                        break;
                    default:
                        cout << "输入值无效！请重新输入：";
                        cin >> menuChoice;
                        break;
                }
            }
            break;
        }

        case cashier: {
            system("title cashier");
            vector<Bills> market; // 创建market作为购物车

            while (menuChoice) {
                if (market.empty())
                    cout << "当前购物车为空。" << endl;
                else
                    Display::cashierMarket(market);

                Display::cashierMenu();
                cin >> menuChoice;

                switch (menuChoice) {
                    case 1: {
                        Display::cashierTrade(goods, market);
                        break;
                    } // 1 销售商品
                    case 2: {
                        cls();
                        if (market.empty()) {
                            cout << "购物车中还未添加商品哦！";
                        } else {
                            // 展示购物车内容
                            Display::cashierMarket(market);

                            cout << "请选择操作（0.取消，1.结算，2.修改，3.删除）：";
                            int choice;
                            cin >> choice;

                            // 购物车操作
                            switch (choice) {
                                case 1: {
                                    cout << endl << "是否确认结算？(y/n)：";
                                    char tradeChoice;
                                    cin >> tradeChoice;
                                    if (tradeChoice == 'y') {
                                        Goods::trade(bills, goods, market);
                                        market.clear();
                                        // 小票打印
                                        cout << "是否打印小票？(y/n)：";
                                        cin >> tradeChoice;
                                        if (tradeChoice == 'y')
                                            Bills::receipt(market);
                                    }
                                    else
                                        menuChoice = -1;
                                    break;
                                }
                                case 2: {
                                    int goodsChoice;
                                    cout << "请输入要修改的商品编号：";
                                    cin >> goodsChoice;

                                    if (!Display::customMarketEdit(goods, market, goodsChoice)) {
                                        cout << "输入的商品编号有误..." << endl;
                                        choice = 0;
                                        pause();
                                    }
                                    menuChoice = -1;
                                    break;
                                }
                                case 3: {
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
                                    menuChoice = -1;
                                    break;
                                }
                                default: {
                                    menuChoice = -1;
                                    break;
                                }
                            }
                        }
                        menuChoice = -1;
                        break;
                    }// 2 购物结算
                    case 3: {
                        Bills::data(bills);
                        break;
                    } // 3 查看销售记录
                    case 4: {
                        Users::pwdedit(users, user);
                        menuChoice = -1;
                        break;
                    } // 4 修改密码
                    case 0:
                        break;
                    default:
                        cout << "输入值无效！请重新输入：";
                        cin >> menuChoice;
                        menuChoice = -1;
                }
            }
            break;
        }

        case admin: {
            system("title admin");

            while (menuChoice) {
                cls();
                Display::adminMenu();

                cin >> menuChoice;
                switch (menuChoice) {
                    case 1: {
                        Display::adminUsers(users);
                        break;
                    } // 用户操作
                    case 2: {
                        Display::adminGoodsMenu();
                        int choice;
                        cin >> choice;

                        switch (choice) {
                            case 1: {
                                Display::goods_data(goods);
                                break;
                            } // 1 商品详情
                            case 2: {
                                Display::goods_edit(goods);
                                break;
                            } // 2 编辑商品
                            case 3: {
                                Goods::add(goods);
                                break;
                            } // 3 添加商品
                            case 4: {
                                Goods::del(goods);
                                break;
                            } // 4 删除商品
                            case 0:
                                break;
                            default:
                                cout << "输入值无效！请重新输入：";
                                cin >> choice;
                                break;
                        }
                        break;
                    } // 货物操作
                    case 3: {
                        Bills::data(bills);
                        break;
                    } // 销售情况
                    case 4: {
                        Users::pwdedit(users, user);
                        menuChoice = -1;
                        break;
                    }  // 4 修改密码

                    default:
                        cout << "输入值无效！请重新输入：";
                        cin >> menuChoice;
                        menuChoice = -1;
                }
                break;
            }
        }
    }



    // 程序结束，保存数据
    Users::save(users);
    Goods::save(goods);
    Bills::save(bills);

    cout << "感谢您的使用，下次再见！";
    system("pause");
    return 0;
}
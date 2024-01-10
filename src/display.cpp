//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage() { // 登录界面
    system("title login");//界面初始化
    system("color 70");

    goto_xy(50,10);
    cout <<"欢迎使用超市购物系统";
    goto_xy(53,11);
    cout <<"AI2302 第五小组";
    goto_xy(54,12);
    cout <<setw(10) <<"组长：沈文伟";
    goto_xy(48,13);
    cout <<setw(7) <<"小组成员：罗梦希，寇笑天";
    goto_xy(53,16);
    system ("pause");
}

void Display::welcomePage(Users user) {
    cls();
    system("title 欢迎使用超市管理系统");
    system("color 70");
    goto_xy(10,15);;
    pause();
}

void Display::customMenu() {
    cls();
    system("title customer");
    system ("color 70");
    // 添加代码以显示顾客菜单界面
    goto_xy(10,10);
    cout << "菜单选项：";
    goto_xy(10,11);
    cout << "1. 商品目录";
    goto_xy(10,12);
    cout << "2. 搜索商品";
    goto_xy(10,13);
    cout << "3. 购物车";
    goto_xy(10,14);
    cout << "4. 结算";
    goto_xy(10,15);
    cout << "5. 修改密码";
    goto_xy(10,16);
    cout << "0. 退出";
    goto_xy(10,17);
    cout <<"请输入您的选择：";
}

bool Display::customMarketEdit(vector<Goods> &goods, vector<Bills> &market, int goodsChoice) {
    for (int i = 0; i < market.size(); i++) {
        if (market[i].id == goodsChoice) {
            market.erase(market.begin() + i); // 直接删除，重新创建

            // 建立重新购买的商品
            Goods buy_goods;
            buy_goods.id = goodsChoice;

            // 从商品数组获取信息
            for (auto & good : goods)
                if (good.id == buy_goods.id)
                    buy_goods = good;

            // 传入交易函数
            Display::customTrade(buy_goods, goods, market, 'y');
            return true;
        }
    }
}

void Display::customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice) {
    if (buy_choice == 'y') {
        for (auto &i: market)
            if (buy_goods.id == i.id) {
                goto_xy(70,11);
                cout << "商品已存在，即将跳转修改..." << endl;
                pause();
                Display::customMarketEdit(goods, market, i.id);
                return;
            }
        Bills new_bills;
        goto_xy(70,10);
        cout << "请输入购买数量：";
        cin >> new_bills.quantity;
        // 对顾客输入的商品数量进行检查
        while (new_bills.quantity <= 0) {
            goto_xy(70,11);
            cout << "商品数量不能为负数或零。" ;
            cin >> new_bills.quantity;
        }
        // 检查商品数量是否超过了库存
        while (new_bills.quantity > buy_goods.quantity) {
            goto_xy(70,12);
            cout << "购物车中的商品数量超过了库存。" ;
            goto_xy(70,13);
            cout << "请再次输入：";
            cin >> new_bills.quantity;
        }

        // 产生销售记录
        new_bills.id = buy_goods.id;
        new_bills.name = buy_goods.name;
        new_bills.species = buy_goods.species;
        new_bills.sellPrice = buy_goods.sellPrice;
        new_bills.price = new_bills.sellPrice * new_bills.quantity;  // 计算总价
        new_bills.profit = new_bills.price - (buy_goods.purchasePrice * new_bills.quantity); // 计算利润
        new_bills.measure = buy_goods.measure;


        // 销售记录推入购物车
        market.push_back(new_bills);
        goto_xy(70,13);
        std::cout << "添加成功！" ;
    }
}

void customGoodsPrint(Goods tmp_goods) {
    cout << setw(5) << tmp_goods.id << setw(12) << tmp_goods.name
         << setw(8) << tmp_goods.species << setw(8) << tmp_goods.quantity
         << setw(7) << tmp_goods.sellPrice << "/" << tmp_goods.measure << endl;
}

void marketPrint(Bills tmp_bills) {
    cout << setw(5) << tmp_bills.id << setw(12) << tmp_bills.name
         << setw(9) << tmp_bills.species << setw(5) << tmp_bills.quantity
         << setw(7) << tmp_bills.sellPrice << "/" << tmp_bills.measure << setw(6) << tmp_bills.price << endl;
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    cls();

    int j = 1;
    // 添加代码以显示顾客商品目录
    goto_xy(10,10);
    cout << "以下是所有商品目录：";
    goto_xy(10,11);
    cout << "==============================================" ;
    goto_xy(10,12);
    cout << "   商品编号    商品名称   种类   库存数量   价格/单位" ;
    goto_xy(10,13);
    int lie=14;
    for (const auto &tmp_goods: goods) {
        goto_xy(10,lie);
        cout << j++ << ".";
        customGoodsPrint(tmp_goods);
        lie++;
    } // 未包含“商品进价”、“阈值提醒”和“备注”

    goto_xy(10,lie);
    cout << "==============================================" << endl;

    goto_xy(10,lie+1);
    cout << "请输入要购买的商品编号（无则请输入0）：";
    // 输入购买商品编号
    int id, i;
    cin >> id;
    if (id != 0) {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;
    } else {
        goto_xy(10, lie + 2);
        return;
    }

    Goods buy_goods = goods[i];
    char buy_choice;
    goto_xy(10,lie+2);
    cout << "是否确认加入购物车？（请输入y/n）：";
    cin >> buy_choice;
    customTrade(buy_goods, goods, market, buy_choice);
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {
    cls();
    string s;
    Goods find_goods;

    // 询问客户要搜索的内容
    goto_xy(10,10);
    cout << "请输入要搜索的商品名称或编号：";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        goto_xy(10,11);
        cout << "商品编号    商品名称   种类   库存数量   价格/单位";
        goto_xy(10,12);
        customGoodsPrint(find_goods);
        char buy_choice;
        goto_xy(10,13);
        cout << "是否确认加入购物车？（请输入y/n）：";
        cin >> buy_choice;
        customTrade(find_goods, goods, market, buy_choice);
    } else {
        goto_xy(10,11);
        cout << "查找的商品不存在！即将返回上一级..." << endl;
    }
}

void Display::customMarket(vector<Bills> &market) {
    cls();
    int j = 1;
    goto_xy(0,10);
    cout << "您的购物车内容：" ;
    goto_xy(0,11);
    cout << "   商品编号    商品名称   种类   数量   价格/单位   总价" << endl;
    int lie2=12;
    for (const auto &tmp_market: market) {
        goto_xy(0,lie2);
        cout << j++ << ".";
        marketPrint(tmp_market);
        lie2++;
    }
}

void goodsPrint(Goods goods) {
    cout << setw(7) << goods.id << setw(10) << goods.name
         << setw(9) << goods.species << setw(8) << goods.quantity
         << setw(7) << goods.purchasePrice << setw(8) << goods.sellPrice
         << setw(9) << goods.measure << setw(10) << goods.lessLimit << endl;
}

void Display::keeperMenu() {
    goto_xy(10,12);
    cout << "1.库存详情" << endl;
    goto_xy(10,13);
    cout << "2.搜索商品" << endl;
    goto_xy(10,14);
    cout << "3.编辑商品" << endl;
    goto_xy(10,15);
    cout << "4.添加商品" << endl;
    goto_xy(10,16);
    cout << "5.删除商品" << endl;
    goto_xy(10,17);
    cout << "6.修改密码" << endl;
    goto_xy(10,18);
    cout << "0.退出" << endl;
}

void Display::keeperSearch(vector<Goods> &goods) {
    cls();
    string s;
    Goods find_goods;

    // 询问客户要搜索的内容
    goto_xy(10,10);
    cout << "请输入要搜索的商品名称或编号：";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        goto_xy(10,10);
        cout << "编号     名称     种类     数量     进价     售价     单位     提醒阈值" << endl;
        goto_xy(10,11);
        goodsPrint(find_goods);
        goto_xy(10,12);
        pause();
    } else {
        goto_xy(10,11);
        cout << "查找的商品不存在！即将返回上一级...";
        goto_xy(10,12);
        pause();
    }
}

void Display::keeperLimit(vector<Goods> &goods) {
    goto_xy(10,10);
    cout << "补货通知：" << endl;
    int j = 1;
    for (auto &igoods: goods) {
        if (igoods.quantity <= igoods.lessLimit) {
            cout << j++ << ".商品 " << igoods.name << " (编号 " << igoods.id << " ）" << "数量低于设置阈值（"
                 << igoods.lessLimit << "），当前库存为：" << igoods.quantity << "，请及时补货。" << endl;
        }
    }
}

void Display::goods_data(vector<Goods> &goods) {
    int pageSize = 10, pageNumber = 1;
    int maxPage = goods.size() / 10 + (goods.size() % 10 > 0);

    while (pageNumber) {
        // 计算起始和结束
        cls();
        int startIndex = (pageNumber - 1) * pageSize;
        int endIndex = pageNumber * pageSize;
        goto_xy(10,10);
        cout << "商品详情页面" << endl;
        goto_xy(10,11);
        cout << "当前页数： 第 " << pageNumber << " 页" << endl;

        goto_xy(10,12);
        cout << "=====================================================================" << endl;
        goto_xy(10,13);
        cout << "     编号    名称     种类     数量    进价    售价    单位     提醒阈值" << endl;
        int lie3=14;
        for (int j = startIndex, i = startIndex; j < endIndex && i < goods.size(); i++, j++) {
            // 打印当前销售记录的信息
            goto_xy(10,lie3);
            goodsPrint(goods[i]);
            lie3++;
        }
        goto_xy(10,lie3);
        cout << "=====================================================================" << endl;

        goto_xy(10,lie3+1);
        cout << "最大页数：" << maxPage << endl;
        goto_xy(10,lie3+2);
        cout << "请输入查看页数（0退出）：";
        cin >> pageNumber;
        if (pageNumber > maxPage) {
            cout << "页数大于最大页数！请重新输入：";
            cin >> pageNumber;
        } else if (pageNumber < 0) {
            cout << "输入页数应大于0！请重新输入：";
            cin >> pageNumber;
        }
    }
}

void Display::goods_edit(vector<Goods> &goods) {
    cls();

    string s;
    Goods find_goods;

    goto_xy(10,10);
    cout << "请输入要修改的商品名称或编号来进行搜索，输入0退出：";
    cin >> s;
    if (s == "0")
        return;
    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        goto_xy(10,12);
        cout << "1.编号   2.名称   3.种类   4.数量   5.进价   6.售价   7.单位   8.提醒阈值" << endl;
        goto_xy(10,13);
        goodsPrint(find_goods);
    } else {
        goto_xy(10,12);
        cout << "要修改的商品不存在！即将返回上一级...";
        goto_xy(10,13);
        pause();
        return;
    }

    goto_xy(10,15);
    cout << "请指定要修改的商品信息对应的数字：";
    int kind;
    cin >> kind;

    // 安全检查
    if (kind >= 1 && kind <= 8) {
        int i;
        for (i = 0; i < goods.size(); i++)
            if (find_goods.id == goods[i].id)
                break;
        string new_value;
        goto_xy(10,16);
        cout << "请输入新的商品信息：";
        cin >> new_value; // 输入数据的安全检查没做
        Goods::edit(goods, i, kind, new_value);
        cls();
        goto_xy(10,10);
        cout << "修改完成，结果如下：" << endl;
        goto_xy(10,11);
        cout << "编号     名称     种类     数量     进价     售价     单位     提醒阈值" << endl;
        goto_xy(10,12);
        goodsPrint(goods[i]);
        goto_xy(10,13);
        pause();
        return;
    } else {
        goto_xy(10,17);
        cout << "输入数字无效，程序即将返回...";
        goto_xy(10,18);
        pause();
        return;
    }
}

void Display::cashierMenu() {
    cout << "1.添加销售商品" << endl;
    cout << "2.销售商品操作" << endl;
    cout << "3.查看销售记录" << endl;
    cout << "4.修改密码" << endl;
    cout << "0.退出" << endl;
}

void Display::cashierMarket(vector<Bills> &market) {
    cls();

    cout << "购物车中的内容：" << endl;
    cout << "   商品编号    商品名称   种类   数量   价格/单位   总价" << endl;
    for (const auto &bill: market) {
        marketPrint(bill);
    }
}

void Display::cashierTrade(vector<Goods> &goods, vector<Bills> &market) {

    int j = 1;
    // 显示商品目录
    cout << "以下是所有商品目录：" << endl;
    cout << "   商品编号    商品名称   种类   库存数量   价格/单位" << endl;
    for (const auto &tmp_goods: goods) {
        cout << j++ << ".";
        customGoodsPrint(tmp_goods);
    } // 未包含“商品进价”、“阈值提醒”和“备注”

    cout << "请输入要销售的商品编号（无则请输入0）：";
    // 输入购买商品编号
    int id, i;
    cin >> id;
    if (id != 0) {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;
    } else {
        pause();
        return;
    }

    Bills new_bills;
    new_bills.id = goods[i].id;
    for (auto &tmp_market: market)
        if (new_bills.id == tmp_market.id) {
            cout << "商品已存在，即将跳转修改..." << endl;
            pause();
            Display::customMarketEdit(goods, market, tmp_market.id);
            return;
        }

    cout << "请输入购买数量：";
    cin >> new_bills.quantity;
    // 对顾客输入的商品数量进行检查
    while (new_bills.quantity <= 0) {
        cout << "商品数量不能为负数或零。" << endl;
        cin >> new_bills.quantity;
    }
    // 检查商品数量是否超过了库存
    while (new_bills.quantity > goods[i].lessLimit) {
        cout << "购物车中的商品数量超过了库存。" << endl;
        cin >> new_bills.quantity;
    }
    // 产生销售记录
    new_bills.name = goods[i].name;
    new_bills.species = goods[i].species;
    new_bills.sellPrice = goods[i].sellPrice;
    new_bills.quantity = goods[i].quantity;
    new_bills.price = new_bills.sellPrice * new_bills.quantity;  // 计算总价
    new_bills.profit = new_bills.price - (goods[i].purchasePrice * new_bills.quantity); // 计算利润
    new_bills.measure = goods[i].measure;

    // 销售记录推入购物车
    market.push_back(new_bills);
    std::cout << "添加成功！" << std::endl;
}

void Display::adminMenu() {
    goto_xy(10,10);
    cout << "1.用户操作";
    goto_xy(10,11);
    cout << "2.货物操作";
    goto_xy(10,12);
    cout << "3.销售记录";
    goto_xy(10,13);
    cout << "4.修改密码";
    goto_xy(10,14);
    cout << "0.退出" << endl;
    goto_xy(10,15);
    cout <<"请选择(输入0-4):";
}

void usersMenuPrint(vector<Users> &users) {
    // 遍历指定范围内的用户信息
    goto_xy(10,10);
    cout << "======================================" << endl;
    goto_xy(10,11);
    cout << "     姓名          id            权限" << endl;
    int lie5=12;
    for (auto &user: users) {
        // 打印当前用户的姓名和ID
        goto_xy(10,lie5);
        cout << setw(9) << user.name << setw(14) << user.id << "       ";
        lie5++;
        switch (user.level) {
            case 0:
                cout << "    顾客" << endl;
                break;
            case 1:
                cout << "仓库管理员" << endl;
                break;
            case 2:
                cout << "   收银员" << endl;
                break;
            case 3:
                cout << "   管理员" << endl;
                break;
        }
    }

// 显示管理员查看用户信息的界面
    goto_xy(70,10);
    cout << "其他选项：";
    goto_xy(70,11);
    cout << "1. 创建用户";
    goto_xy(70,12);
    cout << "2. 编辑用户";
    goto_xy(70,13);
    cout << "3. 删除用户";
    goto_xy(70,14);
    cout << "0. 返回";
    goto_xy(70,15);
    cout <<"您的选择：" ;

}

void Display:: adminUsers(vector<Users> &users, Users user) {//管理员用户操作

    int choice = 1;
    string verify_pwd;
    while (choice) {
        cls();
        usersMenuPrint(users);
        cin >> choice;
        switch (choice) {
            case 1: {
                Users::add(users, 3);
                break;
            } // 创建用户
            case 2: {
                int kind;
                int i;
                string id, new_value;
                goto_xy(10,18);
                cout << "请输入修改的用户id:";
                cin >> id;
                bool cond = false;

                for (i = 0; i < users.size(); i++)
                    if (users[i].id == id) {
                        cond = true;
                        break;
                    }

                if (cond == false) {
                    goto_xy(10,19);
                    cout << "用户id错误！" << endl;
                    goto_xy(10,20);
                    pause();
                    break;
                }
                goto_xy(10,19);
                cout << "请输入修改的数据类型（1.姓名，2.id，3.密码，4.权限，0.退出）：";
                cin >> kind;
                if (kind == 1 || kind == 2 || kind == 3 || kind == 4) {
                    goto_xy(10,20);
                    cout << "请输入新的值：";
                    cin >> new_value;
                    Users::edit(users, i, kind, new_value);
                    break;
                }
                break;
            } // 编辑用户
            case 3: {
                goto_xy(10,18);
                cout << "请输入您的密码以确认身份：";
                cin >> verify_pwd;
                if (verify_pwd == user.pwd) {
                    Users::del(users);
                    break;
                } else {
                    goto_xy(10,19);
                    cout << "密码错误，程序即将返回...";
                    goto_xy(10,20);
                    pause();
                    break;
                }
            } // 删除用户
            case 0:
                break;
            default:
                goto_xy(10,19);
                cout << "输入值无效！请重新输入：";
                cin >> choice;
        }
    }
}

void Display::adminGoodsMenu() {
    cout << "1.库存详情" << endl;
    cout << "2.编辑商品" << endl;
    cout << "3.添加商品" << endl;
    cout << "4.删除商品" << endl;
    cout << "0.退出" << endl;
}

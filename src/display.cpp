//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage() { // 登录界面
    // 登录页面，未设计
}

void Display::welcomePage(Users user) {
    system("cls");
    system("title 欢迎使用超市管理系统");
    system("color 0C");
    cout << endl;
    system("pause");

}

void Display::customMenu() {
    cls();
    system("title customer");
    // 添加代码以显示顾客菜单界面
    cout << "菜单选项：" << endl;
    cout << "1. 商品目录" << endl;
    cout << "2. 搜索商品" << endl;
    cout << "3. 购物车" << endl;
    cout << "4. 结算" << endl;
    cout << "5. 修改密码" << endl;
    cout << "0. 退出" << endl;
}

void Display::customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice) {
    if (buy_choice == 'y') {
        Bills new_bills;
        cout << "请输入购买数量：";
        cin >> new_bills.quantity;
        // 对顾客输入的商品数量进行检查
        while (new_bills.quantity <= 0) {
            cout << "商品数量不能为负数或零。" << endl;
            cin >> new_bills.quantity;
        }
        // 检查商品数量是否超过了库存
        while (new_bills.quantity > buy_goods.lessLimit) {
            cout << "购物车中的商品数量超过了库存。" << endl;
            cin >> new_bills.quantity;
        }

        // 产生销售记录
        new_bills.id = buy_goods.id;
        new_bills.name = buy_goods.name;
        new_bills.species = buy_goods.species;
        new_bills.sellPrice = buy_goods.sellPrice;
        new_bills.quantity = buy_goods.quantity;
        new_bills.price = new_bills.sellPrice * new_bills.quantity;  // 计算总价
        new_bills.measure = buy_goods.measure;


        // 销售记录推入购物车
        market.push_back(new_bills);
        std::cout << "添加成功！" << std::endl;
    }
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    cls();

    int j = 1;
    // 添加代码以显示顾客商品目录
    cout << "以下是所有商品目录：" << endl;
    for (const auto &tmp_goods: goods) {
        cout << j++ << ".商品编号：" << tmp_goods.id << " 名称：" << tmp_goods.name
             << " 种类：" << tmp_goods.species << " 价格：" << tmp_goods.sellPrice << "/" << tmp_goods.measure
             << " 数量：" << tmp_goods.quantity << endl;
    } // 未包含“商品进价”、“阈值提醒”和“备注”

    cout << "请输入要购买的商品编号（无则请输入0）：";
    // 输入购买商品编号
    int id, i;
    cin >> id;
    if (id != 0) {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;
    }
    else
        return;

    Goods buy_goods = goods[i];
    char buy_choice;
    cout << "是否确认加入购物车？（请输入y/n）：";
    cin >> buy_choice;
    customTrade(buy_goods, goods, market, buy_choice);
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {
    cls();
    string s;
    Goods find_goods;

    // 询问客户要搜索的内容
    cout << "请输入要搜索的商品名称或编号：";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        char buy_choice;
        cout << "是否确认加入购物车？（请输入y/n）：";
        cin >> buy_choice;
        customTrade(find_goods, goods, market, buy_choice);
    } else {
        cout << "查找的商品不存在！即将返回上一级...";
        pause();
    }
}

void Display::customMarket(vector<Bills> market) {
    cls();
    int j = 1;
    cout << "您的购物车内容：" << endl;
    for (const auto &bill: market) {
        cout << j++ << ". 商品名称: " << bill.name << ", 数量: " << bill.quantity << ", 单价: "
             << bill.sellPrice << "/" << bill.measure << ", 总价: " << bill.price << endl;
    }
}

void Display::keeperMenu() {
    system("title cashier");
    cout << "1.库存详情" << endl;
    cout << "2.搜索商品" << endl;
    cout << "3.编辑商品" << endl;
    cout << "4.添加商品" << endl;
    cout << "5.删除商品" << endl;
    cout << "6.修改密码" << endl;
    cout << "0.退出" << endl;
}

void Display::keeperSearch(vector<Goods> &goods) {
    cls();
    string s;
    Goods find_goods;

    // 询问客户要搜索的内容
    cout << "请输入要搜索的商品名称或编号：";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        cout << "     编号     名称     种类     数量     进价     售价     单位     提醒阈值" << endl;
        cout << setw(5) << find_goods.id << setw(9) << find_goods.name
             << setw(9) << find_goods.species << setw(9) << find_goods.quantity
             << setw(9) << find_goods.purchasePrice << setw(9) << find_goods.sellPrice
             << setw(9) << find_goods.measure << setw(9) << find_goods.lessLimit << endl;
        pause();
    } else {
        cout << "查找的商品不存在！即将返回上一级...";
        pause();
    }
}

void Display::keeperLimit(vector<Goods> &goods) {
    int j = 1;
    for (auto &igoods: goods) {
        if (igoods.quantity <= igoods.lessLimit) {
            cout << j++ << ".商品 " << igoods.name << " (编号 " << igoods.id << " ）" << "数量低于设置阈值（"
                 << igoods.lessLimit << "），当前库存为：" << igoods.quantity << "，请及时补货。" << endl;
        }
    }
}

void Display::cashierMenu() {
    cout << "1.销售商品" << endl;
    cout << "2.购物结算" << endl;
    cout << "3.查看记录" << endl;
    cout << "4.修改密码" << endl;
    cout << "0.退出" << endl;
}

void Display::cashierMarket(vector<Bills> &market) {
    cls();
    int j = 1;
    cout << "购物车中的内容：" << endl;
    for (const auto &bill: market) {
        cout << j++ << ". 商品名称: " << bill.name << ", 数量: " << bill.quantity << ", 单价: "
             << bill.sellPrice << "/" << bill.measure << ", 总价: " << bill.price << endl;
    }
}

void Display::cashierTrade(vector<Goods> &goods, vector<Bills> &market) {

    int j = 1;
    // 添加代码以显示顾客商品目录
    cout << "以下是所有商品目录：" << endl;
    for (const auto &tmp_goods: goods) {
        cout << j++ << ".商品编号：" << tmp_goods.id << " 名称：" << tmp_goods.name
             << " 种类：" << tmp_goods.species << " 价格：" << tmp_goods.sellPrice << "/" << tmp_goods.measure
             << " 数量：" << tmp_goods.quantity << endl;
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
    cout << "请输入购买数量：";
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
    new_bills.id = goods[i].id;
    new_bills.name = goods[i].name;
    new_bills.species = goods[i].species;
    new_bills.sellPrice = goods[i].sellPrice;
    new_bills.quantity = goods[i].quantity;
    new_bills.price = new_bills.sellPrice * new_bills.quantity;  // 计算总价
    new_bills.measure = goods[i].measure;


    // 销售记录推入购物车
    market.push_back(new_bills);
    std::cout << "添加成功！" << std::endl;
}

void goodsPrint(Goods goods){
    cout << setw(5) << goods.id << setw(9) << goods.name
         << setw(9) << goods.species << setw(9) << goods.quantity
         << setw(9) << goods.purchasePrice << setw(9) << goods.sellPrice
         << setw(9) << goods.measure << setw(9) << goods.lessLimit << endl;
}

void Display::goods_data(vector<Goods> &goods) {
    int pageSize = 10, pageNumber = 1;

    int choice = 1;
    cin >> choice;
    while (pageNumber) {
        // 计算起始和结束
        int startIndex = (pageNumber - 1) * pageSize;
        int endIndex = pageNumber * pageSize;
        cout << "商品详情页面" << endl;
        cout << "当前页数： 第 " << pageNumber << " 页" << endl;
        cout << "     编号     名称     种类     数量     进价     售价     单位     提醒阈值" << endl;
        for (int j = startIndex, i = startIndex; j < endIndex && i < goods.size(); i++, j++) {
            // 打印当前销售记录的信息
            goodsPrint(goods[i]);
        }
        cout << "请输入查看页数（0退出）：" << endl;
        cin >> pageNumber;
    }
}

void Display::goods_edit(vector<Goods> &goods) {
    cls();

    string s;
    Goods find_goods;

    cout << "请输入要修改的商品名称或编号：";
    cin >> s;
    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        cout << "   1.编号   2.名称   3.种类   4.数量   5.进价   6.售价   7.单位   8.提醒阈值" << endl;
        cout << setw(5) << find_goods.id << setw(9) << find_goods.name
             << setw(9) << find_goods.species << setw(9) << find_goods.quantity
             << setw(9) << find_goods.purchasePrice << setw(9) << find_goods.sellPrice
             << setw(9) << find_goods.measure << setw(9) << find_goods.lessLimit << endl;
        pause();
    } else {
        cout << "要修改的商品不存在！即将返回上一级...";
        pause();
        return;
    }

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
        cout << "请输入新的商品信息：";
        cin >> new_value; // 输入数据的安全检查没做
        Goods::edit(goods, i, kind, new_value);
        cls();
        cout << "修改完成，结果如下：" << endl;
        cout << "     编号     名称     种类     数量     进价     售价     单位     提醒阈值" << endl;
        cout << setw(5) << goods[i].id << setw(9) << goods[i].name
             << setw(9) << goods[i].species << setw(9) << goods[i].quantity
             << setw(9) << goods[i].purchasePrice << setw(9) << goods[i].sellPrice
             << setw(9) << goods[i].measure << setw(9) << goods[i].lessLimit << endl;
        pause();
        return;
    } else {
        cout << "输入数字无效，程序即将返回...";
        pause();
        return;
    }
}

void Display::adminMenu() {
    cout << "1.用户操作" << endl;
    cout << "2.货物操作" << endl;
    cout << "3.销售记录" << endl;
    cout << "4.修改密码" << endl;
    cout << "0.退出" << endl;
}

void Display::adminUsers(vector<Users> users) {//管理员用户操作

// 遍历指定范围内的用户信息
    for (auto & user : users) {
        // 打印当前用户的姓名和ID
        cout << " 姓名: " << user.name << " id: " << user.id;
        switch (user.level) {
            case 0:
                cout<<" 权限：顾客"<<endl;
                break;
            case 1:
                cout<<" 权限：仓库管理员"<<endl;
                break;
            case 2:
                cout<<" 权限：收银员"<<endl;
                break;
            case 3:
                cout<<" 权限：管理员"<<endl;
                break;
        }
    }

// 显示管理员查看用户信息的界面
    cout << "其他选项：" << endl;
    cout << "1. 创建用户" << endl;
    cout << "2. 编辑用户" << endl;
    cout << "3. 删除用户" << endl;
    cout << "0. 返回" << endl;

    int choice = 1;
    string verify_pwd;
    cin >> choice;
    switch (choice) {
        case 1: {
            int level;
            Users::add(users, level);
            break;
        } // 创建用户
        case 2: {
            int kind;
            int i;
            string new_value;
            Users::edit(users, i, kind, new_value);
            break;
        } // 编辑用户
        case 3: {
            cout << "请输入密码以确认身份：" << endl;
            cin >> verify_pwd;
            for (int i = 0; i < users.size(); i++) {
                if (verify_pwd == users[i].pwd) {
                    if (users[i].level == 3) {
                        int level;
                        Users::del(users);
                        break;
                    }
                }
            }
            break;
        } // 删除用户
        case 0:
            break;
        default:
            cout << "输入值无效！请重新输入：";
    }
}

void Display::adminGoodsMenu() {
    cout << "1.库存详情" << endl;
    cout << "2.编辑商品" << endl;
    cout << "3.删除商品" << endl;
    cout << "0.退出" << endl;
}

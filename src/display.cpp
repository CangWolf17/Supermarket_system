//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage() { // 登录界面
    // 登录页面，未设计
}

void Display::welcomePage() {
    system("cls");
    system("title 欢迎使用超市管理系统");
    system("color 0C");
    //cout << "娆㈣繋鍏夐【Mr.wang鐨勫皬搴?" << endl;
    //cout << "鎮ㄧ殑璐︽埛锛? " << endl;
    //cout << "鎮ㄧ殑鏉冮檺涓猴細 " << endl;
    cout << endl;
    system("pause");

}

void Display::users_data() {


}

void Display::goods_data(vector<Goods> &goods) {
    // 界面未设计

    static int i = 0;


    for (i; i < goods.size() - 1; i++) {
        cout << goods[i].id << "   " << goods[i].name << "   " << goods[i].species << "   " << goods[i].sellPrice <<
             "   " << goods[i].quantity << endl;
    }
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
        for (const auto &bill: market) {
            if (bill.quantity <= 0) {
                cout << "商品数量不能为负数或零。" << endl;
                return;
            }
        }
        // 检查商品数量是否超过了库存
        for (const auto &bill: market) {
            int i = 0;
            if (bill.quantity > 0) {
                if (bill.quantity > goods[i].lessLimit) {
                    cout << "购物车中的商品数量超过了库存。" << endl;
                    return;
                }
            }
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
        std::cout << "购买成功！" << std::endl;
    }
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    cls();

    // 添加代码以显示顾客商品目录
    cout << "以下是所有商品目录：" << endl;
    for (const auto &tmp_goods: goods) {
        cout << tmp_goods.id << "   " << tmp_goods.name << "   " << tmp_goods.species << "   " << tmp_goods.sellPrice
             << "   " << tmp_goods.quantity << "   " << tmp_goods.measure << "   " << endl;
    } // 未包含“商品进价”、“阈值提醒”和“备注”

    cout << "请输入要购买的商品编号（无则请输入0）：";
    // 输入购买商品编号
    int id, i;
    cin >> id;
    if (id != 0) {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;

        Goods buy_goods = goods[i];
        char buy_choice;
        cout << "是否确认加入购物车？（请输入y/n）：";
        cin >> buy_choice;
        customTrade(buy_goods, goods, market, buy_choice);
    }
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {
    cls();
    string s;
    Goods find_goods;

    // 询问客户要搜索的内容
    cout << "请输入要搜索的商品名称：";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        char buy_choice;
        cout << "是否确认加入购物车？（请输入y/n）：";
        cin >> buy_choice;
        customTrade(find_goods, goods, market, buy_choice);
    } else {
        cout << "查找的商品不存在！即将返回上一级...";

    }
}

void Display::customMarket(vector<Bills> market) {
    cls();
    cout << "您的购物车内容：" << endl;
    for (const auto &bill: market) {
        cout << "商品名称: " << bill.name << ", 数量: " << bill.quantity << ", 单价: "
             << bill.sellPrice << "/" << bill.measure << ", 总价: " << bill.price << endl;
    }
}

void Display::keeperMenu() {
    cout<<"1.库存详情"<<endl;
    cout<<"2.搜索商品"<<endl;
    cout<<"3.编辑商品"<<endl;
    cout<<"4.添加商品"<<endl;
    cout<<"5.删除商品"<<endl;
    cout<<"6.修改密码"<<endl;
    cout<<"0.退出"<<endl;
}

void Display::cashierMenu() {
    system("cls");
    system("title cashier");
    cout<<"1销售"<<endl;
    cout<<"2查看销售记录"<<endl;
    cout<<"3删除顾客用户"<<endl;
    cout<<"4修改密码"<<endl;
    cout<<"0退出"<<endl;
}

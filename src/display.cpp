//
// Created by calfVong on 2023/12/28.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>

#include "head.h"

using namespace std;

void Display::loginPage()
{ // 登录界面
  // 登录页面，未设计
}

void Display::welcomePage() {


}

void Display::users_data() {}

void Display::goods_data(vector<Goods> &goods)
{
    // 界面未设计

    static int i = 0;


    for (i; i < goods.size() - 1; i++) {
        cout << goods[i].id << "   " << goods[i].name << "   " << goods[i].species << "   " << goods[i].sellPrice <<
            "   " << goods[i].quantity << endl;
    }
}

void Display::customMenu(vector<Goods> &goods)
{
    system("cls");
}

void customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market)
{
    char buy_choice;
    cout << "是否确认加入购物车？（请输入y/n）：";
    cin >> buy_choice;
    if (buy_choice == 'y') {
        Bills new_bills;
        cout << "数量";
        cin >> new_bills.quantity;

        // 产生销售记录
        // ...

        // 销售记录推入购物车
        market.push_back(new_bills);
    }
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market)
{
    // 输出商品内容
    cout << " ";

    // 输入购买商品编号
    int id;
    cin >> id;
    Goods buy_goods = goods[id];
    customTrade(buy_goods, goods, market);
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market)
{
    string s;
    Goods find_goods;

    // 询问客户要搜索的内容
    cout << " ";

    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        customTrade(find_goods, goods, market);
    } else {
        cout << "找到的商品不存在！";
    }
}

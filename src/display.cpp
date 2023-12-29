//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage(){ // 登录界面
    // 登录页面，未设计


}

void Display::welcomePage() {




}

void Display::showGoods(vector<Goods> &goods) {
    // 界面未设计

    int i;
    cout << "商品编号   商品名称   商品种类   商品单价   商品数量"<<endl;
    for (i = 0; i < goods.size() - 1; i++) {
        cout << goods[i].id << "   " << goods[i].name << "   " << goods[i].species
             << "   " << goods[i].sellPrice << "   " << goods[i].quantity << endl;
    }
}

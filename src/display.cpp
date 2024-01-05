//
// Created by calfVong on 2023/12/28.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>

#include "head.h"

using namespace std;

void Display::loginPage(){ // 登录界面
    // 登录页面，未设计


}

void Display::welcomePage() {




}

void Display::users_data() {

}

void Display::goods_data(vector<Goods> &goods) {
    // 界面未设计

    static int i = 0;


    for (i; i < goods.size() - 1; i++) {
        cout << goods[i].id << "   " << goods[i].name << "   " << goods[i].species
             << "   " << goods[i].sellPrice << "   " << goods[i].quantity << endl;
    }
}

void Display::customMenu() {
        system("cls");
}

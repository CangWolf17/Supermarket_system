//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage(){ // ��¼����
    // ��¼ҳ�棬δ���


}

void Display::welcomePage() {




}

void Display::goods_data(vector<Goods> &goods) {
    // ����δ���

    static int i = 0;


    for (i; i < goods.size() - 1; i++) {
        cout << goods[i].id << "   " << goods[i].name << "   " << goods[i].species
             << "   " << goods[i].sellPrice << "   " << goods[i].quantity << endl;
    }
}

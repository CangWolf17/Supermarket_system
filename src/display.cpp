//
// Created by calfVong on 2023/12/28.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>

#include "head.h"

using namespace std;

void Display::loginPage()
{ // ��¼����
  // ��¼ҳ�棬δ���
}

void Display::welcomePage() {


}

void Display::users_data() {}

void Display::goods_data(vector<Goods> &goods)
{
    // ����δ���

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
    cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
    cin >> buy_choice;
    if (buy_choice == 'y') {
        Bills new_bills;
        cout << "����";
        cin >> new_bills.quantity;

        // �������ۼ�¼
        // ...

        // ���ۼ�¼���빺�ﳵ
        market.push_back(new_bills);
    }
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market)
{
    // �����Ʒ����
    cout << " ";

    // ���빺����Ʒ���
    int id;
    cin >> id;
    Goods buy_goods = goods[id];
    customTrade(buy_goods, goods, market);
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market)
{
    string s;
    Goods find_goods;

    // ѯ�ʿͻ�Ҫ����������
    cout << " ";

    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        customTrade(find_goods, goods, market);
    } else {
        cout << "�ҵ�����Ʒ�����ڣ�";
    }
}

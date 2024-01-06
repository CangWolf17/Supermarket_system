//
// Created by calfVong on 2023/12/28.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>

#include "head.h"

using namespace std;

void Display::loginPage(){ // ��¼����
    // ��¼ҳ�棬δ���


}

void Display::welcomePage() {




}

void Display::users_data() {

}

void Display::goods_data(vector<Goods> &goods) {
    // ����δ���

    static int i = 0;


    for (i; i < goods.size() - 1; i++) {
        cout << goods[i].id << "   " << goods[i].name << "   " << goods[i].species
             << "   " << goods[i].sellPrice << "   " << goods[i].quantity << endl;
    }
}

void Display::customMenu(vector<Goods> &goods) {
    system("cls");
    // ��Ӵ�������ʾ�˿Ͳ˵�����
    cout << "�˵�ѡ�" << endl;
    cout << "1. ��ƷĿ¼" << endl;
    cout << "2. ������Ʒ" << endl;
    cout << "3. " << endl;
    cout << "4. " << endl;
    cout << "5. " << endl;
    cout << "0. " << endl;
}

void customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market) {
    char buy_choice;
    cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
    cin >> buy_choice;
    if (buy_choice == 'y') {
        Bills new_bills;
        cout << "����";
        cin >> new_bills.quantity;
        // �Թ˿��������Ʒ�������м��
        for (const auto& bill : market) {
            if (bill.quantity <= 0) {
                cout << "��Ʒ��������Ϊ�������㡣" << endl;
                return;
            }
        }
        // �����Ʒ�����Ƿ񳬹��˿��
        for (const auto& bill : market) {
            int i=0;
            if (bill.quantity > 0) {
                    if (bill.quantity > goods[i].lessLimit) {
                        cout << "���ﳵ�е���Ʒ���������˿�档" << endl;
                        return;
                    }
            }
        }
        // �������ۼ�¼
        new_bills.id = buy_goods.id;
        new_bills.name = buy_goods.name;
        new_bills.species = buy_goods.species;
        new_bills.sellPrice = buy_goods.sellPrice;
        new_bills.quantity = buy_goods.quantity;
        new_bills.price = new_bills.sellPrice * new_bills.quantity;  // �����ܼ�
        new_bills.measure = "��";

        // ���ۼ�¼���빺�ﳵ
        market.push_back(new_bills);
        std::cout << "����ɹ���" << std::endl;
    }
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    // �����Ʒ����
    // ��Ӵ�������ʾ�˿���ƷĿ¼
    cout << "������������ƷĿ¼��" << endl;
    for (const auto& goods : goods) {
        cout << goods.id << "   " << goods.name<<"   "<< goods.species<< "   " << goods.sellPrice
        <<"   "<< goods.quantity << "   " << goods.lessLimit<<"   "<< goods.measure<< "   " << goods.remark<< endl;
    }//δ��������Ʒ���ۡ�
    cout<<" ";
    // ���빺����Ʒ���
    int id;
    cin>>id;
    Goods buy_goods = goods[id];
    customTrade(buy_goods,goods,market);
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {

    string s;
    Goods find_goods;
    // ѯ�ʿͻ�Ҫ����������
    cout << "������Ҫ��������Ʒ���ƣ�";
    cout<<" ";
    cin>>s;
    Goods::search(goods,s,find_goods);
    if(find_goods.id != -1){
        customTrade(find_goods,goods, market);
    }else{
        cout<<"�ҵ�����Ʒ�����ڣ�";
    }

}




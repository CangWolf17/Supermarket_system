//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage() { // ��¼����
    // ��¼ҳ�棬δ���
}

void Display::welcomePage() {
    system("cls");
    system("title ��ӭʹ�ó��й���ϵͳ");
    system("color 0C");
    //cout << "欢迎光顾Mr.wang的小�?" << endl;
    //cout << "您的账户�? " << endl;
    //cout << "您的权限为： " << endl;
    cout << endl;
    system("pause");

}

void Display::users_data() {


}

void Display::goods_data(vector<Goods> &goods) {
    // ����δ���

    static int i = 0;


    for (i; i < goods.size() - 1; i++) {
        cout << goods[i].id << "   " << goods[i].name << "   " << goods[i].species << "   " << goods[i].sellPrice <<
             "   " << goods[i].quantity << endl;
    }
}

void Display::customMenu() {
    cls();
    system("title customer");
    // ��Ӵ�������ʾ�˿Ͳ˵�����
    cout << "�˵�ѡ�" << endl;
    cout << "1. ��ƷĿ¼" << endl;
    cout << "2. ������Ʒ" << endl;
    cout << "3. ���ﳵ" << endl;
    cout << "4. ����" << endl;
    cout << "5. �޸�����" << endl;
    cout << "0. �˳�" << endl;
}

void Display::customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice) {
    if (buy_choice == 'y') {
        Bills new_bills;
        cout << "�����빺��������";
        cin >> new_bills.quantity;
        // �Թ˿��������Ʒ�������м��
        for (const auto &bill: market) {
            if (bill.quantity <= 0) {
                cout << "��Ʒ��������Ϊ�������㡣" << endl;
                return;
            }
        }
        // �����Ʒ�����Ƿ񳬹��˿��
        for (const auto &bill: market) {
            int i = 0;
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
        new_bills.measure = buy_goods.measure;


        // ���ۼ�¼���빺�ﳵ
        market.push_back(new_bills);
        std::cout << "����ɹ���" << std::endl;
    }
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    cls();

    // ��Ӵ�������ʾ�˿���ƷĿ¼
    cout << "������������ƷĿ¼��" << endl;
    for (const auto &tmp_goods: goods) {
        cout << tmp_goods.id << "   " << tmp_goods.name << "   " << tmp_goods.species << "   " << tmp_goods.sellPrice
             << "   " << tmp_goods.quantity << "   " << tmp_goods.measure << "   " << endl;
    } // δ��������Ʒ���ۡ�������ֵ���ѡ��͡���ע��

    cout << "������Ҫ�������Ʒ��ţ�����������0����";
    // ���빺����Ʒ���
    int id, i;
    cin >> id;
    if (id != 0) {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;

        Goods buy_goods = goods[i];
        char buy_choice;
        cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
        cin >> buy_choice;
        customTrade(buy_goods, goods, market, buy_choice);
    }
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {
    cls();
    string s;
    Goods find_goods;

    // ѯ�ʿͻ�Ҫ����������
    cout << "������Ҫ��������Ʒ���ƣ�";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        char buy_choice;
        cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
        cin >> buy_choice;
        customTrade(find_goods, goods, market, buy_choice);
    } else {
        cout << "���ҵ���Ʒ�����ڣ�����������һ��...";

    }
}

void Display::customMarket(vector<Bills> market) {
    cls();
    cout << "���Ĺ��ﳵ���ݣ�" << endl;
    for (const auto &bill: market) {
        cout << "��Ʒ����: " << bill.name << ", ����: " << bill.quantity << ", ����: "
             << bill.sellPrice << "/" << bill.measure << ", �ܼ�: " << bill.price << endl;
    }
}

void Display::keeperMenu() {
    cout<<"1.�������"<<endl;
    cout<<"2.������Ʒ"<<endl;
    cout<<"3.�༭��Ʒ"<<endl;
    cout<<"4.�����Ʒ"<<endl;
    cout<<"5.ɾ����Ʒ"<<endl;
    cout<<"6.�޸�����"<<endl;
    cout<<"0.�˳�"<<endl;
}

void Display::cashierMenu() {
    system("cls");
    system("title cashier");
    cout<<"1����"<<endl;
    cout<<"2�鿴���ۼ�¼"<<endl;
    cout<<"3ɾ���˿��û�"<<endl;
    cout<<"4�޸�����"<<endl;
    cout<<"0�˳�"<<endl;
}

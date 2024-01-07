//
// Created by calfVong on 2023/12/22.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#include "head.h"

using namespace std;

// ������������Ϊ��½����ģ��
int main()
{
    enum authority {
        customer = 0,
        keeper,
        cashier,
        admin
    }; // ö�� ʹ�û�Ȩ�޿���Ϊ����

    // ʵ�������󣬳�ʼ������
    Display display; // ʵ����һ���������ڵ��ó�Ա����

    vector<Users> users; // ���������飬���鶼��s��β
    vector<Goods> goods;
    vector<Bills> bills;

    Goods::read(goods); // ��ȡ�ļ��е����ݲ���������
    Users::read(users);
    Bills::read(bills);


    // ��������ʼִ��

    // ��¼
    Users user = login(); // ����login����ʵ�ֵ�¼��ͬʱ����һ�������û����ݵ�users����
    // �˵�ѡ��
    int menuChoice[3] = {-1, 0, 0};

    switch (user.level) {
        display.welcomePage();
        case customer: {

            vector<Bills> market; // һ��bills���������������ﳵ

            // ��while���ֲ˵�
            while (menuChoice[0]) {
                display.customMenu(goods);
                cin >> menuChoice[0];

                switch (menuChoice[0]) {
                    case 1: { // 1 ��ƷĿ¼
                        display.customGoodsData(goods, market);
                        break;
                    }
                    case 2: { // 2 ������Ʒ
                        display.customSearch(goods, market);
                        break;
                    }
                    case 3: {// 3 ���ﳵ
                        display.customMarket(market);

                        cout << "�Ƿ�Ҫ�޸Ļ�ɾ�����ݣ���ȡ����0���޸ģ�1��ɾ����2����";
                        int choice;
                        cin >> choice;

                        // ���ﳵ����
                        switch (choice) {
                            case 1: {
                                int goodsChoice, quantityChoice;
                                cout << "������Ҫ�޸ĵ���Ʒ��ţ�";
                                cin >> goodsChoice;
                                bool cond = false;
                                for (int i = 0; i < market.size(); i++) {
                                    if (market[i].id == goodsChoice) {
                                        market.erase(market.begin() + i); // ֱ��ɾ�������´���
                                        Goods buy_goods;
                                        buy_goods.id = goodsChoice;
                                        for (int j = 0; j < goods.size(); j++)
                                            if (goods[i].id == buy_goods.id)
                                                buy_goods = goods[i];
                                        display.customTrade(buy_goods, goods, market, 'y');
                                        cond = true;
                                        break;
                                    }
                                }
                                if (!cond) {
                                    cout << "�������Ʒ�������..." << endl;
                                    choice = 0;
                                }
                                break;
                            }
                            case 2: {
                                int goodsChoice;
                                cout << "������Ҫ�޸ĵ���Ʒ��ţ�";
                                cin >> goodsChoice;
                                bool cond = false;
                                for (int i = 0; i < market.size(); i++) {
                                    if (market[i].id == goodsChoice) {
                                        market.erase(market.begin() + i);
                                        cout << "���ﳵ�е���Ʒ��ɾ��" << endl;
                                        cond = true;
                                    }
                                }

                                if (!cond) {
                                    cout << "�������Ʒ�������..." << endl;
                                    choice = 0;
                                }
                                break;
                            }
                        }
                    }
                    case 4: { // 4 ����
                        cls();
                        if (market.empty()) {
                            cout << "���ﳵ�л�δ�����ƷŶ��";
                        } else {
                            // չʾ���ﳵ����
                            display.customMarket(market);

                            // ����
                            cout << endl << "�Ƿ�ȷ�Ͻ��㣿(y/n)��";
                            char choice;
                            cin >> choice;
                            if (choice == 'y')
                                Goods::trade(bills, goods, market);
                            else
                                menuChoice[0] = -1;

                            // СƱ��ӡ
                            cout << "�Ƿ��ӡСƱ��(y/n)��";
                            cin >> choice;
                            if (choice == 'y')
                                Bills::receipt(market);
                        }
                        menuChoice[0] = -1;
                        break;
                    }
                    case 5: { // 5 �޸�����
                        Users::pwdedit(users, user);
                        menuChoice[0] = -1;
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "��������Чֵ�� ";
                        menuChoice[0] = -1;
                        cin >> menuChoice[0];
                }
            }
            break;
        }
        case keeper: {

            break;
        }
        case cashier: {

            break;
        }

        case admin: {

            break;
        }
    }


    // ��������Զ���������
    Users::save(users);
    Goods::save(goods);
    Bills::save(bills);

    return 0;
}
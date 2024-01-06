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
                    case 3: {
                    }
                    case 4: { // 4 ����
                        if (market.empty()) {
                            cout << "���ﳵ�л�δ�����ƷŶ��";
                        } else {
                            cout << "�Ƿ�ȷ�Ͻ��㣿(y/n)��";
                            char choice;
                            cin >> choice;
                            if (choice == 'y')
                                Goods::trade(bills, goods, market);
                            else
                                menuChoice[0] = -1;
                            cout << "�Ƿ��ӡСƱ��(y/n)��";
                            cin >> choice;
                            if (choice == 'y')
                                Bills::receipt(market);
                        }
                    }
                    case 5: {
                        Users::pwdedit(users, user);
                        menuChoice[0] = -1;
                    }
                    case 0:
                        break;
                    default:
                        cout << "��������Чֵ�� ";
                        cin >> menuChoice[0];
                        menuChoice[0] = -1;
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
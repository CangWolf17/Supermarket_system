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
int main(){
    enum authority{
        customer = 0, keeper, cashier, admin
    };  // ö�� ʹ�û�Ȩ�޿���Ϊ����

    // ʵ�������󣬳�ʼ������
    Display display;            // ʵ����һ���������ڵ��ó�Ա����
    Goods goodsFunc;
    Users usersFunc;
    Bills billFunc;

    vector<Users> users;        // ���������飬���鶼��s��β
    vector<Goods> goods;
    vector<Bills> bills;

    goodsFunc.read(goods);       // ��ȡ�ļ��е����ݲ���������
    usersFunc.read(users);
    billFunc.read(bills);


    // ��������ʼִ��

    // ��¼
    Users user = login();       // ����login����ʵ�ֵ�¼��ͬʱ����һ�������û����ݵ�users����
    // �˵�ѡ��
    int menuChoice[3] = {-1,0,0};

    switch (user.level) {
        case customer: {
            vector<Bills> custom_bills; // һ��bills���������������ﳵ
            while(menuChoice[0]){
                display.customMenu();
                cin>>menuChoice[0];
                switch (menuChoice[0]) {
                    case 1: { // 1 ��ƷĿ¼
                        display.customGoodsData();
                        break;
                    }
                    case 2: {
                        Goods find_goods;
                        string find_name = display.customSearch();
                        goodsFunc.search(goods,find_name,find_goods);
                        display.customSearchResult();
                        break;
                    }
                    case 3:
                    case 4:
                    case 5:
                    case 0:
                        break;
                    default:
                        cout<<"��������Чֵ�� ";
                        cin>>menuChoice[0];
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

        case admin:{



            break;
        }
    }







    // ��������Զ���������
    usersFunc.save(users);
    goodsFunc.save(goods);
    billFunc.save(bills);

    return 0;
}
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

    switch (user.level) {
        case customer: {
            vector<Bills> custom_bills;


            break;
        }
        case keeper:




            break;

        case cashier:



            break;


        case admin:



            break;
    }







    // ��������Զ���������
    usersFunc.save(users);
    goodsFunc.save(goods);
    billFunc.save(bills);

    return 0;
}
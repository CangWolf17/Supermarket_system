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
    SellLog sellFunc;

    vector<Users> users;        // ���������飬���鶼��s��β
    vector<Goods> goods;
    vector<SellLog> sellLogs;

    goodsFunc.read(goods);       // ��ȡ�ļ��е����ݲ���������
    usersFunc.read(users);
    sellFunc.read(sellLogs);


    // ��������ʼִ��
    Users user = login();       // ����login����ʵ�ֵ�¼��ͬʱ����һ�������û����ݵ�users����









    // ��������Զ���������
    usersFunc.save(users);
    goodsFunc.save(goods);
    sellFunc.save(sellLogs);

    return 0;
}
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

    vector<Users> users;        // ����������
    vector<Goods> goods;
    vector<SellLog> sellLogs;

    goodsFunc.read(goods);       // ��ȡgoods�ļ��е����ݲ���������
    usersFunc.read(users);
    sellFunc.read(sellLogs);

    Users user = login();       // ����login����ʵ�ֵ�¼��ͬʱ����һ�������û����ݵ�users����


    return 0;
}
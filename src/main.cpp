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

    Display display;            // ʵ����һ��Display����
    Users user = login();       // ����login����ʵ�ֵ�¼��ͬʱ����һ�������û����ݵ�users����
    Goods goodsFunc;    // ����һ��goodsfunc���ڵ��ó�Ա����

    vector<Goods> goods;            // ����һ��goods����
    goodsFunc.read(goods);       // ��ȡgoods�ļ��е����ݲ���������


    return 0;
}
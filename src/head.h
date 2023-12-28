//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// ���ڰ�������ͷ�ļ�������
#include "vector"
#include "login/WelcomePage.h"

// ������
// ����������ʾ��Ļ���ݵ���
class Display{
    void loginPage();           // ��¼����
    void welcomePage();         // ��ӭ����


};

// �����û���Ϣ����
class Users{
public:
    string name;            // �û���ʵ����
    string userID;          // �û�id
    string userPwd;         // ����
    int userLevel;          // �û�Ȩ��
};

// �����������
class Goods{
public:
    int id;                     // ��Ʒ���
    string name;                // ��Ʒ����
    string species;             // ��Ʒ����
    float purchasePrice;        // ��Ʒ����
    float sellPrice;            // ��Ʒ����
    int quantity;               // ��Ʒ����
    int lessLimit;              // ��Ʒ����������ֵ
    string measure;             // ��Ʒ�ļ�����λ
    string remark = "��";       // ��ע

    // ������Ա����
    void read(vector<Goods> &goods);           // ����һ��Goods���飬��ȡ�ļ��еĻ�����Ϣ����������
    void write(vector<Goods> &goods);          // ����һ��Goods���飬�����鸲�Ǵ洢���ļ���

};

// �������ۼ�¼����
class SellLog{






};

// ʹ�������̳��������û���Ӧ��Ȩ����Ϳ�ִ�е�Ȩ�޲���
class Customer{
public:
    // ��ų�Ա����
    // Users��Ȩ��
    void users_reg();

    // Goods��Ȩ��
    void goods_buy();
    void goods_find();

    // SellLog��Ȩ��
    void sellLog_receipt();

};

class Keeper: public Customer{
public:

    void goods_data();
    void goods_add();
    void goods_del();
    void goods_addKind();
    void goods_delKind();

};

class Cashier: public Keeper{
public:

    void users_del();

    void goods_sell();

    void sellLog_data();

};



class Admin: public Cashier{
public:

    void users_edit();
    void users_create();
    void users_adminDel();



};

#endif //SUPERMARKET_SYSTEM_HEAD_H

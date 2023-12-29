//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// ���ڰ�������ͷ�ļ�������
#include "vector"
#include "login/WelcomePage.h"

// ������
// �����û���Ϣ����
class Users{
public:
    string name;            // �û���ʵ����
    string userID;          // �û�id
    string userPwd;         // ����
    int userLevel;          // �û�Ȩ��

    // ������Ա����
    void read(vector<Users> &users);
    void save(vector<Users> &users);

    void reg();
    void del();
    void edit();
    void create();
    void adminDel();
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
    void save(vector<Goods> &goods);          // ����һ��Goods���飬�����鸲�Ǵ洢���ļ���

    void buy();
    void find();
    void data();
    void add();
    void del();
    void addKind();
    void delKind();
    void sell();
};

// �������ۼ�¼����
class SellLog{
public:
    long long transactionID;    // ���ױ��
    string time;                // ����ʱ��
    int id;                     // ��Ʒ���
    string name;                // ��Ʒ����
    string species;             // ��Ʒ����
    float sellPrice;            // ��Ʒ����
    int quantity;               // ������Ʒ����
    float price;                // �����ܼ�
    string measure;             // ��Ʒ�ļ�����λ

    // ������Ա����
    void read(vector<SellLog> &sellLogs);
    void save(vector<SellLog> &sellLogs);

    void newLog();
    void receipt();
    void data();

};

// ����������ʾ��Ļ���ݵ���
class Display{
public:
    void loginPage();           // ��¼����
    void welcomePage();         // ��ӭ����
    void showGoods(vector<Goods> &goods);           // ��Ʒ��Ϣչʾ

};

#endif //SUPERMARKET_SYSTEM_HEAD_H

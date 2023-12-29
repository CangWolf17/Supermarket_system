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

    // ������Ա����
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
    void write(vector<Goods> &goods);          // ����һ��Goods���飬�����鸲�Ǵ洢���ļ���

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

    void receipt();
    void data();

};

#endif //SUPERMARKET_SYSTEM_HEAD_H

//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// ���ڰ�������ͷ�ļ�������
#include "vector"
#include "login/WelcomePage.h"
#include "string"

// ����ȫ�ֺ���
// Ŀ����Ϊ�˱����ظ�������

bool isDigitStr(string s); // ���ڼ�鴫����ַ����Ƿ�ȫ��Ϊ���֣�������򷵻�true
int strTurnNum(string s); // ���ڽ��ַ���ת��Ϊ���ֵĺ���������ֵΪת���������
float strTurnFloatNum(string s); // ���ڽ��ַ���ת��ΪС���ĺ���

// ������
// �����û���Ϣ����
class Users{
public:
    string name;        // �û���ʵ����
    string id;          // �û�id
    string pwd;         // ����
    int level;          // �û�Ȩ��

    // ������Ա����
    void read(vector<Users> &users);
    void save(vector<Users> &users);

    void search(vector<Users> &users, string s, Users &find_user); // �����û�
    bool add(vector<Users> &users, Users new_user); // ����û�������ִ�а�ȫ��鲢���ڽ�ָ����users����������飬���û��Ѵ����򷵻�false
    void del(vector<Users> &users, string id);
    void edit(vector<Users> &users, int i, int kind, string new_value); // ָ�����޸ĵ�Ԫ�أ����ֵ࣬
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

    void search(vector<Goods> &goods, string s, Goods &find_goods); // ������Ʒ�����ҵ��Ͱ���Ʒ��Ϣ�����β�find_goods���Ҳ����ͽ����id����Ϊ-1
    void trade(vector<Goods> &goods);       // ���׺����������������������е��ã����ڿ۳����
    void edit(vector<Goods> &goods);        // ��Ʒ�༭���������ڱ༭��Ʒָ������
    void add(vector<Goods> &goods);         // ��Ʒ��Ӻ���
    void del(vector<Goods> &goods);         // ��Ʒɾ������

};

// �������ۼ�¼����
class Bills{
public:
    long long transactionID;    // ���ױ��
    string time;                // ����ʱ��
    int id;                     // ��Ʒ���
    string name;                // ��Ʒ����
    string species;             // ��Ʒ����
    float sellPrice;            // ��Ʒ����
    int quantity;               // ������Ʒ����
    float price;                // �����ܼ�
    float profit;               // ��������
    string measure;             // ��Ʒ�ļ�����λ

    // ������Ա����
    void read(vector<Bills> &bills);
    void save(vector<Bills> &bills);


    void receipt(vector<Bills> &bills);
    void data(vector<Bills> &bills);
    void newLog(vector<Bills> &bills);
};

// ����������ʾ��Ļ���ݵ���
class Display{
public:
    void loginPage();           // ��¼����
    void welcomePage();         // ��ӭ����

    void users_data();
    void goods_data(vector<Goods> &goods);           // ���е���Ʒ��Ϣչʾ

};

#endif //SUPERMARKET_SYSTEM_HEAD_H

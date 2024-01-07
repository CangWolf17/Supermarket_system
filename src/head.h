//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// ���ڰ�������ͷ�ļ�������
#include "fstream"
#include "iostream"
#include "algorithm"
#include "windows.h"
#include "sstream"
#include "vector"
#include "vector"
#include "login/WelcomePage.h"
#include "string"
#include "sysinfoapi.h"
#include "iomanip"

#define BLANKSPACE "   "

// ����ȫ�ֺ���
// Ŀ����Ϊ�˱����ظ�������

bool isDigitStr(string s);       // ���ڼ�鴫����ַ����Ƿ�ȫ��Ϊ���֣�������򷵻�true
int strTurnNum(string s);        // ���ڽ��ַ���ת��Ϊ���ֵĺ���������ֵΪת���������
inline void pause();             // ��ͣ��������ͣ�ڴ��ڲ���ʾ�����������
inline void cls();               // ��������

// ������
// �����û���Ϣ����
class Users {
public:
    string name; // �û���ʵ����
    string id;   // �û�id
    string pwd;  // ����
    int level;   // �û�Ȩ��

    // ������Ա����
    static void read(vector<Users> &users);
    static void save(vector<Users> &users);

    static void search(vector<Users> &users, string s, Users &find_user);      // �����û�
    static void add(vector<Users> &users, int level);                    // ����û�����
    static void del(vector<Users> &users, string userid);                      // ɾ���û�����Ҫ�����û�id
    static void pwdedit(vector<Users> &users, Users currentUser);              // �޸�����
    static void edit(vector<Users> &users, int i, int kind, string new_value); // ָ�����޸ĵ�Ԫ���±꣬���ֵ࣬
};

// �������ۼ�¼����
class Bills {
public:
    int transactionID; // ���ױ��
    SYSTEMTIME time;         // ����ʱ��
    int id;                  // ��Ʒ���
    string name;             // ��Ʒ����
    string species;          // ��Ʒ����
    float sellPrice;         // ��Ʒ����
    int quantity;            // ������Ʒ����
    float price;             // �����ܼ�
    float profit;            // ��������
    string measure;          // ��Ʒ�ļ�����λ

    // ������Ա����
    static void read(vector<Bills> &bills);
    static void save(vector<Bills> &bills);

    static void receipt(vector<Bills> market);
    static void data(vector<Bills> market,const Bills& bill, int pageNumber, const string& name, const string& species);
};

// �����������
class Goods {
public:
    int id;               // ��Ʒ���
    string name;          // ��Ʒ����
    string species;       // ��Ʒ����
    float purchasePrice;  // ��Ʒ����
    float sellPrice;      // ��Ʒ����
    int quantity;         // ��Ʒ����
    int lessLimit;        // ��Ʒ����������ֵ
    string measure;       // ��Ʒ�ļ�����λ
    string remark = "��"; // ��ע

    // ������Ա����
    static void read(vector<Goods> &goods); // ����һ��Goods���飬��ȡ�ļ��еĻ�����Ϣ����������
    static void save(vector<Goods> &goods); // ����һ��Goods���飬�����鸲�Ǵ洢���ļ���

    static void search(vector<Goods> &goods, string s, Goods &find_goods);
    // ������Ʒ�����ҵ��Ͱ���Ʒ��Ϣ�����β�find_goods���Ҳ����ͽ����id����Ϊ-1
    // �����string s��������ƷidҲ��������Ʒ��

    static void trade(vector<Bills> bills, vector<Goods> &goods,
        vector<Bills> &new_bills); // ���׺����������������������е��ã����ڿ۳����
    static void edit(vector<Goods> &goods, int i, int kind, string new_value); // ��Ʒ�༭���������ڱ༭��Ʒָ������
    static void add(vector<Goods> &goods); // ��Ʒ��Ӻ���
    static void del(vector<Goods> &goods); // ��Ʒɾ������

};

// ����������ʾ��Ļ���ݵ���
class Display {
public:
    void loginPage();   // ��¼����
    void welcomePage(); // ��ӭ����

    void customMenu(vector<Goods> &goods);                             // �˿Ͳ˵�����
    void customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice);
    void customGoodsData(vector<Goods> &goods, vector<Bills> &market); // �˿���ƷĿ¼
    void customSearch(vector<Goods> &goods, vector<Bills> &market);    // �˿�������Ʒ
    void customMarket(vector<Bills> market);                           // �˿͹��ﳵ


    void users_data();
    void goods_data(vector<Goods> &goods); // ���е���Ʒ��Ϣչʾ
};

#endif // SUPERMARKET_SYSTEM_HEAD_H

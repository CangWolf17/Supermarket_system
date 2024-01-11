//
// Created by calfVong on 2023/12/22.
//

#ifndef SUPERMARKET_SYSTEM_HEAD_H
#define SUPERMARKET_SYSTEM_HEAD_H

// ���ڰ�������ͷ�ļ�������
#include "fstream"
#include "iostream"
#include "map"
#include "ctime"
#include "windows.h"
#include "sstream"
#include "vector"
#include "login/WelcomePage.h"
#include "string"
#include "sysinfoapi.h"
#include "iomanip"
#include "algorithm"

#define BLANKSPACE "   "

// ����ȫ�ֺ���
// Ŀ����Ϊ�˱����ظ�������

bool isDigitStr(string s);       // ���ڼ�鴫����ַ����Ƿ�ȫ��Ϊ���֣�������򷵻�true
int strTurnNum(const string& s);        // ���ڽ��ַ���ת��Ϊ���ֵĺ���������ֵΪת���������
void pause();             // ��ͣ��������ͣ�ڴ��ڲ���ʾ�����������
void cls();               // ��������
void goto_xy(int x,int y);

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

    static void add(vector<Users> &users, int level);                    // ����û�����
    static void del(vector<Users> &users);                      // ɾ���û�����Ҫ�����û�id
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

    static void data(vector<Bills> &bills);

    static void analyzeSales(vector<Bills> &bills);
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

    // ������Ա����
    static void read(vector<Goods> &goods); // ����һ��Goods���飬��ȡ�ļ��еĻ�����Ϣ����������
    static void save(vector<Goods> &goods); // ����һ��Goods���飬�����鸲�Ǵ洢���ļ���

    static void search(vector<Goods> &goods, string s, Goods &find_goods);
    // ������Ʒ�����ҵ��Ͱ���Ʒ��Ϣ�����β�find_goods���Ҳ����ͽ����id����Ϊ-1
    // �����string s��������ƷidҲ��������Ʒ��

    static void trade(vector<Bills> &bills, vector<Goods> &goods,
                      vector<Bills> &new_bills); // ���׺����������������������е��ã����ڿ۳����
    static void edit(vector<Goods> &goods, int i, int kind, string new_value); // ��Ʒ�༭���������ڱ༭��Ʒָ������
    static void add(vector<Goods> &goods); // ��Ʒ��Ӻ���
    static void del(vector<Goods> &goods); // ��Ʒɾ������

};

// ����������ʾ��Ļ���ݵ���
class Display {
public:
    static void loginPage();   // ��¼����
    static void welcomePage(Users user); // ��ӭ����

    static void customMenu();                             // �˿Ͳ˵�����
    static void customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice);

    static bool customMarketEdit(vector<Goods> &goods, vector<Bills> &market, int goodsChoice); // ���ﳵ��Ʒ�༭
    static void customGoodsData(vector<Goods> &goods, vector<Bills> &market); // �˿���ƷĿ¼
    static void customSearch(vector<Goods> &goods, vector<Bills> &market);    // �˿�������Ʒ
    static void customMarket(vector<Bills> &market);                           // �˿͹��ﳵ

    static void keeperMenu();

    static void keeperSearch(vector<Goods> &goods);

    static void keeperLimit(vector<Goods> &goods);

    static void cashierMenu();

    static void cashierMarket(vector<Bills> &market);

    static void cashierTrade(vector<Goods> &goods, vector<Bills> &market);

    static void goods_data(vector<Goods> &goods); // ���е���Ʒ��Ϣչʾ
    static void goods_edit(vector<Goods> &goods); // ��Ʒ�༭

    static void adminMenu(); // ����Ա�ܲ˵�
    static void adminUsers(vector<Users> &users, Users user); // �û��˵�
    static void adminGoodsMenu(); // ����˵�
};

#endif // SUPERMARKET_SYSTEM_HEAD_H

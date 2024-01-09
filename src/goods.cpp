//
// Created by calfVong on 2023/12/27.
//

#include "head.h"

using namespace std;

void Goods::read(vector<Goods> &goods) {
    string fname = R"(.\data\goods.txt)"; // ָ���ļ���ַ
    ifstream txt_data(fname, ios::in);    // ���ļ�
    Goods new_goods = *new Goods;         // Ϊһ���µ�Goods�������ڴ�

    if (!txt_data.is_open()) {
        cout << "������Ϣ�ļ���ʧ�ܣ�";
        pause();
        exit(1);
    } else {
        while (!txt_data.eof()) {
            txt_data >> new_goods.id >> new_goods.name                           // ��ȡ��Ʒ�ı�ź�����
                     >> new_goods.species >> new_goods.purchasePrice                  // ��ȡ����ͽ���
                     >> new_goods.sellPrice >> new_goods.quantity                     // ��ȡ�ۼۺ�����
                     >> new_goods.lessLimit >> new_goods.measure; // ��ȡ������ֵ����λ�ͱ�ע
            // �Ӵ򿪵��ļ�����ν�������ṹ��
            goods.push_back(new_goods);
        }
    }
    txt_data.close();
}

void Goods::save(vector<Goods> &goods) {
    string fname = R"(.\data\goods.txt)"; // ָ���ļ���ַ
    ofstream txt_data(fname, ios::out);   // ���ļ�
    int i = 0;


    if (!txt_data.is_open()) {
        cout << "������Ϣ�ļ���ʧ�ܣ�";
        pause();
        exit(1);
    } else
        while (i < goods.size()) {
            if(i == 0){
                txt_data << goods[i].id << BLANKSPACE << goods[i].name << BLANKSPACE << goods[i].species << BLANKSPACE <<
                         goods[i].purchasePrice << BLANKSPACE << goods[i].sellPrice << BLANKSPACE << goods[i].quantity <<
                         BLANKSPACE << goods[i].lessLimit << BLANKSPACE << goods[i].measure;
            }
            else {

                txt_data << '\n' << goods[i].id << BLANKSPACE << goods[i].name << BLANKSPACE << goods[i].species
                         << BLANKSPACE << goods[i].purchasePrice
                         << BLANKSPACE << goods[i].sellPrice << BLANKSPACE
                         << goods[i].quantity  << BLANKSPACE
                         << goods[i].lessLimit << BLANKSPACE << goods[i].measure;
            }
            i++;
        }
    txt_data.close();
}


void Goods::search(vector<Goods> &goods, string s, Goods &find_goods) {
    int i = 0;

    if (isDigitStr(s)) { // �жϸ����ַ����Ƿ�Ϊ�����֣�����Ǵ�������Ϊ��Ʒid�����������Ϊ��Ʒ��
        int num = strTurnNum(s);

        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == num) {
                find_goods = goods[i];
                return;
            }

        find_goods.id = -1;
    } else {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].name == s) {
                find_goods = goods[i];
                return;
            }

        find_goods.id = -1;
    }
}

int simpleSreach(vector<Goods> &goods, int id) {
    int i;
    for (i = 0; i < goods.size(); i++)
        if (goods[i].id == id)
            return i;
    return 0;
}

void Goods::trade(vector<Bills> &bills, vector<Goods> &goods, vector<Bills> &new_bills) {
    int marketSize = new_bills.size();

    SYSTEMTIME tradeTime;
    GetLocalTime(&tradeTime);
    // ��ȡ����ʱ��

    int i;
    for (i = 0; i < marketSize; i++) {
        int index = simpleSreach(goods, bills[i].id);

        goods[index].quantity -= bills[i].quantity; // �۳����
        new_bills[i].time = tradeTime; // д�뽻��ʱ��
        new_bills[i].transactionID = bills.back().transactionID + 1;
        bills.push_back(new_bills[i]); // ���뽻��
    }
}

void Goods::edit(vector<Goods> &goods, int i, int kind, string new_value) {
    switch (kind) {
        case 1:
            goods[i].id = strTurnNum(new_value);
            break;
        case 2:
            goods[i].name = new_value;
            break;
        case 3:
            goods[i].species = new_value;
            break;
        case 4:
            goods[i].quantity = strTurnNum(new_value);
            break;
        case 5:
            goods[i].purchasePrice = stof(new_value);
            break;
        case 6:
            goods[i].sellPrice = stof(new_value);
            break;
        case 7:
            goods[i].measure = new_value;
            break;
        case 8:
            goods[i].lessLimit = strTurnNum(new_value);
            break;
    }
}

void Goods::add(vector<Goods> &goods) {
    cls();
    Goods newGoods = *new Goods; // �����µ� Goods ����
    cout << "����������Ʒ��Ϣ" << endl;
    cout << "��ţ�";
    cin >> newGoods.id;
    // ��ȫ���
    while (newGoods.id < 0) {
        cout << "���Ӧ����0�����������룺";
        cin >> newGoods.id;
    }
    cout << "���ƣ�";
    cin >> newGoods.name;
    // ��ȫ���
    for (auto &good: goods)
        if (good.id == newGoods.id || good.name == newGoods.name) {
            cout << "��Ż������ظ����������Ʒ�Ѵ��ڣ�";
            pause();
            return;
        }

    cout << "���ࣺ";
    cin >> newGoods.species;
    cout << "���ۣ�";
    cin >> newGoods.purchasePrice;
    cout << "�ۼۣ�";
    cin >> newGoods.sellPrice;
    cout << "��λ:";
    cin >> newGoods.measure;
    cout << "������";
    cin >> newGoods.quantity;
    cout << "������ֵ";
    cin >> newGoods.lessLimit;
    goods.push_back(newGoods); // ������Ʒ��ӵ���Ʒ�б���
    cout << "��ӳɹ���" << endl;
}

void Goods::del(vector<Goods> &goods) {
    int choice;
    cout << "��ѡ��Ҫɾ������Ʒ��" << endl;
    for (int i = 0; i < goods.size(); i++) {
        cout << i + 1 << ". " << goods[i].id << " - " << goods[i].name << endl;
    }
    // ��ȫ���
    cin >> choice;
    if (choice < 1 || choice > goods.size()) {
        cout << "��Ч��ѡ��" << endl;
        return;
    }

    int index = choice - 1;             // ��ȡѡ�����Ʒ������
    goods.erase(goods.begin() + index); // ɾ��ѡ�е���Ʒ
    cout << "ɾ���ɹ���" << endl;
}

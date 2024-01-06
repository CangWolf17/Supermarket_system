//
// Created by calfVong on 2023/12/27.
//

#include "fstream"
#include "iostream"
#include "vector"

#include "head.h"

#define BLANKSPACE "   "

using namespace std;

void Goods::read(vector<Goods> &goods){

    string fname = R"(.\data\goods.txt)"; // ָ���ļ���ַ
    ifstream txt_data(fname, ios::in); // ���ļ�
    Goods new_goods = *new Goods; // Ϊһ���µ�Goods�������ڴ�

    if(!txt_data.is_open()){
        cout << "�ļ���ʧ��";
        exit(1);
    }
    else{
        while(!txt_data.eof()){
            txt_data >> new_goods.id >> new_goods.name                                     // ��ȡ��Ʒ�ı�ź�����
                     >> new_goods.species >> new_goods.purchasePrice                           // ��ȡ����ͽ���
                     >> new_goods.sellPrice >> new_goods.quantity                              // ��ȡ�ۼۺ�����
                     >> new_goods.lessLimit >> new_goods.measure >> new_goods.remark;          // ��ȡ������ֵ����λ�ͱ�ע
            // �Ӵ򿪵��ļ�����ν�������ṹ��
            goods.push_back(new_goods);
        }
    }
    txt_data.close();
}

void Goods::save(vector<Goods> &goods) {

    string fname = R"(.\data\goods.txt)"; // ָ���ļ���ַ
    ofstream txt_data(fname, ios::out); // ���ļ�
    int i = 0;


    if (!txt_data.is_open()) {
        cout << "�ļ���ʧ��";
        exit(1);
    } else while(i<goods.size()-1){

            txt_data << goods[i].id << BLANKSPACE << goods[i].name << BLANKSPACE
                     << goods[i].species << BLANKSPACE << goods[i].purchasePrice << BLANKSPACE
                     << goods[i].sellPrice << BLANKSPACE << goods[i].quantity << BLANKSPACE
                     << goods[i].lessLimit << BLANKSPACE << goods[i].measure << BLANKSPACE
                     << goods[i].remark << '\n';
            i++;
        }
    txt_data.close();
}

void Goods::search(vector<Goods> &goods, string s, Goods &find_goods) {
    int i = 0;

    if(isDigitStr(s)) { //�жϸ����ַ����Ƿ�Ϊ�����֣�����Ǵ�������Ϊ��Ʒid�����������Ϊ��Ʒ��
        int num = strTurnNum(s);

        for(i=0;i<goods.size();i++)
            if(i == num) {
                find_goods = goods[i];
                return;
            }

        find_goods.id = -1;
    }
    else{
        for(i=0;i<goods.size();i++)
            if(goods[i].name == s) {
                find_goods = goods[i];
                return;
            }

        find_goods.id = -1;
    }
}

void Goods::trade(vector<Goods> &goods, Bills &new_bills) {



}

void Goods::edit() {


}

void Goods::add(vector<Goods> &goods) {
    Goods newGoods = *new Goods; // �����µ� Goods ����
    cout << "����������Ʒ�ı�š����ơ����ࡢ���ۡ��ۼۡ�������������ֵ����λ�ͱ�ע��" << endl;
    cin >> newGoods.id >> newGoods.name >> newGoods.species >>newGoods.purchasePrice
    >> newGoods.sellPrice >> newGoods.quantity >> newGoods.lessLimit >> newGoods.measure >> newGoods.remark; // ��ȡ�û��������Ʒ��Ϣ����������Ʒ������
    goods.push_back(newGoods); // ������Ʒ��ӵ���Ʒ�б���
    cout << "��ӳɹ���" << endl;
}

void Goods::del(vector<Goods> &goods) {
    int choice;
    cout << "��ѡ��Ҫɾ������Ʒ��" << endl;
    for (int i = 0; i < goods.size(); i++) {
        cout << i+1 << ". " << goods[i].id << " - " << goods[i].name << endl;
    }
    cin >> choice;
    if (choice < 1 || choice > goods.size()) {
        cout << "��Ч��ѡ��" << endl;
        return;
    }
    int index = choice - 1; // ��ȡѡ�����Ʒ������
    goods.erase(goods.begin() + index); // ɾ��ѡ�е���Ʒ
    cout << "ɾ���ɹ���" << endl;
}





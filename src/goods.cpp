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

void Goods::buy() {
    // ����display������ʾ�û�����
    cout<<"������Ҫ�������Ʒ�ı�Ż����ƣ�";

    // �����������

}

void Goods::search() {

}

void Goods::data() {

}

void Goods::add() {

}

void Goods::del() {

}

void Goods::addKind() {

}

void Goods::delKind() {

}

void Goods::sell() {

}



//
// Created by calfVong on 2023/12/28.
//
#include "iostream"
#include "fstream"

#include "head.h"

#define BLANKSPACE "   "

using namespace std;

void Bills::read(vector<Bills> &bills) {
    string fname = R"(.\data\bills.txt)"; // ִ���ļ�·������Ŀ�ļ����£������ļ�ָ����data��
    ifstream txt_data(fname, ios::in);
    Bills new_bill;

    if(!txt_data.is_open()){
        cout << "�ļ���ʧ��";
        exit(1);
    }
    else{
        while(!txt_data.eof()){
            txt_data >> new_bill.transactionID >> new_bill.time>> new_bill.id
            >> new_bill.name >> new_bill.species
            >> new_bill.sellPrice >> new_bill.quantity
            >> new_bill.price >> new_bill.profit >> new_bill.measure;
            bills.push_back(new_bill);
        }
    }
    txt_data.close();
}

void Bills::save(vector<Bills> &bills) {
    string fname = R"(.\data\bills.txt)"; // ָ���ļ���ַ
    ofstream txt_data(fname, ios::out); // ���ļ�
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "�ļ���ʧ��";
        exit(1);
    } else while(i<bills.size()-1) {
            txt_data << bills[i].transactionID << BLANKSPACE << bills[i].time << BLANKSPACE << bills[i].id
                     << BLANKSPACE << bills[i].name << BLANKSPACE << bills[i].species << BLANKSPACE
                     << bills[i].sellPrice << BLANKSPACE << bills[i].quantity << BLANKSPACE
                     << bills[i].price << BLANKSPACE << bills[i].profit
                     << BLANKSPACE << bills[i].measure << '\n';
            i++;
        }
    txt_data.close();
}

void Bills::receipt(vector<Bills> &bills){
    // ��ӡСƱ���߼�
    // ���ݵ�ǰ�����ۼ�¼�������Ӧ���������飬�������ױ��롢ʱ�䡢��š���Ʒ���ơ����ࡢ���ۡ���Ʒ�������ܼۡ�����ͼ�����λ��
    cout << "СƱ���ݣ�" << endl;
    cout << "���ױ���\tʱ��\t���\t��Ʒ����\t����\t����\t��Ʒ����\t�ܼ�\t����\t������λ" << endl;
    for (const auto& bill : bills) {
        cout << bill.transactionID << "\t"; // ���ױ���
        cout << bill.time << "\t"; // ʱ��
        cout << bill.id << "\t"; // ���
        cout << bill.name << "\t"; // ��Ʒ����
        cout << bill.species << "\t"; // ����
        cout << bill.sellPrice << "\t"; // ����
        cout << bill.quantity << "\t"; // ��Ʒ����
        cout << bill.sellPrice * bill.quantity << "\t"; // �ܼ�
        cout << bill.profit << "\t"; // ����
        cout << bill.measure; // ������λ
        cout << endl;
    }
}

void Bills::data(vector<Bills> &bills) {
    // ������ۼ�¼���߼�
    // ���ݴ洢�����ۼ�¼�����������¼����ϸ��Ϣ����������ID��ʱ�䡢��Ʒ���ơ����ۼ۸��
    cout << "���ۼ�¼��" << endl;
    for (const auto& bill : bills) {
        cout << "����ID��" << bill.transactionID << ", ʱ�䣺" << bill.time << ", ��Ʒ���ƣ�" << bill.name
             << ", ���ۼ۸�" << bill.sellPrice << endl;
    }
}

void Bills::newLog(vector<Bills> &bills){
// �������ۼ�¼���߼�
    // �����������Ʒ��Ϣ������һ���µ����ۼ�¼������ӵ��洢�����ۼ�¼��
    Bills newBill;
    cout << "�����뽻��ID��ʱ�䡢��Ʒ���ơ����ࡢ���ۼ۸����������ۡ��ۼۺͱ�ע��" << endl;
    cin >> newBill.transactionID >> newBill.time >> newBill.name >> newBill.species >> newBill.sellPrice >> newBill.quantity
        >> newBill.price >> newBill.profit >> newBill.measure;
    bills.push_back(newBill);
    cout << "�µ����ۼ�¼����ӡ�" << endl;
}
//
// Created by calfVong on 2023/12/28.
//
#include "iostream"
#include "fstream"

#include "head.h"

#define BLANKSPACE "   "

using namespace std;

void Bills::read(vector<Bills> &bills) {
    string fname = R"(.\data\bills.txt)"; // 执行文件路径在项目文件夹下，数据文件指定在data下
    ifstream txt_data(fname, ios::in);
    Bills new_bill;

    if(!txt_data.is_open()){
        cout << "文件打开失败";
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
    string fname = R"(.\data\bills.txt)"; // 指定文件地址
    ofstream txt_data(fname, ios::out); // 打开文件
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "文件打开失败";
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
    // 打印小票的逻辑
    // 根据当前的销售记录，输出对应的销售详情，包括交易编码、时间、编号、商品名称、种类、单价、商品数量、总价、利润和计量单位等
    cout << "小票内容：" << endl;
    cout << "交易编码\t时间\t编号\t商品名称\t种类\t单价\t商品数量\t总价\t利润\t计量单位" << endl;
    for (const auto& bill : bills) {
        cout << bill.transactionID << "\t"; // 交易编码
        cout << bill.time << "\t"; // 时间
        cout << bill.id << "\t"; // 编号
        cout << bill.name << "\t"; // 商品名称
        cout << bill.species << "\t"; // 种类
        cout << bill.sellPrice << "\t"; // 单价
        cout << bill.quantity << "\t"; // 商品数量
        cout << bill.sellPrice * bill.quantity << "\t"; // 总价
        cout << bill.profit << "\t"; // 利润
        cout << bill.measure; // 计量单位
        cout << endl;
    }
}

void Bills::data(vector<Bills> &bills) {
    // 输出销售记录的逻辑
    // 根据存储的销售记录，逐条输出记录的详细信息，包括交易ID、时间、商品名称、销售价格等
    cout << "销售记录：" << endl;
    for (const auto& bill : bills) {
        cout << "交易ID：" << bill.transactionID << ", 时间：" << bill.time << ", 商品名称：" << bill.name
             << ", 销售价格：" << bill.sellPrice << endl;
    }
}

void Bills::newLog(vector<Bills> &bills){
// 新增销售记录的逻辑
    // 根据输入的商品信息，创建一个新的销售记录，并添加到存储的销售记录中
    Bills newBill;
    cout << "请输入交易ID、时间、商品名称、种类、销售价格、数量、进价、售价和备注：" << endl;
    cin >> newBill.transactionID >> newBill.time >> newBill.name >> newBill.species >> newBill.sellPrice >> newBill.quantity
        >> newBill.price >> newBill.profit >> newBill.measure;
    bills.push_back(newBill);
    cout << "新的销售记录已添加。" << endl;
}
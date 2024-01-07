//
// Created by calfVong on 2023/12/28.
//

#include "head.h"

using namespace std;

void Bills::read(vector<Bills> &bills) {
    string fname = R"(.\data\bills.txt)"; // 执行文件路径在项目文件夹下，数据文件指定在data下
    ifstream txt_data(fname, ios::in);
    Bills new_bill;

    if(!txt_data.is_open()){
        cout << "账单信息文件打开失败！";
        pause();
        exit(1);
    }
    else{
        while(!txt_data.eof()){
            txt_data >> new_bill.transactionID >> 
            new_bill.time.wYear >> new_bill.time.wMonth >> new_bill.time.wDay
            >> new_bill.time.wHour >> new_bill.time.wMinute
            >> new_bill.id >> new_bill.name >> new_bill.species
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
        cout << "账单信息文件打开失败！";
        pause();
        exit(1);
    } else while(i<bills.size()-1) {
            txt_data << bills[i].transactionID << BLANKSPACE
            << bills[i].time.wYear << BLANKSPACE << bills[i].time.wMonth << BLANKSPACE << bills[i].time.wDay
            << BLANKSPACE << bills[i].time.wHour << BLANKSPACE << bills[i].time.wMinute 
            << BLANKSPACE << bills[i].id
                     << BLANKSPACE << bills[i].name << BLANKSPACE << bills[i].species << BLANKSPACE
                     << bills[i].sellPrice << BLANKSPACE << bills[i].quantity << BLANKSPACE
                     << bills[i].price << BLANKSPACE << bills[i].profit
                     << BLANKSPACE << bills[i].measure << '\n';
            i++;
        }
    txt_data.close();
}


void Bills::receipt(vector<Bills> market){
    int i, size = market.size();

    // cout 菜单头
    cout<<"小票：";
    for(i=0;i<size;i++)
        cout<<market[i].id<<BLANKSPACE<<market[i].name<<BLANKSPACE
        <<market[i].sellPrice<<BLANKSPACE<<market[i].quantity<<market[i].measure
        <<BLANKSPACE<<market[i].price<<endl;
    cout<<"交易时间："<<market[0].time.wYear<<"/"<<market[0].time.wMonth<<"/"<<market[0].time.wDay<<" "
    <<market[0].time.wHour<<":"<<market[0].time.wMinute<<endl;
}

// 销售数据的函数还没写
void Bills::data() {

}




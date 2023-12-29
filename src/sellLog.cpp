//
// Created by calfVong on 2023/12/28.
//
#include "iostream"
#include "fstream"

#include "head.h"

#define BLANKSPACE "   "

using namespace std;

void SellLog::read(vector<SellLog> &sellLogs) {
    string fname = R"(.\data\sellLogs.txt)"; // 执行文件路径在项目文件夹下，数据文件指定在data下
    ifstream txt_data(fname, ios::in);
    SellLog new_sellLog;

    if(!txt_data.is_open()){
        cout << "文件打开失败";
        exit(1);
    }
    else{
        while(!txt_data.eof()){
            txt_data >> new_sellLog.transactionID >> new_sellLog.id
            >> new_sellLog.name >> new_sellLog.species
            >> new_sellLog.sellPrice >> new_sellLog.quantity
            >> new_sellLog.price >> new_sellLog.measure;
            sellLogs.push_back(new_sellLog);
        }
    }
    txt_data.close();
}

void SellLog::save(vector<SellLog> &sellLogs) {
    string fname = R"(.\data\users.txt)"; // 指定文件地址
    ofstream txt_data(fname, ios::out); // 打开文件
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "文件打开失败";
        exit(1);
    } else while(i<sellLogs.size()-1){
            txt_data << sellLogs[i].transactionID << BLANKSPACE << sellLogs[i].id << BLANKSPACE
                     << sellLogs[i].name << BLANKSPACE << sellLogs[i].species << BLANKSPACE
                    << sellLogs[i].sellPrice << BLANKSPACE << sellLogs[i].quantity << BLANKSPACE
                    << sellLogs[i].price << BLANKSPACE << sellLogs[i].measure << '\n';
            i++;
        }
    txt_data.close();
}

void SellLog::receipt(){

}

void SellLog::data() {

}

void SellLog::newLog(){

}




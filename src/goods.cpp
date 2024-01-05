//
// Created by calfVong on 2023/12/27.
//

#include "head.h"

using namespace std;

void Goods::read(vector<Goods> &goods){

    string fname = R"(.\data\goods.txt)"; // 指定文件地址
    ifstream txt_data(fname, ios::in); // 打开文件
    Goods new_goods = *new Goods; // 为一个新的Goods类申请内存

    if(!txt_data.is_open()){
        cout << "文件打开失败";
        exit(1);
    }
    else{
        while(!txt_data.eof()){
            txt_data >> new_goods.id >> new_goods.name                                     // 获取商品的编号和名称
                     >> new_goods.species >> new_goods.purchasePrice                           // 获取种类和进价
                     >> new_goods.sellPrice >> new_goods.quantity                              // 获取售价和数量
                     >> new_goods.lessLimit >> new_goods.measure >> new_goods.remark;          // 获取提醒阈值、单位和备注
            // 从打开的文件中逐次将流存入结构体
            goods.push_back(new_goods);
        }
    }
    txt_data.close();
}

void Goods::save(vector<Goods> &goods) {

    string fname = R"(.\data\goods.txt)"; // 指定文件地址
    ofstream txt_data(fname, ios::out); // 打开文件
    int i = 0;


    if (!txt_data.is_open()) {
        cout << "文件打开失败";
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

    if(isDigitStr(s)) { //判断给定字符串是否为纯数字，如果是纯数字则为商品id，如果不是则为商品名
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

void Goods::trade(vector<Bills> bills, vector<Goods> &goods, vector<Bills> &new_bills) {
    int marketSize = new_bills.size();

    SYSTEMTIME tradetime;
    GetLocalTime(&tradetime);
    // 获取交易时间

    int i;
    for(i=0;i<marketSize;i++) {
        new_bills[i].time = tradetime; // 写入交易时间
        bills.push_back(new_bills[i]); // 推入交易
    }

}

void Goods::edit() {


}

void Goods::add() {

}

void Goods::del() {

}





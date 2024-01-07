//
// Created by calfVong on 2023/12/28.
//

#include "head.h"
#include "algorithm"

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
        cout << "文件打开失败";
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

// 销售数据的函数
void Bills::data(vector<Bills> market,const Bills& bill, int pageNumber, const string& name, const string& species) {

    // 每页显示的销售记录数量
    int pageSize = 10;

    // 计算起始和结束
    int startIndex = (pageNumber - 1) * pageSize;
    int endIndex = pageNumber * pageSize;

    // 遍历指定范围内的销售记录
    for (int i = startIndex; i < endIndex && i < market.size(); i++) {
        // 打印当前销售记录的信息
        cout << " 交易编号: " << market[i].transactionID ;
        cout << " 时间: " << market[i].time.wYear << "/" << market[i].time.wMonth << "/" << market[i].time.wDay << " "
             << market[i].time.wHour << ":" << market[i].time.wMinute ;
        cout << " 商品编号: " << market[i].id ;
        cout << " 商品名称: " << market[i].name ;
        cout << " 商品种类: " << market[i].species ;
        cout << " 商品单价: " << market[i].sellPrice ;
        cout << " 交易数量: " << market[i].quantity ;
        cout << " 计量单位: " << market[i].measure ;
        cout << " 交易总价: " << market[i].price ;
        cout << " 交易利润: " << market[i].profit ;
        cout << endl; // 便于区分每条销售数据
    }
    // 显示管理员销售记录的界面
    cout << "其他选项：" << endl;
    cout << "1. 按类别查看" << endl;
    cout << "2. 按商品名称查看" << endl;
    cout << "0. 退出" << endl;

    int choice = 1;
    cin >> choice;
    switch (choice) {

        case 1: {   //按类别
            for (int i = startIndex; i < endIndex && i < market.size(); i++) {
                // 检查商品种类是否符合条件
                if (market[i].species == species) {
                    // 打印当前销售记录的信息
                    cout << " 交易编号: " << market[i].transactionID ;
                    cout << " 时间: " << market[i].time.wYear << "/" << market[i].time.wMonth << "/" << market[i].time.wDay << " "
                         << market[i].time.wHour << ":" << market[i].time.wMinute ;
                    cout << " 商品编号: " << market[i].id ;
                    cout << " 商品名称: " << market[i].name ;
                    cout << " 商品种类: " << market[i].species ;
                    cout << " 商品单价: " << market[i].sellPrice ;
                    cout << " 交易数量: " << market[i].quantity ;
                    cout << " 计量单位: " << market[i].measure ;
                    cout << " 交易总价: " << market[i].price ;
                    cout << " 交易利润: " << market[i].profit ;
                    cout << endl; // 便于区分每条销售数据
                }
            }
            break;
        }
        case 2: {   //按名称
            for (int i = startIndex; i < endIndex && i < market.size(); i++) {
                // 检查商品种类是否符合条件
                if (market[i].name == name) {
                    // 打印当前销售记录的信息
                    cout << " 交易编号: " << market[i].transactionID ;
                    cout << " 时间: " << market[i].time.wYear << "/" << market[i].time.wMonth << "/" << market[i].time.wDay << " "
                         << market[i].time.wHour << ":" << market[i].time.wMinute ;
                    cout << " 商品编号: " << market[i].id ;
                    cout << " 商品名称: " << market[i].name ;
                    cout << " 商品种类: " << market[i].species ;
                    cout << " 商品单价: " << market[i].sellPrice ;
                    cout << " 交易数量: " << market[i].quantity ;
                    cout << " 计量单位: " << market[i].measure ;
                    cout << " 交易总价: " << market[i].price ;
                    cout << " 交易利润: " << market[i].profit ;
                    cout << endl; // 便于区分每条销售数据
                }
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "请输入有效值！ ";
            return;

    }
}
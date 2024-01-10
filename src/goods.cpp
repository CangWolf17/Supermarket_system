//
// Created by calfVong on 2023/12/27.
//

#include "head.h"

using namespace std;

void Goods::read(vector<Goods> &goods) {
    string fname = R"(.\data\goods.txt)"; // 指定文件地址
    ifstream txt_data(fname, ios::in);    // 打开文件
    Goods new_goods = *new Goods;         // 为一个新的Goods类申请内存

    if (!txt_data.is_open()) {
        cout << "货物信息文件打开失败！";
        pause();
        exit(1);
    } else {
        while (!txt_data.eof()) {
            txt_data >> new_goods.id >> new_goods.name                           // 获取商品的编号和名称
                     >> new_goods.species >> new_goods.purchasePrice                  // 获取种类和进价
                     >> new_goods.sellPrice >> new_goods.quantity                     // 获取售价和数量
                     >> new_goods.lessLimit >> new_goods.measure; // 获取提醒阈值、单位和备注
            // 从打开的文件中逐次将流存入结构体
            goods.push_back(new_goods);
        }
    }
    txt_data.close();
}

void Goods::save(vector<Goods> &goods) {
    string fname = R"(.\data\goods.txt)"; // 指定文件地址
    ofstream txt_data(fname, ios::out);   // 打开文件
    int i = 0;


    if (!txt_data.is_open()) {
        cout << "货物信息文件打开失败！";
        pause();
        exit(1);
    } else
        while (i < goods.size()) {
            if (i == 0) {
                txt_data << goods[i].id << BLANKSPACE << goods[i].name << BLANKSPACE << goods[i].species << BLANKSPACE
                         <<
                         goods[i].purchasePrice << BLANKSPACE << goods[i].sellPrice << BLANKSPACE << goods[i].quantity
                         <<
                         BLANKSPACE << goods[i].lessLimit << BLANKSPACE << goods[i].measure;
            } else {

                txt_data << '\n' << goods[i].id << BLANKSPACE << goods[i].name << BLANKSPACE << goods[i].species
                         << BLANKSPACE << goods[i].purchasePrice
                         << BLANKSPACE << goods[i].sellPrice << BLANKSPACE
                         << goods[i].quantity << BLANKSPACE
                         << goods[i].lessLimit << BLANKSPACE << goods[i].measure;
            }
            i++;
        }
    txt_data.close();
}


void Goods::search(vector<Goods> &goods, string s, Goods &find_goods) {
    int i;

    if (isDigitStr(s)) { // 判断给定字符串是否为纯数字，如果是纯数字则为商品id，如果不是则为商品名
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
    // 获取交易时间

    int i;
    for (i = 0; i < marketSize; i++) {
        int index = simpleSreach(goods, bills[i].id);

        goods[index].quantity -= bills[i].quantity; // 扣除库存
        new_bills[i].time = tradeTime; // 写入交易时间
        new_bills[i].transactionID = bills.back().transactionID + 1;
        bills.push_back(new_bills[i]); // 推入交易
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
    Goods newGoods = *new Goods; // 创建新的 Goods 对象
    goto_xy(10,10);
    cout << "请输入新商品信息" << endl;
    goto_xy(10,11);
    cout << "编号：";
    cin >> newGoods.id;
    // 安全检查
    while (newGoods.id < 0) {
        goto_xy(10,11);
        cout << "编号应大于0，请重新输入：";
        cin >> newGoods.id;
    }
    goto_xy(10,12);
    cout << "名称：";
    cin >> newGoods.name;
    // 安全检查
    for (auto &good: goods)
        if (good.id == newGoods.id || good.name == newGoods.name) {
            goto_xy(10,12);
            cout << "编号或名称重复，所添加商品已存在！";
            pause();
            return;
        }

    goto_xy(10,13);
    cout << "种类：";
    cin >> newGoods.species;
    goto_xy(10,14);
    cout << "进价：";
    cin >> newGoods.purchasePrice;
    goto_xy(10,15);;
    cout << "售价：";
    cin >> newGoods.sellPrice;
    goto_xy(10,16);
    cout << "单位:";
    cin >> newGoods.measure;
    goto_xy(10,17);
    cout << "数量：";
    cin >> newGoods.quantity;
    goto_xy(10,18);
    cout << "提醒阈值: ";
    cin >> newGoods.lessLimit;
    goods.push_back(newGoods); // 将新商品添加到商品列表中
    goto_xy(10,19);
    cout << "添加成功！";
    goto_xy(10,20);
    pause();
}

void Goods::del(vector<Goods> &goods) {
    cls();
    int choice;
    goto_xy(10,9);
    cout << "请选择要删除的商品：" << endl;
    for (int i = 0; i < goods.size(); i++) {
        goto_xy(10,10+i);
        cout << i + 1 << ". " << goods[i].id << " - " << goods[i].name << endl;
    }
    // 安全检查
    goto_xy(30,9);
    cin >> choice;
    if (choice < 1 || choice > goods.size()) {
        goto_xy(10,18);
        cout << "无效的选择！" << endl;
        return;
    }

    int index = choice - 1;             // 获取选择的商品的索引
    goods.erase(goods.begin() + index); // 删除选中的商品
    goto_xy(10,18);
    cout << "删除成功！" << endl;
}

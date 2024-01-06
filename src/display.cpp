//
// Created by calfVong on 2023/12/28.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>

#include "head.h"

using namespace std;

void Display::loginPage(){ // 登录界面
    // 登录页面，未设计


}

void Display::welcomePage() {




}

void Display::users_data() {

}

void Display::goods_data(vector<Goods> &goods) {
    // 界面未设计

    static int i = 0;


    for (i; i < goods.size() - 1; i++) {
        cout << goods[i].id << "   " << goods[i].name << "   " << goods[i].species
             << "   " << goods[i].sellPrice << "   " << goods[i].quantity << endl;
    }
}

void Display::customMenu(vector<Goods> &goods) {
    system("cls");
    // 添加代码以显示顾客菜单界面
    cout << "菜单选项：" << endl;
    cout << "1. 商品目录" << endl;
    cout << "2. 搜索商品" << endl;
    cout << "3. " << endl;
    cout << "4. " << endl;
    cout << "5. " << endl;
    cout << "0. " << endl;
}

void customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market) {
    char buy_choice;
    cout << "是否确认加入购物车？（请输入y/n）：";
    cin >> buy_choice;
    if (buy_choice == 'y') {
        Bills new_bills;
        cout << "数量";
        cin >> new_bills.quantity;
        // 对顾客输入的商品数量进行检查
        for (const auto& bill : market) {
            if (bill.quantity <= 0) {
                cout << "商品数量不能为负数或零。" << endl;
                return;
            }
        }
        // 检查商品数量是否超过了库存
        for (const auto& bill : market) {
            int i=0;
            if (bill.quantity > 0) {
                    if (bill.quantity > goods[i].lessLimit) {
                        cout << "购物车中的商品数量超过了库存。" << endl;
                        return;
                    }
            }
        }
        // 产生销售记录
        new_bills.id = buy_goods.id;
        new_bills.name = buy_goods.name;
        new_bills.species = buy_goods.species;
        new_bills.sellPrice = buy_goods.sellPrice;
        new_bills.quantity = buy_goods.quantity;
        new_bills.price = new_bills.sellPrice * new_bills.quantity;  // 计算总价
        new_bills.measure = "件";

        // 销售记录推入购物车
        market.push_back(new_bills);
        std::cout << "购买成功！" << std::endl;
    }
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    // 输出商品内容
    // 添加代码以显示顾客商品目录
    cout << "以下是所有商品目录：" << endl;
    for (const auto& goods : goods) {
        cout << goods.id << "   " << goods.name<<"   "<< goods.species<< "   " << goods.sellPrice
        <<"   "<< goods.quantity << "   " << goods.lessLimit<<"   "<< goods.measure<< "   " << goods.remark<< endl;
    }//未包含“商品进价”
    cout<<" ";
    // 输入购买商品编号
    int id;
    cin>>id;
    Goods buy_goods = goods[id];
    customTrade(buy_goods,goods,market);
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {

    string s;
    Goods find_goods;
    // 询问客户要搜索的内容
    cout << "请输入要搜索的商品名称：";
    cout<<" ";
    cin>>s;
    Goods::search(goods,s,find_goods);
    if(find_goods.id != -1){
        customTrade(find_goods,goods, market);
    }else{
        cout<<"找到的商品不存在！";
    }

}




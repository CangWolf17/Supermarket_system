//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage() { // 登录界面
    // 登录页面，未设计
}

void Display::welcomePage() {
    system("cls");
    system("title 欢迎使用超市管理系统");
    system("color 0C");
    cout << endl;
    system("pause");

}

void Display::customMenu() {
    cls();
    system("title customer");
    // 添加代码以显示顾客菜单界面
    cout << "菜单选项：" << endl;
    cout << "1. 商品目录" << endl;
    cout << "2. 搜索商品" << endl;
    cout << "3. 购物车" << endl;
    cout << "4. 结算" << endl;
    cout << "5. 修改密码" << endl;
    cout << "0. 退出" << endl;
}
void Display::customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice) {
    if (buy_choice == 'y') {
        Bills new_bills;
        cout << "请输入购买数量：";
        cin >> new_bills.quantity;
        // 对顾客输入的商品数量进行检查
        for (const auto &bill: market) {
            if (bill.quantity <= 0) {
                cout << "商品数量不能为负数或零。" << endl;
                return;
            }
        }
        // 检查商品数量是否超过了库存
        for (const auto &bill: market) {
            int i = 0;
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
        new_bills.measure = buy_goods.measure;


        // 销售记录推入购物车
        market.push_back(new_bills);
        std::cout << "购买成功！" << std::endl;
    }
}
void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    cls();

    int j = 1;
    // 添加代码以显示顾客商品目录
    cout << "以下是所有商品目录：" << endl;
    for (const auto &tmp_goods: goods) {
        cout << j++ << ".商品编号：" << tmp_goods.id << " 名称：" << tmp_goods.name
             << " 种类：" << tmp_goods.species << " 价格：" << tmp_goods.sellPrice << "/" << tmp_goods.measure
             << " 数量：" << tmp_goods.quantity << endl;
    } // 未包含“商品进价”、“阈值提醒”和“备注”

    cout << "请输入要购买的商品编号（无则请输入0）：";
    // 输入购买商品编号
    int id, i;
    cin >> id;
    if (id != 0)
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;

    Goods buy_goods = goods[i];
    char buy_choice;
    cout << "是否确认加入购物车？（请输入y/n）：";
    cin >> buy_choice;
    customTrade(buy_goods, goods, market, buy_choice);
}
void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {
    cls();
    string s;
    Goods find_goods;

    // 询问客户要搜索的内容
    cout << "请输入要搜索的商品名称或编号：";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        char buy_choice;
        cout << "是否确认加入购物车？（请输入y/n）：";
        cin >> buy_choice;
        customTrade(find_goods, goods, market, buy_choice);
    } else {
        cout << "查找的商品不存在！即将返回上一级...";
        pause();
    }
}
void Display::customMarket(vector<Bills> market) {
    cls();
    int j=1;
    cout << "您的购物车内容：" << endl;
    for (const auto &bill: market) {
        cout << j++ << ". 商品名称: " << bill.name << ", 数量: " << bill.quantity << ", 单价: "
             << bill.sellPrice << "/" << bill.measure << ", 总价: " << bill.price << endl;
    }
}

void Display::keeperMenu() {
    system("title cashier");
    cout<<"1.库存详情"<<endl;
    cout<<"2.搜索商品"<<endl;
    cout<<"3.编辑商品"<<endl;
    cout<<"4.添加商品"<<endl;
    cout<<"5.删除商品"<<endl;
    cout<<"6.修改密码"<<endl;
    cout<<"0.退出"<<endl;
}
void Display::keeperSearch(vector<Goods> &goods) {
    cls();
    string s;
    Goods find_goods;

    // 询问客户要搜索的内容
    cout << "请输入要搜索的商品名称或编号：";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        cout << "     编号     名称     种类     数量     进价     售价     单位     提醒阈值"<<endl;
        cout << setw(5)<< find_goods.id << setw(9) << find_goods.name
             << setw(9) << find_goods.species << setw(9) << find_goods.quantity
             << setw(9) << find_goods.purchasePrice  << setw(9) << find_goods.sellPrice
             << setw(9) << find_goods.measure << setw(9) << find_goods.lessLimit << endl;
        pause();
    } else {
        cout << "查找的商品不存在！即将返回上一级...";
        pause();
    }
}
void Display::keeperLimit(vector<Goods> &goods) {
    int j = 1;
    for(auto & igoods : goods){
        if(igoods.quantity <= igoods.lessLimit){
            cout << j++ << ".商品 " << igoods.name << " (编号 " << igoods.id << " ）" << "数量低于设置阈值（"
                 << igoods.lessLimit << "），当前库存为：" << igoods.quantity << "，请及时补货。" << endl;
        }
    }
}

void Display::cashierMenu() {
    cout<<"1.销售商品"<<endl;
    cout<<"2.购物结算"<<endl;
    cout<<"3.查看记录"<<endl;
    cout<<"4.修改密码"<<endl;
    cout<<"0.退出"<<endl;
}
void Display::cashierMarket(vector<Bills> &market) {
        cls();
        int j=1;
        cout << "购物车中的内容：" << endl;
        for (const auto &bill: market) {
            cout << j++ << ". 商品名称: " << bill.name << ", 数量: " << bill.quantity << ", 单价: "
                 << bill.sellPrice << "/" << bill.measure << ", 总价: " << bill.price << endl;
        }
}
void cashierTrade(vector<Goods> &goods, vector<Bills> market) {

    int j = 1;
    // 添加代码以显示顾客商品目录
    cout << "以下是所有商品目录：" << endl;
    for (const auto &tmp_goods: goods) {
        cout << j++ << ".商品编号：" << tmp_goods.id << " 名称：" << tmp_goods.name
             << " 种类：" << tmp_goods.species << " 价格：" << tmp_goods.sellPrice << "/" << tmp_goods.measure
             << " 数量：" << tmp_goods.quantity << endl;
    } // 未包含“商品进价”、“阈值提醒”和“备注”


    cout << "请输入要销售的商品编号（无则请输入0）：";
    // 输入购买商品编号
    int id, i;
    cin >> id;
    if (id != 0)
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;

    Goods buy_goods = goods[i];
    char buy_choice;
    cout << "是否确认加入购物车？（请输入y/n）：";
    cin >> buy_choice;
    if (buy_choice == 'y') {
        Bills new_bills;
        cout << "请输入购买数量：";
        cin >> new_bills.quantity;
        // 对顾客输入的商品数量进行检查
        for (const auto &bill: market) {
            if (bill.quantity <= 0) {
                cout << "商品数量不能为负数或零。" << endl;
                return;
            }
        }
        // 检查商品数量是否超过了库存
        for (const auto &bill: market) {
            int i = 0;
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
        new_bills.measure = buy_goods.measure;


        // 销售记录推入购物车
        market.push_back(new_bills);
        std::cout << "购买成功！" << std::endl;
    }
}

void Display::users_data() {


}

void Display::goods_data(vector<Goods> &goods) {
    // 界面未设计
    cout << "商品列表如下，输入0：退出";

    int i;

    cout << "     编号     名称     种类     数量     进价     售价     单位     提醒阈值"<<endl;
    for (i = 0; i < goods.size(); i++) {
        cout << setw(5)<< goods[i].id << setw(9) << goods[i].name
             << setw(9) << goods[i].species << setw(9) << goods[i].quantity
             << setw(9) << goods[i].purchasePrice  << setw(9) << goods[i].sellPrice
             << setw(9) << goods[i].measure << setw(9) << goods[i].lessLimit << endl;
    }
}

void Display::goods_edit(vector<Goods> &goods) {
    cls();

    string s;
    Goods find_goods;

    cout << "请输入要修改的商品名称或编号：";
    cin >> s;
    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        cout << "   1.编号   2.名称   3.种类   4.数量   5.进价   6.售价   7.单位   8.提醒阈值"<<endl;
        cout << setw(5)<< find_goods.id << setw(9) << find_goods.name
             << setw(9) << find_goods.species << setw(9) << find_goods.quantity
             << setw(9) << find_goods.purchasePrice  << setw(9) << find_goods.sellPrice
             << setw(9) << find_goods.measure << setw(9) << find_goods.lessLimit << endl;
        pause();
    } else {
        cout << "要修改的商品不存在！即将返回上一级...";
        pause();
        return;
    }

    cout<< "请指定要修改的商品信息对应的数字：";
    int kind;
    cin >> kind;
    
    // 安全检查
    if(kind>=1&&kind<=8){
        int i;
        for(i=0;i<goods.size();i++)
            if(find_goods.id == goods[i].id)
                break;
        string new_value;
        cout<<"请输入新的商品信息：";
        cin >> new_value; // 输入数据的安全检查没做
        Goods::edit(goods,i,kind,new_value);
        cls();
        cout<<"修改完成，结果如下："<<endl;
        cout << "     编号     名称     种类     数量     进价     售价     单位     提醒阈值"<<endl;
        cout << setw(5)<< goods[i].id << setw(9) << goods[i].name
             << setw(9) << goods[i].species << setw(9) << goods[i].quantity
             << setw(9) << goods[i].purchasePrice  << setw(9) << goods[i].sellPrice
             << setw(9) << goods[i].measure << setw(9) << goods[i].lessLimit << endl;
        pause();
        return;
    } else{
        cout<<"输入数字无效，程序即将返回...";
        pause();
        return;
    }
    

}




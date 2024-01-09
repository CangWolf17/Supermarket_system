//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage() { // ��¼����
    // ��¼ҳ�棬δ���
}

void Display::welcomePage(Users user) {
    system("cls");
    system("title ��ӭʹ�ó��й���ϵͳ");
    system("color 0C");
    cout << endl;
    system("pause");

}

void Display::customMenu() {
    cls();
    system("title customer");
    // ��Ӵ�������ʾ�˿Ͳ˵�����
    cout << "�˵�ѡ�" << endl;
    cout << "1. ��ƷĿ¼" << endl;
    cout << "2. ������Ʒ" << endl;
    cout << "3. ���ﳵ" << endl;
    cout << "4. ����" << endl;
    cout << "5. �޸�����" << endl;
    cout << "0. �˳�" << endl;
}

bool Display::customMarketEdit(vector<Goods> &goods, vector<Bills> &market, int goodsChoice) {
    for (int i = 0; i < market.size(); i++) {
        if (market[i].id == goodsChoice) {
            market.erase(market.begin() + i); // ֱ��ɾ�������´���

            // �������¹������Ʒ
            Goods buy_goods;
            buy_goods.id = goodsChoice;

            // ����Ʒ�����ȡ��Ϣ
            for (int j = 0; j < goods.size(); j++)
                if (goods[j].id == buy_goods.id)
                    buy_goods = goods[j];

            // ���뽻�׺���
            Display::customTrade(buy_goods, goods, market, 'y');
            return true;
        }
    }
}

void Display::customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice) {
    if (buy_choice == 'y') {
        for(auto & i : market)
            if(buy_goods.id == i.id) {
                cout << "��Ʒ�Ѵ��ڣ�������ת�޸�..." << endl;
                pause();
                Display::customMarketEdit(goods,market,i.id);
                return;
            }
        Bills new_bills;
        cout << "�����빺��������";
        cin >> new_bills.quantity;
        // �Թ˿��������Ʒ�������м��
        while (new_bills.quantity <= 0) {
            cout << "��Ʒ��������Ϊ�������㣬���������룺" << endl;
            cin >> new_bills.quantity;
        }
        // �����Ʒ�����Ƿ񳬹��˿��
        while (new_bills.quantity > buy_goods.quantity) {
            cout << "���ﳵ�е���Ʒ���������˿�棬���������룺" << endl;
            cin >> new_bills.quantity;
        }

        // �������ۼ�¼
        new_bills.id = buy_goods.id;
        new_bills.name = buy_goods.name;
        new_bills.species = buy_goods.species;
        new_bills.sellPrice = buy_goods.sellPrice;
        new_bills.price = new_bills.sellPrice * new_bills.quantity;  // �����ܼ�
        new_bills.measure = buy_goods.measure;


        // ���ۼ�¼���빺�ﳵ
        market.push_back(new_bills);
        std::cout << "��ӳɹ���" << std::endl;
    }
}

void customGoodsPrint(Goods tmp_goods){
    cout << setw(5) << tmp_goods.id << setw(12) << tmp_goods.name
         << setw(8) << tmp_goods.species << setw(8) << tmp_goods.quantity
         << setw(7) << tmp_goods.sellPrice << "/" << tmp_goods.measure << endl;
}

void marketPrint(Bills tmp_bills){
    cout << setw(5) << tmp_bills.id << setw(12) << tmp_bills.name
         << setw(9) << tmp_bills.species << setw(5) << tmp_bills.quantity
         << setw(7) << tmp_bills.sellPrice << "/" << tmp_bills.measure << setw(6) << tmp_bills.price << endl;
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    cls();

    int j = 1;
    // ��Ӵ�������ʾ�˿���ƷĿ¼
    cout << "������������ƷĿ¼��" << endl;
    cout<<"   ��Ʒ���    ��Ʒ����   ����   �������   �۸�/��λ"<<endl;
    for (const auto &tmp_goods: goods) {
        cout<<j++<<".";
        customGoodsPrint(tmp_goods);
    } // δ��������Ʒ���ۡ�������ֵ���ѡ��͡���ע��

    cout << "������Ҫ�������Ʒ��ţ�����������0����";
    // ���빺����Ʒ���
    int id, i;
    cin >> id;
    if (id != 0) {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;
    }
    else
        return;

    Goods buy_goods = goods[i];
    char buy_choice;
    cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
    cin >> buy_choice;
    customTrade(buy_goods, goods, market, buy_choice);
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {
    cls();
    string s;
    Goods find_goods;

    // ѯ�ʿͻ�Ҫ����������
    cout << "������Ҫ��������Ʒ���ƻ��ţ�";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        cout<<"��Ʒ���    ��Ʒ����   ����   �������   �۸�/��λ"<<endl;
        customGoodsPrint(find_goods);
        char buy_choice;
        cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
        cin >> buy_choice;
        customTrade(find_goods, goods, market, buy_choice);
    } else {
        cout << "���ҵ���Ʒ�����ڣ�����������һ��...";
        pause();
    }
}

void Display::customMarket(vector<Bills> &market) {
    cls();
    int j = 1;
    cout << "���Ĺ��ﳵ���ݣ�" << endl;
    cout<<"   ��Ʒ���    ��Ʒ����   ����   ����   �۸�/��λ   �ܼ�"<<endl;
    for (const auto &tmp_market: market) {
        cout<<j++<<".";
        marketPrint(tmp_market);
    }
}

void goodsPrint(Goods goods){
    cout << setw(7) << goods.id << setw(10) << goods.name
         << setw(9) << goods.species << setw(8) << goods.quantity
         << setw(7) << goods.purchasePrice << setw(8) << goods.sellPrice
         << setw(9) << goods.measure << setw(10) << goods.lessLimit << endl;
}

void Display::keeperMenu() {
    system("title cashier");
    cout << "1.�������" << endl;
    cout << "2.������Ʒ" << endl;
    cout << "3.�༭��Ʒ" << endl;
    cout << "4.�����Ʒ" << endl;
    cout << "5.ɾ����Ʒ" << endl;
    cout << "6.�޸�����" << endl;
    cout << "0.�˳�" << endl;
}

void Display::keeperSearch(vector<Goods> &goods) {
    cls();
    string s;
    Goods find_goods;

    // ѯ�ʿͻ�Ҫ����������
    cout << "������Ҫ��������Ʒ���ƻ��ţ�";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        cout << "     ���     ����     ����     ����     ����     �ۼ�     ��λ     ������ֵ" << endl;
        goodsPrint(find_goods);
        pause();
    } else {
        cout << "���ҵ���Ʒ�����ڣ�����������һ��...";
        pause();
    }
}

void Display::keeperLimit(vector<Goods> &goods) {
    cout<<endl<<"����֪ͨ��"<<endl;
    int j = 1;
    for (auto &igoods: goods) {
        if (igoods.quantity <= igoods.lessLimit) {
            cout << j++ << ".��Ʒ " << igoods.name << " (��� " << igoods.id << " ��" << "��������������ֵ��"
                 << igoods.lessLimit << "������ǰ���Ϊ��" << igoods.quantity << "���뼰ʱ������" << endl;
        }
    }
}

void Display::goods_data(vector<Goods> &goods) {
    int pageSize = 10, pageNumber = 1;
    int maxPage = goods.size() / 10 + (goods.size() % 10 > 0);

    while (pageNumber) {
        // ������ʼ�ͽ���
        int startIndex = (pageNumber - 1) * pageSize;
        int endIndex = pageNumber * pageSize;
        cout << "��Ʒ����ҳ��" << endl;
        cout << "��ǰҳ���� �� " << pageNumber << " ҳ" << endl;
        cout << "     ���     ����     ����     ����     ����     �ۼ�     ��λ     ������ֵ" << endl;
        for (int j = startIndex, i = startIndex; j < endIndex && i < goods.size(); i++, j++) {
            // ��ӡ��ǰ���ۼ�¼����Ϣ
            goodsPrint(goods[i]);
        }
        cout << "���ҳ����" << maxPage << endl;
        cout << "������鿴ҳ����0�˳�����" << endl;
        cin >> pageNumber;
        if (pageNumber > maxPage) {
            cout << "ҳ���������ҳ�������������룺";
            cin >> pageNumber;
        } else if (pageNumber < 0) {
            cout << "����ҳ��Ӧ����0�����������룺";
            cin >> pageNumber;
        }
    }
}

void Display::goods_edit(vector<Goods> &goods) {
    cls();

    string s;
    Goods find_goods;

    cout << "������Ҫ�޸ĵ���Ʒ���ƻ�������������������0�˳���";
    cin >> s;
    if(s == "0")
        return;
    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        cout << "   1.���   2.����   3.����   4.����   5.����   6.�ۼ�   7.��λ   8.������ֵ" << endl;
        goodsPrint(find_goods);
    } else {
        cout << "Ҫ�޸ĵ���Ʒ�����ڣ�����������һ��...";
        pause();
        return;
    }

    cout << "��ָ��Ҫ�޸ĵ���Ʒ��Ϣ��Ӧ�����֣�";
    int kind;
    cin >> kind;

    // ��ȫ���
    if (kind >= 1 && kind <= 8) {
        int i;
        for (i = 0; i < goods.size(); i++)
            if (find_goods.id == goods[i].id)
                break;
        string new_value;
        cout << "�������µ���Ʒ��Ϣ��";
        cin >> new_value; // �������ݵİ�ȫ���û��
        Goods::edit(goods, i, kind, new_value);
        cls();
        cout << "�޸���ɣ�������£�" << endl;
        cout << "     ���     ����     ����     ����     ����     �ۼ�     ��λ     ������ֵ" << endl;
        goodsPrint(goods[i]);
        pause();
        return;
    } else {
        cout << "����������Ч�����򼴽�����...";
        pause();
        return;
    }
}

void Display::cashierMenu() {
    cout << "1.������Ʒ" << endl;
    cout << "2.�������" << endl;
    cout << "3.�鿴��¼" << endl;
    cout << "4.�޸�����" << endl;
    cout << "0.�˳�" << endl;
}

void Display::cashierMarket(vector<Bills> &market) {
    cls();
    int j = 1;
    cout << "���ﳵ�е����ݣ�" << endl;
    cout<<"   ��Ʒ���    ��Ʒ����   ����   ����   �۸�/��λ   �ܼ�"<<endl;
    for (const auto &bill: market) {
        marketPrint(bill);
    }
}

void Display::cashierTrade(vector<Goods> &goods, vector<Bills> &market) {

    int j = 1;
    // ��ʾ��ƷĿ¼
    cout << "������������ƷĿ¼��" << endl;
    cout<<"   ��Ʒ���    ��Ʒ����   ����   �������   �۸�/��λ"<<endl;
    for (const auto &tmp_goods: goods) {
        cout<<j++<<".";
        customGoodsPrint(tmp_goods);
    } // δ��������Ʒ���ۡ�������ֵ���ѡ��͡���ע��

    cout << "������Ҫ���۵���Ʒ��ţ�����������0����";
    // ���빺����Ʒ���
    int id, i;
    cin >> id;
    if (id != 0) {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;
    } else {
        pause();
        return;
    }

    Bills new_bills;
    new_bills.id = goods[i].id;
    for(auto & tmp_market : market)
        if(new_bills.id == tmp_market.id) {
            cout << "��Ʒ�Ѵ��ڣ�������ת�޸�..." << endl;
            pause();
            Display::customMarketEdit(goods, market, tmp_market.id);
            return;
        }

    cout << "�����빺��������";
    cin >> new_bills.quantity;
    // �Թ˿��������Ʒ�������м��
    while (new_bills.quantity <= 0) {
        cout << "��Ʒ��������Ϊ�������㡣" << endl;
        cin >> new_bills.quantity;
    }
    // �����Ʒ�����Ƿ񳬹��˿��
    while (new_bills.quantity > goods[i].lessLimit) {
        cout << "���ﳵ�е���Ʒ���������˿�档" << endl;
        cin >> new_bills.quantity;
    }
    // �������ۼ�¼
    new_bills.name = goods[i].name;
    new_bills.species = goods[i].species;
    new_bills.sellPrice = goods[i].sellPrice;
    new_bills.quantity = goods[i].quantity;
    new_bills.price = new_bills.sellPrice * new_bills.quantity;  // �����ܼ�
    new_bills.measure = goods[i].measure;

    // ���ۼ�¼���빺�ﳵ
    market.push_back(new_bills);
    std::cout << "��ӳɹ���" << std::endl;
}

void Display::adminMenu() {
    cout << "1.�û�����" << endl;
    cout << "2.�������" << endl;
    cout << "3.���ۼ�¼" << endl;
    cout << "4.�޸�����" << endl;
    cout << "0.�˳�" << endl;
}

void Display::adminUsers(vector<Users> users) {//����Ա�û�����

// ����ָ����Χ�ڵ��û���Ϣ
    for (auto & user : users) {
        // ��ӡ��ǰ�û���������ID
        cout << " ����: " << user.name << " id: " << user.id;
        switch (user.level) {
            case 0:
                cout<<" Ȩ�ޣ��˿�"<<endl;
                break;
            case 1:
                cout<<" Ȩ�ޣ��ֿ����Ա"<<endl;
                break;
            case 2:
                cout<<" Ȩ�ޣ�����Ա"<<endl;
                break;
            case 3:
                cout<<" Ȩ�ޣ�����Ա"<<endl;
                break;
        }
    }

// ��ʾ����Ա�鿴�û���Ϣ�Ľ���
    cout << "����ѡ�" << endl;
    cout << "1. �����û�" << endl;
    cout << "2. �༭�û�" << endl;
    cout << "3. ɾ���û�" << endl;
    cout << "0. ����" << endl;

    int choice = 1;
    string verify_pwd;
    cin >> choice;
    switch (choice) {
        case 1: {
            int level;
            Users::add(users, level);
            break;
        } // �����û�
        case 2: {
            int kind;
            int i;
            string new_value;
            Users::edit(users, i, kind, new_value);
            break;
        } // �༭�û�
        case 3: {
            cout << "������������ȷ����ݣ�" << endl;
            cin >> verify_pwd;
            for (int i = 0; i < users.size(); i++) {
                if (verify_pwd == users[i].pwd) {
                    if (users[i].level == 3) {
                        int level;
                        Users::del(users);
                        break;
                    }
                }
            }
            break;
        } // ɾ���û�
        case 0:
            break;
        default:
            cout << "����ֵ��Ч�����������룺";
    }
}

void Display::adminGoodsMenu() {
    cout << "1.�������" << endl;
    cout << "2.�༭��Ʒ" << endl;
    cout << "3.ɾ����Ʒ" << endl;
    cout << "0.�˳�" << endl;
}

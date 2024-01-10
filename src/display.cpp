//
// Created by calfVong on 2023/12/28.
//

#include <iostream>

#include "head.h"

using namespace std;

void Display::loginPage() { // ��¼����
    system("title login");//�����ʼ��
    system("color 70");

    goto_xy(50,10);
    cout <<"��ӭʹ�ó��й���ϵͳ";
    goto_xy(53,11);
    cout <<"AI2302 ����С��";
    goto_xy(54,12);
    cout <<setw(10) <<"�鳤������ΰ";
    goto_xy(48,13);
    cout <<setw(7) <<"С���Ա������ϣ����Ц��";
    goto_xy(53,16);
    system ("pause");
}

void Display::welcomePage(Users user) {
    cls();
    system("title ��ӭʹ�ó��й���ϵͳ");
    system("color 70");
    goto_xy(10,15);;
    pause();
}

void Display::customMenu() {
    cls();
    system("title customer");
    system ("color 70");
    // ��Ӵ�������ʾ�˿Ͳ˵�����
    goto_xy(10,10);
    cout << "�˵�ѡ�";
    goto_xy(10,11);
    cout << "1. ��ƷĿ¼";
    goto_xy(10,12);
    cout << "2. ������Ʒ";
    goto_xy(10,13);
    cout << "3. ���ﳵ";
    goto_xy(10,14);
    cout << "4. ����";
    goto_xy(10,15);
    cout << "5. �޸�����";
    goto_xy(10,16);
    cout << "0. �˳�";
    goto_xy(10,17);
    cout <<"����������ѡ��";
}

bool Display::customMarketEdit(vector<Goods> &goods, vector<Bills> &market, int goodsChoice) {
    for (int i = 0; i < market.size(); i++) {
        if (market[i].id == goodsChoice) {
            market.erase(market.begin() + i); // ֱ��ɾ�������´���

            // �������¹������Ʒ
            Goods buy_goods;
            buy_goods.id = goodsChoice;

            // ����Ʒ�����ȡ��Ϣ
            for (auto & good : goods)
                if (good.id == buy_goods.id)
                    buy_goods = good;

            // ���뽻�׺���
            Display::customTrade(buy_goods, goods, market, 'y');
            return true;
        }
    }
}

void Display::customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice) {
    if (buy_choice == 'y') {
        for (auto &i: market)
            if (buy_goods.id == i.id) {
                goto_xy(70,11);
                cout << "��Ʒ�Ѵ��ڣ�������ת�޸�..." << endl;
                pause();
                Display::customMarketEdit(goods, market, i.id);
                return;
            }
        Bills new_bills;
        goto_xy(70,10);
        cout << "�����빺��������";
        cin >> new_bills.quantity;
        // �Թ˿��������Ʒ�������м��
        while (new_bills.quantity <= 0) {
            goto_xy(70,11);
            cout << "��Ʒ��������Ϊ�������㡣" ;
            cin >> new_bills.quantity;
        }
        // �����Ʒ�����Ƿ񳬹��˿��
        while (new_bills.quantity > buy_goods.quantity) {
            goto_xy(70,12);
            cout << "���ﳵ�е���Ʒ���������˿�档" ;
            goto_xy(70,13);
            cout << "���ٴ����룺";
            cin >> new_bills.quantity;
        }

        // �������ۼ�¼
        new_bills.id = buy_goods.id;
        new_bills.name = buy_goods.name;
        new_bills.species = buy_goods.species;
        new_bills.sellPrice = buy_goods.sellPrice;
        new_bills.price = new_bills.sellPrice * new_bills.quantity;  // �����ܼ�
        new_bills.profit = new_bills.price - (buy_goods.purchasePrice * new_bills.quantity); // ��������
        new_bills.measure = buy_goods.measure;


        // ���ۼ�¼���빺�ﳵ
        market.push_back(new_bills);
        goto_xy(70,13);
        std::cout << "��ӳɹ���" ;
    }
}

void customGoodsPrint(Goods tmp_goods) {
    cout << setw(5) << tmp_goods.id << setw(12) << tmp_goods.name
         << setw(8) << tmp_goods.species << setw(8) << tmp_goods.quantity
         << setw(7) << tmp_goods.sellPrice << "/" << tmp_goods.measure << endl;
}

void marketPrint(Bills tmp_bills) {
    cout << setw(5) << tmp_bills.id << setw(12) << tmp_bills.name
         << setw(9) << tmp_bills.species << setw(5) << tmp_bills.quantity
         << setw(7) << tmp_bills.sellPrice << "/" << tmp_bills.measure << setw(6) << tmp_bills.price << endl;
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    cls();

    int j = 1;
    // ��Ӵ�������ʾ�˿���ƷĿ¼
    goto_xy(10,10);
    cout << "������������ƷĿ¼��";
    goto_xy(10,11);
    cout << "==============================================" ;
    goto_xy(10,12);
    cout << "   ��Ʒ���    ��Ʒ����   ����   �������   �۸�/��λ" ;
    goto_xy(10,13);
    int lie=14;
    for (const auto &tmp_goods: goods) {
        goto_xy(10,lie);
        cout << j++ << ".";
        customGoodsPrint(tmp_goods);
        lie++;
    } // δ��������Ʒ���ۡ�������ֵ���ѡ��͡���ע��

    goto_xy(10,lie);
    cout << "==============================================" << endl;

    goto_xy(10,lie+1);
    cout << "������Ҫ�������Ʒ��ţ�����������0����";
    // ���빺����Ʒ���
    int id, i;
    cin >> id;
    if (id != 0) {
        for (i = 0; i < goods.size(); i++)
            if (goods[i].id == id)
                break;
    } else {
        goto_xy(10, lie + 2);
        return;
    }

    Goods buy_goods = goods[i];
    char buy_choice;
    goto_xy(10,lie+2);
    cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
    cin >> buy_choice;
    customTrade(buy_goods, goods, market, buy_choice);
}

void Display::customSearch(vector<Goods> &goods, vector<Bills> &market) {
    cls();
    string s;
    Goods find_goods;

    // ѯ�ʿͻ�Ҫ����������
    goto_xy(10,10);
    cout << "������Ҫ��������Ʒ���ƻ��ţ�";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        goto_xy(10,11);
        cout << "��Ʒ���    ��Ʒ����   ����   �������   �۸�/��λ";
        goto_xy(10,12);
        customGoodsPrint(find_goods);
        char buy_choice;
        goto_xy(10,13);
        cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
        cin >> buy_choice;
        customTrade(find_goods, goods, market, buy_choice);
    } else {
        goto_xy(10,11);
        cout << "���ҵ���Ʒ�����ڣ�����������һ��..." << endl;
    }
}

void Display::customMarket(vector<Bills> &market) {
    cls();
    int j = 1;
    goto_xy(0,10);
    cout << "���Ĺ��ﳵ���ݣ�" ;
    goto_xy(0,11);
    cout << "   ��Ʒ���    ��Ʒ����   ����   ����   �۸�/��λ   �ܼ�" << endl;
    int lie2=12;
    for (const auto &tmp_market: market) {
        goto_xy(0,lie2);
        cout << j++ << ".";
        marketPrint(tmp_market);
        lie2++;
    }
}

void goodsPrint(Goods goods) {
    cout << setw(7) << goods.id << setw(10) << goods.name
         << setw(9) << goods.species << setw(8) << goods.quantity
         << setw(7) << goods.purchasePrice << setw(8) << goods.sellPrice
         << setw(9) << goods.measure << setw(10) << goods.lessLimit << endl;
}

void Display::keeperMenu() {
    goto_xy(10,12);
    cout << "1.�������" << endl;
    goto_xy(10,13);
    cout << "2.������Ʒ" << endl;
    goto_xy(10,14);
    cout << "3.�༭��Ʒ" << endl;
    goto_xy(10,15);
    cout << "4.�����Ʒ" << endl;
    goto_xy(10,16);
    cout << "5.ɾ����Ʒ" << endl;
    goto_xy(10,17);
    cout << "6.�޸�����" << endl;
    goto_xy(10,18);
    cout << "0.�˳�" << endl;
}

void Display::keeperSearch(vector<Goods> &goods) {
    cls();
    string s;
    Goods find_goods;

    // ѯ�ʿͻ�Ҫ����������
    goto_xy(10,10);
    cout << "������Ҫ��������Ʒ���ƻ��ţ�";
    cin >> s;

    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        goto_xy(10,10);
        cout << "���     ����     ����     ����     ����     �ۼ�     ��λ     ������ֵ" << endl;
        goto_xy(10,11);
        goodsPrint(find_goods);
        goto_xy(10,12);
        pause();
    } else {
        goto_xy(10,11);
        cout << "���ҵ���Ʒ�����ڣ�����������һ��...";
        goto_xy(10,12);
        pause();
    }
}

void Display::keeperLimit(vector<Goods> &goods) {
    goto_xy(10,10);
    cout << "����֪ͨ��" << endl;
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
        cls();
        int startIndex = (pageNumber - 1) * pageSize;
        int endIndex = pageNumber * pageSize;
        goto_xy(10,10);
        cout << "��Ʒ����ҳ��" << endl;
        goto_xy(10,11);
        cout << "��ǰҳ���� �� " << pageNumber << " ҳ" << endl;

        goto_xy(10,12);
        cout << "=====================================================================" << endl;
        goto_xy(10,13);
        cout << "     ���    ����     ����     ����    ����    �ۼ�    ��λ     ������ֵ" << endl;
        int lie3=14;
        for (int j = startIndex, i = startIndex; j < endIndex && i < goods.size(); i++, j++) {
            // ��ӡ��ǰ���ۼ�¼����Ϣ
            goto_xy(10,lie3);
            goodsPrint(goods[i]);
            lie3++;
        }
        goto_xy(10,lie3);
        cout << "=====================================================================" << endl;

        goto_xy(10,lie3+1);
        cout << "���ҳ����" << maxPage << endl;
        goto_xy(10,lie3+2);
        cout << "������鿴ҳ����0�˳�����";
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

    goto_xy(10,10);
    cout << "������Ҫ�޸ĵ���Ʒ���ƻ�������������������0�˳���";
    cin >> s;
    if (s == "0")
        return;
    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        goto_xy(10,12);
        cout << "1.���   2.����   3.����   4.����   5.����   6.�ۼ�   7.��λ   8.������ֵ" << endl;
        goto_xy(10,13);
        goodsPrint(find_goods);
    } else {
        goto_xy(10,12);
        cout << "Ҫ�޸ĵ���Ʒ�����ڣ�����������һ��...";
        goto_xy(10,13);
        pause();
        return;
    }

    goto_xy(10,15);
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
        goto_xy(10,16);
        cout << "�������µ���Ʒ��Ϣ��";
        cin >> new_value; // �������ݵİ�ȫ���û��
        Goods::edit(goods, i, kind, new_value);
        cls();
        goto_xy(10,10);
        cout << "�޸���ɣ�������£�" << endl;
        goto_xy(10,11);
        cout << "���     ����     ����     ����     ����     �ۼ�     ��λ     ������ֵ" << endl;
        goto_xy(10,12);
        goodsPrint(goods[i]);
        goto_xy(10,13);
        pause();
        return;
    } else {
        goto_xy(10,17);
        cout << "����������Ч�����򼴽�����...";
        goto_xy(10,18);
        pause();
        return;
    }
}

void Display::cashierMenu() {
    cout << "1.���������Ʒ" << endl;
    cout << "2.������Ʒ����" << endl;
    cout << "3.�鿴���ۼ�¼" << endl;
    cout << "4.�޸�����" << endl;
    cout << "0.�˳�" << endl;
}

void Display::cashierMarket(vector<Bills> &market) {
    cls();

    cout << "���ﳵ�е����ݣ�" << endl;
    cout << "   ��Ʒ���    ��Ʒ����   ����   ����   �۸�/��λ   �ܼ�" << endl;
    for (const auto &bill: market) {
        marketPrint(bill);
    }
}

void Display::cashierTrade(vector<Goods> &goods, vector<Bills> &market) {

    int j = 1;
    // ��ʾ��ƷĿ¼
    cout << "������������ƷĿ¼��" << endl;
    cout << "   ��Ʒ���    ��Ʒ����   ����   �������   �۸�/��λ" << endl;
    for (const auto &tmp_goods: goods) {
        cout << j++ << ".";
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
    for (auto &tmp_market: market)
        if (new_bills.id == tmp_market.id) {
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
    new_bills.profit = new_bills.price - (goods[i].purchasePrice * new_bills.quantity); // ��������
    new_bills.measure = goods[i].measure;

    // ���ۼ�¼���빺�ﳵ
    market.push_back(new_bills);
    std::cout << "��ӳɹ���" << std::endl;
}

void Display::adminMenu() {
    goto_xy(10,10);
    cout << "1.�û�����";
    goto_xy(10,11);
    cout << "2.�������";
    goto_xy(10,12);
    cout << "3.���ۼ�¼";
    goto_xy(10,13);
    cout << "4.�޸�����";
    goto_xy(10,14);
    cout << "0.�˳�" << endl;
    goto_xy(10,15);
    cout <<"��ѡ��(����0-4):";
}

void usersMenuPrint(vector<Users> &users) {
    // ����ָ����Χ�ڵ��û���Ϣ
    goto_xy(10,10);
    cout << "======================================" << endl;
    goto_xy(10,11);
    cout << "     ����          id            Ȩ��" << endl;
    int lie5=12;
    for (auto &user: users) {
        // ��ӡ��ǰ�û���������ID
        goto_xy(10,lie5);
        cout << setw(9) << user.name << setw(14) << user.id << "       ";
        lie5++;
        switch (user.level) {
            case 0:
                cout << "    �˿�" << endl;
                break;
            case 1:
                cout << "�ֿ����Ա" << endl;
                break;
            case 2:
                cout << "   ����Ա" << endl;
                break;
            case 3:
                cout << "   ����Ա" << endl;
                break;
        }
    }

// ��ʾ����Ա�鿴�û���Ϣ�Ľ���
    goto_xy(70,10);
    cout << "����ѡ�";
    goto_xy(70,11);
    cout << "1. �����û�";
    goto_xy(70,12);
    cout << "2. �༭�û�";
    goto_xy(70,13);
    cout << "3. ɾ���û�";
    goto_xy(70,14);
    cout << "0. ����";
    goto_xy(70,15);
    cout <<"����ѡ��" ;

}

void Display:: adminUsers(vector<Users> &users, Users user) {//����Ա�û�����

    int choice = 1;
    string verify_pwd;
    while (choice) {
        cls();
        usersMenuPrint(users);
        cin >> choice;
        switch (choice) {
            case 1: {
                Users::add(users, 3);
                break;
            } // �����û�
            case 2: {
                int kind;
                int i;
                string id, new_value;
                goto_xy(10,18);
                cout << "�������޸ĵ��û�id:";
                cin >> id;
                bool cond = false;

                for (i = 0; i < users.size(); i++)
                    if (users[i].id == id) {
                        cond = true;
                        break;
                    }

                if (cond == false) {
                    goto_xy(10,19);
                    cout << "�û�id����" << endl;
                    goto_xy(10,20);
                    pause();
                    break;
                }
                goto_xy(10,19);
                cout << "�������޸ĵ��������ͣ�1.������2.id��3.���룬4.Ȩ�ޣ�0.�˳�����";
                cin >> kind;
                if (kind == 1 || kind == 2 || kind == 3 || kind == 4) {
                    goto_xy(10,20);
                    cout << "�������µ�ֵ��";
                    cin >> new_value;
                    Users::edit(users, i, kind, new_value);
                    break;
                }
                break;
            } // �༭�û�
            case 3: {
                goto_xy(10,18);
                cout << "����������������ȷ����ݣ�";
                cin >> verify_pwd;
                if (verify_pwd == user.pwd) {
                    Users::del(users);
                    break;
                } else {
                    goto_xy(10,19);
                    cout << "������󣬳��򼴽�����...";
                    goto_xy(10,20);
                    pause();
                    break;
                }
            } // ɾ���û�
            case 0:
                break;
            default:
                goto_xy(10,19);
                cout << "����ֵ��Ч�����������룺";
                cin >> choice;
        }
    }
}

void Display::adminGoodsMenu() {
    cout << "1.�������" << endl;
    cout << "2.�༭��Ʒ" << endl;
    cout << "3.�����Ʒ" << endl;
    cout << "4.ɾ����Ʒ" << endl;
    cout << "0.�˳�" << endl;
}

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
    cout << endl;
    pause();
}

void Display::customMenu() {
    cls();
    system("title customer");
    system ("color 70");
    // ��Ӵ�������ʾ�˿Ͳ˵�����
    goto_xy(50,10);
    cout << "�˵�ѡ�";
    goto_xy(50,11);
    cout << "1. ��ƷĿ¼";
    goto_xy(50,12);
    cout << "2. ������Ʒ";
    goto_xy(50,13);
    cout << "3. ���ﳵ";
    goto_xy(50,14);
    cout << "4. ����";
    goto_xy(50,15);
    cout << "5. �޸�����";
    goto_xy(50,16);
    cout << "0. �˳�";
}

void Display::customTrade(Goods buy_goods, vector<Goods> &goods, vector<Bills> &market, char buy_choice) {
    if (buy_choice == 'y') {
        Bills new_bills;
        goto_xy(50,10);
        cout << "�����빺��������";
        cin >> new_bills.quantity;
        // �Թ˿��������Ʒ�������м��
        while (new_bills.quantity <= 0) {
            goto_xy(50,11);
            cout << "��Ʒ��������Ϊ�������㡣" << endl;
            cin >> new_bills.quantity;
        }
        // �����Ʒ�����Ƿ񳬹��˿��
        while (new_bills.quantity > buy_goods.lessLimit) {
            goto_xy(50,12);
            cout << "���ﳵ�е���Ʒ���������˿�档" << endl;
            cin >> new_bills.quantity;
        }

        // �������ۼ�¼
        new_bills.id = buy_goods.id;
        new_bills.name = buy_goods.name;
        new_bills.species = buy_goods.species;
        new_bills.sellPrice = buy_goods.sellPrice;
        new_bills.quantity = buy_goods.quantity;
        new_bills.price = new_bills.sellPrice * new_bills.quantity;  // �����ܼ�
        new_bills.measure = buy_goods.measure;


        // ���ۼ�¼���빺�ﳵ
        market.push_back(new_bills);
        goto_xy(50,17);
        std::cout << "��ӳɹ���" << std::endl;
    }
}

void Display::customGoodsData(vector<Goods> &goods, vector<Bills> &market) {
    cls();

    int j = 1;
    // ��Ӵ�������ʾ�˿���ƷĿ¼
    cout << "������������ƷĿ¼��" << endl;
    for (const auto &tmp_goods: goods) {
        cout << j++ << ".��Ʒ��ţ�" << tmp_goods.id << " ���ƣ�" << tmp_goods.name
             << " ���ࣺ" << tmp_goods.species << " �۸�" << tmp_goods.sellPrice << "/" << tmp_goods.measure
             << " ������" << tmp_goods.quantity << endl;
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
        char buy_choice;
        cout << "�Ƿ�ȷ�ϼ��빺�ﳵ����������y/n����";
        cin >> buy_choice;
        customTrade(find_goods, goods, market, buy_choice);
    } else {
        cout << "���ҵ���Ʒ�����ڣ�����������һ��...";
        pause();
    }
}

void Display::customMarket(vector<Bills> market) {
    cls();
    int j = 1;
    cout << "���Ĺ��ﳵ���ݣ�" << endl;
    for (const auto &bill: market) {
        cout << j++ << ". ��Ʒ����: " << bill.name << ", ����: " << bill.quantity << ", ����: "
             << bill.sellPrice << "/" << bill.measure << ", �ܼ�: " << bill.price << endl;
    }
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
        cout << setw(5) << find_goods.id << setw(9) << find_goods.name
             << setw(9) << find_goods.species << setw(9) << find_goods.quantity
             << setw(9) << find_goods.purchasePrice << setw(9) << find_goods.sellPrice
             << setw(9) << find_goods.measure << setw(9) << find_goods.lessLimit << endl;
        pause();
    } else {
        cout << "���ҵ���Ʒ�����ڣ�����������һ��...";
        pause();
    }
}

void Display::keeperLimit(vector<Goods> &goods) {
    int j = 1;
    for (auto &igoods: goods) {
        if (igoods.quantity <= igoods.lessLimit) {
            cout << j++ << ".��Ʒ " << igoods.name << " (��� " << igoods.id << " ��" << "��������������ֵ��"
                 << igoods.lessLimit << "������ǰ���Ϊ��" << igoods.quantity << "���뼰ʱ������" << endl;
        }
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
    for (const auto &bill: market) {
        cout << j++ << ". ��Ʒ����: " << bill.name << ", ����: " << bill.quantity << ", ����: "
             << bill.sellPrice << "/" << bill.measure << ", �ܼ�: " << bill.price << endl;
    }
}

void Display::cashierTrade(vector<Goods> &goods, vector<Bills> &market) {

    int j = 1;
    // ��Ӵ�������ʾ�˿���ƷĿ¼
    cout << "������������ƷĿ¼��" << endl;
    for (const auto &tmp_goods: goods) {
        cout << j++ << ".��Ʒ��ţ�" << tmp_goods.id << " ���ƣ�" << tmp_goods.name
             << " ���ࣺ" << tmp_goods.species << " �۸�" << tmp_goods.sellPrice << "/" << tmp_goods.measure
             << " ������" << tmp_goods.quantity << endl;
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
    cout << "�����빺��������";
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
    new_bills.id = goods[i].id;
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

void goodsPrint(Goods goods){
    cout << setw(5) << goods.id << setw(9) << goods.name
         << setw(9) << goods.species << setw(9) << goods.quantity
         << setw(9) << goods.purchasePrice << setw(9) << goods.sellPrice
         << setw(9) << goods.measure << setw(9) << goods.lessLimit << endl;
}

void Display::goods_data(vector<Goods> &goods) {
    int pageSize = 10, pageNumber = 1;

    int choice = 1;
    cin >> choice;
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
        cout << "������鿴ҳ����0�˳�����" << endl;
        cin >> pageNumber;
    }
}

void Display::goods_edit(vector<Goods> &goods) {
    cls();

    string s;
    Goods find_goods;

    cout << "������Ҫ�޸ĵ���Ʒ���ƻ��ţ�";
    cin >> s;
    Goods::search(goods, s, find_goods);
    if (find_goods.id != -1) {
        cout << "   1.���   2.����   3.����   4.����   5.����   6.�ۼ�   7.��λ   8.������ֵ" << endl;
        cout << setw(5) << find_goods.id << setw(9) << find_goods.name
             << setw(9) << find_goods.species << setw(9) << find_goods.quantity
             << setw(9) << find_goods.purchasePrice << setw(9) << find_goods.sellPrice
             << setw(9) << find_goods.measure << setw(9) << find_goods.lessLimit << endl;
        pause();
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
        cout << setw(5) << goods[i].id << setw(9) << goods[i].name
             << setw(9) << goods[i].species << setw(9) << goods[i].quantity
             << setw(9) << goods[i].purchasePrice << setw(9) << goods[i].sellPrice
             << setw(9) << goods[i].measure << setw(9) << goods[i].lessLimit << endl;
        pause();
        return;
    } else {
        cout << "����������Ч�����򼴽�����...";
        pause();
        return;
    }
}

void Display::adminMenu() {
    goto_xy(50,10);
    cout << "1.�û�����";
    goto_xy(50,11);
    cout << "2.�������";
    goto_xy(50,12);
    cout << "3.���ۼ�¼";
    goto_xy(50,13);
    cout << "4.�޸�����";
    goto_xy(50,14);
    cout << "0.�˳�" << endl;
    goto_xy(50,15);
    cout <<"��ѡ��(����0-4):";
}

void Display::adminUsers(vector<Users> users) {//����Ա�û�����

// ����ָ����Χ�ڵ��û���Ϣ
    for (auto & user : users) {
        // ��ӡ��ǰ�û���������ID
        goto_xy(50,10);
        cout << " ����: " << user.name << " id: " << user.id;
        switch (user.level) {
            case 0:
                goto_xy(50,11);
                cout<<" Ȩ�ޣ��˿�"<<endl;
                break;
            case 1:
                goto_xy(50,12);
                cout<<" Ȩ�ޣ��ֿ����Ա"<<endl;
                break;
            case 2:
                goto_xy(50,13);
                cout<<" Ȩ�ޣ�����Ա"<<endl;
                break;
            case 3:
                goto_xy(50,14);
                cout<<" Ȩ�ޣ�����Ա"<<endl;
                break;
        }
    }

// ��ʾ����Ա�鿴�û���Ϣ�Ľ���
    goto_xy(50,10);
    cout << "����ѡ�";
    goto_xy(50,11);
    cout << "1. �����û�";
    goto_xy(50,12);
    cout << "2. �༭�û�";
    goto_xy(50,13);
    cout << "3. ɾ���û�";
    goto_xy(50,14);
    cout << "0. ����";
    goto_xy(50,15);
    cout <<"����ѡ��0-4����";

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
            goto_xy(50,16);
            cout << "������������ȷ����ݣ�";
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
            goto_xy(50,17);
            cout << "����ֵ��Ч�����������룺";
    }
}

void Display::adminGoodsMenu() {
    cout << "1.�������" << endl;
    cout << "2.�༭��Ʒ" << endl;
    cout << "3.ɾ����Ʒ" << endl;
    cout << "0.�˳�" << endl;
}

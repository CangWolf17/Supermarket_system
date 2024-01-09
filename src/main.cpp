//
// Created by calfVong on 2023/12/22.
//

#include "head.h"

using namespace std;

// ������������Ϊ��½����ģ��
int main() {
    enum authority {
        customer = 0,
        keeper,
        cashier,
        admin
    }; // ö�� ʹ�û�Ȩ�޿���Ϊ����

    vector<Users> users; // ʵ��������
    vector<Goods> goods;
    vector<Bills> bills;

    Goods::read(goods); // ��ȡ�ļ��е����ݲ���������
    Users::read(users);
    Bills::read(bills);


    // ��������ʼִ��

    // ��¼
    Users user = login(); // ����login����ʵ�ֵ�¼��ͬʱ����һ�������û����ݵ�users����
    if (user.name == "NOTFOUND")
        user = login();
    if (user.id == "reg")
        Users::add(users, 0);
    else if (user.id == "0") {
        user.name = "visitor";
        user.level = 0;
    }

    // ��ӭҳ��չʾ
    Display::welcomePage(user);
    // �˵�ѡ��
    int menuChoice = -1;

    switch (user.level) {
        case customer: {
            vector<Bills> market; // һ��bills���������������ﳵ
            system("title customer");
            // ��while���ֲ˵�
            while (menuChoice) {
                cls();
                Display::customMenu();
                cin >> menuChoice;

                switch (menuChoice) {
                    case 1: { // 1 ��ƷĿ¼
                        Display::customGoodsData(goods, market);
                        pause();
                        break;
                    }
                    case 2: { // 2 ������Ʒ
                        Display::customSearch(goods, market);
                        pause();
                        break;
                    }
                    case 3: {// 3 ���ﳵ
                        Display::customMarket(market);

                        cout << "�Ƿ�Ҫ�޸Ļ�ɾ�����ݣ���ȡ����0���޸ģ�1��ɾ����2����";
                        int choice;
                        cin >> choice;

                        // ���ﳵ����
                        switch (choice) {
                            case 1: {
                                int goodsChoice;
                                cout << "������Ҫ�޸ĵ���Ʒ��ţ�";
                                cin >> goodsChoice;

                                if (!Display::customMarketEdit(goods,market,goodsChoice)) {
                                    cout << "�������Ʒ�������..." << endl;
                                    choice = 0;
                                    pause();
                                }
                                menuChoice = -1;
                                break;
                            }
                            case 2: {
                                int goodsChoice;
                                cout << "������Ҫɾ������Ʒ��ţ�";
                                cin >> goodsChoice;
                                bool cond = false;
                                for (int i = 0; i < market.size(); i++) {
                                    if (market[i].id == goodsChoice) {
                                        market.erase(market.begin() + i);
                                        cout << "���ﳵ�е���Ʒ��ɾ��" << endl;
                                        cond = true;
                                    }
                                }

                                if (!cond) {
                                    cout << "�������Ʒ�������..." << endl;
                                    choice = 0;
                                }
                                menuChoice = -1;
                                break;
                            }
                            default: {
                                menuChoice = -1;
                                break;
                            }
                        }
                        break;
                    }
                    case 4: { // 4 ����
                        cls();
                        if (market.empty()) {
                            cout << "���ﳵ�л�δ�����ƷŶ��";
                        } else {
                            // չʾ���ﳵ����
                            Display::customMarket(market);

                            // ����
                            cout << endl << "�Ƿ�ȷ�Ͻ��㣿(y/n)��";
                            char choice;
                            cin >> choice;
                            if (choice == 'y') {
                                Goods::trade(bills, goods, market);
                                market.clear();
                                // СƱ��ӡ
                                cout << "�Ƿ��ӡСƱ��(y/n)��";
                                cin >> choice;
                                if (choice == 'y') {
                                    Bills::receipt(market);
                                }
                                market.clear();
                            } else {
                                menuChoice = -1;
                                break;
                            }
                            menuChoice = -1;
                            break;
                        }
                        case 5: { // 5 �޸�����
                            if (user.id != "0") {
                                Users::pwdedit(users, user);
                                menuChoice = -1;
                            }
                            else{
                                cout<<"�������޸��ο���ݵ����룡���˳���ע�ᣡ"<<endl;
                                menuChoice = -1;
                            }
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "��������Чֵ�� ";
                        menuChoice = -1;
                        cin >> menuChoice;
                    }
                }
            }
            break;
        }

        case keeper: {
            system("title keeper");

            while (menuChoice) {
                cls();
                Display::keeperLimit(goods);
                cout << endl;
                Display::keeperMenu();

                cin >> menuChoice;
                switch (menuChoice) {
                    case 1: {
                        Display::goods_data(goods);
                        break;
                    } // 1 ��Ʒ����
                    case 2: {
                        Display::keeperSearch(goods);
                        break;
                    } // 2 ������Ʒ
                    case 3: {
                        Display::goods_edit(goods);
                        break;
                    } // 3 �༭��Ʒ
                    case 4: {
                        Goods::add(goods);
                        break;
                    } // 4 �����Ʒ
                    case 5: {
                        Goods::del(goods);
                        break;
                    } // 5 ɾ����Ʒ
                    case 6: { // 6 �޸�����
                        Users::pwdedit(users, user);
                        menuChoice = -1;
                        break;
                    } // 6 �޸�����
                    case 0:
                        break;
                    default:
                        cout << "����ֵ��Ч�����������룺";
                        cin >> menuChoice;
                        break;
                }
            }
            break;
        }

        case cashier: {
            system("title cashier");
            vector<Bills> market; // ����market��Ϊ���ﳵ

            while (menuChoice) {
                if (market.empty())
                    cout << "��ǰ���ﳵΪ�ա�" << endl;
                else
                    Display::cashierMarket(market);

                Display::cashierMenu();
                cin >> menuChoice;

                switch (menuChoice) {
                    case 1: {
                        Display::cashierTrade(goods, market);
                        break;
                    } // 1 ������Ʒ
                    case 2: {
                        cls();
                        if (market.empty()) {
                            cout << "���ﳵ�л�δ�����ƷŶ��";
                        } else {
                            // չʾ���ﳵ����
                            Display::cashierMarket(market);

                            cout << "��ѡ�������0.ȡ����1.���㣬2.�޸ģ�3.ɾ������";
                            int choice;
                            cin >> choice;

                            // ���ﳵ����
                            switch (choice) {
                                case 1: {
                                    cout << endl << "�Ƿ�ȷ�Ͻ��㣿(y/n)��";
                                    char tradeChoice;
                                    cin >> tradeChoice;
                                    if (tradeChoice == 'y') {
                                        Goods::trade(bills, goods, market);
                                        market.clear();
                                        // СƱ��ӡ
                                        cout << "�Ƿ��ӡСƱ��(y/n)��";
                                        cin >> tradeChoice;
                                        if (tradeChoice == 'y')
                                            Bills::receipt(market);
                                    }
                                    else
                                        menuChoice = -1;
                                    break;
                                }
                                case 2: {
                                    int goodsChoice;
                                    cout << "������Ҫ�޸ĵ���Ʒ��ţ�";
                                    cin >> goodsChoice;

                                    if (!Display::customMarketEdit(goods, market, goodsChoice)) {
                                        cout << "�������Ʒ�������..." << endl;
                                        choice = 0;
                                        pause();
                                    }
                                    menuChoice = -1;
                                    break;
                                }
                                case 3: {
                                    int goodsChoice;
                                    cout << "������Ҫɾ������Ʒ��ţ�";
                                    cin >> goodsChoice;
                                    bool cond = false;
                                    for (int i = 0; i < market.size(); i++) {
                                        if (market[i].id == goodsChoice) {
                                            market.erase(market.begin() + i);
                                            cout << "���ﳵ�е���Ʒ��ɾ��" << endl;
                                            cond = true;
                                        }
                                    }

                                    if (!cond) {
                                        cout << "�������Ʒ�������..." << endl;
                                        choice = 0;
                                    }
                                    menuChoice = -1;
                                    break;
                                }
                                default: {
                                    menuChoice = -1;
                                    break;
                                }
                            }
                        }
                        menuChoice = -1;
                        break;
                    }// 2 �������
                    case 3: {
                        Bills::data(bills);
                        break;
                    } // 3 �鿴���ۼ�¼
                    case 4: {
                        Users::pwdedit(users, user);
                        menuChoice = -1;
                        break;
                    } // 4 �޸�����
                    case 0:
                        break;
                    default:
                        cout << "����ֵ��Ч�����������룺";
                        cin >> menuChoice;
                        menuChoice = -1;
                }
            }
            break;
        }

        case admin: {
            system("title admin");

            while (menuChoice) {
                cls();
                Display::adminMenu();

                cin >> menuChoice;
                switch (menuChoice) {
                    case 1: {
                        Display::adminUsers(users);
                        break;
                    } // �û�����
                    case 2: {
                        Display::adminGoodsMenu();
                        int choice;
                        cin >> choice;

                        switch (choice) {
                            case 1: {
                                Display::goods_data(goods);
                                break;
                            } // 1 ��Ʒ����
                            case 2: {
                                Display::goods_edit(goods);
                                break;
                            } // 2 �༭��Ʒ
                            case 3: {
                                Goods::add(goods);
                                break;
                            } // 3 �����Ʒ
                            case 4: {
                                Goods::del(goods);
                                break;
                            } // 4 ɾ����Ʒ
                            case 0:
                                break;
                            default:
                                cout << "����ֵ��Ч�����������룺";
                                cin >> choice;
                                break;
                        }
                        break;
                    } // �������
                    case 3: {
                        Bills::data(bills);
                        break;
                    } // �������
                    case 4: {
                        Users::pwdedit(users, user);
                        menuChoice = -1;
                        break;
                    }  // 4 �޸�����

                    default:
                        cout << "����ֵ��Ч�����������룺";
                        cin >> menuChoice;
                        menuChoice = -1;
                }
                break;
            }
        }
    }



    // �����������������
    Users::save(users);
    Goods::save(goods);
    Bills::save(bills);

    cout << "��л����ʹ�ã��´��ټ���";
    system("pause");
    return 0;
}
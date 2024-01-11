//
// Created by calfVong on 2023/12/28.
//

#include "head.h"
#include "map"
#include "ctime"

using namespace std;

void Bills::read(vector<Bills> &bills) {
    string fname = R"(.\data\bills.txt)"; // ִ���ļ�·������Ŀ�ļ����£������ļ�ָ����data��
    ifstream txt_data(fname, ios::in);
    Bills new_bill;

    if (!txt_data.is_open()) {
        cout << "�˵���Ϣ�ļ���ʧ�ܣ�";
        pause();
        exit(1);
    } else {
        while (!txt_data.eof()) {
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
    string fname = R"(.\data\bills.txt)"; // ָ���ļ���ַ
    ofstream txt_data(fname, ios::out); // ���ļ�
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "�˵���Ϣ�ļ���ʧ�ܣ�";
        pause();
        exit(1);
    } else
        while (i < bills.size()) {
            if (i == 0) {
                txt_data << bills[i].transactionID << BLANKSPACE
                         << bills[i].time.wYear << BLANKSPACE << bills[i].time.wMonth << BLANKSPACE
                         << bills[i].time.wDay
                         << BLANKSPACE << bills[i].time.wHour << BLANKSPACE << bills[i].time.wMinute
                         << BLANKSPACE << bills[i].id
                         << BLANKSPACE << bills[i].name << BLANKSPACE << bills[i].species << BLANKSPACE
                         << bills[i].sellPrice << BLANKSPACE << bills[i].quantity << BLANKSPACE
                         << bills[i].price << BLANKSPACE << bills[i].profit
                         << BLANKSPACE << bills[i].measure;
            } else {
                txt_data << '\n' << bills[i].transactionID << BLANKSPACE
                         << bills[i].time.wYear << BLANKSPACE << bills[i].time.wMonth << BLANKSPACE
                         << bills[i].time.wDay
                         << BLANKSPACE << bills[i].time.wHour << BLANKSPACE << bills[i].time.wMinute
                         << BLANKSPACE << bills[i].id
                         << BLANKSPACE << bills[i].name << BLANKSPACE << bills[i].species << BLANKSPACE
                         << bills[i].sellPrice << BLANKSPACE << bills[i].quantity << BLANKSPACE
                         << bills[i].price << BLANKSPACE << bills[i].profit
                         << BLANKSPACE << bills[i].measure;
            }
            i++;
        }
    txt_data.close();
}


void Bills::receipt(vector<Bills> market) {
    int i, size = market.size();
    float sum;

    cout << "СƱ��" << endl;
    cout << "=============================" << endl
         << "���   ����  ����   ����  �ܼ�" << endl;
    for (i = 0; i < size; i++) {
        cout << " " << market[i].id << ' ' << BLANKSPACE << market[i].name << "  "
             << market[i].sellPrice << "/" << market[i].measure << BLANKSPACE << market[i].quantity
             << BLANKSPACE << " " << market[i].price << endl;
        sum += market[i].price;
    }
    cout << "����ʱ�䣺" << market[0].time.wYear << "/" << market[0].time.wMonth << "/" << market[0].time.wDay << " "
         << market[0].time.wHour << ":" << market[0].time.wMinute << endl;
    cout << "=============================" << endl;
}

void billsPrint(Bills print_bills) {
    cout << "   " << print_bills.transactionID << setw(8)
         << print_bills.time.wYear << "/" << print_bills.time.wMonth << "/"
         << print_bills.time.wDay << " " << print_bills.time.wHour << ":" << print_bills.time.wMinute
         << setw(6) << print_bills.id
         << setw(11) << print_bills.name
         << setw(7) << print_bills.species
         << setw(5) << print_bills.sellPrice
         << setw(9) << print_bills.quantity
         << setw(6) << print_bills.measure
         << setw(8) << print_bills.price
         << setw(8) << print_bills.profit
         << endl; // ��������ÿ����������

}

void billsMenu() {
    // ��Ϣչʾҳ
    goto_xy(10,10);
    cout << "���ۼ�¼����" << endl;
    goto_xy(10,12);
    cout << "1. ��ʱ��˳��鿴" << endl;
    goto_xy(10,13);
    cout << "2. �����鿴" << endl;
    goto_xy(10,14);
    cout << "3. ����Ʒ���Ʋ鿴" << endl;
    goto_xy(10,15);
    cout << "4. ���۶�ͳ��" << endl;
    goto_xy(10,16);
    cout << "0. �˳�" << endl;
    goto_xy(10,17);
    cout <<"����ѡ�� ";

}

void Bills::data(vector<Bills> &bills) {
    cls();

    // ÿҳ��ʾ�����ۼ�¼����
    int pageSize = 10, pageNumber = 1;
    int choice = 1;

    while (choice) {
        billsMenu();
        cin >> choice;
        switch (choice) {
            case 1: {

                int hang6=13;
                while (pageNumber) {
                    cls();
                    // ������ʼ�ͽ���
                    int startIndex = (pageNumber - 1) * pageSize;
                    int endIndex = pageNumber * pageSize;

                    // ���һҳ����
                    int maxPage = bills.size() / 10 + (bills.size() % 10 > 0);

                    goto_xy(10,10);
                    cout << "��ǰҳ���� �� " << pageNumber << " ҳ" << endl;
                    goto_xy(10,11);
                    cout << "=================================================================================="
                         << endl;
                    goto_xy(10,12);
                    cout << " ���ױ��       ʱ��       ��Ʒ���    ����   ����   ����  ��������   ��λ     �ܼ�   ��������"
                         << endl;
                    for (int j = startIndex, i = startIndex; j < endIndex && i < bills.size(); i++, j++) {
                        // ��ӡ��ǰ���ۼ�¼����Ϣ
                        goto_xy(10,hang6);
                        billsPrint(bills[i]);
                        hang6++;
                    }
                    goto_xy(10,hang6);
                    cout << "=================================================================================="
                         << endl;
                    goto_xy(10,hang6+1);
                    cout << "���ҳ����" << maxPage << endl;
                    goto_xy(10,hang6+2);
                    cout << "������鿴ҳ����0�˳�����";
                    cin >> pageNumber;
                    if (pageNumber > maxPage) {
                        goto_xy(10,hang6+3);
                        cout << "ҳ���������ҳ�������������룺";
                        cin >> pageNumber;
                    } else if (pageNumber < 0) {
                        goto_xy(10,hang6+3);
                        cout << "����ҳ��Ӧ����0�����������룺";
                        cin >> pageNumber;
                    }
                }
                goto_xy(10,hang6+3);
                pause();
                cls();
                break;
            } // ��ʱ��˳��鿴
            case 2: {
                cls();
                // �����Ʒ��������
                vector<string> species;
                for (auto &bill: bills)
                    if (!(count(species.begin(), species.end(), bill.species)))
                        species.push_back(bill.species);
                for (auto &kind: species) {
                    goto_xy(10, 8);
                    cout << kind << endl;
                }

                string speciesChoice;
                goto_xy(10,10);
                cout << "������Ҫ��ѯ����Ʒ���ࣺ";
                cin >> speciesChoice;
                if (count(species.begin(), species.end(), speciesChoice)) {
                    vector<Bills> speciesBills;
                    for (const auto &bill: bills)
                        if (bill.species == speciesChoice)
                            speciesBills.push_back(bill);

                    while (pageNumber) {
                        // ������ʼ�ͽ���
                        cls();
                        int startIndex = (pageNumber - 1) * pageSize;
                        int endIndex = pageNumber * pageSize;

                        // ���һҳ����
                        int maxPage = speciesBills.size() / 10 + (speciesBills.size() % 10 > 0);

                        goto_xy(10,11);
                        cout << "��ǰҳ���� �� " << pageNumber << " ҳ" << endl;
                        goto_xy(10,12);
                        cout << "=================================================================================="
                             << endl;
                        goto_xy(10,13);
                        cout << " ���ױ��       ʱ��       ��Ʒ���    ����   ����   ����  ��������   ��λ     �ܼ�   ��������"
                             << endl;
                        // j��ѭ�����ƣ�i�����޿���
                        for (int j = startIndex, i = startIndex; j < endIndex && i < speciesBills.size(); i++, j++) {
                            // �����Ʒ�����Ƿ��������
                            cls();
                            goto_xy(10,12);
                            cout << "=================================================================================="
                                 << endl;
                            goto_xy(10,13);
                            cout << " ���ױ��       ʱ��       ��Ʒ���    ����   ����   ����  ��������   ��λ     �ܼ�   ��������"
                                 << endl;
                            if (speciesBills[i].species == speciesChoice) {
                                // ��ӡ��ǰ���ۼ�¼����Ϣ
                                goto_xy(10,14);
                                billsPrint(bills[i]);
                            } else {
                                j--;
                                continue;
                            }
                        }
                        goto_xy(10,15);
                        cout << "=================================================================================="
                             << endl;
                        goto_xy(10,16);
                        cout << "���ҳ����" << maxPage << endl;
                        goto_xy(10,17);
                        cout << "������鿴ҳ����0�˳�����";
                        cin >> pageNumber;
                        if (pageNumber > maxPage) {
                            goto_xy(10,18);
                            cout << "ҳ���������ҳ�������������룺";
                            cin >> pageNumber;
                        } else if (pageNumber < 0) {
                            goto_xy(10,18);
                            cout << "����ҳ��Ӧ����0�����������룺";
                            cin >> pageNumber;
                        }
                    }
                    cls();
                }

                break;

            } // �����
            case 3: {
                // �����Ʒ��������
                cls();
                vector<string> names;
                for (auto &bill: bills)
                    if (!(count(names.begin(), names.end(), bill.name)))
                        names.push_back(bill.name);
                int shuaige=10;
                for (auto &name: names) {
                    goto_xy(10, shuaige);
                    cout << name << endl;
                    shuaige++;
                }

                string nameChoice;
                goto_xy(10,shuaige);
                cout << "������Ҫ��ѯ����Ʒ���ࣺ";
                cin >> nameChoice;
                if (count(names.begin(), names.end(), nameChoice)) {
                    vector<Bills> namesBills;
                    for (const auto &bill: bills)
                        if (bill.name == nameChoice)
                            namesBills.push_back(bill);

                    while (pageNumber) {
                        // ������ʼ�ͽ���

                        cls();
                        int startIndex = (pageNumber - 1) * pageSize;
                        int endIndex = pageNumber * pageSize;

                        // ���һҳ����
                        int maxPage = namesBills.size() / 10 + (namesBills.size() % 10 > 0);
                        goto_xy(10,shuaige);
                        cout << "=================================================================================="
                             << endl;
                        goto_xy(10,shuaige+1);
                        cout << "��ǰҳ���� �� " << pageNumber << " ҳ" << endl;
                        // j��ѭ�����ƣ�i�����޿���
                        for (int j = startIndex, i = startIndex; j < endIndex && i < namesBills.size(); i++, j++) {
                            // �����Ʒ�����Ƿ��������
                            if (namesBills[i].species == nameChoice) {
                                // ��ӡ��ǰ���ۼ�¼����Ϣ
                                goto_xy(10,shuaige+2);
                                billsPrint(bills[i]);
                            } else {
                                j--;
                                continue;
                            }
                        }
                        goto_xy(10,shuaige+3);
                        cout << "=================================================================================="
                             << endl;
                        goto_xy(10,shuaige+4);
                        cout << "���ҳ����" << maxPage << endl;
                        goto_xy(10,shuaige+5);
                        cout << "������鿴ҳ����0�˳�����";
                        cin >> pageNumber;
                        if (pageNumber > maxPage) {
                            goto_xy(10,shuaige+6);
                            cout << "ҳ���������ҳ�������������룺";
                            cin >> pageNumber;
                        } else if (pageNumber < 0) {
                            goto_xy(10,shuaige+7);
                            cout << "����ҳ��Ӧ����0�����������룺";
                            cin >> pageNumber;
                        }
                    }
                    cls();
                }
                break;
            } // ������
            case 4: {
                analyzeSales(bills);
                break;
            } // ���۶�ͳ�ƺ���
            case 0:
                cls();
                break;
            default:
                cout << "��������Чֵ�� ";
                break;
        }
    }
}

void Bills::analyzeSales(vector<Bills> &bills) {

    // ��ʼ��ÿ�ա�ÿ�ܺ�ÿ�����۵ı���
    map<int, map<string, int >> dailySalesQuantity;  // �� -> ��Ʒ -> ����
    map<int, map<string, double >> dailySalesTotal;  // �� -> ��Ʒ -> �ܽ��
    map<int, map<string, double >> weeklySalesTotal;  // �� -> ��Ʒ -> �ܽ��
    map<int, map<string, double >> monthlySalesTotal;  // �� -> ��Ʒ -> �ܽ��

    // ��ȡ��ǰ���ں�ʱ��
    SYSTEMTIME currentTime;
    GetSystemTime(&currentTime);
    int currentDay = currentTime.wDay;  // ���µ�������1-31��
    int currentWeek = (currentTime.wDay - 1) / 7 + 1;  // �����������1-52��
    int currentMonth = currentTime.wMonth;  // ��ǰ�·ݣ�1-12��

    // ����ÿ�ա�ÿ�ܺ�ÿ�µ�����ͳ������
    for (const Bills &bill: bills) {
        int billDay = bill.time.wDay;  // ���˵�������1-31��
        int billWeek = (bill.time.wDay - 1) / 7 + 1;  // ���˵�������1-52��
        int billMonth = bill.time.wMonth;  // ���˵��·ݣ�1-12��

        // ����ÿ������ͳ������
        dailySalesQuantity[billDay][bill.name] += bill.quantity;  // ��ӵ�ÿ��������
        dailySalesTotal[billDay][bill.name] += bill.price * bill.quantity;  // ��ӵ�ÿ���ܽ���У����ǵ�ÿ����Ʒ���۵������͵���

        // ����ÿ������ͳ������
        weeklySalesTotal[billWeek][bill.name] += bill.price * bill.quantity;  // ��ӵ�ÿ���ܽ���У����ǵ�ÿ����Ʒ���۵������͵���

        // ����ÿ������ͳ������
        monthlySalesTotal[billMonth][bill.name] += bill.price * bill.quantity;  // ��ӵ�ÿ���ܽ���У����ǵ�ÿ����Ʒ���۵������͵���
    }

    // ��ӡÿ������ͳ�����ݣ��������ܽ�
    cls();

    cout << "ÿ�����۶��:" << endl;
    for (const auto &daySales: dailySalesQuantity) {


        cout << "��" << daySales.first << "��: ";
        for (const auto &productSales: daySales.second) {
            cout << productSales.first << ": " << productSales.second << " ��, "
                 << dailySalesTotal[daySales.first][productSales.first] << " �ܽ��" << endl;
        }
    }
    // ��ӡÿ������ͳ�����ݣ��������ܽ�
    cout << "ÿ�������ܶ�:" << endl;
    for (const auto &weekSales: weeklySalesTotal) {
        int weekNumber = weekSales.first;
        cout << "��" << weekNumber << "��: ";
        for (const auto &productSales: weekSales.second) {
            cout << productSales.first << ": ";
            cout << "�ܽ��: " << weeklySalesTotal[weekNumber][productSales.first] << endl;
        }
    }

    // ��ӡÿ������ͳ�����ݣ��������ܽ�
    cout << "ÿ�������ܶ�:" << endl;
    for (const auto &monthSales: monthlySalesTotal) {
        int monthNumber = monthSales.first;
        cout << "��" << monthNumber << "��: ";
        for (const auto &productSales: monthSales.second) {
            cout << productSales.first << ": ";
            cout << "�ܽ��: " << monthlySalesTotal[monthNumber][productSales.first] << endl;
        }
    }
}
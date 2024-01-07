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

    if(!txt_data.is_open()){
        cout << "�˵���Ϣ�ļ���ʧ�ܣ�";
        pause();
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
    string fname = R"(.\data\bills.txt)"; // ָ���ļ���ַ
    ofstream txt_data(fname, ios::out); // ���ļ�
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "�˵���Ϣ�ļ���ʧ�ܣ�";
        pause();
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

    // cout �˵�ͷ
    cout<<"СƱ��";
    for(i=0;i<size;i++)
        cout<<market[i].id<<BLANKSPACE<<market[i].name<<BLANKSPACE
        <<market[i].sellPrice<<BLANKSPACE<<market[i].quantity<<market[i].measure
        <<BLANKSPACE<<market[i].price<<endl;
    cout<<"����ʱ�䣺"<<market[0].time.wYear<<"/"<<market[0].time.wMonth<<"/"<<market[0].time.wDay<<" "
    <<market[0].time.wHour<<":"<<market[0].time.wMinute<<endl;
}

// �������ݵĺ���
void Bills::data(vector<Bills> market,const Bills& bill, int pageNumber, const string& name, const string& species) {

    // ÿҳ��ʾ�����ۼ�¼����
    int pageSize = 10;

    // ������ʼ�ͽ���
    int startIndex = (pageNumber - 1) * pageSize;
    int endIndex = pageNumber * pageSize;

    // ����ָ����Χ�ڵ����ۼ�¼
    for (int i = startIndex; i < endIndex && i < market.size(); i++) {
        // ��ӡ��ǰ���ۼ�¼����Ϣ
        cout << " ���ױ��: " << market[i].transactionID ;
        cout << " ʱ��: " << market[i].time.wYear << "/" << market[i].time.wMonth << "/" << market[i].time.wDay << " "
             << market[i].time.wHour << ":" << market[i].time.wMinute ;
        cout << " ��Ʒ���: " << market[i].id ;
        cout << " ��Ʒ����: " << market[i].name ;
        cout << " ��Ʒ����: " << market[i].species ;
        cout << " ��Ʒ����: " << market[i].sellPrice ;
        cout << " ��������: " << market[i].quantity ;
        cout << " ������λ: " << market[i].measure ;
        cout << " �����ܼ�: " << market[i].price ;
        cout << " ��������: " << market[i].profit ;
        cout << endl; // ��������ÿ����������
    }
    // ��ʾ����Ա�鿴���ۼ�¼�Ľ���
    cout << "����ѡ�" << endl;
    cout << "1. �����鿴" << endl;
    cout << "2. ����Ʒ���Ʋ鿴" << endl;
    cout << "3. ���۶�ͳ��" << endl;
    cout << "0. �˳�" << endl;

    int choice = 1;
    cin >> choice;
    switch (choice) {

        case 1: {   //�����
            for (int i = startIndex; i < endIndex && i < market.size(); i++) {
                // �����Ʒ�����Ƿ��������
                if (market[i].species == species) {
                    // ��ӡ��ǰ���ۼ�¼����Ϣ
                    cout << " ���ױ��: " << market[i].transactionID;
                    cout << " ʱ��: " << market[i].time.wYear << "/" << market[i].time.wMonth << "/"
                         << market[i].time.wDay << " "<< market[i].time.wHour << ":" << market[i].time.wMinute;
                    cout << " ��Ʒ���: " << market[i].id;
                    cout << " ��Ʒ����: " << market[i].name;
                    cout << " ��Ʒ����: " << market[i].species;
                    cout << " ��Ʒ����: " << market[i].sellPrice;
                    cout << " ��������: " << market[i].quantity;
                    cout << " ������λ: " << market[i].measure;
                    cout << " �����ܼ�: " << market[i].price;
                    cout << " ��������: " << market[i].profit;
                    cout << endl; // ��������ÿ����������
                }
            }
            break;
        }
        case 2: {   //������
            for (int i = startIndex; i < endIndex && i < market.size(); i++) {
                // �����Ʒ�����Ƿ��������
                if (market[i].name == name) {
                    // ��ӡ��ǰ���ۼ�¼����Ϣ
                    cout << " ���ױ��: " << market[i].transactionID;
                    cout << " ʱ��: " << market[i].time.wYear << "/" << market[i].time.wMonth << "/"
                         << market[i].time.wDay << " "<< market[i].time.wHour << ":" << market[i].time.wMinute;
                    cout << " ��Ʒ���: " << market[i].id;
                    cout << " ��Ʒ����: " << market[i].name;
                    cout << " ��Ʒ����: " << market[i].species;
                    cout << " ��Ʒ����: " << market[i].sellPrice;
                    cout << " ��������: " << market[i].quantity;
                    cout << " ������λ: " << market[i].measure;
                    cout << " �����ܼ�: " << market[i].price;
                    cout << " ��������: " << market[i].profit;
                    cout << endl; // ��������ÿ����������
                }
            }
            break;
        }
        case 3: {

                break;
            }
            case 0:
                break;
            default:
                cout << "��������Чֵ�� ";
            return;
        }
    }

void Bills::analyzeSales(vector<Bills> &bills) {
    // ��ʼ��ÿ�ա�ÿ�ܺ�ÿ�����۵ı���
    map < int, map < string, int >> dailySalesQuantity;  // �� -> ��Ʒ -> ����
    map < int, map < string, double >> dailySalesTotal;  // �� -> ��Ʒ -> �ܽ��
    map < int, map < string, double >> weeklySalesTotal;  // �� -> ��Ʒ -> �ܽ��
    map < int, map < string, double >> monthlySalesTotal;  // �� -> ��Ʒ -> �ܽ��

    // ��ȡ��ǰ���ں�ʱ��
    SYSTEMTIME currentTime;
    GetSystemTime(&currentTime);
    int currentDay = currentTime.wDay;  // ���µ�������1-31��
    int currentWeek = (currentTime.wDay - 1) / 7 + 1;  // �����������1-52��
    int currentMonth = currentTime.wMonth;  // ��ǰ�·ݣ�1-12��

    // ����ÿ�ա�ÿ�ܺ�ÿ�µ�����ͳ������
    for (const Bills& bill : bills) {
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
    cout << "ÿ�����۶��:" << endl;
    for (const auto& daySales : dailySalesQuantity) {
        cout << "��" << daySales.first << "��: ";
        for (const auto& productSales : daySales.second) {
            cout << productSales.first << ": " << productSales.second << " ��, " << dailySalesTotal[daySales.first][productSales.first] << " �ܽ��" << endl;
        }
    }
    // ��ӡÿ������ͳ�����ݣ��������ܽ�
    cout << "ÿ�������ܶ�:" << endl;
    for (const auto& weekSales : weeklySalesTotal) {
        int weekNumber = weekSales.first;
        cout << "��" << weekNumber << "��: ";
        for (const auto& productSales : weekSales.second) {
            cout << productSales.first << ": ";
            cout << "�ܽ��: " << weeklySalesTotal[weekNumber][productSales.first] << endl;
        }
    }

    // ��ӡÿ������ͳ�����ݣ��������ܽ�
    cout << "ÿ�������ܶ�:" << endl;
    for (const auto& monthSales : monthlySalesTotal) {
        int monthNumber = monthSales.first;
        cout << "��" << monthNumber << "��: ";
        for (const auto& productSales : monthSales.second) {
            cout << productSales.first << ": ";
            cout << "�ܽ��: " << monthlySalesTotal[monthNumber][productSales.first] << endl;
        }
    }
}
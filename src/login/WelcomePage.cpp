//
// Created by calfVong on 2023/12/22.
//

#include "iostream"
#include "fstream"

#include "..\\head.h"
#include "WelcomePage.h"

using namespace std;

Users user_login(Users user, string login_id, string login_pwd) {// ��ȡ�ļ���֤�û������Ϣ
    // �����β�Ϊһ���µ�users�ṹ�壬��¼id�͵�½����

    string fname = R"(.\data\users.txt)"; // ִ���ļ�·������Ŀ�ļ����£������ļ�ָ����data��
    ifstream txt_data(fname, ios::in);
    int sta = 0;

    if (!txt_data.is_open()) {
        cout << "�û��ļ���ʧ��";
    } else {
        while (!txt_data.eof()) {
            txt_data >> user.name >> user.id >> user.pwd >> user.level;
            // �Ӵ򿪵��ļ�����ν���������

            if (user.id == login_id && user.pwd == login_pwd) {
                sta = 1;
                break; // ���û�����������ȷʱ�˳�ѭ��
            }
        }
    }
    txt_data.close();


    if(sta == 0) {
        goto_xy(35,13);
        cout << "�˺Ż������������������" << endl;
        user.name = "NOTFOUND";
        pause();
        cls();
        return user;
    }

    return user;
}

Users login() {

    // �����µ�users��
    Users user = *new Users;

    string id, pwd;

    // �������

    do{
        goto_xy(35,10);
        cout<<"����ע�������� reg ������ʹ�÷ÿ���ݵ�¼������ 0 ";
        goto_xy(35,11);
        cout<<"�������û�����";
        cin>>id;
        if(id == "reg") {
            user.id = "reg";
            return user;
        } else if (id == "0") {
            user.id = "0";
            return user;
        }
        else {
            goto_xy(35,12);
            cout << "���������룺";
            cin >> pwd;
        }
        // ���ú������ҵ�¼Ŀ��
        user = user_login(user, id, pwd);
    } while (user.name == "NOTFOUND");

    goto_xy(50,13);
    cout << user.name << " " << user.id << endl;

    return user;

}
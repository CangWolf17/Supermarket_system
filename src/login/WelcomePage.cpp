//
// Created by calfVong on 2023/12/22.
//

#include "iostream"
#include "fstream"
#include "windows.h"

#include "..\\head.h"
#include "WelcomePage.h"

using namespace std;

Users user_login(Users user, string login_id, string login_pwd){// ��ȡ�ļ���֤�û������Ϣ
    // �����β�Ϊһ���µ�users�ṹ�壬��¼id�͵�½����

    string fname = R"(.\data\users.txt)"; // ִ���ļ�·������Ŀ�ļ����£������ļ�ָ����data��
    ifstream txt_data(fname, ios::in);
    int sta = 0;

    if(!txt_data.is_open()){
        cout << "�ļ���ʧ��";
    }
    else{
        while(!txt_data.eof()){
            txt_data >> user.name >> user.userID >> user.userPwd >> user.userLevel;
            // �Ӵ򿪵��ļ�����ν�������ṹ��

            if(user.userID == login_id && user.userPwd == login_pwd) {
                sta = 1;
                break; // ���û�����������ȷʱ�˳�ѭ��
            }
        }
    }
    txt_data.close();

    if(sta == 0) {
        cout << "�˺Ż������������������" << endl;
        user.name = "NOTFOUND";
        return user;
    }

    return user;
}

Users login(){

    // �����µ�users��
    Users user = *new Users;

    string id, pwd;
    do{
    cout<<"�������û�����";
    cin>>id;
    cout<<"���������룺";
    cin>>pwd;

    // ���ú������ҵ�¼Ŀ��
    user = user_login(user,id,pwd);
    }while(user.name == "NOTFOUND");

    cout<<user.name<<" "<<user.userID;

    return user;

}
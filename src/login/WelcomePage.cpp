//
// Created by calfVong on 2023/12/22.
//

#include "iostream"
#include "fstream"
#include "windows.h"

#include "WelcomePage.h"

using namespace std;

void welPage(){ // ��ӭ����
    // ��ӭҳ�棬δ���


}

users user_login(users user, string login_id, string login_pwd){// ��ȡ�ļ���֤�û������Ϣ
    // �����β�Ϊһ���µ�users�ṹ�壬��¼id�͵�½����

    string fname = R"(.\data\users.txt)"; // ִ���ļ�·������Ŀ�ļ����£������ļ�ָ����data��
    ifstream txt_data(fname, ios::in);
    int sta = 0;

    if(!txt_data.is_open()){
        cout << "�ļ���ʧ��";
        cin>>sta;
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

    if(sta == 0)
        cout<<"�˺Ż������������������";

    return user;
}

void login(){

    // �����µ�users�ṹ��
    users user = *new users;

    welPage();

    string id, pwd;
    cout<<"�������û�����";
    cin>>id;
    cout<<"���������룺";
    cin>>pwd;

    // ���ú������ҵ�¼Ŀ��
    user = user_login(user,id,pwd);
    cout<<user.name<<" "<<user.userID;

}
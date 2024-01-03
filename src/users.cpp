//
// Created by calfVong on 2023/12/29.
//
#include "iostream"
#include "fstream"

#include "head.h"

#define BLANKSPACE "   "

using namespace std;

void Users::read(vector<Users> &users){
    string fname = R"(.\data\users.txt)"; // ִ���ļ�·������Ŀ�ļ����£������ļ�ָ����data��
    ifstream txt_data(fname, ios::in);
    Users new_user;

    if(!txt_data.is_open()){
        cout << "�ļ���ʧ��";
        exit(1);
    }
    else{
        while(!txt_data.eof()){
            txt_data >> new_user.name >> new_user.id >> new_user.pwd >> new_user.level;
            users.push_back(new_user);
        }
    }
    txt_data.close();

}

void Users::save(vector<Users> &users) {
    string fname = R"(.\data\users.txt)"; // ָ���ļ���ַ
    ofstream txt_data(fname, ios::out); // ���ļ�
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "�ļ���ʧ��";
        exit(1);
    } else while(i<users.size()-1){
            cout << users[i].name << BLANKSPACE << users[i].id << BLANKSPACE
                 << users[i].pwd << BLANKSPACE << users[i].level << '\n';
            txt_data << users[i].name << BLANKSPACE << users[i].id << BLANKSPACE
                     << users[i].pwd << BLANKSPACE << users[i].level << '\n';
            i++;
        }
    txt_data.close();

}


void Users::reg() {

}

void Users::del() {

}

void Users::edit() {

}

void Users::create() {

}

void Users::adminDel() {

}


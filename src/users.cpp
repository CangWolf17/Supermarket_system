//
// Created by calfVong on 2023/12/29.
//
#include "iostream"
#include "fstream"

#include "head.h"

#define BLANKSPACE "   "

using namespace std;

void Users::read(vector<Users> &users){
    string fname = R"(.\data\users.txt)"; // 执行文件路径在项目文件夹下，数据文件指定在data下
    ifstream txt_data(fname, ios::in);
    Users new_user;

    if(!txt_data.is_open()){
        cout << "文件打开失败";
        exit(1);
    }
    else{
        while(!txt_data.eof()){
            txt_data >> new_user.name >> new_user.userID >> new_user.userPwd >> new_user.userLevel;
            users.push_back(new_user);
        }
    }
    txt_data.close();

}

void Users::save(vector<Users> &users) {
    string fname = R"(.\data\users.txt)"; // 指定文件地址
    ofstream txt_data(fname, ios::out); // 打开文件
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "文件打开失败";
        exit(1);
    } else while(i<users.size()-1){
            cout<<users[i].name << BLANKSPACE << users[i].userID << BLANKSPACE
                << users[i].userPwd << BLANKSPACE << users[i].userLevel <<'\n';
            txt_data << users[i].name << BLANKSPACE << users[i].userID << BLANKSPACE
            << users[i].userPwd << BLANKSPACE << users[i].userLevel <<'\n';
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


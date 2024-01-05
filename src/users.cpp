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
            txt_data >> new_user.name >> new_user.id >> new_user.pwd >> new_user.level;
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
            cout << users[i].name << BLANKSPACE << users[i].id << BLANKSPACE
                 << users[i].pwd << BLANKSPACE << users[i].level << '\n';
            txt_data << users[i].name << BLANKSPACE << users[i].id << BLANKSPACE
                     << users[i].pwd << BLANKSPACE << users[i].level << '\n';
            i++;
        }
    txt_data.close();

}


void Users::search(vector<Users> &users, string s, Users &find_user){
    int i = 0;

    if(isDigitStr(s)) {
        int num = strTurnNum(s);

        for(i=0;i<users.size();i++)
            if(i == num) {
                find_user = users[i];
                return;
            }

        find_user.id = -1;
    }
    else{
        for(i=0;i<users.size();i++)
            if(users[i].name == s) {
                find_user = users[i];
                return;
            }

        find_user.id = "-1";
    }
}

bool Users::add(vector<Users> &users, Users new_user) {

    // 安全检查
    int i;
    for(i=0;i<users.size();i++)
        if(users[i].name == new_user.name || users[i].id == new_user.id)
            return false;

    users.push_back(new_user);
    return true;
}

void Users::del(vector<Users> &users, string id) {
    int i;

    for(i=0;i<users.size();i++)
        if(users[i].id == id)
            break;
}

void Users::edit(vector<Users> &users, int i, int kind, string new_value) {

    switch (kind) {
        case 1:
            users[i].name = new_value;
            break;
        case 2:
            users[i].id = new_value;
            break;
        case 3:
            users[i].pwd = new_value;
            break;
        case 4:
            users[i].level = strTurnNum(new_value);
            break;
    }
}


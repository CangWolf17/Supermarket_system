//
// Created by calfVong on 2023/12/29.
//

#include "head.h"

using namespace std;

void Users::read(vector<Users> &users) {
    string fname = R"(.\data\users.txt)"; // 执行文件路径在项目文件夹下，数据文件指定在data下
    ifstream txt_data(fname, ios::in);
    Users new_user;

    if (!txt_data.is_open()) {
        cout << "用户信息文件打开失败！";
        pause();
        exit(1);
    } else {
        while (!txt_data.eof()) {
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
        cout << "用户信息文件打开失败！";
        pause();
        exit(1);
    } else
        while (i < users.size()) {
            if (i == 0) {
                txt_data << users[i].name << BLANKSPACE << users[i].id << BLANKSPACE
                         << users[i].pwd << BLANKSPACE << users[i].level;
            } else {
                txt_data << '\n' << users[i].name << BLANKSPACE << users[i].id << BLANKSPACE
                         << users[i].pwd << BLANKSPACE << users[i].level;
            }
            i++;
        }
    txt_data.close();
}


void Users::add(vector<Users> &users, int level) {


    // 前端询问
    cls();
    int i;
    Users new_user;
    new_user.level = 0;
    goto_xy(10,10);
    cout << "请输入新用户姓名：";
    cin >> new_user.name;
    goto_xy(10,11);
    cout << "请输入新用户id：";
    cin >> new_user.id;
    while (new_user.id == "reg" || new_user.id == "0") {
        goto_xy(10,12);
        cout << "用户id非法！" << endl;
        goto_xy(10,13);
        cout << "请再次输入：";
        cin >> new_user.id;
    }

    // 安全检查
    for (i = 0; i < users.size(); i++)
        if (users[i].name == new_user.name || users[i].id == new_user.id) {
            goto_xy(10,15);
            cout << "输入的用户姓名或id已存在" << endl;
            goto_xy(10,16);
            pause();
            return;
        }

    goto_xy(10,12);
    cout << "请输入新用户密码：";
    cin >> new_user.pwd;
    goto_xy(10,13);
    cout << "请再次输入新用户密码以确认：";
    string tmp;
    cin >> tmp;

    if (new_user.pwd != tmp) {
        goto_xy(10,14);
        cout << "二次输入错误，程序即将返回..." << endl;
        goto_xy(10,15);
        pause();
        return;
    } else {
        if (level == 3) {
            goto_xy(10,14);
            cout << "请输入新用户权限（顾客0，仓库管理员1，收银员2，管理员3）：";
            cin >> new_user.level;
        }
    }

    users.push_back(new_user);
    goto_xy(10,15);
    cout << "创建新用户成功。" << endl;
    goto_xy(10,16);
    pause();
}

void Users::del(vector<Users> &users) {
    int i;
    string userid;

    goto_xy(10,19);
    cout << "请输入要删除的用户id：";
    cin >> userid;

    for (i = 0; i < users.size(); i++)
        if (users[i].id == userid)
            break;

    int index = i;             // 获取选择的用户的索引
    users.erase(users.begin() + index); // 删除选中的用户
    cout << "删除成功！" << endl;
}

void Users::pwdedit(vector<Users> &users, Users currentUser) {
    cls();
    int i, size = users.size();

    for (i = 0; i < size; i++)
        if (users[i].id == currentUser.id)
            break;

    string old_pwd, new_pwd;
    goto_xy(10,10);
    cout << "请输入原密码：";
    cin >> old_pwd;
    if (old_pwd == users[i].pwd) {
        goto_xy(10,11);
        cout << "请输入新密码：";
        cin >> new_pwd;
        string tmp;
        goto_xy(10,12);
        cout << "请再次输入新密码：";
        cin >> tmp;
        if (new_pwd == tmp) {
            users[i].pwd = new_pwd;
            goto_xy(10,13);
            cout << "密码修改成功！";
            goto_xy(10,14);
            pause();
        } else
            goto_xy(10,13);
            cout << "二次密码输入错误，程序即将返回...";
    } else {
        goto_xy(10,13);
        cout << "原密码错误！" ;
        pause();
    }

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


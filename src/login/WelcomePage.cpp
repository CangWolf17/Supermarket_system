//
// Created by calfVong on 2023/12/22.
//

#include "iostream"
#include "fstream"
#include "windows.h"

#include "WelcomePage.h"

using namespace std;

void welPage(){ // 欢迎界面
    // 欢迎页面，未设计


}

users user_login(users user, string login_id, string login_pwd){// 读取文件验证用户身份信息
    // 传入形参为一个新的users结构体，登录id和登陆密码

    string fname = R"(.\data\users.txt)"; // 执行文件路径在项目文件夹下，数据文件指定在data下
    ifstream txt_data(fname, ios::in);
    int sta = 0;

    if(!txt_data.is_open()){
        cout << "文件打开失败";
        cin>>sta;
    }
    else{
        while(!txt_data.eof()){
            txt_data >> user.name >> user.userID >> user.userPwd >> user.userLevel;
            // 从打开的文件中逐次将流存入结构体

            if(user.userID == login_id && user.userPwd == login_pwd) {
                sta = 1;
                break; // 当用户名和密码正确时退出循环
            }
        }
    }
    txt_data.close();

    if(sta == 0)
        cout<<"账号或密码错误！请重新输入";

    return user;
}

void login(){

    // 创建新的users结构体
    users user = *new users;

    welPage();

    string id, pwd;
    cout<<"请输入用户名：";
    cin>>id;
    cout<<"请输入密码：";
    cin>>pwd;

    // 调用函数查找登录目标
    user = user_login(user,id,pwd);
    cout<<user.name<<" "<<user.userID;

}
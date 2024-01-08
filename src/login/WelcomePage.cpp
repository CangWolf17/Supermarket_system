//
// Created by calfVong on 2023/12/22.
//

#include "iostream"
#include "fstream"

#include "..\\head.h"
#include "WelcomePage.h"

using namespace std;

Users user_login(Users user, string login_id, string login_pwd){// 读取文件验证用户身份信息
    // 传入形参为一个新的users结构体，登录id和登陆密码

    string fname = R"(.\data\users.txt)"; // 执行文件路径在项目文件夹下，数据文件指定在data下
    ifstream txt_data(fname, ios::in);
    int sta = 0;

    if(!txt_data.is_open()){
        cout << "用户文件打开失败";
    }
    else{
        while(!txt_data.eof()){
            txt_data >> user.name >> user.id >> user.pwd >> user.level;
            // 从打开的文件中逐次将流存入类

            if(user.id == login_id && user.pwd == login_pwd) {
                sta = 1;
                break; // 当用户名和密码正确时退出循环
            }
        }
    }
    txt_data.close();

    if(sta == 0) {
        cout << "账号或密码错误！请重新输入" << endl;
        user.name = "NOTFOUND";
        return user;
    }

    return user;
}

Users login(){

    // 创建新的users类
    Users user = *new Users;

    string id, pwd;

    // 输出部分
    do{
        cout<<"欢迎使用超市管理系统"<<endl;
        cout<<"如需注册请输入 reg ，如需使用访客身份登录请输入 0 "<<endl;
        cout<<"请输入用户名：";
        cin>>id;
        if(id == "reg") {
            user.id = "reg";
            return user;
        }
        else if(id == "0") {
            user.id = "0";
            return user;
        }
        else {
            cout << "请输入密码：";
            cin >> pwd;
        }
        // 调用函数查找登录目标
        user = user_login(user,id,pwd);
    }while(user.name == "NOTFOUND");

    cout << user.name << " " << user.id << endl;

    return user;

}
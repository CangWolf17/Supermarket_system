//
// Created by calfVong on 2023/12/29.
//

#include "head.h"

using namespace std;

void Users::read(vector<Users> &users) {
    string fname = R"(.\data\users.txt)"; // ִ���ļ�·������Ŀ�ļ����£������ļ�ָ����data��
    ifstream txt_data(fname, ios::in);
    Users new_user;

    if (!txt_data.is_open()) {
        cout << "�û���Ϣ�ļ���ʧ�ܣ�";
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
    string fname = R"(.\data\users.txt)"; // ָ���ļ���ַ
    ofstream txt_data(fname, ios::out); // ���ļ�
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "�û���Ϣ�ļ���ʧ�ܣ�";
        pause();
        exit(1);
    } else
        while (i < users.size()) {
            if(i == 0) {
                txt_data << users[i].name << BLANKSPACE << users[i].id << BLANKSPACE
                         << users[i].pwd << BLANKSPACE << users[i].level;
            }else{
                txt_data << '\n' << users[i].name << BLANKSPACE << users[i].id << BLANKSPACE
                         << users[i].pwd << BLANKSPACE << users[i].level;
            }
            i++;
        }
    txt_data.close();

}


void Users::search(vector<Users> &users, string s, Users &find_user) {
    int i;

    for (i = 0; i < users.size(); i++) // ͨ������id������Ʒ
        if (users[i].id == s) {
            find_user = users[i];
            return;
        }

    find_user.id = "-1";
}

void Users::add(vector<Users> &users, int level) {


    // ǰ��ѯ��
    int i;
    Users new_user;
    new_user.level = 0;
    cout << "���������û�������";
    cin >> new_user.name;
    cout << "���������û�id��";
    cin >> new_user.id;
    while (new_user.id == "reg" || new_user.id == "0") {
        cout << "�û�id�Ƿ���" << endl;
        cout << "���ٴ����룺" << endl;
        cin >> new_user.id;
    }

    // ��ȫ���
    for (i = 0; i < users.size(); i++)
        if (users[i].name == new_user.name || users[i].id == new_user.id) {
            cout << "������û�������id�Ѵ���" << endl;
            pause();
            return;
        }

    cout << "���������û����룺";
    cin >> new_user.pwd;
    cout << "���ٴ��������û�������ȷ�ϣ�";
    string tmp;
    cin >> tmp;

    if (new_user.pwd != tmp) {
        cout << "����������󣬳��򼴽�����..." << endl;
        pause();
        return;
    } else {
        if (level == 3) {
            cout << "���������û�Ȩ�ޣ��˿�0���ֿ����Ա1������Ա2������Ա3����";
            cin >> new_user.level;
        }
    }

    users.push_back(new_user);
    cout << "�������û��ɹ���"<<endl;
    pause();
}

void Users::del(vector<Users> &users) {
    int i;
    string userid;

    cout  << "������Ҫɾ�����û�id��";
    cin >> userid;

    for (i = 0; i < users.size(); i++)
        if (users[i].id == userid)
            break;

    int index = i;             // ��ȡѡ����û�������
    users.erase(users.begin() + index); // ɾ��ѡ�е��û�
    cout << "ɾ���ɹ���" << endl;
}

void Users::pwdedit(vector<Users> &users, Users currentUser) {
    int i, size = users.size();

    for (i = 0; i < size; i++)
        if (users[i].id == currentUser.id)
            break;

    string old_pwd, new_pwd;
    cout << "������ԭ���룺";
    cin >> old_pwd;
    if (old_pwd == users[i].pwd) {
        cout << "�����������룺";
        cin >> new_pwd;
        string tmp;
        cout << "���ٴ����������룺";
        cin >> tmp;
        if (new_pwd == tmp) {
            users[i].pwd = new_pwd;
            cout << "�����޸ĳɹ���" << endl;
        } else
            cout << "��������������󣬳��򼴽�����...";
    } else {
        cout << "ԭ�������" << endl;
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


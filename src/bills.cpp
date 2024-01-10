//
// Created by calfVong on 2023/12/28.
//

#include "head.h"
#include "map"
#include "ctime"

using namespace std;

void Bills::read(vector<Bills> &bills) {
    string fname = R"(.\data\bills.txt)"; // 执行文件路径在项目文件夹下，数据文件指定在data下
    ifstream txt_data(fname, ios::in);
    Bills new_bill;

    if (!txt_data.is_open()) {
        cout << "账单信息文件打开失败！";
        pause();
        exit(1);
    } else {
        while (!txt_data.eof()) {
            txt_data >> new_bill.transactionID >>
                     new_bill.time.wYear >> new_bill.time.wMonth >> new_bill.time.wDay
                     >> new_bill.time.wHour >> new_bill.time.wMinute
                     >> new_bill.id >> new_bill.name >> new_bill.species
                     >> new_bill.sellPrice >> new_bill.quantity
                     >> new_bill.price >> new_bill.profit >> new_bill.measure;
            bills.push_back(new_bill);
        }
    }
    txt_data.close();
}

void Bills::save(vector<Bills> &bills) {
    string fname = R"(.\data\bills.txt)"; // 指定文件地址
    ofstream txt_data(fname, ios::out); // 打开文件
    int i = 0;

    if (!txt_data.is_open()) {
        cout << "账单信息文件打开失败！";
        pause();
        exit(1);
    } else
        while (i < bills.size()) {
            if (i == 0) {
                txt_data << bills[i].transactionID << BLANKSPACE
                         << bills[i].time.wYear << BLANKSPACE << bills[i].time.wMonth << BLANKSPACE
                         << bills[i].time.wDay
                         << BLANKSPACE << bills[i].time.wHour << BLANKSPACE << bills[i].time.wMinute
                         << BLANKSPACE << bills[i].id
                         << BLANKSPACE << bills[i].name << BLANKSPACE << bills[i].species << BLANKSPACE
                         << bills[i].sellPrice << BLANKSPACE << bills[i].quantity << BLANKSPACE
                         << bills[i].price << BLANKSPACE << bills[i].profit
                         << BLANKSPACE << bills[i].measure;
            } else {
                txt_data << '\n' << bills[i].transactionID << BLANKSPACE
                         << bills[i].time.wYear << BLANKSPACE << bills[i].time.wMonth << BLANKSPACE
                         << bills[i].time.wDay
                         << BLANKSPACE << bills[i].time.wHour << BLANKSPACE << bills[i].time.wMinute
                         << BLANKSPACE << bills[i].id
                         << BLANKSPACE << bills[i].name << BLANKSPACE << bills[i].species << BLANKSPACE
                         << bills[i].sellPrice << BLANKSPACE << bills[i].quantity << BLANKSPACE
                         << bills[i].price << BLANKSPACE << bills[i].profit
                         << BLANKSPACE << bills[i].measure;
            }
            i++;
        }
    txt_data.close();
}


void Bills::receipt(vector<Bills> market) {
    int i, size = market.size();
    float sum;

    cout << "小票：" << endl;
    cout << "=============================" << endl
         << "编号   名称  单价   数量  总价" << endl;
    for (i = 0; i < size; i++) {
        cout << " " << market[i].id << ' ' << BLANKSPACE << market[i].name << "  "
             << market[i].sellPrice << "/" << market[i].measure << BLANKSPACE << market[i].quantity
             << BLANKSPACE << " " << market[i].price << endl;
        sum += market[i].price;
    }
    cout << "交易时间：" << market[0].time.wYear << "/" << market[0].time.wMonth << "/" << market[0].time.wDay << " "
         << market[0].time.wHour << ":" << market[0].time.wMinute << endl;
    cout << "=============================" << endl;
}

void billsPrint(Bills print_bills) {
    cout << "   " << print_bills.transactionID << setw(8)
         << print_bills.time.wYear << "/" << print_bills.time.wMonth << "/"
         << print_bills.time.wDay << " " << print_bills.time.wHour << ":" << print_bills.time.wMinute
         << setw(6) << print_bills.id
         << setw(11) << print_bills.name
         << setw(7) << print_bills.species
         << setw(5) << print_bills.sellPrice
         << setw(9) << print_bills.quantity
         << setw(6) << print_bills.measure
         << setw(8) << print_bills.price
         << setw(8) << print_bills.profit
         << endl; // 便于区分每条销售数据

}

void billsMenu() {
    // 信息展示页
    goto_xy(10,10);
    cout << "销售记录管理：" << endl;
    goto_xy(10,12);
    cout << "1. 按时间顺序查看" << endl;
    goto_xy(10,13);
    cout << "2. 按类别查看" << endl;
    goto_xy(10,14);
    cout << "3. 按商品名称查看" << endl;
    goto_xy(10,15);
    cout << "4. 销售额统计" << endl;
    goto_xy(10,16);
    cout << "0. 退出" << endl;
    goto_xy(10,17);
    cout <<"您的选择： ";

}

void Bills::data(vector<Bills> &bills) {
    cls();

    // 每页显示的销售记录数量
    int pageSize = 10, pageNumber = 1;
    int choice = 1;

    while (choice) {
        billsMenu();
        cin >> choice;
        switch (choice) {
            case 1: {

                int hang6=13;
                while (pageNumber) {
                    // 计算起始和结束
                    int startIndex = (pageNumber - 1) * pageSize;
                    int endIndex = pageNumber * pageSize;

                    // 最后一页查找
                    int maxPage = bills.size() / 10 + (bills.size() % 10 > 0);

                    goto_xy(10,10);
                    cout << "当前页数： 第 " << pageNumber << " 页" << endl;
                    goto_xy(10,11);
                    cout << "=================================================================================="
                         << endl;
                    goto_xy(10,12);
                    cout << " 交易编号       时间       商品编号    名称   种类   单价  交易数量   单位     总价   交易利润"
                         << endl;
                    for (int j = startIndex, i = startIndex; j < endIndex && i < bills.size(); i++, j++) {
                        // 打印当前销售记录的信息
                        goto_xy(10,hang6);
                        billsPrint(bills[i]);
                        hang6++;
                    }
                    goto_xy(10,hang6);
                    cout << "=================================================================================="
                         << endl;
                    goto_xy(10,hang6+1);
                    cout << "最大页数：" << maxPage << endl;
                    goto_xy(10,hang6+2);
                    cout << "请输入查看页数（0退出）：";
                    cin >> pageNumber;
                    if (pageNumber > maxPage) {
                        goto_xy(10,hang6+3);
                        cout << "页数大于最大页数！请重新输入：";
                        cin >> pageNumber;
                    } else if (pageNumber < 0) {
                        goto_xy(10,hang6+3);
                        cout << "输入页数应大于0！请重新输入：";
                        cin >> pageNumber;
                    }
                }
                goto_xy(10,hang6+3);
                pause();
                cls();
                break;
            } // 按时间顺序查看
            case 2: {
                // 输出商品所有种类
                vector<string> species;
                for (auto &bill: bills)
                    if (!(count(species.begin(), species.end(), bill.species)))
                        species.push_back(bill.species);
                for (auto &kind: species)
                    cout << kind << endl;

                string speciesChoice;
                cout << "请输入要查询的商品种类：";
                cin >> speciesChoice;
                if (count(species.begin(), species.end(), speciesChoice)) {
                    vector<Bills> speciesBills;
                    for (const auto &bill: bills)
                        if (bill.species == speciesChoice)
                            speciesBills.push_back(bill);

                    while (pageNumber) {
                        // 计算起始和结束
                        int startIndex = (pageNumber - 1) * pageSize;
                        int endIndex = pageNumber * pageSize;

                        // 最后一页查找
                        int maxPage = speciesBills.size() / 10 + (speciesBills.size() % 10 > 0);

                        cout << "当前页数： 第 " << pageNumber << " 页" << endl;
                        cout << "=================================================================================="
                             << endl;
                        cout << " 交易编号       时间       商品编号    名称   种类   单价  交易数量   单位     总价   交易利润"
                             << endl;
                        // j做循环控制，i做界限控制
                        for (int j = startIndex, i = startIndex; j < endIndex && i < speciesBills.size(); i++, j++) {
                            // 检查商品种类是否符合条件
                            if (speciesBills[i].species == speciesChoice) {
                                // 打印当前销售记录的信息
                                billsPrint(bills[i]);
                            } else {
                                j--;
                                continue;
                            }
                        }
                        cout << "=================================================================================="
                             << endl;
                        cout << "最大页数：" << maxPage << endl;
                        cout << "请输入查看页数（0退出）：" << endl;
                        cin >> pageNumber;
                        if (pageNumber > maxPage) {
                            cout << "页数大于最大页数！请重新输入：";
                            cin >> pageNumber;
                        } else if (pageNumber < 0) {
                            cout << "输入页数应大于0！请重新输入：";
                            cin >> pageNumber;
                        }
                    }
                }
                break;
            } // 按类别
            case 3: {
                // 输出商品所有种类
                vector<string> names;
                for (auto &bill: bills)
                    if (!(count(names.begin(), names.end(), bill.name)))
                        names.push_back(bill.name);
                for (auto &name: names)
                    cout << name << endl;

                string nameChoice;
                cout << "请输入要查询的商品种类：";
                cin >> nameChoice;
                if (count(names.begin(), names.end(), nameChoice)) {
                    vector<Bills> namesBills;
                    for (const auto &bill: bills)
                        if (bill.name == nameChoice)
                            namesBills.push_back(bill);

                    while (pageNumber) {
                        // 计算起始和结束
                        int startIndex = (pageNumber - 1) * pageSize;
                        int endIndex = pageNumber * pageSize;

                        // 最后一页查找
                        int maxPage = namesBills.size() / 10 + (namesBills.size() % 10 > 0);
                        cout << "=================================================================================="
                             << endl;
                        cout << "当前页数： 第 " << pageNumber << " 页" << endl;
                        // j做循环控制，i做界限控制
                        for (int j = startIndex, i = startIndex; j < endIndex && i < namesBills.size(); i++, j++) {
                            // 检查商品名称是否符合条件
                            if (namesBills[i].species == nameChoice) {
                                // 打印当前销售记录的信息
                                billsPrint(bills[i]);
                            } else {
                                j--;
                                continue;
                            }
                        }
                        cout << "=================================================================================="
                             << endl;
                        cout << "最大页数：" << maxPage << endl;
                        cout << "请输入查看页数（0退出）：" << endl;
                        cin >> pageNumber;
                        if (pageNumber > maxPage) {
                            cout << "页数大于最大页数！请重新输入：";
                            cin >> pageNumber;
                        } else if (pageNumber < 0) {
                            cout << "输入页数应大于0！请重新输入：";
                            cin >> pageNumber;
                        }
                    }
                }
                break;
            } // 按名称
            case 4: {
                analyzeSales(bills);
                break;
            } // 销售额统计函数
            case 0:
                break;
            default:
                cout << "请输入有效值！ ";
                break;
        }
    }
}

void Bills::analyzeSales(vector<Bills> &bills) {

    // 初始化每日、每周和每月销售的变量
    map<int, map<string, int >> dailySalesQuantity;  // 天 -> 产品 -> 数量
    map<int, map<string, double >> dailySalesTotal;  // 天 -> 产品 -> 总金额
    map<int, map<string, double >> weeklySalesTotal;  // 周 -> 产品 -> 总金额
    map<int, map<string, double >> monthlySalesTotal;  // 月 -> 产品 -> 总金额

    // 获取当前日期和时间
    SYSTEMTIME currentTime;
    GetSystemTime(&currentTime);
    int currentDay = currentTime.wDay;  // 当月的天数（1-31）
    int currentWeek = (currentTime.wDay - 1) / 7 + 1;  // 今年的周数（1-52）
    int currentMonth = currentTime.wMonth;  // 当前月份（1-12）

    // 计算每日、每周和每月的销售统计数据
    for (const Bills &bill: bills) {
        int billDay = bill.time.wDay;  // 记账的天数（1-31）
        int billWeek = (bill.time.wDay - 1) / 7 + 1;  // 记账的周数（1-52）
        int billMonth = bill.time.wMonth;  // 记账的月份（1-12）

        // 更新每日销售统计数据
        dailySalesQuantity[billDay][bill.name] += bill.quantity;  // 添加到每日数量中
        dailySalesTotal[billDay][bill.name] += bill.price * bill.quantity;  // 添加到每日总金额中，考虑到每个产品销售的数量和单价

        // 更新每周销售统计数据
        weeklySalesTotal[billWeek][bill.name] += bill.price * bill.quantity;  // 添加到每周总金额中，考虑到每个产品销售的数量和单价

        // 更新每月销售统计数据
        monthlySalesTotal[billMonth][bill.name] += bill.price * bill.quantity;  // 添加到每月总金额中，考虑到每个产品销售的数量和单价
    }

    // 打印每日销售统计数据（数量和总金额）
    cout << "每日销售额度:" << endl;
    for (const auto &daySales: dailySalesQuantity) {
        cout << "第" << daySales.first << "天: ";
        for (const auto &productSales: daySales.second) {
            cout << productSales.first << ": " << productSales.second << " 件, "
                 << dailySalesTotal[daySales.first][productSales.first] << " 总金额" << endl;
        }
    }
    // 打印每周销售统计数据（数量和总金额）
    cout << "每周销售总额:" << endl;
    for (const auto &weekSales: weeklySalesTotal) {
        int weekNumber = weekSales.first;
        cout << "第" << weekNumber << "周: ";
        for (const auto &productSales: weekSales.second) {
            cout << productSales.first << ": ";
            cout << "总金额: " << weeklySalesTotal[weekNumber][productSales.first] << endl;
        }
    }

    // 打印每月销售统计数据（数量和总金额）
    cout << "每月销售总额:" << endl;
    for (const auto &monthSales: monthlySalesTotal) {
        int monthNumber = monthSales.first;
        cout << "第" << monthNumber << "月: ";
        for (const auto &productSales: monthSales.second) {
            cout << productSales.first << ": ";
            cout << "总金额: " << monthlySalesTotal[monthNumber][productSales.first] << endl;
        }
    }
}
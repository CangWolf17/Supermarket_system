# 超市收银管理系统
大一年级计算机思维实践I小组开发任务，进行关于超市收银管理系统的多人协同开发

## 目录

[toc]

## 安装

### 在CMD中使用CMake构建

``` bash
// 如果没有build文件夹的话，请先创建
mkdir build

cd build
cmake ..
cmake --build .

```

需要注意的是，由于数据使用了相对路径进行调用，需要保证exe文件运行目录下有data文件夹和其下的三个txt数据文件。

## 使用

### 注册

在初始界面询问id时输入reg以进行注册



### 访客访问

在初始界面询问id时输入0以顾客身份进行访问



### 登录

#### 测试账户

| 用户名（userName） | 用户ID（id） | 用户密码（pwd） | 用户权限（level） |
| :----------------- | :--------------- | :------------------ | :-------------------- |
| 管理员             | Admin            | Admin               | 3                     |
| 仓库管理           | Keeper           | 0000                | 2                     |
| 收银员             | Cashier          | 1234                | 1                     |
| 顾客1              | Customer1        | 123456              | 0                     |

输入测试账户信息，按照屏幕提示操作即可。



## ~~权限组~~

~~关于权限组，请查看[这里](doc/authority.md)~~



## 贡献者

<!-- readme: collaborators,contributors -start -->
<!-- readme: collaborators,contributors -end -->



## 许可证

本仓库下的所有内容受Apache-2.0许可证保护，违者必究。

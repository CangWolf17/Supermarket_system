# 超市收银管理系统
大一年级计算机思维实践I小组开发任务，进行关于超市收银管理系统的多人协同开发



## 在CMD中使用CMake构建

``` bash
// 如果没有build文件夹的话，请先创建
mkdir build

cd build
cmake ..
cmake --build .

```



## 测试账户

| 用户名（userName） | 用户ID（id） | 用户密码（pwd） | 用户权限（level） |
| :----------------- | :--------------- | :------------------ | :-------------------- |
| 管理员             | Admin            | Admin               | 3                     |
| 仓库管理           | Keeper           | 0000                | 2                     |
| 收银员             | Cashier          | 1234                | 1                     |
| 顾客1              | Customer1        | 123456              | 0                     |



# 权限组

关于权限组，请查看[这里](doc/authority.md)

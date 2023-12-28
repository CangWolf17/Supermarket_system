# 权限组

#### 1.管理员

``` 
Users.edit			// 用户编辑权限
Users.create		// 创建用户权限（如收银员、仓库管理员等用户）
Users.adminDel		// 用户删除权限

```



#### 2.收银员

``` 
users.del			// 删除权限

Goods.sell			// 销售权限

SellLog.data		// 销售记录的查看
```



#### 3.仓库管理员

``` 
Goods.data			// 仓库数据的查看权限
Goods.addKind		// 添加商品种类的权限
Goods.add			// 补货
Goods.delKind		// 删除商品种类的权限
Godds.del			// 减货
```

#### 4.顾客

```
Users.reg			// 注册用户的权限

Goods.buy			// 购买商品
Goods.find			// 查找商品的权限

SellLog.receipt		// 打印小票

```








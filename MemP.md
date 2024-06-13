用vector管理的内存，用连续的内存模拟数组

命名空间里定义类P,用来模拟指针，重载了-> 和 * 方法使其能像指针一样使用

+ static void init()
  初始数组空间
+ static P newNode()
  获得新节点的指针
+ static void del(const P &t)
  删除节点t
+ static P clone(const P &t)
  获得新节点的指针，并且新点是t的拷贝

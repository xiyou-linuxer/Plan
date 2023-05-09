# 前置C++语言知识
* `类和对象`：**构造函数**，**析构函数**，**拷贝构造（深拷贝/浅拷贝）**，**拷贝赋值**
* `模板` :使用模板来实现泛性编程，支持存储**各种类型**
* `STL迭代器的思想`:STL容器使用迭代器来进行封装**统一接口**，忽略底层复杂的实现逻辑
* `operator重载`:使用operator重载常用的操作符,如`[]`,`++`,`--`,`*`,`->`
* `C++基本语法与关键词`:`引用`，`初始化列表`，`缺省值`，`auto`,`nullptr`
* `函数重载`

# 介绍
如果同学们应该都了解过C语言的实现一个带头双向循环链表，或许也使用过C++的STL库中的list容器,如下是list的基本操作
~~~cpp
#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_back(3);
    l.pop_back();
    auto it=l.begin();
    while(it!=l.end())
    {
        cout<<(*it)<<endl;
        it++;
    }
    return 0;
}
~~~
我们运行上述代码会看到如下结果
~~~cpp
2
1
~~~
你或许会疑惑`l.begin()`是什么类型，为什么能够进行`*`解引用，同时还能使用`++`?

这就要谈到STL容器，使用了迭代器，将各种常见的操作符都进行了重载，如:`[]`,`++`,`--`,`*`,`->`

经过重载之后，使用者就无需了解该类型底层的实现，同时降低了使用成本


# list类的实现
[list.hpp](./code/list/include/list.hpp)中定义了需要实现的函数与类,完成这个文件中的所有函数

[test.cpp](./code/list/src/test.cc)中有相应的使用和测试

注意:
>1. **先安装gtest**,不会的话问万能的GPT如何安装
>2. 需要完成了大部分的函数才能编译通过，或将test.cpp中未完成的函数测试用例先注释掉

编译
~~~cpp
cd list
mkdir build
cd build
cmake ..
make
~~~

# 建议
* 先掌握STL容器的使用
* 掌握STL迭代器的思想
* 可以先实现一个非模板类，后期在用模板进行替换

# 时间
开始时间：2023-4-20
截止时间：2023-5-12

# 参考资料
* [1] [cplusplus/list](https://cplusplus.com/reference/list/list/?kw=list)

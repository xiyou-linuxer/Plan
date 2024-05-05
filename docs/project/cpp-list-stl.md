# C++ List STL

## 前置 C++ 语言知识

- `类和对象`：构造函数，析构函数，拷贝构造（深拷贝/浅拷贝），拷贝赋值
- `模板`：使用模板来实现泛型编程，支持存储各种类型
- `STL 迭代器的思想`：STL 容器使用迭代器来进行封装统一接口，忽略底层复杂的实现逻辑
- `operator 重载`：使用 operator 重载常用的操作符，如 `[]`，`++`，`--`，`*`，`->`
- `C++ 基本语法与关键词`：引用，初始化列表，缺省值，auto，nullptr
- `函数重载`

## 介绍

如果同学们应该都了解过 C 语言的实现一个带头双向循环链表，或许也使用过 C++ 的 STL 库中的 list 容器。下面是 list 的基本操作示例：

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_back(3);
    l.pop_back();
    auto it = l.begin();
    while (it != l.end())
    {
        cout << (*it) << endl;
        it++;
    }
    return 0;
}
```

运行上述代码会得到如下结果：

```
2
1
```

你或许会疑惑 `l.begin()` 是什么类型，为什么能够进行 `*` 解引用，同时还能使用 `++`？

这就要谈到 STL 容器，它使用了迭代器，将各种常见的操作符都进行了重载，如 `[]`，`++`，`--`，`*`，`->`。

经过重载之后，使用者就无需了解该类型底层的实现，同时降低了使用成本。

## list 类的实现

[list.hpp](https://github.com/xiyou-linuxer/Plan/tree/main/code/list/include/list.hpp) 中定义了需要实现的函数与类，完成这个文件中的所有函数。

[test.cpp](https://github.com/xiyou-linuxer/Plan/tree/main/code/list/src/test.cc) 中有相应的使用和测试。

注意：

- 先安装 gtest，不会的话问万能的 GPT 如何安装。
- 需要完成大部分的函数才能编译通过，或将 test.cpp 中未完成的函数测试用例先注释掉。

编译：

```sh
cd list
mkdir build
cd build
cmake ..
make
```

## 建议

- 先掌握 STL 容器的使用。
- 掌握 STL 迭代器的思想。
- 可以先实现一个非模板类，后期再用模板进行替换。

## 时间

??? info "往期任务时间"

    2022级：2023-04-20 ~ 2023-05-12

## 参考资料

- [cplusplus/list](https://cplusplus.com/reference/list/list/?kw=list)
#include "Plan6-list.hpp"
using namespace YOUR_NAME;
using namespace std;
struct D
{
    int x;
    std::string y;
    float z;
    D(int x_ = 1, std::string y_ = "hello", float z_ = 3.14)
        : x(x_), y(y_), z(z_)
    {
    }
};
void test1()
{
    list<int> l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_front(4);
    list<int>::Iterator it = l1.begin();
    while (it != l1.end())
    {
        std::cout << (*it) << std::endl;
        ++it;
    }
    l1.clear();
    if (l1.empty())
    {
        std::cout << "empty() ok" << std::endl;
    }
}
void test2()
{
    list<D> l1;
    l1.push_back(D(1, "aaa", 1.1));
    l1.push_back(D(2, "bbb", 2.2));
    l1.pop_front();
    auto it = l1.begin();
    while (it != l1.end())
    {
        std::cout << it->x << " " << it->y << " " << it->z << std::endl;
        ++it;
    }
}
void test3()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    list<int>::Iterator pos = l1.find(2);
    if (pos != l1.end())
    {
        l1.insert(pos, 5, false); //插入到前面
    }
    if (l1.size() == 5)
    {
        std::cout << "success" << std::endl;
    }
    auto it = l1.begin();
    while (it != l1.end())
    {
        std::cout << (*it) << " ";
        ++it;
    }
    //输出1 5 2 3 4
}
void test4()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    list<int>::Iterator pos = l1.find(2);
    if (pos != l1.end())
    {
        l1.erase(pos);
    }
    list<int> l2(l1);
    l2.push_back(3);
    //l2此时应该为1 3 4 3
    //l1此时应该为1 3 4
    if (l1.size() == l2.size())
    {
        std::cout << "error" << std::endl;
    }
}
void test5()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    auto pos=l1.find(3);
    list<int> l2(l1.begin(),pos);
    //l2中应该为1 2
    if(l2.size()!=2)
    {
        std::cout<<"error"<<std::endl;
    }

}

// 测试基本功能以及迭代器的操作
void test6()
{
    list<int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(1);

    for (auto i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;

    l.pop_front();

    for (auto i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;

    auto it = l.find(3);
    l.insert(it, 10, false);

    for (auto i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;

    l.erase(l.begin());
    l.erase(--l.end());

    for (auto i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;
}

// 测试深拷贝
void test7()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    list<int> l2 = l1; // 测试拷贝构造

    l2.push_back(4);
    l2.push_back(5);

    for (auto i = l1.begin(); i != l1.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;

    for (auto i = l2.begin(); i != l2.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;

    list<int> l3;
    l3.push_back(6);
    l3.push_back(7);

    l3 = l2; // 测试拷贝赋值

    for (auto i = l2.begin(); i != l2.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;

    for (auto i = l3.begin(); i != l3.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;
}

// 测试空list
void test8()
{
    list<int> l;
    cout << l.empty() << endl; // 应输出1，即true
    l.push_back(1);
    cout << l.empty() << endl; // 应输出0，即false
}

// 测试边界条件下的操作
void test9()
{
    list<int> l;

    cout << (l.begin() == l.end()) << endl; // 应输出1，即true

    l.push_back(1);
    l.erase(l.begin());

    cout << (l.begin() == l.end()) << endl; // 应输出1，即true

    l.push_back(1);
    l.pop_front();

    cout << (l.begin() == l.end()) << endl; // 应输出1，即true

    auto it = l.begin();
    ++it;
    l.erase(it);

    cout << (l.begin() == l.end()) << endl; // 应输出1，即true
}

// 测试自定义类型
struct Person
{
    int age;
    string name;

    bool operator==(const Person &other)
    {
        return age == other.age && name == other.name;
    }
};

void test10()
{
    list<Person> l;

    l.push_back({18, "Tom"});
    l.push_back({19, "Jerry"});

    auto it = l.find({18, "Tom"});

    if (it != l.end())
    {
        cout << it->name << endl; // 应输出Tom
    }

    l.clear();

    cout << l.empty() << endl; // 应输出1，即true
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}




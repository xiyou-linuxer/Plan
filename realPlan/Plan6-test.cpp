#include "Plan6-list.hpp"
using namespace YOUR_NAME;

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
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
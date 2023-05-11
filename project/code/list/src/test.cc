#include "list.hpp"
#include <gtest/gtest.h>
#include <memory>
using namespace YOUR_NAME;
using namespace std;

class listIntTest : public ::testing::Test
{
protected:
    listIntTest()
    {
        list_ = make_unique<list<int>>();
    }
    ~listIntTest() override = default;
    virtual void SetUp()
    {
        list_->push_back(1);
        list_->push_back(2);
    }
    virtual void TearDown() override {}

    std::unique_ptr<list<int>> list_;
};

TEST_F(listIntTest, BasicFunctionality)
{
    EXPECT_EQ(list_->size(), 2);
    EXPECT_FALSE(list_->empty());
    EXPECT_EQ(list_->front(), 1);
    EXPECT_EQ(list_->back(), 2);

    auto it = list_->begin();
    EXPECT_EQ(*it, 1);
    it++;
    EXPECT_EQ(*it, 2);
    list_->clear();
    EXPECT_TRUE(list_->empty());
    EXPECT_EQ(list_->size(), 0);
}

TEST_F(listIntTest, DefaultConstruct)
{
    list<int> l;
    EXPECT_EQ(l.size(), 0);
    EXPECT_TRUE(l.empty());
}

TEST_F(listIntTest, IteratorConstruct)
{
    std::cout <<"LINE: " <<__LINE__ << endl;

    for (int i = 3; i <= 10; i++)
    {
        EXPECT_TRUE(list_->push_back(i));
    }

    auto pos = list_->find(3);
    list<int> sublist(list_->begin(), pos);
    auto it = list_->begin();
    for (int i = 1; it != list_->end(); it++, i++)
    {
        EXPECT_EQ(*it, i);
    }
}

TEST_F(listIntTest, DeepCopyConstruct)
{
    list<int> copy(*list_);

    // 比较两个list对象，测试是否通过
    EXPECT_EQ(copy.size(), list_->size());
    auto it1 = copy.begin();
    auto it2 = list_->begin();

    while (it2 != list_->end())
    {
        EXPECT_EQ(*it1, *it2);
        it1++;
        it2++;
    }
}

TEST_F(listIntTest, DeepCopyAssign)
{
    list<int> copy;
    for (int i = 0; i < 10; ++i)
    {
        copy.push_back(i);
    }
    EXPECT_EQ(copy.size(), 10);
    EXPECT_GT(copy.size(), list_->size());
    copy = *list_;

    EXPECT_EQ(copy.size(), list_->size());
    auto it1 = list_->begin();
    auto it2 = copy.begin();
    for (; it1 != list_->end(); ++it1, ++it2)
    {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST_F(listIntTest, Add)
{
    for (int i = 3; i <= 10; i++)
    {
        EXPECT_TRUE(list_->push_back(i));
    }
    EXPECT_EQ(list_->size(), 10);
    auto pos1 = list_->find(5);
    if (pos1 != list_->end())
    {
        EXPECT_TRUE(list_->insert(pos1, 11, false));
        // 11插入在5的前面
        auto pos2 = list_->find(5);
        pos2--;
        EXPECT_EQ(*pos2, 11);
        EXPECT_EQ(list_->size(), 11);
    }
    auto pos3 = list_->find(6);
    if (pos3 != list_->end())
    {
        EXPECT_TRUE(list_->insert(pos3, 12));
        auto pos4 = list_->find(6);
        pos4++;
        EXPECT_EQ(*pos4, 12);
    }
    EXPECT_TRUE(list_->push_front(0));
    EXPECT_EQ(list_->front(), 0);
}

TEST_F(listIntTest, Delete)
{
    EXPECT_TRUE(list_->pop_front());
    EXPECT_EQ(list_->front(), 2);
    EXPECT_EQ(list_->back(), 2);
    EXPECT_TRUE(list_->pop_back());
    EXPECT_TRUE(list_->empty());

    for (int i = 0; i < 10; i++)
    {
        EXPECT_TRUE(list_->push_back(i));
    }

    auto it = list_->begin();
    it++;
    EXPECT_TRUE(list_->erase(it)); //删除第二个元素
    EXPECT_EQ(list_->size(), 9);
    auto pos = list_->find(1);
    // EXPECT_EQ(pos,nullptr);
}
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
class listDTest : public ::testing::Test
{
protected:
    listDTest()
    {
        list_ = make_unique<list<D>>();
    }
    ~listDTest() override = default;
    virtual void SetUp()
    {
    }
    virtual void TearDown() override {}

    std::unique_ptr<list<D>> list_;
};

TEST_F(listDTest, Random)
{
    list_->push_back({18,"Tom"});
    list_->push_back({3,"Jerry"});
    EXPECT_EQ(list_->size(),2);
    auto it=list_->begin();
    EXPECT_EQ(it->x,18);
    EXPECT_EQ(it->y,"Tom");

}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv); //初始化gtest

    return RUN_ALL_TESTS();
}
#include <iostream>
#include <gtest/gtest.h>
#include "../src/Vector.h"

using namespace ara;
using namespace core;

TEST(VectorIntTest, DefualtConstructor)
{
    Vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 10);
    EXPECT_THROW(v[1], std::out_of_range);
    EXPECT_THROW(v.pop_back(), std::out_of_range);
}

TEST(VectorIntTest, Initializer_listConstructor)
{
    Vector<int> v({5, 4, 8});
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 5);
    EXPECT_EQ(v[1], 4);
    EXPECT_EQ(v[2], 8);
    EXPECT_THROW(v[3], std::out_of_range);
}

TEST(VectorIntTest, ValueConstructor)
{
    Vector<int> v(20, 7);
    EXPECT_EQ(v.size(), 20);
    for(int i = 0; i < 20; i++)
    {
        EXPECT_EQ(v[i], 7);
    }
    EXPECT_THROW(v[20], std::out_of_range);
}

TEST(VectorIntTest, CopyConstructor)
{
    Vector<int> v1(10, 7);
    Vector<int> v2(v1);
    EXPECT_EQ(v2.size(), 10);
    EXPECT_EQ(v2.capacity(), 10);
    for(std::size_t i = 0; i < 10; i++)
    {
        EXPECT_EQ(v2[i], 7);
    }

}

TEST(VectorIntTest, MoveConstructor)
{
    Vector<int> v1(5, 37);
    Vector<int> v2(std::move(v1));
    EXPECT_EQ(v2.size(), 5);
    EXPECT_EQ(v2.capacity(), 5);
    EXPECT_EQ(v1.size(), 0);
    EXPECT_EQ(v1.capacity(), 0);
    for(std::size_t i = 0; i < 5; i++)
    {
        EXPECT_EQ(v2[i], 37);
    }
}

TEST(VectorIntTest, Push_backtest)
{
    Vector<int> v(10, 7);
    v.push_back(15);
    EXPECT_EQ(v.size(), 11);
    EXPECT_EQ(v[10], 15);
    EXPECT_EQ(v.capacity(), 20);
}

TEST(VectorIntTest, Pop_backtest)
{
    Vector<int> v(10, 7);
    for(std::size_t i = 0; i < 10; i++)
    {
        EXPECT_EQ(v.size(), 10 - i);
        v.pop_back();
    }
    EXPECT_THROW(v.pop_back(), std::out_of_range);

}

TEST(VectorIntTest, begin_end)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    Vector<int>::iterator mybegin = v.begin(), myend = v.end();
    EXPECT_EQ(*mybegin, 7);
    EXPECT_EQ(*(mybegin + 1), 4);
    EXPECT_EQ(*(myend - 1), 11);
}

TEST(VectorIntTest, cbegin_cend)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    Vector<int>::const_iterator mycbegin = v.cbegin(), mycend = v.cend();
    EXPECT_EQ(*mycbegin, 7);
    EXPECT_EQ(*(mycbegin + 1), 4);
    EXPECT_EQ(*(mycend - 1), 11);
}

TEST(VectorIntTest, rbegin_rend)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    Vector<int>::reverse_iterator rbeginiter = v.rbegin(), renditer = v.rend();
    EXPECT_EQ(*(rbeginiter + 1), 3);
    EXPECT_EQ(*(renditer - 1), 7);
}

TEST(VectorIntTest, crbegin_crend)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    Vector<int>::const_reverse_iterator crbeginiter = v.crbegin(), crenditer = v.crend();
    EXPECT_EQ(*(crbeginiter + 1), 3);
    EXPECT_EQ(*(crenditer - 1), 7);
}
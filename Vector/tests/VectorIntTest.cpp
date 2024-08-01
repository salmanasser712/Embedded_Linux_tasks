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
    EXPECT_THROW(v.at(1), std::out_of_range);
    EXPECT_THROW(v.pop_back(), std::out_of_range);
}

TEST(VectorIntTest, Initializer_listConstructor)
{
    Vector<int> v({5, 4, 8});
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 5);
    EXPECT_EQ(v[1], 4);
    EXPECT_EQ(v[2], 8);
    EXPECT_THROW(v.at(3), std::out_of_range);
}

TEST(VectorIntTest, ValueConstructor)
{
    Vector<int> v(20, 7);
    EXPECT_EQ(v.size(), 20);
    for(int i = 0; i < 20; i++)
    {
        EXPECT_EQ(v[i], 7);
    }
    EXPECT_THROW(v.at(20), std::out_of_range);
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

TEST(VectorIntTest, Max_Size)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    EXPECT_EQ(v.max_size(), 4611686018427387903);

}

TEST(VectorIntTest, resize_novalue)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    v.resize(13);
    EXPECT_EQ(v.size(), 13);
    EXPECT_EQ(v[10], 0);
    EXPECT_EQ(v.capacity(), 26);
}

TEST(VectorIntTest, resize_value)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    v.resize(25, 7);
    EXPECT_EQ(v.size(), 25);
    EXPECT_EQ(v[10], 7);
    EXPECT_EQ(v.capacity(), 50);
}

TEST(VectorIntTest, shrink_to_fit)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    v.shrink_to_fit();
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 5);
}

TEST(VectorIntTest, reserve)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    EXPECT_EQ(v.capacity(), 5);
    v.reserve(11);
    EXPECT_EQ(v.capacity(), 22);
    EXPECT_EQ(v.size(), 5);

    v.reserve(3);
    EXPECT_EQ(v.capacity(), 22);
    EXPECT_EQ(v.size(), 5);

}

TEST(VectorIntTest, front_back)
{
    Vector<int> v = {7, 4, 5, 3, 11};
    EXPECT_EQ(v.front(), 7);
    EXPECT_EQ(v.back(), 11);
}

TEST(VectorIntTest, data)
{
    Vector<int> v;
    v.push_back(5);
    v.push_back(8);
    v.push_back(37);
    int *ptr = v.data();
    EXPECT_EQ(*ptr, 5);
    EXPECT_EQ(*(ptr + 1), 8);
}
TEST(VectorIntTest, assign_size_value)
{
    Vector<int> v = {3, 5, 37};
    v.assign(8, 7);
    for(int i = 0; i < 8; i++)
    {
        EXPECT_EQ(v[i], 7);
    }
    EXPECT_EQ(v.size(), 8);
    EXPECT_EQ(v.capacity(), 16);
}

TEST(VectorIntTest, clear)
{
    Vector<int> v = {3, 5, 37};
    v.clear();
    EXPECT_EQ(v[1], 5);
    EXPECT_EQ(v.size(), 0);
}

TEST(VectorIntTest, assign_range)
{
    Vector<int> v1;
    int a[] = { 1, 2, 3 };
    v1.assign(a, a + 2);
    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1.size(), 2);
    EXPECT_EQ(v1.capacity(), 10);
}

TEST(VectorIntTest, insert_rvalue)
{
    Vector<int> v = {3, 5, 37};
    EXPECT_EQ(v.size(), 3);
    v.insert(v.begin() + 3, 500);
    v.insert(v.begin(), 200);
    EXPECT_EQ(v[4], 500);
    EXPECT_EQ(v[0], 200);
    EXPECT_EQ(v[1], 3);
    EXPECT_EQ(v[2], 5);
    EXPECT_EQ(v[3], 37);

}

TEST(VectorIntTest, insert_range)
{
    Vector<int> original{ 1, 2, 3, 4, 5 }; 
    Vector<int> temp{ 2, 5, 9, 0, 3, 10 };  
    original.insert(original.begin() + 3, temp.begin() + 2, temp.begin() + 5); 
    EXPECT_EQ(original.size(), 8);
    EXPECT_EQ(original[3], 9);
    EXPECT_EQ(original[4], 0);
    EXPECT_EQ(original[5], 3);

}

TEST(VectorIntTest, insert_initalization)
{
    Vector<int> v = {3, 5, 37};
    v.insert(v.begin() + 2, {5, 4, 77});
    EXPECT_EQ(v.size(), 6);
    EXPECT_EQ(v[0], 3);
    EXPECT_EQ(v[1], 5);
    EXPECT_EQ(v[2], 5);
    EXPECT_EQ(v[3], 4);
    EXPECT_EQ(v[4], 77);
    EXPECT_EQ(v[5], 37);
}

TEST(VectorIntTest, erase_position)
{
    Vector<int> v = {3, 5, 37};
    EXPECT_THROW(v.erase(v.begin() + 3), std::out_of_range);
    v.erase(v.begin());
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 5);
    EXPECT_EQ(v[1], 37);
}

TEST(VectorIntTest, erase_range)
{
    Vector<int> vector = { 1, 2, 3, 3, 4, 5 };
    Vector<int>::iterator it1, it2;
 
    it1 = vector.begin();
    it2 = vector.end();
    it2--;
    it2--;
    vector.erase(it1, it2);
    EXPECT_EQ(vector.size(), 2);
    EXPECT_EQ(vector[0], 4);
    EXPECT_EQ(vector[1], 5);
}


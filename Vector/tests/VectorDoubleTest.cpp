#include <iostream>
#include <gtest/gtest.h>
#include "../src/Vector.h"

using namespace ara;
using namespace core;

TEST(VectorDoubleTest, DefualtConstructor)
{
    Vector<double> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 10);
    EXPECT_THROW(v.at(0), std::out_of_range);
    EXPECT_THROW(v.pop_back(), std::out_of_range);
}


TEST(VectorDoubleTest, Initializer_listConstructor)
{
    Vector<double> v({52.88, 4.7887, 8.37});
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 52.88);
    EXPECT_EQ(v[1], 4.7887);
    EXPECT_EQ(v[2], 8.37);
    EXPECT_THROW(v.at(3), std::out_of_range);
}

TEST(VectorDoubleTest, ValueConstructor)
{
    Vector<double> v(20, 7.78);
    EXPECT_EQ(v.size(), 20);
    for(int i = 0; i < 20; i++)
    {
        EXPECT_EQ(v[i], 7.78);
    }
    EXPECT_THROW(v.at(20), std::out_of_range);
}
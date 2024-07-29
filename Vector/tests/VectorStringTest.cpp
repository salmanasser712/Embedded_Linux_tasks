#include <iostream>
#include <gtest/gtest.h>
#include "../src/Vector.h"

using namespace ara;
using namespace core;

TEST(VectorStringTest, DefualtConstructor)
{
    Vector<std::string> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 10);
    EXPECT_THROW(v.at(1), std::out_of_range);
    EXPECT_THROW(v.pop_back(), std::out_of_range);
}

TEST(VectorStringTest, Initializer_listConstructor)
{
    Vector<std::string> v({"hii", "I'm", "salma!"});
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], "hii");
    EXPECT_EQ(v[1], "I'm");
    EXPECT_EQ(v[2], "salma!");
    EXPECT_THROW(v.at(3), std::out_of_range);
}

TEST(VectorStringTest, ValueConstructor)
{
    Vector<std::string> v(20, "Hii");
    EXPECT_EQ(v.size(), 20);
    for(int i = 0; i < 20; i++)
    {
        EXPECT_EQ(v[i], "Hii");
    }
    EXPECT_THROW(v.at(20), std::out_of_range);
}



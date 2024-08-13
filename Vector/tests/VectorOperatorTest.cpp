#include <iostream>
#include <gtest/gtest.h>
#include "../src/Vector.h"

using namespace ara;
using namespace core;

TEST(VectorOperator, Equal_Operator)
{
    const Vector<int>
        a{1, 2, 3},
        b{1, 2, 3},
        c{7, 8, 9, 10};

    EXPECT_EQ(a == b, true);
    EXPECT_EQ(a == c, false);
}

TEST(VectorOperator, NotEqual_Operator)
{
    const Vector<int>
        a{1, 2, 3},
        b{1, 2, 3},
        c{7, 8, 9, 10};

    EXPECT_EQ(a != b, false);
    EXPECT_EQ(a != c, true);
}
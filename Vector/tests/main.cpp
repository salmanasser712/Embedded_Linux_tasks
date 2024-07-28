#include <iostream>
#include <gtest/gtest.h>


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Add command line option for json output
    ::testing::GTEST_FLAG(output) = "json:report/test_report.json";

    return RUN_ALL_TESTS();
}


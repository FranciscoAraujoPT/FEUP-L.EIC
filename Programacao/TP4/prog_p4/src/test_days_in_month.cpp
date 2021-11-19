#include <gtest/gtest.h>
#include <funcs.h>

TEST(days_in_month, january_2021) {
    EXPECT_EQ(31,
              days_in_month(JANUARY, 2021));
}


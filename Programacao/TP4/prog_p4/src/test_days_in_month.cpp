#include <gtest/gtest.h>
#include <funcs.h>

TEST(days_in_month, january_2021) {
    EXPECT_EQ(31,
              days_in_month(JANUARY, 2021));
}

TEST(days_in_month, february_2021) {
    EXPECT_EQ(28,
              days_in_month(FEBRUARY, 2021));
}

TEST(days_in_month, april_2021) {
    EXPECT_EQ(30,
              days_in_month(APRIL, 2021));
}

TEST(days_in_month, february_2000) {
    EXPECT_EQ(29,
              days_in_month(FEBRUARY, 2000));
}


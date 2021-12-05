#include <gtest/gtest.h>
#include <funcs.h>

TEST(hexstr_convert, zero) {
    EXPECT_EQ(0, hexstr_convert("0"));
}

TEST(hexstr_convert, only_decimal_digits) {
    EXPECT_EQ(291, hexstr_convert("123"));
}

TEST(hexstr_convert, all_digits) {
    EXPECT_EQ(243, hexstr_convert("F3"));
}

TEST(hexstr_convert, all_digits_lowercase) {
    EXPECT_EQ(243, hexstr_convert("f3"));
}

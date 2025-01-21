#include "gtest/gtest.h"
#include "traffic_light.h"


TEST(FactorialAlgoTest, SimpleRecursion) {
    for (ll i = 0; i < 7; i++) {
        EXPECT_EQ(factorials[i], falgo::simple_recursion(i));
    }
};

TEST(FactorialAlgoTest, FactNaive) {
    for(ll i = 0; i < 6; i++) {
        EXPECT_EQ(factorials[i], falgo::fact_naive(i));
    }
}

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}
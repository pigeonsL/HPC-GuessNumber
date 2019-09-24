#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Hello.h"

TEST(lib, Case1)
{
    EXPECT_EQ(1, 1);
    EXPECT_THAT(1, ::testing::Ge(0));
}

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"

using ::testing::Eq;
using ::testing::Return;


TEST(lib, Case1)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({1, 2, 3, 4});

    std::string expect = "4A0B";
    EXPECT_THAT(result, Eq(expect));
}

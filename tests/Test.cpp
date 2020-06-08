#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"

using ::testing::Eq;
using ::testing::Return;


TEST(Guess, should_output_answer_code_with_valid_input)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({1, 2, 3, 4});

    std::string expect = "4A0B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(Guess, should_output_answer_code_2A4B_with_valid_input)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({1, 3, 2, 4});

    std::string expect = "2A4B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(Guess, should_output_wrong_input_with_invalid_input)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};
    std::string input = "1 1 2 3";
    auto result = game.IsValidInput(input);

    bool expect = false;
    EXPECT_THAT(result, Eq(expect));
}
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
TEST(Guess, should_output_answer_code_1A0B_with_valid_input)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({1, 5, 6, 7});

    std::string expect = "1A0B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(Guess, should_output_answer_code_0A2B_with_valid_input)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({2, 4, 7, 8});

    std::string expect = "0A2B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(Guess, should_output_answer_code_1A2B_with_valid_input)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({0, 3, 2, 4});

    std::string expect = "1A2B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(IsValidInput, should_output_wrong_input_with_invalid_repeat_number)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};
    std::string input = "1 1 2 3";

    auto result = game.IsValidInput(input);

    bool expect = false;
    EXPECT_THAT(result, Eq(expect));
}
TEST(IsValidInput, wrong_input_with_invalid_lack_of_number)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};
    std::string input = "1 2";

    auto result = game.IsValidInput(input);

    bool expect = false;
    EXPECT_THAT(result, Eq(expect));
}
TEST(IsValidInput, wrong_input_with_invalid_number_out_of_range)
{
    GuessNumberGame game;
    game.answer_ = {1, 2, 3, 4};
    std::string input = "11 2";

    auto result = game.IsValidInput(input);

    bool expect = false;
    EXPECT_THAT(result, Eq(expect));
}
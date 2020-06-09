#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"

using ::testing::Eq;
using ::testing::Return;

class MockRandomGenerator: public RandomGenerator {
public:
    MOCK_METHOD0(Generate, int());
};

TEST(lib, Case2)
{
    MockRandomGenerator mockRandomGenerator;
    GuessNumberGame game(mockRandomGenerator);
    EXPECT_CALL(mockRandomGenerator, Generate())
        .WillOnce(Return(1))
        .WillOnce(Return(2))
        .WillOnce(Return(3))
        .WillOnce(Return(4));

    game.GenerateNumbers();

    std::array<int, 4> expect{1, 2, 3, 4};
    EXPECT_THAT(game.answer_, Eq(expect));
}

TEST(lib, Case3)
{
    MockRandomGenerator mockRandomGenerator;
    GuessNumberGame game(mockRandomGenerator);
    EXPECT_CALL(mockRandomGenerator, Generate())
        .WillOnce(Return(1))
        .WillOnce(Return(2))
        .WillOnce(Return(2))
        .WillOnce(Return(3))
        .WillOnce(Return(4));

    game.GenerateNumbers();

    std::array<int, 4> expect{1, 2, 3, 4};
    EXPECT_THAT(game.answer_, Eq(expect));
}

TEST(lib, Case4)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);

    game.GenerateNumbers();

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            EXPECT_THAT(game.answer_[i], testing::Ne(game.answer_[j]));
        }
    }
}

TEST(Guess, should_output_answer_code_with_valid_input)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({1, 2, 3, 4});

    std::string expect = "4A0B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(Guess, should_output_answer_code_2A2B_with_valid_input)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({1, 3, 2, 4});

    std::string expect = "2A2B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(Guess, should_output_answer_code_1A0B_with_valid_input)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({1, 5, 6, 7});

    std::string expect = "1A0B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(Guess, should_output_answer_code_0A2B_with_valid_input)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({2, 4, 7, 8});

    std::string expect = "0A2B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(Guess, should_output_answer_code_1A2B_with_valid_input)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Guess({0, 3, 2, 4});

    std::string expect = "1A2B";
    EXPECT_THAT(result, Eq(expect));
}
TEST(IsValidInput, should_output_wrong_input_with_invalid_repeat_number)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};
    std::string input = "1 1 2 3";

    auto result = game.IsValidInput(input);

    bool expect = false;
    EXPECT_THAT(result, Eq(expect));
}
TEST(IsValidInput, wrong_input_with_invalid_lack_of_number)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};
    std::string input = "1 2";

    auto result = game.IsValidInput(input);

    bool expect = false;
    EXPECT_THAT(result, Eq(expect));
}
TEST(IsValidInput, wrong_input_with_invalid_number_out_of_range)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};
    std::string input = "11 2";

    auto result = game.IsValidInput(input);

    bool expect = false;
    EXPECT_THAT(result, Eq(expect));
}
TEST(Instruction, code_instruction_1A0B_of_user_answer)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Instruction({1, 5, 6, 7});

    std::string expect = "1 correct";

    EXPECT_THAT(result, Eq(expect));
}
TEST(Instruction, code_instruction_4A0B_of_user_answer)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Instruction({1, 2, 3, 4});

    std::string expect = "win, all correct";

    EXPECT_THAT(result, Eq(expect));
}
TEST(Instruction, code_instruction_1A2B_of_user_answer)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Instruction({0, 3, 2, 4});

    std::string expect = "4 correct, 2 3 wrong position";

    EXPECT_THAT(result, Eq(expect));
}
TEST(Instruction, code_instruction_0A4B_of_user_answer)
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.answer_ = {1, 2, 3, 4};

    auto result = game.Instruction({4, 3, 2, 1});

    std::string expect = "4 numbers position wrong";

    EXPECT_THAT(result, Eq(expect));
}
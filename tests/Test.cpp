#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"

using ::testing::Eq;
using ::testing::Return;

class MockRandomGenerator : public RandomGenerator
{
public:
    MOCK_METHOD0(Generate, int());
};

TEST(lib, Case1)
{
    MockRandomGenerator generator;
    EXPECT_CALL(generator, Generate()).WillOnce(Return(1)).WillOnce(Return(2)).WillOnce(Return(3)).WillOnce(Return(4));
    GuessNumberGame game(generator);
    auto result = game.Guess({1, 2, 3, 4});
    EXPECT_THAT(result, Eq("4A0B"));
}

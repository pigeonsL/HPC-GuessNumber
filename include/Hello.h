#ifndef __HELLO_H__
#define __HELLO_H__

#include <array>
#include <string>

class RandomGenerator
{
public:
    virtual ~RandomGenerator() = default;
    virtual int Generate() = 0;
};

class GuessNumberGame
{
    RandomGenerator& generator;

public:
    GuessNumberGame(RandomGenerator& generator);
    std::string Guess(const std::array<int, 4>& digits);
};
#endif

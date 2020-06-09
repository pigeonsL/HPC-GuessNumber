#ifndef __HELLO_H__
#define __HELLO_H__

#include <array>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

class RandomGenerator {
public:
    virtual ~RandomGenerator() = default;
    virtual int Generate();
};

class GuessNumberGame
{
    RandomGenerator &generator;
public:
    GuessNumberGame(RandomGenerator& generator);
    void GenerateNumbers();
    std::string Guess(const std::array<int, 4>& digits);
    bool IsValidInput(const std::string& input);
    std::string Instruction(const std::array<int, 4>& digits);
    void PlayGame();
    std::array<int, 4> guess_;
    std::array<int, 4> answer_;
};
#endif

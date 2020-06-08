#ifndef __HELLO_H__
#define __HELLO_H__

#include <array>
#include <string>
#include <sstream>
#include <vector>

class GuessNumberGame
{
public:
    std::string Guess(const std::array<int, 4>& digits);
    bool IsValidInput(const std::string& input);
    std::array<int, 4> answer_;
};
#endif

#ifndef __HELLO_H__
#define __HELLO_H__

#include <array>
#include <string>

class GuessNumberGame
{
public:
    std::string Guess(const std::array<int, 4>& digits);
    std::array<int, 4> answer_;
};
#endif

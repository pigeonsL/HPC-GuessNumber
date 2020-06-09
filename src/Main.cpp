#include "Hello.h"

int main(int argc, char* argv[])
{
    RandomGenerator generator;
    GuessNumberGame game(generator);
    game.GenerateNumbers();
//    game.answer_ = {1,2,3,4};
    game.PlayGame();
    return 0;
}

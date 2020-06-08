#include "Hello.h"

std::string GuessNumberGame::Guess(const std::array<int, 4>& digits)
{
    size_t numberA = 0, numberB = 0;
    std::string answerCode;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(digits[i] == this->answer_[j]){
                if(i == j){
                    numberA++;
                }else{
                    numberB++;
                }
            }
        }
    }
    answerCode = std::to_string(numberA) + "A" + std::to_string(numberB) + "B";
    return answerCode;
}
bool GuessNumberGame::IsValidInput(const std::string& input) {
    std::vector<size_t> guessNumber;
    std::stringstream ss(input);
    size_t number;
    while (ss >> number){
        guessNumber.push_back(number);
    }
    if(guessNumber.size() != 4){
        return false;
    }
    for(int i=0;i<guessNumber.size();++i){
        for(int j=i+1;j<guessNumber.size();++j){
            if(guessNumber[i]<0 || guessNumber[i]>9){
                return false;
            }
            if(guessNumber[i] == guessNumber[j]){
                return false;
            }
        }
    }
    return true;
}

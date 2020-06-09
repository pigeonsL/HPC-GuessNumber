#include "Hello.h"


GuessNumberGame::GuessNumberGame(RandomGenerator& generator) : generator(generator), answer_({0, 0, 0, 0})
{
}
void GuessNumberGame::GenerateNumbers()
{
    // TODO: implement me
    std::vector<size_t> number;
    while (number.size()<4){
        size_t temp = this->generator.Generate();
        bool flag = true;
        for(auto it = number.begin(); it != number.end(); it++){
            if(temp == *it){
                flag = false;
                break;
            }
        }
        if(flag){
            number.push_back(temp);
        }
    }

    for(int i=0;i<4;++i){
        this->answer_[i] = number[i];
    }
}

int RandomGenerator::Generate()
{
    std::uniform_int_distribution<> u(0, 9);//
    std::random_device r;
    std::default_random_engine engine(r());
    return u(engine);
}
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
    for(int i=0;i<4;++i){
        this->guess_[i] = guessNumber[i];
    }
    return true;
}
std::string GuessNumberGame::Instruction(const std::array<int, 4>& digits){
    std::vector<int> rightNumber,wrongPos;
    std::string instruction = "";
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(digits[i] == this->answer_[j]){
                if(i == j){
                    rightNumber.push_back(digits[i]);//number&position right
                }else{
                    wrongPos.push_back(digits[i]);//position wrong
                }
            }
        }
    }
//    TODO
    if(rightNumber.size() == 4){
        instruction += "win, all correct";
        return instruction;
    }
    if(wrongPos.size() == 0 && rightNumber.size() == 0){
        instruction += "all wrong";
        return instruction;
    }
    if(wrongPos.size() == 4){
        instruction += "4 numbers position wrong";
        return instruction;
    }

    while (!rightNumber.empty()){

        std::sort(rightNumber.begin(),rightNumber.end());
        for(auto it = rightNumber.begin(); it != rightNumber.end(); it++){
            instruction += std::to_string(*it) + " ";
        }
        instruction += "correct";
        if(!wrongPos.empty()){
            instruction += ", ";
        }
        break;
    }

    while (!wrongPos.empty()){

        std::sort(wrongPos.begin(),wrongPos.end());
        for(auto it = wrongPos.begin(); it != wrongPos.end(); it++){
            instruction += std::to_string(*it) + " ";
        }
        instruction += "wrong position";
        break;
    }
    return instruction;
}
void GuessNumberGame::PlayGame() {
    std::string userInput;
    while(getline(std::cin, userInput)){
        std::string output = "";
        if(this->IsValidInput(userInput)){
            output += this->Guess(this->guess_);
            output += "   ";
            output += this->Instruction(this->guess_);
            std::cout<<output<<std::endl;
            if(output == "4A0B   win, all correct"){
                return;
            }
        }
        else{
            std::cout<<"Wrong Input, Input again"<<std::endl;
        }
    }

}

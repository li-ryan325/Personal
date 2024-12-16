#include <iostream>
#include <string>
#include "test_5.h"

const std::string yes = "Y";
const std::string no = "N";
extern std::string op;
extern int num_1;
extern int num_2;
bool repeat = true;
std::string reply = " ";

int main(int argc, char* argv[]){
    std::cout << "This program is a simple calculator that solves two whole number equations.\n";
    std::cout << "When answering the questions use only integers, y and n without space.\n";
    while (reply == no || repeat == true){
        repeat = false;
        again();
        std::cin >> reply;
        if (reply == no){
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        }
    }
    if (op == "+"){
        addition(num_1, num_2);
    } else if (op == "-"){
        subtraction(num_1, num_2);
    } else if (op == "*"){
        multiplcation(num_1, num_2);
    } else {
        division(num_1, num_2);
    }
    return 0;
}
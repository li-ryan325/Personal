#include <iostream>
#include <string>
#include "test_5.h"

const int a = 0;
std::string op = " ";
int num_1 = 0;
int num_2 = 0;

int add_1 (int x, int y){
    return x + y;
}

int sub_1 (int x, int y){
    return x - y;
}

int mult_1 (int x, int y){
    return x * y;
}

int div_1 (int x, int y){
    return x / y;
}

void addition (int x, int y){
    int add{add_1(x, y)};
    std::cout << x << " + " << y << " is " << add <<std::endl;
}

void subtraction (int x, int y){
    int sub{sub_1(x, y)};
    std::cout << x << " + " << y << " is " << sub <<std::endl;
}

void multiplcation (int x, int y){
    int mult{mult_1(x, y)};
    std::cout << x << " + " << y << " is " << mult <<std::endl;
}

void division (int x, int y){
    int div{div_1(x, y)};
    int remainder = x % y;
    if (remainder == a){
        std::cout << x << " / " << y << " is " << div << std::endl;
    } else {
        std::cout << x << "/" << y << " is " << div << " with the remainder of " << remainder << std::endl;
    }
}

void again (){
    std::cout << "Using whole nmber choose the first number of the equation.\n";
    std::cin >> num_1;
    std::cout << "Choose your operation from +, -, *, or / with out space.\n";
    std::cin >> op;
    std::cout << "Choose the second number of the equation.\n";
    std::cin >> num_2;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << num_1 << " " << op << " " << num_2 << std::endl;
    std::cout << "Is this the equation you want? Y/N\n";
}
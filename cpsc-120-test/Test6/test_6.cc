#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "test_6.h"


int main(int argc, char* argv[]){
    extern std::vector<int> total;
    bool end = false;
    srand(time(0));
    std::string suit = "";
    std::vector<std::vector<int>> deck = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}};

    // start();


    // std::cout << total.at(0) << total.at(1) << total.at(2);
    // std::cout << whole();

    loop(deck, end);






    // loop(deck, end);
    return 0;
}
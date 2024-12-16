
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "blackjack_functions.h"

int main(int argc, char* argv[]) {

    // Sets the seed for the random number generator to make it peudorandom
    srand(time(0));

    
    std::vector<std::vector<int>> deck = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}};

}
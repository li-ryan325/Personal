#include <iostream>
#include <math.h>
#include <vector>

int main(int argc, char* argv[]){
    std::vector<int> scores{1,2,3,4};
    for (int score : scores) {
        std::cout << " " << score;
    }
}

#include <iostream>

int main(int argc, char* argv[]) {
    int a = rand() % 10 + 0;
    while (a < 17) {
    	a = rand() % 10 + 1;
        std::cout << a << " ";
    }
    return 0;
}

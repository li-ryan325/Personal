#include <iostream>

const int kCounterMax = 100;
int main(int argc, char const *argv[]) {
  
  for (int i = 0; kCounterMax > i; i++) {
    if (i != 0) {
      for (int j = i; j > 0; j--) {
        std::cout << "-";
      }
    }
    std::cout << "*";
    for (int j = kCounterMax - i; j > 0; j--) {
      std::cout << "|";
    }
    std::cout << "\n";
  }


  return 0;
}
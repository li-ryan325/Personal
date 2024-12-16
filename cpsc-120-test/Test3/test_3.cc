// cpsc120_prompt.cc
// Gist https://gist.github.com/70457715ff7fc2fcdcdaf44437624dd0

#include <iostream>
#include <string>

std::string PromptForString(std::string query) {
  std::cout << query;
  std::string answer;
  std::cin >> answer;
  return answer;
}

int PromptForInt(std::string query) {
  std::cout << query;
  int answer;
  std::cin >> answer;
  return answer;
}

double PromptForDouble(std::string query) {
  std::cout << query;
  double answer;
  std::cin >> answer;
  return answer;
}

int main(int argc, char const *argv[]) {
  std::cout << "What's your favorite color? ";
  std::string favorite_color;
  std::cin >> favorite_color;
  std::cout << "Your favorite color is " << favorite_color
            << "! That's mine too!\n";

  std::string favorite_animal{PromptForString("What's your favorite animal? ")};
  std::cout << "Your favorite animal is " << favorite_animal
            << "! That's mine too!\n";

  int favorite_number{PromptForInt("What's your favorite number? ")};
  std::cout << "Your favorite number is " << favorite_number
            << "! That's mine too!\n";

  double favorite_decimal{
      PromptForDouble("What's your favorite decimal number? ")};
  std::cout << "Your favorite decimal number is " << favorite_decimal
            << "! That's mine too!\n";

  int number_of_cats{std::stoi(PromptForString("How many cats do you have? "))};
  std::cout << "You have " << number_of_cats << "! That's a lot!\n";

  double stick_of_gum_price{std::stod(PromptForString(
      "How many dollars and cents would you pay for a stick of gum? "))};
  std::cout << "If you paid $" << stick_of_gum_price
            << ", then you paid too much.\n";

  return 0;
}
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "test_6.h"

using namespace std::chrono_literals;
int a = 0;
const int max = 24;
std::vector<int> total;

//It has the start screen with "Press to Enter to continue" and "Please wait..."
void start(){
    std::cout << "\033[31m***\033[0m\033[1;5;31mWelcome to the BlackJack\033[0m\033[31m***\033[0m\n";
    std::cout << "Press Enter to continue...";
    std::cin.get();
    std::cout << "Please wait...\n";
    std::this_thread::sleep_for(2s);
}

int ran_suits(){
    return rand() % 4 + 0;
}

int ran_num(){
    return rand() % 12 + 0;
}

std::string suit(int num_suits){
    if (num_suits == 0){
        return "Diamonds";
    } else if (num_suits == 1){
        return "Clubs";
    } else if (num_suits == 2){
        return "Hearts";
    } else {
        return "Spades";
    }
}

bool is_face(int num_num){
    if (num_num == 10 || num_num == 11 || num_num == 12){
        return true;
    } else {
        return false;
    }
}

bool is_ace(int num_num){
    if (num_num == 0) {
        return true;
    }
    return false;
}

std::string face(int num_num){
    if (num_num == 0){
        return "Ace";
    } else if (num_num == 10){
        return "Jack";
    } else if (num_num == 11){
        return "Queen";
    } else {
        return "King";
    }
}

void ace(int num_suits, int num_num, std::vector<std::vector<int>> deck){
    std::string answer = "";
    std::cout << "Do you want the Ace to be an 11?\nUse Y or N to answer.\n";
    std::cin >> answer;
    while (answer != "Y" && answer != "N"){
        if (answer == "Y"){
            total.push_back(11);
            break;
        } else if (answer == "N"){
            total.push_back(1);
            break;
        } else {
            std::cout << "Not a valid input. Please try again.\n";
            std::cin >> answer;
        }
    }
}

void first_card(int num_suits, int num_num, std::vector<std::vector<int>> deck){
    if (is_face(num_num) == true){
        std::cout << "Your first card is the " << face(num_num) << " of " << suit(num_suits) << std::endl;
        total.push_back(10);
    } else if (is_ace(num_num) == true) {
        std::cout << "Your first card is the " << face(num_num) << " of " << suit(num_suits) << std::endl;
        ace(num_suits, num_num, deck);
    } else {
        std::cout << "Your first card is the " << deck.at(num_suits).at(num_num) << " of " << suit(num_suits) << std::endl;
        total.push_back(deck.at(num_suits).at(num_num));
    }
    deck.at(num_suits).at(num_num) = 0;
    a += 1;
}

void second_card(int num_suits, int num_num, std::vector<std::vector<int>> deck){
    if (is_face(num_num) == true){
        std::cout << "Your second card is the " << face(num_num) << " of " << suit(num_suits) << std::endl;
        total.push_back(10);
    } else if (is_ace(num_num) == true) {
        std::cout << "Your second card is the " << face(num_num) << " of " << suit(num_suits) << std::endl;
        ace(num_suits, num_num, deck);
    } else {
        std::cout << "Your second card is the " << deck.at(num_suits).at(num_num) << " of " << suit(num_suits) << std::endl;
        total.push_back(deck.at(num_suits).at(num_num));
    }
    deck.at(num_suits).at(num_num) = 0;
    a += 1; 
}

void next_card(int num_suits, int num_num, std::vector<std::vector<int>> deck){
    if (is_face(num_num) == true){
        std::cout << "Your next card is the " << face(num_num) << " of " << suit(num_suits) << std::endl;
        total.push_back(10);
    } else if (is_ace(num_num) == true) {
        std::cout << "Your next card is the " << face(num_num) << " of " << suit(num_suits) << std::endl;
        ace(num_suits, num_num, deck);
    } else {
        std::cout << "Your next card is the " << deck.at(num_suits).at(num_num) << " of " << suit(num_suits) << std::endl;
        total.push_back(deck.at(num_suits).at(num_num));
    }
    deck.at(num_suits).at(num_num) = 0;
    a += 1;
}

int whole (){
    int combine = 0;
    for (int i = 0; i < total.size(); i++) {
        combine += total.at(i);
    }
    return combine;
}

bool bust (int all){
    if (all > 21){
        return true;
    } else {
        return false;
    }
}

void shuffle(std::vector<std::vector<int>> deck){
    std::cout << "Now suffling\nPlease wait...\n";
    std::this_thread::sleep_for(2s);
    for (int i = 0; deck.size() > i; i++) {
        for (int j = 0; deck.at(i).size() > i; i++){
            deck.at(i).at(j) = (j + 1);
        }
    }
    std::cout << "If you are ready for another game. Please press ENTER";
    std::cin.get();
}

void prepare(std::vector<std::vector<int>> deck, int combine){
    if (a > max){
        a = 0;
        shuffle(deck);
    }
    combine = 0;
    std::cout << "Preparing next game!\nPlease wait...\n";
    std::this_thread::sleep_for(2s);
}

void loose(std::vector<std::vector<int>> deck, bool end, int combine){
    std::string answer = "";    
    for (int i = 0; total.size() > i; i++){
        total.at(1) = 0;
    }
    std::cout << "\033[1;5;31mYou Lose!!\033[0m\n";
    std::cout << "Do you want to play again or end game?\nUse END or AGAIN to answer.\n";
    std::cin >> answer;
    while (answer != "END" && answer != "AGAIN"){
        if (answer == "END"){
            end = true;
            break;
        } else if (answer == "AGAIN"){
            prepare(deck, combine);
            break;
        } else {
            std::cout << "Not a valid input. Please try again.\n";
            std::cin >> answer;
        }
    }
}

void next(int num_suits, int num_num, std::vector<std::vector<int>> deck, bool end){
    std::string answer;
    while (answer != "N"){
        int combine = whole();
        std::cout << "Your current total is " << combine << std::endl;
        if (bust(combine) == true){
            loose(deck, end, combine);
            break;
        } else {
            std::cout << "Do you wish to draw another card\nUse Y or N to answer.\n";
            std::cin >> answer;
            if (answer == "Y"){
                do {
                    num_suits = ran_suits();
                    num_num = ran_num();
                } while (deck.at(num_suits).at(num_num) == 0);
                next_card(num_suits, num_num, deck);
            } else if (answer == "N"){
                combine = 0;
                prepare(deck, combine);
            } else {
                while (answer != "Y" && answer != "N"){
                    std::cout << "Not a valid input. Please try again.\n";
                    std::cin >> answer;
                }
            }
        }
    }
}

void loop(std::vector<std::vector<int>> deck, bool end){
    int num_suits;
    int num_num;
    do {
        num_suits = ran_suits();
        num_num = ran_num();
    } while (deck.at(num_suits).at(num_num) == 0);
    first_card(num_suits, num_num, deck);

    do {
        num_suits = ran_suits();
        num_num = ran_num();
    } while (deck.at(num_suits).at(num_num) == 0);
    second_card(num_suits, num_num, deck);

    do {
        num_suits = ran_suits();
        num_num = ran_num();
    } while (deck.at(num_suits).at(num_num) == 0);
    next(num_suits, num_num, deck, end);

}
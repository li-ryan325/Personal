
#ifndef TEST_6_H_
#define TEST_6_H_

void start();

int ran_suits();

int ran_num();

std::string suit(int num_suits);

bool is_face(int num_num);

bool is_ace(int num_num);

std::string face(int num_num);

void ace(int num_suits, int num_num, std::vector<std::vector<int>> deck);

void first_card(int num_suits, int num_num, std::vector<std::vector<int>> deck);

void second_card(int num_suits, int num_num, std::vector<std::vector<int>> deck);

void next_card(int num_suits, int num_num, std::vector<std::vector<int>> deck);

int whole ();

bool bust (int all);

void prepare(int combine);

void loose(std::vector<std::vector<int>> deck, bool end, int combine);

void next(int num_suits, int num_num, std::vector<std::vector<int>> deck, bool end);

void shuffle(std::vector<std::vector<int>> deck);

void loop(std::vector<std::vector<int>> deck, bool end);

class Hand {

 public :

 private :
  std::string suits_;
  std::string cards_;
};

#endif //test_6_h
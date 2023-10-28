#include <iostream>
#include "cricketer.cpp"

constexpr int NUM_SCORES = 3;

class Batter : public Cricketer {
 private:
  int* highScores;

 public:
  Batter(const std::string& name, int year_of_birth, int jerseyNo, std::initializer_list<int> scores) :
      Cricketer(name, year_of_birth, jerseyNo),
      highScores{new int[NUM_SCORES]} { // RAII: Allocate memory in constructor
    UpdateHighScores(scores);
  }

  ~Batter() {
    delete[] highScores; // Must delete local memory as per RAII 
  }

  void UpdateHighScores(std::initializer_list<int> scores) {
    int i = 0;
    for (int s : scores) {
      if (i == NUM_SCORES) {
        break;
      }
      highScores[i] = s;
      ++i;
    }
    for (; i < NUM_SCORES; ++i) {
      highScores[i] = 0;
    }
  }

  int& operator[](int i) { // Mutable [] access to high scores
    return highScores[i];
  }

  void Show() const override {
    Cricketer::Show();
    std::cout << '\t';
    for (int i = 0; i < NUM_SCORES; ++i) {
      std::cout << '\t' << highScores[i];
    }
    std::cout << std::endl;
  }
};
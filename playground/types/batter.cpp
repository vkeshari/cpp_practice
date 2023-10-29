#include <iostream>
#include "cricketer.cpp"

constexpr int MAX_NUM_SCORES = 3;

class Batter : public Cricketer {
 private:
  int* highScores;

 public:
  Batter(const std::string& name, int year_of_birth, int jerseyNo, std::initializer_list<int> scores) :
      Cricketer(name, year_of_birth, jerseyNo),
      highScores{new int[MAX_NUM_SCORES]} { // RAII: Allocate memory in constructor
    UpdateHighScores(scores);
  }

  ~Batter() override {
    // RAII: Must delete local memory,
    // Delete array with delete[]
    delete[] highScores;
  }

  Batter(const Batter& b) :
      Cricketer(b), // Simply call base class's copy constructor
      highScores{new int[MAX_NUM_SCORES]} {
    for (int i = 0; i < MAX_NUM_SCORES; ++i) {
      highScores[i] = b.highScores[i];
    }
  }

  Batter(Batter&& b) :
      // Call base class's move constructor with std::move (weird!)
      Cricketer(std::move(b)) {
    highScores = b.highScores; // Just re-assign pointer for move operation
    b.highScores = nullptr;
  }

  void UpdateHighScores(std::initializer_list<int> scores) { // {} are initializer_list objects
    // Just logic, ignore
    int i = 0;
    for (int s : scores) {
      if (i == MAX_NUM_SCORES) {
        break;
      }
      highScores[i] = s;
      ++i;
    }
    for (; i < MAX_NUM_SCORES; ++i) {
      highScores[i] = 0;
    }
  }

  int& operator[](int i) { // Mutable [] access to high scores
    return highScores[i];
  }

  Batter& operator+=(int score) { // Can redefine operator to take arbitrary type
    int i = 0;
    for (; highScores[i] != 0 && i < MAX_NUM_SCORES; ++i);
    if (i < MAX_NUM_SCORES) {
      highScores[i] = score;
    }
    return *this; // this pointer
  }

  void Show() const override {
    Cricketer::Show();
    std::cout << '\t';
    for (int i = 0; i < MAX_NUM_SCORES; ++i) {
      std::cout << '\t' << highScores[i];
    }
    std::cout << std::endl;
  }
};
#include <iostream>

namespace player {

class Player {
 private:
  std::string name;
  std::vector<int> scores;

 public:
  Player(std::string name) : name{name} { }

  int& operator[](int i) { // make operators refs
    if (i >= scores.size()) {
      throw std::out_of_range("Not enough scores for index");
    }
    return scores[i];
  };

  const std::string& Name() const noexcept { // make getters const noexcept, make returned ref const
    return name;
  }
  const std::vector<int>& Scores() const noexcept { // make getters const noexcept, make returned ref const
    return scores;
  }
  int NumScores() const noexcept { // make getters const noexcept, no need to make returned value const
    return scores.size();
  }

  void AddScore(int score) {
    scores.push_back(score);
  }
  
};

void show_player(const Player& p) {
  std::cout << "Player " << p.Name() << " has " << p.NumScores() << " scores:";
  for (int s : p.Scores()) {
    std::cout << " " << s;
  }
  std::cout << std::endl;
}

} // namespace player

namespace { // put tests in anonymous namespace

void test_player() {
  std::cout << "TEST PLAYER" << std::endl;
  player::Player p {"Sachin"};
  p.AddScore(200);
  p.AddScore(186);
  p.AddScore(175);
  p.AddScore(100);
  
  player::show_player(p);

  p[3] = 0;
  player::show_player(p);

  try {
    p[5] = 0;
  } catch (const std::out_of_range& e) {
    std::cout << "Caught an out-of-range exception: " << e.what() << std::endl;
  }
}

} // namespace

int main() {
  test_player();
}
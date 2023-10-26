#include <iostream>

namespace player {

class Player {
 public:
  Player(std::string name) : name{name} { }

  int& operator[](int i) { // make operators refs
    return scores[i];
  };

  const std::string& Name() const { // make getters const, make returned ref const
    return name;
  }
  const std::vector<int>& Scores() const { // make getters const, make returned ref const
    return scores;
  }
  int NumScores() const { // make getters const, no need to make returned value const
    return scores.size();
  }

  void AddScore(int score) {
    scores.push_back(score);
  }

 private:
  std::string name;
  std::vector<int> scores;
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
}

} // namespace

int main() {
  test_player();
}
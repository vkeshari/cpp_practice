#include <iostream>

struct Player {
  std::string name;
  double* scores;

  Player(std::string name) : name{name} {} // structs can have constructors

  double& operator[](int i) { // return a reference for read/write access
    return scores[i];
  }
}; // struct definition is a statement, unlike function definition

void test_struct() {
  std::cout << "TEST STRUCT" << std::endl;
  Player p("Sachin");
  p.scores = new double[5]; // can direct-access everything (public by default)
  p.scores[0] = 200;
  p.scores[1] = 186;
  p.scores[2] = 175;
  p.scores[3] = 99;
  p.scores[4] = 0;
  std::cout << p.name << " scored:";
  for (double *s = p.scores; s < &p.scores[5]; ++s) {
    std::cout << " " << *s;
  }
  std::cout << std::endl;

  std::cout << "The first score is " << p[0] << std::endl;
  p.name = "Virender";
  p[0] = 219; // reference returned from [] allows read-write access

  std::cout << p.name << "'s top score: " << p[0] << std::endl;

}

int main() {
  test_struct();
}
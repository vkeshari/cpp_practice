#include "bio.cpp"

namespace {

void test_bio() {
  std::cout << "TEST BIO" << std::endl;
  Bio b {"Kohli", 1987};
  std::cout << "Bio for " << b.GetName() << ": Age is " << b.GetAge() << std::endl;
}

void test_bios() {
  std::cout << "TEST BIOS" << std::endl;
  std::vector<Bio> bios {{"Kohli", 1987}, {"Rohit", 1987}, {"Shubhman", 1999}};
  for (Bio b : bios) {
    b.Show();
  }
}

void test_copy() {
  std::cout << "TEST COPY" << std::endl;
  Bio b{"Kohli", 1987};
  Bio c {b}; // copy-initialize
  Bio d = b; // copy-assign
  b.Show();
  c.Show();
  d.Show();
}

Bio returns_a_kohli() {
  Bio b{"Kohli", 1987};
  return b; // Will invoke move constructor on return
}

void test_move() {
  std::cout << "TEST MOVE" << std::endl;
  Bio b = returns_a_kohli();
  Bio c {b}; // copy-initialize after move
  b.Show();
  c.Show();
}

void test_equals() {
  std::cout << "TEST EQUALS" << std::endl;
  Bio b1 {"Kohli", 1987};
  Bio b2 {"Rohit", 1987};
  Bio b3 {"Kohli", 1987};
  std::cout << "b1, b2, b3" << std::endl;
  b1.Show();
  b2.Show();
  b3.Show();
  std::cout << "b1 == b2 is " << (b1 == b2) << std::endl;
  std::cout << "b1 == b3 is " << (b1 == b3) << std::endl;
  std::cout << "b2 == b3 is " << (b2 == b3) << std::endl;
  std::cout << "b1 != b2 is " << (b1 != b2) << std::endl;
  std::cout << "b1 != b3 is " << (b1 != b3) << std::endl;
  std::cout << "b2 != b3 is " << (b2 != b3) << std::endl;
}

} // namespace

int main() {
  test_bio();
  test_bios();
  test_copy();
  test_move();
  test_equals();
}
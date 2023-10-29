#include<iostream>
#include "batter.cpp"

namespace {

void test_batter() {
  std::cout << "TEST BATTER" << std::endl;
  Batter b {"Kohli", 1987, 18, {183, 160, 157, 154}};
  std::cout << "Batter " << b.GetName() << ", age " << b.GetAge() << " shows as: " << std::endl;
  b.Show();

  b.UpdateHighScores({183, 166, 160, 157, 154});
  b.Show();

  b.UpdateHighScores({183});
  b.Show();

  b += 166; // test insert with +=
  b.Show();
  b += 160;
  b.Show();
  b += 157; // should not insert
  b.Show();

  b[0] = 0; // test mutable index access
  b.Show();
}

void test_copy() {
  std::cout << "TEST COPY" << std::endl;
  Batter b{"Kohli", 1987, 18, {183, 160, 157, 154}};
  Batter c {b}; // copy-initialize
  Batter d = b; // copy-assign
  b.Show();
  c.Show();
  d.Show();
}

Batter returns_a_kohli() {
  Batter b{"Kohli", 1987, 18, {183, 160, 157, 154}};
  return b; // Will invoke move constructor on return
}

void test_move() {
  std::cout << "TEST MOVE" << std::endl;
  Batter b = returns_a_kohli();
  Batter c {b}; // copy-initialize after move
  Batter d = std::move(c);
  b.Show();
  // c.Show(); Segfault (see person_test)
  d.Show();
}

} // namespace

int main() {
  test_batter();
  test_copy();
  test_move();
}
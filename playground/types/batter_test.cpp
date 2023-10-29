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

} // namespace

int main() {
  test_batter();
}
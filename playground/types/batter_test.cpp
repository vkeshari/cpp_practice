#include<iostream>
#include "batter.cpp"

namespace {

void test_batter() {
  std::cout << "TEST BATTER" << std::endl;
  Batter b {"Kohli", 1987, 18, {183, 160, 157, 154}};
  std::cout << "Batter " << b.GetName() << ", age " << b.GetAge() << " shows as: " << std::endl;
  b.Show();

  b.UpdateHighScores({183, 166, 160, 157, 154});
  std::cout << "Batter " << b.GetName() << ", age " << b.GetAge() << " shows as: " << std::endl;
  b.Show();

  b.UpdateHighScores({183});
  std::cout << "Batter " << b.GetName() << ", age " << b.GetAge() << " shows as: " << std::endl;
  b.Show();

  b[0] = 0;
  std::cout << "Batter " << b.GetName() << ", age " << b.GetAge() << " shows as: " << std::endl;
  b.Show();
}

} // namespace

int main() {
  test_batter();
}
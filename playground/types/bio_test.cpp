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

} // namespace

int main() {
  test_bio();
  test_bios();
}
#include <iostream>
#include "cricketer.cpp"

namespace {

void test_cricketer () {
  std::cout << "TEST CRICKETER" << std::endl;
  Cricketer c {"Kohli", 1987, 18};
  std::cout << "Cricketer " << c.GetName() << ", age " << c.GetAge() << " shows as: " << std::endl;
  c.Show();
}

} // namespace

int main() {
  test_cricketer();
}
#include <iostream>
#include "cricketer.cpp"

namespace {

void test_cricketer () {
  std::cout << "TEST CRICKETER" << std::endl;
  Cricketer c {"Kohli", 1987, 18};
  std::cout << "Cricketer " << c.GetName() << ", age " << c.GetAge() << " shows as: " << std::endl;
  c.Show();
}

void test_copy() {
  std::cout << "TEST COPY" << std::endl;
  Cricketer c{"Kohli", 1987, 18};
  Cricketer d {c}; // copy-initialize
  Cricketer e = c; // copy-assign
  c.Show();
  d.Show();
  e.Show();
}

Cricketer returns_a_kohli() {
  Cricketer c{"Kohli", 1987, 18};
  return c; // Will invoke move constructor on return
}

void test_move() {
  std::cout << "TEST MOVE" << std::endl;
  Cricketer c = returns_a_kohli();
  Cricketer d {c}; // copy-initialize after move
  c.Show();
  d.Show();
}

void test_equals() {
  std::cout << "TEST EQUALS" << std::endl;
  Cricketer c1 {"Kohli", 1987, 18};
  Cricketer c2 {"Rohit", 1987, 45};
  Cricketer c3 {"Kohli", 1987, 18};
  std::cout << "c1, c2, c3" << std::endl;
  c1.Show();
  c2.Show();
  c3.Show();
  std::cout << "c1 == c2 is " << (c1 == c2) << std::endl;
  std::cout << "c1 == c3 is " << (c1 == c3) << std::endl;
  std::cout << "c2 == c3 is " << (c2 == c3) << std::endl;
}

} // namespace

int main() {
  test_cricketer();
  test_copy();
  test_move();
  test_equals();
}
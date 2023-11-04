#include "person.cpp"

namespace {

void test_person() {
  std::cout << "TEST PERSON" << std::endl;
  Person p {"Kohli", 1987};
  std::cout << "Person " << p.GetName() << ", age " << p.GetAge() << " shows as: " << std::endl;
  p.GetBio().Show();

  Person q {new Bio("Rohit", 1987)};
  std::cout << "Person " << q.GetName() << ", age " << q.GetAge() << " shows as: " << std::endl;
  q.GetBio().Show();
}

void test_copy() {
  std::cout << "TEST COPY" << std::endl;
  Person p{"Kohli", 1987};
  Person q {p}; // copy-initialize
  Person r = p; // copy-assign
  p.Show();
  q.Show();
  r.Show();
}

Person returns_a_kohli() {
  Person p{"Kohli", 1987};
  return p; // Will invoke move constructor on return
}

void test_move() {
  std::cout << "TEST MOVE" << std::endl;
  Person p = returns_a_kohli();
  Person q {p}; // copy-initialize after move
  Person r = std::move(q);
  p.Show();
  // q.Show(); Segfault as q.bio is nullptr
  r.Show();
}

void test_equals() {
  std::cout << "TEST EQUALS" << std::endl;
  Person p1 {"Kohli", 1987};
  Person p2 {"Rohit", 1987};
  Person p3 {"Kohli", 1987};
  std::cout << "p1, p2, p3" << std::endl;
  p1.Show();
  p2.Show();
  p3.Show();
  std::cout << "p1 == p2 is " << (p1 == p2) << std::endl;
  std::cout << "p1 == p3 is " << (p1 == p3) << std::endl;
  std::cout << "p2 == p3 is " << (p2 == p3) << std::endl;
}

} // namespace

int main() {
  test_person();
  test_copy();
  test_move();
  test_equals();
}
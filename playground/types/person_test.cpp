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
}

int main() {
  test_person();
}
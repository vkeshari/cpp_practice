#include <iostream>
#include "person.cpp"

class Cricketer : public Person {
 private:
  int jerseyNo;

 public:
  Cricketer(const std::string& name, int year_of_birth, int jerseyNo) :
      Person{name, year_of_birth}, // Initialize super-class with its constructor
      jerseyNo{jerseyNo} { } // Initialize member variable like normal

  ~Cricketer() {}

  const int GetJerseyNo() const {
    return jerseyNo;
  }

  void Show() const {
    std::cout << '[' << jerseyNo << ']' ;
    Person::Show(); // Call super-class method
  }
};
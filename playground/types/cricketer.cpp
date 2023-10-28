#include <iostream>
#include <string>
#include "person.cpp"

class Cricketer : public Person {
 private:
  int jerseyNo;
  std::string customName;

 public:
  Cricketer(const std::string& name, int year_of_birth, int jerseyNo) :
      Person{name, year_of_birth}, // Initialize super-class with its constructor
      jerseyNo{jerseyNo} {
    customName = '[' + std::to_string(jerseyNo) + "] " + Person::GetName();
  } // Initialize member variable like normal

  ~Cricketer() {}

  int GetJerseyNo() const {
    return jerseyNo;
  }

  const std::string& GetName() const override { // override an overriden method
    return customName; // cannot build a string here since method returns a reference
  }

  virtual void Show() const override {
    std::cout << '[' << jerseyNo << ']' ;
    Person::Show(); // Call super-class method
  }
};
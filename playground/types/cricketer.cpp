#include <iostream>
#include <string>
#include "person.cpp"

class Cricketer : public Person {
 private:
  int jerseyNo;
  std::string nameWithJersey;

 public:
  Cricketer(const std::string& name, int year_of_birth, int jerseyNo) :
      Person{name, year_of_birth}, // Initialize super-class with its constructor
      jerseyNo{jerseyNo} {
    nameWithJersey = '[' + std::to_string(jerseyNo) + "] " + Person::GetName();
  } // Initialize member variable like normal

  ~Cricketer() override { }

  // Can use default move and copy constructors even if base class has defined ones
  Cricketer(const Cricketer&) = default;
  Cricketer(Cricketer&&) = default;

  bool operator==(const Cricketer& c) const {
    // Can call base class's function with child's argument-type
    // Can directly access base class's members (no need for getter)
    return jerseyNo == c.jerseyNo && Person::operator==(c);
  }

  bool operator!=(const Cricketer& c) const {
    return !operator==(c);
  }

  int GetJerseyNo() const {
    return jerseyNo;
  }

  const std::string& GetName() const override { // override an overriden method
    return nameWithJersey; // cannot build a string here since method returns a reference
  }

  virtual void Show() const override {
    std::cout << '[' << jerseyNo << ']' ;
    Person::Show(); // Call super-class method
  }
};
#include <iostream>

constexpr int YEAR = 2023;

// A concrete class has all operations defined inline
class Bio {
 private:
  std::string name;
  int yearOfBirth;

 public:
  Bio (const std::string& name, int year_of_birth) : name{name}, yearOfBirth{year_of_birth} { }

  inline const std::string& GetName() const { // Make getters const, return objects by const reference
    return name;
  }

  inline int GetAge() const { // Make getters const, return basic types by value
    return YEAR - yearOfBirth;
  }

  inline void Show() const {
    std::cout << '\t' << name << ": " << GetAge() << std::endl;
  }
};
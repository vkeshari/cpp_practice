#include <iostream>

constexpr int YEAR = 2023;

// A concrete class has all operations defined inline
class Bio {
 private:
  std::string name;
  int yearOfBirth;

 public:
  Bio (const std::string& name, int year_of_birth) : name{name}, yearOfBirth{year_of_birth} { }

  ~Bio() { }; // Member destructors are automatically called

  Bio(const Bio&) = default; // Default copy constructor
  Bio(Bio&&) = default; // Default move constructor

  inline const std::string& GetName() const { // Make getters const, return objects by const reference
    return name;
  }

  inline int GetAge() const { // Make getters const, return basic types by value
    return YEAR - yearOfBirth;
  }

  inline void Show() const {
    std::cout << '\t' << name << " (" << GetAge() << ')' << std::endl;
  }

  bool operator==(const Bio& b) const { // Mark operators const
    return b.name == name && b.yearOfBirth == yearOfBirth;
  }

  bool operator!=(const Bio& b) const { // Always have a != for a ==
    return !operator==(b);
  }
};
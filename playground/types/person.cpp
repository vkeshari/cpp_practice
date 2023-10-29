#include "human.h"

class Person : public Human {
 private:
  std::unique_ptr<Bio> bio; // Use unique_ptr instead of naked pointer for auto garbage-collection

 public:
  Person (const std::string& name, int year_of_birth)
      : bio{std::unique_ptr<Bio> (new Bio{name, year_of_birth})} { }

  // Mark single-argument constructors as explicit to avoid Person = Bio (implicit conversion)
  explicit Person (Bio* bio) : bio{std::unique_ptr<Bio>(bio)} { } // Can assign pointer to unique_ptr

  ~Person() override { } // Destructor automatically destructs members

  // Copy constructor
  Person(const Person& p) {
    Bio b {*p.bio};
    bio = std::make_unique<Bio>(b); // std::make_unique<> perserves memory outside scope
  }

  // Move constructor
  Person(Person&& p) {
    bio = std::move(p.bio); // Use std::unique_ptr<>'s move 
  }

  bool operator==(const Person& p) const {
    return *bio == p.GetBio();
  }

  bool operator!=(const Person& p) const {
    return !operator==(p);
  }

  const Bio& GetBio() const override {
    return *bio; // Can dereference unique_ptr directly
  }

  const std::string& GetName() const override {
    return bio->GetName(); // Can access unique_ptr members directly
  }

  int GetAge() const override {
    return bio->GetAge(); // Can access unique_ptr members directly
  }

  // Can define virtual function in a concrete class
  // (it just means "can be overriden")
  virtual void Show() const {
    bio->Show();
  }
};
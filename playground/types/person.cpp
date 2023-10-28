#include "human.h"

class Person : public Human {
 private:
  std::unique_ptr<Bio> bio; // Use unique_ptr instead of naked pointer for auto garbage-collection

 public:
  Person (const std::string& name, int year_of_birth)
      : bio{std::unique_ptr<Bio> (new Bio{name, year_of_birth})} { }

  Person (Bio* bio) : bio{std::unique_ptr<Bio>(bio)} { } // Can assign pointer to unique_ptr

  ~Person() { } // Destructor automatically destructs members

  const Bio& GetBio() const override {
    return *bio; // Can dereference unique_ptr directly
  }

  const std::string& GetName() const override {
    return bio->GetName(); // Can access unique_ptr members directly
  }

  const int GetAge() const override {
    return bio->GetAge(); // Can access unique_ptr members directly
  }

  virtual void Show() const {
    bio->Show();
  }
};
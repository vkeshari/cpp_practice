#include "bio.cpp"

// Human is an interface: A pure virtual class
class Human {
 public:
  // No need for a constructor in abstract classes
  // But they need a destructor (so that derivatives' destructors can be called from their pointers)
  ~Human() {}

  // virtual functions may be redefined,
  // =0 means pure virtual, it must be defined somewhere,
  virtual const Bio& GetBio() const = 0;

  virtual const std::string& GetName() const = 0;

  virtual const int GetAge() const = 0;
};
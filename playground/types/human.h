#include "bio.cpp"

// Human is an interface: A pure virtual class
class Human {
 public:
  // No need for a constructor in abstract classes
  // But they need a destructor (so that derivatives' destructors can be called from their pointers)
  virtual ~Human() {}

  // virtual functions may be overriden by subclasses (abstract or not),
  // =0 means pure virtual, it must be defined by non-abstract subclasses,
  virtual const Bio& GetBio() const = 0;

  virtual const std::string& GetName() const = 0;

  virtual int GetAge() const = 0; // primary return types don't need to be const, they're immutable
};
#include <iostream>

template<typename T>
class BadContainer {
 private:
  T* values;
  int size;

 public:
  // Constructors
  BadContainer(int s) : values {new T[s]}, size {s} { }

  BadContainer(std::initializer_list<T> elems) {
    // BadContainer<T>(elems.size()); Cannot call constructor from another constructor

    size = static_cast<int>(elems.size());
    values = new T[size];
    int i = 0;
    for (const T& e : elems) {
      values[i] = e;
      ++i;
    }
  }

  // Destructor
  ~BadContainer() {
    delete[] values;
  }

  // Copy initialize
  BadContainer(const BadContainer<T>& bad) : values {new T[bad.size]}, size{bad.size} {
    for (int i = 0; i < size; ++i) {
      values[i] = bad.values[i];
    }
  }

  // Move initialize
  BadContainer(BadContainer<T>&& bad) : values{bad.values}, size{bad.size} {
    bad.values = nullptr;
  }

  // Mutable element access
  T& operator[](int i) const {
    return values[i];
  }

  // Iteration
  T* begin() const {
    return size ? &values[0] : nullptr;
  }

  T* end() const {
    return size ? &values[size] : nullptr;
  }

  // Debug
  void Show() const {
    for (const T& v : *this) { // calls begin() and end() on self
      std::cout << '\t' << v;
    }
    std::cout << std::endl;
  }

};

namespace {

void test_bad_container() {
  std::cout << "TEST BAD CONTAINER" << std::endl;

  BadContainer<int> b1 {1, 2, 3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadContainer<int> c1 {b1}; // test copy
  BadContainer<int> m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();

  BadContainer<int> b2(3); // no elements, default to zero (why?)
  std::cout << "b2 is:" << std::endl;
  b2.Show();

  BadContainer<int> c2 {b2}; // test copy
  BadContainer<int> m2 = std::move(b2); // test move
  std::cout << "c2, m2:" << std::endl;
  c2.Show();
  m2.Show();

  // BadContainer b3 {1, 1.5, "hello"s}; Ambiguous type
}

void test_type_deduction() {
  std::cout << "TEST TYPE DEDUCTION" << std::endl;

  BadContainer b1 {1, 2, 3}; // Parameter T not specified
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadContainer c1 {b1}; // test copy
  BadContainer m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();

  // BadContainer b2(3); There is no type to deduce
}

void test_alias() {
  std::cout << "TEST ALIAS" << std::endl;
  using BadIntContainer = BadContainer<int>;

  BadIntContainer b1 {1, 2, 3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadIntContainer c1 {b1}; // test copy
  BadIntContainer m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();

  BadIntContainer b2(3); // no elements but type already declared, default to zero (why?)
  std::cout << "b2 is:" << std::endl;
  b2.Show();

  BadIntContainer c2 {b2}; // test copy
  BadIntContainer m2 = std::move(b2); // test move
  std::cout << "c2, m2:" << std::endl;
  c2.Show();
  m2.Show();
}

} // namespace

int main() {
  test_bad_container();
  test_type_deduction();
  test_alias();
}
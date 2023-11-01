#include<iostream>

template <typename T, int N>
class BadParameterized {
 private:
  std::unique_ptr<T[]> values {new T[N]}; // default value initializer

 public:
  BadParameterized() { } // empty constructor because default value initializer

  BadParameterized(std::initializer_list<T> elems) {
    // just logic, ignore
    int i = 0;
    for (const T& e : elems) {
      values[i] = e;
      ++i;
      if (i == N) {
        break;
      }
    }
  }

  ~BadParameterized() { } // destructor auto-destructs membersc

  // Copy constructor for size N
  BadParameterized(const BadParameterized<T, N>& bad) {
    values = std::make_unique<T[]>(N); // std::unipue_ptr factory constructor for arrays
    for (int i = 0; i < N; ++i) {
      values[i] = bad.values[i]; // can use operator[] on std::unique_ptr<T[]>
    }
  }

  // Move constructor will use std::unique_ptr's default
  BadParameterized(BadParameterized<T, N>&& bad) = default;

  // Debug
  void Show() const {
    for (int i = 0; i < N; ++i) {
      std::cout << '\t' << values[i];
    }
    std::cout << std::endl;
  }
};

namespace {

void test_bad_param() {
  std::cout << "TEST BAD PARAM" << std::endl;

  BadParameterized<int, 3> b1 {1, 2, 3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadParameterized<int, 3> c1 {b1}; // test copy
  BadParameterized<int, 3> m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();

  // Argument deduction only works for types, not value parameters
  // BadParameterized b2 {1, 2, 3};
}

template <int N>
using BadIntParameterized = BadParameterized<int, N>;

void test_left_alias() {
  std::cout << "TEST LEFT ALIAS" << std::endl;

  BadIntParameterized<3> b1 {1, 2, 3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadIntParameterized<3> c1 {b1}; // test copy
  BadIntParameterized<3> m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();
}

template <typename T>
using BadThree = BadParameterized<T, 3>;

void test_right_alias() {
  std::cout << "TEST RIGHT ALIAS" << std::endl;

  BadThree<int> b1 {1, 2, 3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadThree<int> c1 {b1}; // test copy
  BadThree<int> m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();

  // Argument deduction only allowed for class templates, not alias templates
  // BadThree b2 {1, 2, 3};

  // Can't do it without alias template either, _ doesn't work unlike Python
  // BadParameterized<_, 3> b3 {1, 2, 3};
}

}  // namespace

int main() {
  test_bad_param();
  test_left_alias();
  test_right_alias();
}
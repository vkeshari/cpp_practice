#include<iostream>

template <typename T1, typename T2>
class BadPair {
 private:
  std::unique_ptr<T1> value1;
  std::unique_ptr<T2> value2;
 
 public:
  BadPair() { }

  BadPair(T1 v1, T2 v2) :
      value1{std::make_unique<T1>(v1)},
      value2{std::make_unique<T2>(v2)} { }

  ~BadPair() { }

  BadPair(const BadPair<T1, T2>& bad) {
    T1 t1_val {*bad.value1};
    value1 = std::make_unique<T1>(t1_val);
    T2 t2_val {*bad.value2};
    value2 = std::make_unique<T2>(t2_val);
  }

  BadPair(BadPair<T1, T2>&& bad) = default;

  void Show() const {
    std::cout << '\t' << *value1 << '\t' << *value2 << std::endl;
  }
};

namespace {

void test_pair() {
  std::cout << "TEST PAIR" << std::endl;

  BadPair<int, double> b1 {1, 2.3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadPair<int, double> c1 {b1}; // test copy
  BadPair<int, double> m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();
}

void test_type_deduction() {
  std::cout << "TEST TYPE DEDUCTION" << std::endl;

  BadPair b1 {1, 2.3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadPair c1 {b1}; // test copy
  BadPair m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();

  BadPair b2 {1, 2};
  // Can't copy a <T1, T2> to a <T1, T3> even if conversion is possible
  // BadPair<int, double> b3 {b2};
}

template <typename T>
using BadLeftInt = BadPair<int, T>;

void test_left_alias() {
  std::cout << "TEST LEFT ALIAS" << std::endl;

  BadLeftInt<double> b1 {1, 2.3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadLeftInt<double> c1 {b1}; // test copy
  BadLeftInt<double> m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();
}

template <typename T>
using BadRightDouble = BadPair<T, double>;

void test_right_alias() {
  std::cout << "TEST RIGHT ALIAS" << std::endl;

  BadRightDouble<int> b1 {1, 2.3};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadRightDouble<int> c1 {b1}; // test copy
  BadRightDouble<int> m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();
}

struct SimpleStruct {
  int value1, value2;

  SimpleStruct(int v1, int v2) : value1{v1}, value2{v2} { }
  ~SimpleStruct() { }
  SimpleStruct(const SimpleStruct&) = default;
  SimpleStruct(SimpleStruct&&) = default;

  const int GetValue1() const {return value1;}
  const int GetValue2() const {return value2;}
};

// operator<< is the C++ equivalent of Java's toString() or Python's __str()__
std::ostream& operator<<(std::ostream &os, const SimpleStruct &ss) {
  return os << '{' + std::to_string(ss.GetValue1()) + ", " + std::to_string(ss.GetValue2()) + '}';
}

void test_class_deduction() {
  std::cout << "TEST CLASS DEDUCTION" << std::endl;

  SimpleStruct ss1 {1, 2};
  SimpleStruct ss2 {3, 4};

  BadPair<SimpleStruct, SimpleStruct> b1 {ss1, ss2};
  std::cout << "b1 is:" << std::endl;
  b1.Show();

  BadPair<SimpleStruct, SimpleStruct> c1 {b1}; // test copy
  BadPair<SimpleStruct, SimpleStruct> m1 = std::move(b1); // test move
  std::cout << "c1, m1:" << std::endl;
  c1.Show();
  m1.Show();
}

} // namespace

int main() {
  test_pair();
  test_type_deduction();
  test_left_alias();
  test_right_alias();
  test_class_deduction();
}
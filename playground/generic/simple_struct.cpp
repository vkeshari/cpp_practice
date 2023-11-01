#include<iostream>

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
std::ostream& operator<<(std::ostream& os, const SimpleStruct& ss) {
  return os << '{' + std::to_string(ss.GetValue1()) + ", " + std::to_string(ss.GetValue2()) + '}';
}

bool operator==(const SimpleStruct& ss1, const SimpleStruct& ss2) {
  return ss1.GetValue1() == ss2.GetValue1() && ss1.GetValue2() == ss2.GetValue2();
}
#include <iostream>

void test_curly_assignment() {
  std::cout << "TEST CURLY ASSIGNMENT" << std::endl;

  int a = 5;

  // int b = c = 5; Chain assignments no longer work
  int b = 5, c = b;

  int d {5}; // initializer assignment

  std::cout<< "a is " << a << std::endl;
  std::cout<< "b is " << b << std::endl;
  std::cout<< "c is " << c << std::endl;
  std::cout<< "d is " << d << std::endl;

  int e = 3.5; // implicit conversion warning
  // int e {3.5}; "cannot be narrowed" in initializer

  float f = 3.5;
  int g = f; // no implicit conversion warning
  // int g1 {f}; "cannot be narrowed" in initializer

  std::cout<< "e is " << e << std::endl;
  std::cout<< "f is " << f << std::endl;
  std::cout<< "g is " << g << std::endl;

  int h = static_cast<int>(f); // use static cast to explicitly narrow
  std::cout<< "h is " << h << std::endl;
 }

void test_references() {
  std::cout << "TEST REFERENCES" << std::endl;

  int a = 5;
  // int &b; Cannot initialize an empty reference variable
  int &b = a, &c {a}; // & binds to variable name, not type (common mistake in C++ texts)

  std::cout<< "a is " << a << std::endl;
  std::cout<< "b is " << b << std::endl;
  std::cout<< "c is " << c << std::endl;

  b = 7; // this will change a, and also c as all are references to the same value
  std::cout<< "a is " << a << std::endl;
  std::cout<< "b is " << b << std::endl;
  std::cout<< "c is " << c << std::endl;
}

void test_floating_point() {
  std::cout << "TEST FLOATING POINT" << std::endl;
  float a = 3.14f;
  float b = 3.14; // no implicit conversion warning (constants default to double)
  float c = 3.14e-1; // can initialize in exponent format

  std::cout<< "a is " << a << std::endl;
  std::cout<< "b is " << b << std::endl;
  std::cout<< "c is " << c << std::endl;

  double d = 3.14;
  float e = d; // no implicit conversion warning

  std::cout<< "d is " << d << std::endl;
  std::cout<< "e is " << e << std::endl;
}

 int main() {
  test_curly_assignment();
  test_references();
  test_floating_point();
 }
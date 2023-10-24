#include <iostream>

constexpr double PI = 3.14; // scope is global

namespace const_scope {
  constexpr double SQRT_2 = 1.414; // scope is namespace (even for constexpr)
} // namespace const_test

void test_constexpr_scope() {
  std::cout << "TEST CONSTEXPR SCOPE" << std::endl;

  std::cout << "PI is " << PI << std::endl;
  // std::cout << "SQRT_2 is " <<  SQRT_2 << std::endl; must use scope qualified name
  std::cout << "SQRT_2 is " <<  const_scope::SQRT_2 << std::endl;
}

// Note: constexpr functions should not have any side effects
constexpr double square(const double &x) {
  return x * x;
}
constexpr double PI_SQUARE = square(PI); // can call constexpr function in constexpr definition

void test_constexpr_function() {
  std::cout << "TEST CONSTEXPR FUNCTION" << std::endl;
  std::cout << "PI squared is " << PI_SQUARE << std::endl;

  double SQRT_3 = 1.732;
  std::cout << "SQRT_3 squared is " << square(SQRT_3) << std::endl; // call constexpr function with any arg in code
}

void test_const_reference() {
  std::cout << "TEST CONST REFERENCE" << std::endl;
  // double &p = PI; // Cannot assign constexpr variable to non-const reference
  const double &p = PI; // can assign to const reference

  std::cout << "p is " << p << std::endl;

  const double q = 5.0;
  // double &r = q; // Cannot assign const variable to non-const reference
  const double &r = q; // can assign to const reference

  std::cout << "q is " << q << std::endl;
  std::cout << "r is " << r << std::endl;
}

int main() {
  test_constexpr_scope();
  test_constexpr_function();
  test_const_reference();
}

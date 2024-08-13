#include <iostream>

constexpr double PI = 3.14; // scope is global

namespace const_scope {
  // Scope is namespace (even for constexpr)
  constexpr double SQRT_2 = 1.414;
} // namespace const_scope

void test_constexpr_scope() {
  std::cout << "TEST CONSTEXPR SCOPE" << std::endl;

  std::cout << "PI is " << PI << std::endl;
  // Must use scope qualified name
  //   std::cout << "SQRT_2 is " << SQRT_2 << std::endl;
  std::cout << "SQRT_2 is " << const_scope::SQRT_2 << std::endl;
}

// Note: constexpr functions should not have any side effects
constexpr double square(const double &x) {
  return x * x;
}
// Can call constexpr function in constexpr definition
constexpr double PI_SQUARE = square(PI);

void test_constexpr_function() {
  std::cout << "TEST CONSTEXPR FUNCTION" << std::endl;
  std::cout << "PI squared is " << PI_SQUARE << std::endl;

  double sqrt_3 = 1.732;
  // Call constexpr function with any arg in code
  std::cout << "SQRT_3 squared is " << square(sqrt_3) << std::endl;
}

void test_const_reference() {
  std::cout << "TEST CONST REFERENCE" << std::endl;
  // Cannot assign constexpr variable to non-const reference
  //   double &p = PI;
  // Can assign to const reference
  const double &p = PI;

  std::cout << "p is " << p << std::endl;

  const double q = 5.0;
  // Cannot assign const variable to non-const reference
  //   double &r = q;
  // Can assign to const reference
  const double &r = q;

  std::cout << "q is " << q << std::endl;
  std::cout << "r is " << r << std::endl;
}

int main() {
  test_constexpr_scope();
  test_constexpr_function();
  test_const_reference();
}

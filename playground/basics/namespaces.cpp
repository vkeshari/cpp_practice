#include <iostream>

namespace alpha {

int alpha_val = 1;
int get_val2();

} // namespace alpha

// alpha::alpha_val = 5; Can't assign values outside namespace

int alpha::get_val2() { // can define declared functions outside namespace
  return 2;
}

/* Can't define an undeclared function outside namespace
int alpha::get_val3() {
  return 3;
}
*/

void test_namespace_declarations() {
  std::cout << "TEST NAMESPACE DECLARATIONS" << std::endl;

  std::cout << "Alpha val1 is " << alpha::alpha_val << std::endl;
  std::cout << "Alpha val2 is " << alpha::get_val2() << std::endl;

  alpha::alpha_val = 5; // can assign values outside namespace only from within function (why?)
  std::cout << "Alpha val1 is " << alpha::alpha_val << std::endl;
  alpha::alpha_val = 1;
}

void test_namespace_usage() {
  std::cout << "TEST NAMESPACE USAGE" << std::endl;
  using namespace alpha;

  std::cout << "Alpha val1 is " << alpha_val << std::endl;
  std::cout << "Alpha val2 is " << get_val2() << std::endl;

  alpha_val = 5; // can also directly assign values from within function when using namespace
  std::cout << "Alpha val1 is " << alpha_val << std::endl;
  alpha_val = 1;
}

void test_namespace_member_usage() {
  std::cout << "TEST NAMESPACE MEMBER USAGE" << std::endl;
  using alpha::get_val2;

  std::cout << "Alpha val1 is " << alpha::alpha_val << std::endl;
  std::cout << "Alpha val2 is " << get_val2() << std::endl;
}

namespace {
  int gamma = 5;
} // namespace

void test_anonymous_namespace() {
  std::cout << "TEST ANONYMOUS NAMESPACE" << std::endl;
  std::cout << "Gamma is " << gamma << std::endl; // can directly access member in anonymous namespace
}

int main() {
  test_namespace_declarations();
  test_namespace_usage();
  test_namespace_member_usage();
  test_anonymous_namespace();
}

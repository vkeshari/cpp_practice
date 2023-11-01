#include<iostream>
#include "simple_struct.cpp"

namespace lambdas {

// A function template that runs a predicate on values in a vector
template <typename V, typename P>
bool run_predicate(const V& values, const P& predicate) {
  return predicate(values);
}

} // namespace lambdas

namespace {
using namespace lambdas;

// Debug: A function template that prints a vector of generic type
template <typename T>
void show_vector(const std::vector<T>& vec) {
  std::cout << '\t' << '{';
  for (const auto& v : vec) {
    std::cout << v << ", ";
  }
  std::cout << '}' << std::endl;
}

// Debug: Bool to string
std::string bool_to_string(bool b) {
  return b? "True" : "False";
}

void test_lambda() {
  std::cout << "TEST LAMBDA" << std::endl;

  std::vector<int> v1 {1, 2, 3, 4, 5};
  std::vector<int> v2 {1, 2, 3, 3, 3};
  std::vector<int> v3 {1, 2, 4, 4, 5};

  int value = 3;

  // type of a lambda function is std::function (no need to specify it, can use auto)
  const std::function<bool(const std::vector<int>&)>
      // [&] means all local variables by reference, [=] means by value, [] means no variables
      // auto& argument to lambda function makes it a generic lambda
      // No local variables in lambda functions, but multiple statements are okay
      // No need to specify return type anywhere in lambda definition
      contains_lambda = [&](const auto& vec) {
                          for (const auto& v : vec) {
                            if (v == value) return true; 
                          } return false;
                        };

  std::cout << "v1 is:";
  show_vector(v1);
  std::cout << "Contains " << value << ": " << bool_to_string(run_predicate(v1, contains_lambda)) << std::endl;

  std::cout << "v2 is:";
  show_vector(v2);
  std::cout << "Contains " << value << ": " << bool_to_string(run_predicate(v2, contains_lambda)) << std::endl;

  std::cout << "v3 is:";
  show_vector(v3);
  std::cout << "Contains " << value << ": " << bool_to_string(run_predicate(v3, contains_lambda)) << std::endl;
}

} // namespace

int main() {
  test_lambda();
}
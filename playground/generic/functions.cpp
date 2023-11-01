#include<iostream>
#include "simple_struct.cpp"

namespace counter { // Class and function together in a namespace

// Class for a function object that counts occurrences in a std::vector
template <typename T>
class CountValues {
 private:
  T value;

 public:
  explicit CountValues(T v) : value {v} { }
  ~CountValues() { }
  CountValues(const CountValues&) = default;
  CountValues(CountValues&&) = default;

  const T& GetValue() const {return value;}

  // Define operator() for Function objects
  int operator()(const std::vector<T>& vals) const {
    int count = 0;
    for (const auto& v : vals) {
      if (v == value) {
        ++count;
      }
    }
    return count;
  }
};

// A function template that counts values with a counter function object
template <typename V, typename C>
int count_values(const V& vec, const C& counter) {
  return counter(vec); // A function object can be called like a function if operator() is defined
}

} // namespace counter

namespace {
using namespace counter;

// Debug: A function template that prints a vector of generic type
template <typename T>
void show_vector(const std::vector<T>& vec) {
  std::cout << '\t' << '{';
  for (const auto& v : vec) {
    std::cout << v << ", ";
  }
  std::cout << '}' << std::endl;
}

void test_count_ints() {
  std::cout << "TEST COUNT INTS" << std::endl;

  CountValues count_3s {3};
  std::vector vals = {1, 2, 3, 3, 2, 1, 3, 3, 4, 5, 3, 0};

  std::cout << "Vals: ";
  show_vector(vals);
  std::cout << "Count for " << count_3s.GetValue() << ": " << count_values(vals, count_3s) << std::endl;
}

void test_count_structs() {
  std::cout << "TEST COUNT STRUCTS" << std::endl;

  SimpleStruct ss {2, 3};
  CountValues count_ss {ss};

  SimpleStruct ss1 {1, 2};
  SimpleStruct ss2 {2, 3};
  SimpleStruct ss3 {3, 4};
  SimpleStruct ss4 {2, 3};
  std::vector vals = {ss1, ss2, ss3, ss4};

  std::cout << "Vals: ";
  show_vector(vals);
  std::cout << "Count for " << count_ss.GetValue() << ": " << count_values(vals, count_ss) << std::endl;
}

} // namespace

int main() {
  test_count_ints();
  test_count_structs();
}
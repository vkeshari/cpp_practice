#include<iostream>
#include "simple_struct.cpp"

template <typename T>
class CountValues { // A function object that counts occurrences in a std::vector
 private:
  T value;

 public:
  explicit CountValues(T v) : value {v} { }
  ~CountValues() { }
  CountValues(const CountValues&) = default;
  CountValues(CountValues&&) = default;

  const T& GetValue() const {return value;}

  int operator()(const std::vector<T>& vals) const { // define operator() for Function objects
    int count = 0;
    for (const auto& v : vals) {
      if (v == value) {
        ++count;
      }
    }
    return count;
  }
};

namespace {

template <typename T>
void show_vector(const std::vector<T>& vec) {
  std::cout << '\t' << '{';
  for (const auto& v : vec) {
    std::cout << v << ", ";
  }
  std::cout << '}' << std::endl;
}

void test_count_values() {
  std::cout << "TEST COUNT VALUES" << std::endl;

  CountValues count_3s {3};
  std::vector vals = {1, 2, 3, 3, 2, 1, 3, 3, 4, 5, 3, 0};
  std::cout << "Vals: ";
  show_vector(vals);
  std::cout << "Count for " << count_3s.GetValue() << ": " << count_3s(vals) << std::endl;
}

void test_count_structs() {
  std::cout << "TEST COUNT STRUCTS" << std::endl;

  SimpleStruct ss {2, 3};
  SimpleStruct ss1 {1, 2};
  SimpleStruct ss2 {2, 3};
  SimpleStruct ss3 {3, 4};
  SimpleStruct ss4 {2, 3};
  CountValues count_ss {ss};
  std::vector vals = {ss1, ss2, ss3, ss4};
  std::cout << "Vals: ";
  show_vector(vals);
  std::cout << "Count for " << count_ss.GetValue() << ": " << count_ss(vals) << std::endl;
}

} // namespace

int main() {
  test_count_values();
  test_count_structs();
}
#include <iostream>

namespace {

template <typename T>
// Array is passed as a pointer, not as an array type
// Note that [] is after variable name not after type
// There is no way to measure length once passed to function
//   (sizeof(arr) won't work), so also pass length
void show_array(const T arr[], int l) {
// Alternative definition
//   void show_array(const T* arr, int l) {
  std::cout << "{";
  for (int i = 0; i < l; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "}" << std::endl;
  std::cout << "\tSize: " << l << std::endl;

  // Can measure sizeof template
  std::cout << "\tElement size: " << sizeof(T) << std::endl;
  std::cout << "\tTotal Bytes: " << sizeof(T) * l << std::endl;
  std::cout << std::endl;
}

void test_arrays() {
  std::cout << "TEST ARRAYS" << std::endl;

  int a[] {1, 2, 3, 4, 5}; // Initialization
  int a_size = sizeof(a) / sizeof(a[0]); // Size of array
  std::cout << "Array a is: ";
  show_array(a, a_size);

  int b[5] {1, 2, 3, 4, 5}; // Initialization with specific size
  int b_size = sizeof(b) / sizeof(b[0]); // Size of array
  std::cout << "Array b is: ";
  show_array(b, b_size);

  int c[5] = {1, 2, 3, 4, 5}; // Assignment
  int c_size = sizeof(c) / sizeof(c[0]); // Size of array
  std::cout << "Array c is: ";
  show_array(c, c_size);

  int d[5] = {1, 2, 3}; // Assignment with smaller size (zero-padded)
  int d_size = sizeof(d) / sizeof(d[0]); // Size of array
  std::cout << "Array d is: ";
  show_array(d, d_size);

  // Can't assign with larger size
  //   int e[5] = {1, 2, 3, 4, 5, 6, 7};
}

} // namespace

int main() {
  test_arrays();
}
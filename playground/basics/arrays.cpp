#include <iostream>

namespace {

template <typename T>
// Array is passed as a pointer, not as an array type
// Note that [] is after variable name not after type
// There is no way to measure length once passed to function, so also pass length
void show_array(const T arr[], int l) {
// void show_array(const T* arr, int l) { Alternative definition
  std::cout << "\t(Size: " << l << ")\t{";
  for (int i = 0; i < l; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << '}' << std::endl;
}

void test_arrays() {
  std::cout << "TEST ARRAYS" << std::endl;

  int a[] {1, 2, 3, 4, 5};
  int a_size = sizeof(a) / sizeof(a[0]); // Size of array
  std::cout << "Array a is: ";
  show_array(a, a_size);
}

} // namespace

int main() {
  test_arrays();
}
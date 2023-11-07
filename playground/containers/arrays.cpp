#include<iostream>

namespace {

// Debug: Print an array
template <typename T, unsigned long N> // size type of std::array is unsigned long (or size_t)
void show_array(std::array<T, N> arr) {
  std::cout << "Size(" << N << ")\t{";
  for (const T& a : arr) {
    std::cout << a << ", ";
  }
  std::cout << '}' << std::endl;
}

void test_array() {
  std::cout << "TEST ARRAY" << std::endl;
  std::array<int, 5> a {1, 2, 3, 4, 5};
  std::cout << "Array a is: ";
  show_array(a);

  // std::array<int, 5> b {1, 2, 3, 4, 5, 6, 7, 8}; Cannot assign excess elements

  std::array<int, 5> c {1, 2, 3}; // Zero-padded if not enough elements
  std::cout << "Array c is: ";
  show_array(c);
}

void test_copy_and_move() {
  std::cout << "TEST COPY AND MOVE" << std::endl;
  std::array<int, 5> a {1, 2, 3, 4, 5};
  std::cout << "Array a is: ";
  show_array(a);

  std::array<int, 5> b {a}; // Test copy
  std::cout << "Array b is: ";
  show_array(b);

  // std::array<int, 3> c {a}; Cannot copy to smaller size
  // std::array<int, 7> c {a}; Cannot copy to larger size

  std::array<int, 5> d = std::move(b); // Move after copy
  std::cout << "Array d is: ";
  show_array(d);

  std::cout << "Array b is: "; // Access after move
  show_array(b); // Works (how?)
}

void test_access() {
  std::cout << "TEST ACCESS" << std::endl;
  std::array<int, 3> a;
  a[0] = 1;
  a[2] = 5; // No default value for a[1] if std::initializer list is not used
  a[3] = 2; // Can assign index SIZE (why?)
  std::cout << "Array a is: ";
  show_array(a);
  std::cout << "Index 3 is: " << a[3] << std::endl; // Can access index SIZE (why?), junk value

  int *p = &a[1]; // Pointer access works as normal
  std::cout << "Pointer value at index 1: " << *p << std::endl;
  std::cout << "Pointer value at index 2: " << *++p << std::endl;
}

void test_container_access() {
  std::cout << "TEST COUNTAINER ACCESS" << std::endl;
  std::array<int, 5> a {1, 2, 3, 4, 5};
  std::cout << "Array a is: ";
  show_array(a);

  std::cout << "Value at index 2: " << a.at(2) << std::endl;
  std::cout << "First value: " << a.front() << std::endl;
  std::cout << "Last value: " << a.back() << std::endl;

  std::cout << "Reverse iterator: ";
  for (auto i = a.crbegin(); i != a.crend(); ++i) {
    std::cout << *i << ", ";
  }
  std::cout << std::endl;

}

template <size_t N>
using IntArray = std::array<int, N>;

void test_alias() {
  std::cout << "TEST ALIAS" << std::endl;
  IntArray<5> a {1, 2, 3, 4, 5};
  std::cout << "Array a is: ";
  show_array(a);
}

} // namespace

int main() {
  test_array();
  test_copy_and_move();
  test_access();
  test_container_access();
  test_alias();
}
#include <iostream>

void test_nullptr() {
  std::cout << "TEST NULL POINTER" << std::endl;

  int *p = nullptr, *q = nullptr; // * binds to variable name, not type (common mistake in C++ texts)

  std::cout << "p is " << p << std::endl;
  std::cout << "q is " << q << std::endl;

  if (p == q) {
    std::cout << "There is only one nullptr. p == q." << std::endl;
  }

  int *r; // contains garbage value (always initialize pointers)
  std::cout << "r is " << r << std::endl;

  int *s = 0; // initializes to nullptr (same as std::nullptr_t)
  std::cout << "s is " << s << std::endl;

  if (s == p && s == q) {
    std::cout << "There is only one nullptr. s == p == q." << std::endl;
  }

  if (p == 0) {
    std::cout << "nullptr variable is the same as 0." << std::endl;
  }
  if (nullptr == 0) {
    std::cout << "nullptr itself is the same as 0." << std::endl;
  }
}

void test_array_pointer() {
  std::cout << "TEST ARRAY POINTER" << std::endl;

  int v[] {1, 2, 3, 4, 5};

  int *p = v; // an array variable is actually an address
  int *q = &v[0]; // directly assign 0 index
  int *r = &v[3]; // directly assign any index

  std::cout << "p is " << p << " with value " << *p << std::endl;
  std::cout << "q is " << p << " with value " << *q << std::endl;
  std::cout << "r is " << p << " with value " << *r << std::endl;

  r = q;
  std::cout << "r is now " << p << " with value " << *r << std::endl;

  // int *s = &v; Address of v is an int**, not int*

  /* .. but I cannot assign address of v as a pointer to a pointer (why?)
  int **s = &v;
  std::cout << "s is " << s << " with value " << *s << " which in turn has value " << **s << std::endl;
  */

  // Array pointers can be incremented (automatically advance by sizeof)
  for (int* i = v; i < &v[5]; ++i) { // can use &v[N] as a bound (how?)
    ;
  }
  std::cout << "Iterated over array with pointer" << std::endl;

}

int main() {
  test_nullptr();
  test_array_pointer();
}
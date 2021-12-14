#include <iostream>

void test_basic_enum() {
  std::cout << "TEST BASIC ENUMS" << std::endl;
  enum Color {RED, BLUE, GREEN};
  Color c1 = Color::RED;
  Color c2 = Color::BLUE;
  Color c3 = Color::RED;
  std::cout << "c1 is " << c1 << std::endl;
  std::cout << "c2 is " << c2 << std::endl;
  std::cout << "c3 is " << c3 << std::endl;
  if (c1 > c2) {
    std::cout << "Can compare enum ints. c1 is bigger." << std::endl;
  } else if (c2 > c1) {
    std::cout << "Can compare enum ints. c2 is bigger." << std::endl;
  }
  if (c1 == c3) {
    std::cout << "Two enum ints are equal if value is equal." << std::endl;
  }
}

void test_numbered_enum() {
  std::cout << "TEST NUMBERED ENUMS" << std::endl;
  enum Color {RED=3, BLUE=2, GREEN=7, ORANGE};
  Color c1 {RED}; // No need to qualify as Color::RED, not just in constructor.
  std::cout << "c1 is " << c1 << std::endl;
  if (c1 == 3) {
    std::cout << "Can compare enum value to int." << std::endl;
  }

  // Color c2 {2}; Cannot assign int to an enum.
  int c2 = BLUE;
  std::cout << "Can assign unqualified enum to an integer." << std::endl;

  Color c3 = static_cast<Color>(2); // Can assign int to an enum with cast.
  std::cout << "Can assign cast integer to an enum." << std::endl;

  Color c4 {ORANGE};
  if (c4 == 8) {
    std::cout << "enum values are assigned sequentially." << std::endl;
  }
}

void test_enum_range() {
  std::cout << "TEST ENUM RANGE" << std::endl;
  enum Color {RED, BLUE, GREEN=12};
  Color c1 = static_cast<Color>(100); // Can assign any value.
  std::cout << "c1 is " << c1 << std::endl;
  Color c2 = static_cast<Color>('A'); // Can assign other castable types too.
  std::cout << "c2 is " << c2 << std::endl;
}

void test_two_enums() {
  std::cout << "TEST TWO ENUMS" << std::endl;
  enum Color {RED, BLUE, GREEN};
  enum Difficulty {EASY, MEDIUM, HARD};
  Color c {RED};
  Difficulty d {EASY};
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;
  /* Two enums' int value cannot be compared.
  if (c == d) {
    std::cout << "Can compare ints from different enums" << std::endl;
  }
  */
}

void test_enum_class() {
  std::cout << "TEST ENUM CLASS" << std::endl;
  enum class Color {RED, BLUE, GREEN};
  // Color c1 {RED}; Must qualify with class name.
  Color c1 {Color::RED};
  // std::cout << "c1 is " << c1 << std::endl; Cannot print class enum.
}

void test_typed_enum_class() {
  std::cout << "TEST TYPED ENUM CLASS" << std::endl;
  enum class Color : uint32_t {RED, BLUE, GREEN};
  // Color c1 {RED}; Must qualify with class name.
  Color c1 {Color::RED};
  // std::cout << "c1 is " << c1 << std::endl; Cannot print class enum.
  Color c2 = static_cast<Color>(100); // Can assign any uint32_t.
  Color c3 = static_cast<Color>('A'); // Can assign any other castable type too.

  enum class Difficulty : char {EASY = 'A', MEDIUM = 'B', HARD = 'C'};
  Difficulty d1 {Difficulty::EASY};
  Difficulty d2 = static_cast<Difficulty>('D');
  // Difficulty d2 {'E'}; Need to cast even if its the same type.
  Difficulty d3 = static_cast<Difficulty>(5);
}

int main() {
  test_basic_enum();
  test_numbered_enum();
  test_enum_range();
  test_two_enums();
  test_enum_class();
  test_typed_enum_class();
  return 0;
}

#include <iostream>

struct Player {
  std::string name;
  double* scores;

  Player(const std::string& name) : name{name}, scores{new double[5]} { }
  ~Player() {
    delete[] scores;
    std::cout << name << " destroyed" << std::endl;
  }
};

int throw_an_exception() {
  throw std::invalid_argument("BRO WTF");
}

void test_catch() {
  std::cout << "TEST CATCH" << std::endl;
  try {
    throw_an_exception();
  } catch (const std::exception& e) {
    std::cout << "Caught an exeption: " << e.what() << std::endl;
  }
}

void test_specific_catch() {
  std::cout << "TEST SPECIFIC CATCH" << std::endl;
  try {
    throw_an_exception();
  } catch (const std::invalid_argument& e) {
    std::cout << "Caught an invalid argument exception: " << e.what() << std::endl;
  }
}

void test_other_catch() {
  std::cout << "TEST OTHER CATCH" << std::endl;
  try {
    throw_an_exception();
  } catch (const std::out_of_range& e) {
    std::cout << "Caught an out of range exception: " << e.what() << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Caught an other exception: " << e.what() << std::endl;
  }
}

void rethrow_an_exception() {
  try {
    throw_an_exception();
  } catch (const std::exception& e) {
    std::cout << "Rethrowing.." << std::endl;
    throw;
  }
}

void test_rethrow() {
  std::cout << "TEST RETHROW" << std::endl;
  try {
    rethrow_an_exception();
  } catch (const std::exception& e) {
    std::cout << "Caught a rethrown exception: " << e.what() << std::endl; // message preserved on rethrow
  }
}

void test_rethrow_nested() {
  std::cout << "TEST RETHROW NESTED" << std::endl;
  try {
    try {
      throw_an_exception();
    } catch (const std::exception& e) {
      std::cout << "Rethrowing.." << std::endl;
      throw;
    }
  } catch (const std::exception& e) {
    std::cout << "Caught a rethrown exception: " << e.what() << std::endl; // message preserved on rethrow
  }
}

void test_destructor() {
  std::cout << "TEST DESTRUCTOR" << std::endl;
  try {
    Player p("Sachin"); // will be destroyed when exception is thrown
    throw_an_exception();
  } catch(const std::exception e) {
    std::cout << "Caught an exeption: " << e.what() << std::endl; // doesn't preserve message (why?)
  }
}

int main() {
  test_catch();
  test_specific_catch();
  test_other_catch();
  test_rethrow();
  test_rethrow_nested();
  test_destructor();
}
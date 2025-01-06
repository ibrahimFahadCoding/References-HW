#include <iostream>

// Problem 1: passing an int by value
void intVal(int val) {
  // do you expect this to change the val that was passed in?
  val = 20;
  // No, the original value will not change because it's passed by value.
}

// Problem 2: passing an int by reference
void intRef(int &val) {
  // do you expect this to change the val that was passed in?
  val = 20;
  // Yes, the original value will change because it's passed by reference.
}

// Problem 3: passing an int by const reference
void intConstRef(const int& val) {
  // this line doesn't compile: why?
  // val = 20;
  // This doesn't compile because 'val' is a const reference and cannot be modified.
}

// Problem 4: passing two ints by value - what will this return
int addTwoVals(int val1, int val2) {
  val1 = 20;
  val2 = 30;
  return val1 + val2;
  // This will return 50. The local copies of val1 and val2 are changed, but the original values remain unchanged.
}

// Problem 5: passing two ints by reference
int addTwoValsRef(int& val1, int& val2) {
  val1 = 20;
  val2 = 30;
  return val1 + val2;
  // This will modify the original values of val1 and val2 to 20 and 30 respectively, and return their sum, which is 50.
}

// Problem 6: passing two ints by const reference
int addTwoValsConstRef(const int& val1, const int& val2) {
  // do you expect this to run?
  // val1 = 20;
  // val2 = 30;
  // This will not compile because val1 and val2 are const references and cannot be modified.
  return val1 + val2;
}

// Problem 7: returning local variable
/*
// Would this code run? Why or why not?
int& localReturn() {
  int val2 = 10;
  return val2;
  // This will not run correctly because it returns a reference to a local variable which will be destroyed when the function exits, leaving a dangling reference.
}
*/

/* 
------- PASSING STRINGS --------
*/
// Problem 11: passing a string by value
void stringVal(std::string str) {
  str = "!Olleh Dlrow";
  // The original string will not be changed because it's passed by value.
}

// Problem 12: passing a string by reference
void stringRef(std::string& str) {
  str = "!Olleh Dlrow";
  // The original string will be changed because it's passed by reference.
}

// Problem 13: passing a string by const reference
void stringConstRef(const std::string& str) {
  // str = "!Olleh Dlrow";
  // This doesn't compile because str is a const reference and cannot be modified.
}

int main() {
  int a = 10;
  int b = 15;
  int c = 10;
  int d = 15;
  const int e = 10;
  const int f = 15;

  std::cout << "Initial values: a=" << a << ", b=" << b << std::endl;
  intVal(a);
  std::cout << "After intVal(a): a=" << a << std::endl; // Expecting a to remain 10

  std::cout << "Initial values: a=" << a << ", b=" << b << std::endl;
  intRef(a);
  std::cout << "After intRef(a): a=" << a << std::endl; // Expecting a to be 20

  std::cout << "Initial values: e=" << e << std::endl;
  intConstRef(e);
  std::cout << "After intConstRef(e): e=" << e << std::endl; // Expecting e to remain 10

  int result1 = addTwoVals(a, b);
  std::cout << "After addTwoVals(a, b): a=" << a << ", b=" << b << ", result=" << result1 << std::endl; // Expecting a=20, b=15, result=50

  int result2 = addTwoValsRef(c, d);
  std::cout << "After addTwoValsRef(c, d): c=" << c << ", d=" << d << ", result=" << result2 << std::endl; // Expecting c=20, d=30, result=50

  int result3 = addTwoValsConstRef(e, f);
  std::cout << "After addTwoValsConstRef(e, f): e=" << e << ", f=" << f << ", result=" << result3 << std::endl; // Expecting e=10, f=15, result=25

  std::string str1 = "Hello World";
  std::string str2 = "Hello World";
  const std::string str3 = "Hello World";

  std::cout << "Initial value: str1=" << str1 << std::endl;
  stringVal(str1);
  std::cout << "After stringVal(str1): str1=" << str1 << std::endl; // Expecting str1 to remain "Hello World"

  std::cout << "Initial value: str2=" << str2 << std::endl;
  stringRef(str2);
  std::cout << "After stringRef(str2): str2=" << str2 << std::endl; // Expecting str2 to be "!Olleh Dlrow"

  std::cout << "Initial value: str3=" << str3 << std::endl;
  stringConstRef(str3);
  std::cout << "After stringConstRef(str3): str3=" << str3 << std::endl; // Expecting str3 to remain "Hello World"

  return 0;
}

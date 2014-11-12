#include "calculator.h"
using namespace std;

int main() {
  // some basic test cases
  Calculator calc;

  ((((calc + 3.12) + 5) - 2) * 3) / 5;
  cout << "Expect: The value is: 3.672" << endl;
  cout << "Output: " << calc << endl;

  Calculator otherCalc(calc);
  calc.clear();
  otherCalc / 2;
  cout << "Expect: The value is: 0" << endl;
  cout << "Output: " << calc << endl;
  cout << "Expect: The value is: 1.836" << endl;
  cout << "Output: " << otherCalc << endl;
}

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "check.h"

class Calculator {
private:
  static const int DEFSIZE = 10;
  double nValue;
  int size;
  double* memory;

  void init(int s);
public:
  static const int ADD = 0, SUB = 1, MUL = 2, DIV = 3;
  
  Calculator();
  Calculator(const double d);
  Calculator(const Calculator& c);
  ~Calculator();
  Calculator& addValue(const double d);
  Calculator& subtractValue(const double d);
  Calculator& multiplyValue(const double d);
  Calculator& divideBy(const double d);
  void printValue() const;
  double getValue() const;
  Calculator& clear();
  Calculator& memAdd(const int index);
  Calculator& memRecall(const int index);
  Calculator& memClear(const int index);
  Calculator& opMem(const int op, const int index);
  Calculator& enter(const double num);
  double operator[] (const int index) const;
  double& operator[] (const int index);

  Calculator& operator+ (const double d);
  Calculator& operator- (const double d);
  Calculator& operator* (const double d);
  Calculator& operator/ (const double d);
  Calculator& operator= (const Calculator& c);

  friend std::istream& operator>> (std::istream& in, Calculator& c);
  friend std::ostream& operator<< (std::ostream& out, const Calculator& c);
};

#endif

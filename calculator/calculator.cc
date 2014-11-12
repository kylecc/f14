#include "calculator.h"

Calculator::Calculator() {
  nValue = 0;
  memory = NULL;
  init(DEFSIZE);  
}

Calculator::Calculator(const double d) {
  nValue = d;
  memory = NULL;
  init(DEFSIZE);
}

Calculator::Calculator(const Calculator& c) {
  memory = NULL;
  *this = c;
}

Calculator::~Calculator() {
  delete []memory;
}

void Calculator::init(const int s) {
  size = s;
  memory = new double[size];
  check(memory != NULL, "Calculator::init(int) : Out of memory");
  for(int i = 0; i < size; ++i) {
    memory[i] = 0;
  }
}

Calculator& Calculator::addValue(const double d) {
  nValue += d;
  return *this;
}

Calculator& Calculator::subtractValue(const double d) {
  nValue -= d;
  return *this;
}

Calculator& Calculator::multiplyValue(const double d) {
  nValue *= d;
  return *this;
}

Calculator& Calculator::divideBy(const double d) {
  check(d != 0, "Calculator::divideBy(double) : Divide by zero");
  nValue /= d;
  return *this;
}

void Calculator::printValue() const {
  std::cout << "The value is: " << nValue << std::endl;
}

double Calculator::getValue() const {
  return nValue;
}

Calculator& Calculator::clear() {
  nValue = 0;
  return *this;
}

Calculator& Calculator::operator+ (const double d) {
  nValue += d;
  return *this;
}

Calculator& Calculator::operator- (const double d) {
  nValue -= d;
  return *this;
}

Calculator& Calculator::operator* (const double d) {
  nValue *= d;
  return *this;
}

Calculator& Calculator::operator/ (const double d) {
  check(d != 0, "Calculator::operator/ (double) : Divide by zero");
  nValue /= d;
  return *this;
}

Calculator& Calculator::operator= (const Calculator& c) {
  if(memory != NULL) {
    delete []memory;
  }
  nValue = c.nValue;
  size = c.size;
  memory = new double[size];
  for(int i = 0; i < size; ++i) {
    memory[i] = c.memory[i];
  }
  return *this;
}

Calculator& Calculator::memAdd(const int index) {
  check(index >= 0 && index < size, "Calculator::memAdd(int) : Invalid index");
  memory[index] += nValue;
  return *this;
}

Calculator& Calculator::memRecall(const int index) {
  check(index >= 0 && index < size, "Calculator::memRecall(int) : Invalid index");
  memory[index] -= nValue;
  return *this;
}

Calculator& Calculator::memClear(const int index) {
  check(index >= 0 && index < size, "Calculator::memClear(int) : Invalid index");
  memory[index] = 0;
  return *this;
}

Calculator& Calculator::opMem(const int op, const int index) {
  check(index >= 0 && index < size, "Calculator::opMem(int) : Invalid index");
  switch(op) {
  case ADD:
    nValue += memory[index]; break;
  case SUB:
    nValue -= memory[index]; break;
  case MUL:
    nValue *= memory[index]; break;
  case DIV:
    check(memory[index] != 0, "Calculator::opMem(int, int) : Divide by zero");
    nValue /= memory[index]; break;
  default:
    check(false, "Calculator::opMem(int, int) : Invalid operation");
  }
  
  return *this;
}

Calculator& Calculator::enter(double num) {
  nValue = num;
  return *this;
}

double Calculator::operator[] (const int index) const {
  check(index >= 0 && index < size, "Calculator::operator[] const : Invalid index");
  return memory[index];
}

double& Calculator::operator[] (const int index) {
  check(index >= 0 && index < size, "Calculator::operator[] : Invalid index");
  return memory[index];
}

std::istream& operator>> (std::istream& in, Calculator& c) {
  double temp;
  in >> temp;
  c.nValue = temp;
  return in;
}

std::ostream& operator<< (std::ostream& out, const Calculator& c) {
  out << "The value is: " << c.nValue << "\n";
  return out;
}

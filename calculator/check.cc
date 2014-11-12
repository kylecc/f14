#include "check.h"

void check(bool good, const char* msg) {
  if(!good) {
    std::cerr << msg << std::endl;
    exit(-1);
  }
}

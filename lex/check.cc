#include "check.h"

void check(bool bad, const string mess) {
  if(bad) {
    cerr << mess << endl;
    exit(-1);
  }
}

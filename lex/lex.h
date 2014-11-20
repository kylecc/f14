#ifndef LEX_H
#define LEX_H

#include "hashtable.h"
#include "check.h"
#include <fstream>

class Lex {
private:
  String line, token;
  int pos;
  HashTable keywords, symbols;
  
  int alpha();
  int number();
  int symbol();
  
public:
  Lex();
  Lex(const Lex& l);
  Lex& setString(String str);
  int next();
  bool atEnd();
  Lex& reset(int index = 0);
  String word();
  int position();
  int peek();
  Lex& loadKeyWords(ifstream& fin);
  Lex& loadSymbols(ifstream& fin);

  static const int JUNK = 24, NUMBER = 0, IDENTIFIER = 1, PLUS = 2,
    MINUS = 3, TIMES = 4, DIVIDE = 5, CLEAR = 6, GETVALUE = 7,
    ENTER = 8, LBRACK = 9, RBRACK = 10, LPAR = 11, RPAR = 12,
    PUSH = 13, POP = 14, JUMP = 15, JUMPL = 16, JUMPG = 17,
    JUMPLE = 18, JUMPGE = 19, JUMPE = 20, JUMPNE = 21,
    DOLLAR = 22, END = 23;
};

#endif

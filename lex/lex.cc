#include "lex.h"

Lex::Lex() {
  pos = 0;
}

Lex::Lex(const Lex& l) {
  keywords = l.keywords;
  symbols = l.symbols;
  line = l.line;
  token = l.token;
  pos = l.pos;
}

int Lex::alpha() {
  while((line[pos] >= 'A' && line[pos] <= 'Z') ||
	(line[pos] >= 'a' && line[pos] <= 'z')) {
    token + line[pos++];
  }
  if(keywords.inTable(token)) {
    return keywords[token];
  } else {
    return IDENTIFIER;
  }
}

int Lex::number() {
  bool dot = false;
  while((line[pos] >= '0' && line[pos] <= '9') ||
	(line[pos] == '.' && !dot)) {
    if(line[pos] == '.' && !dot) {
      dot = true;
    }
    token + line[pos++];
  }
  return NUMBER;
}

int Lex::symbol() {
  token + line[pos++];
  if(symbols.inTable(token)) {
    if(symbols[token] == DOLLAR) {
      --pos;
    }
    return symbols[token];
  } else {
    return JUNK;
  }
}

Lex& Lex::setString(String str) {
  line = str + "$";
  pos = 0;

  return *this;
}

int Lex::next() {
  token = "";
  
  while(line[pos] == ' ' || line[pos] == '\n' || line[pos] == '\t') {
    ++pos;
  }
  if((line[pos] >= 'A' && line[pos] <= 'Z') ||
     (line[pos] >= 'a' && line[pos] <= 'z')) {
    return alpha();
  } else if(line[pos] >= '0' && line[pos] <= '9') {
    return number();
  } else {
    return symbol();
  }
}

bool Lex::atEnd() {
  return line[pos] == '$';
}

Lex& Lex::reset(int index) {
  check(index < 0 || index >= line.length(), "Lex::reset(int) : Invalid index");
  pos = index;

  return *this;
}

String Lex::word() {
  return token;
}

int Lex::position() {
  return pos;
}

int Lex::peek() {
  int ret, temp;
  temp = pos;
  ret = next();
  reset(temp);
  return ret;
}

Lex& Lex::loadKeyWords(ifstream& fin) {
  String key, val;
  fin >> key;
  while(fin.good()) {
    fin >> val;
    keywords.add(key, val.asInt());
    fin >> key;
  }

  return *this;
}

Lex& Lex::loadSymbols(ifstream& fin) {
  String key, val;
  fin >> key;
  while(fin.good()) {
    fin >> val;
    symbols.add(key, val.asInt());
    fin >> key;
  }

  return *this;
}

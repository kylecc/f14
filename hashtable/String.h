#ifndef STRING_H
#define STRING_H

#include <cstring>
#include "check.h"

class String {
private:
  char *wd, * delimiters;
  int count, size;

  void init(const char *c, const char stoppers[] = " \t\n");
  void grow();
  bool isDelimiter(istream& in, char& c);
public:
  static const int DEFAULT_SIZE = 10;
  String();
  String(const String& b);
  String(int x);
  String(char c);
  String(const char *c, const char * stopper =" \t\n");
  ~String();
  bool operator==(String&b)const;
  bool operator!=(String &b)const;
  String & operator+(const String &b);

  bool operator >(const String& b);
  bool operator >(const char* c);
  bool operator <(const String& b);
  bool operator <(const char* c);
  bool operator >=(const String& b);
  bool operator >=(const char* c);
  bool operator <=(const String& b);
  bool operator <=(const char* c);
  bool operator ==(const char* c);
  bool operator !=(const char* c);

  String& operator =(const String& b);
  String& operator =(const char* c);
  char operator [](const int index) const;
  char& operator [](const int index);

  double asDouble() const;
  int asInt() const;
  char* getStr() const;
  String& add(char c);
  int length();
  void setDelimiters(const char* stoppers);
  
  friend ostream & operator<<(ostream &out,const String &b);
  friend istream& operator >>(istream& in, String& b);
};

#endif

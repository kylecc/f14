#include "String.h"
/*
int main()
{
    String phrase;
    String phrase2("Hello World",", \t");
    String phrase3(phrase2);
    String phrase4('x');
    
    String number (100); //store as characters
    String number1("500.25");
    String number2("750");

    double num = number1.asDouble();
    //converts the string 500.25 to a double
    //asDouble throws an error if
    //not a double or integer
    cout << "Expect 500.25: " << num << endl;

    int integer  = number2.asInt();
    //converts the string 750 to an integer throws an error if not an integer
    //if string is 750.0 throw an error
    cout << "Expect 750: " << integer << endl;

    phrase4 + phrase2 + number;
    //concatenates all three Strings into phrase4
    cout << "Expect: 1: " << (phrase4 == "xHello World100") << endl;

    cout << "Expect 100: " << number << endl;

    cout<<"Expect: ' Hello World Hello World xHello World100 100'\n        ";
    cout<<"'"<<phrase<<" "<<phrase2<<" "<<phrase3<<" "<<phrase4<<" "<<number<<"'\n";

    phrase2 =phrase4;
    phrase4="Lehigh";
    phrase3="won";
    cout<<"Expect: 'xHello World100 Lehigh won'\n        ";
    cout<<"'"<<phrase2<<" " <<phrase4<<" " <<phrase3<<"'\n";

    phrase4 = '!';
    phrase4[0]='S';
    cout<<"Expect: 'S'\n        '"<<phrase4 << "'\n";

    char * temp;
    temp=phrase2.getStr();
    //returns the characters in str
    temp[0]='!';
    cout<<"Expect: 'xHello World100 !Hello World100' \n        '"<<phrase2<<" "<<temp<<"'\n";

    if(temp != NULL) delete [] temp;

    phrase.add('!').add('!').add('!').add('!').add('!').add('!').add('!');
    //adds a character to phrase and size of phrase should not matter allow as many characters as the user gives you, do not go out of bounds of array
    cout<<"Expect: '!!!!!!!' has 7 letters'\n        ";
    cout <<"'"<<phrase<<"' has "<<phrase.length()<<" letters\n";


    cout<<"Expect 100: "<<String("100").asInt()<<endl;

    cout<<"Expect 101.23: "<<String ("101.23").asDouble()<<endl;

    cout<<"Enter a line of text: ";

    phrase.setDelimiters(",\n");
    //method that sets delimiter for phrase to a comma and end of line character
    cin>>phrase;

    cout<<"You entered: '"<<phrase<<"'\n";
    //test this by entering "hello world" should print hello world  and then enter "hello,world" and only hello should print
    cout<<"Expect crash (non double): \n";

    cout<<phrase.asDouble()<<endl;
    //test that asInt will also throw an error if a non-integer value is trying to be converted note to do an asInt on 500.25 should through an error
}
*/

String::~String()
{
    delete [] wd;
    delete [] delimiters;
}

String::String(){
    const char *c = '\0';
    init(c);
}

String::String(const String& b) {
  (*this) = b;
}

String::String(int x) {
  int sz, temp;
  bool negative = false;
  char* w;
  if(x < 0) {
    negative = true;
    x *= -1;
  }
  temp = x;
  sz = 0;
  if(temp == 0) {
    size = 1;
  }
  while(temp > 0) {
    temp /= 10;
    ++sz;
  }
  if(negative) {
    ++sz;
  }
  w = new char[sz + 1];
  check(w == NULL, "String::String(int) : Heap overflow");
  if(negative) {
    wd[0] = '-';
  }
  w[sz] = '\0';
  while(sz > negative) {
    sz--;
    w[sz] = x % 10 + '0';
    x /= 10;
  }
  init(w);
}

String& String::operator= (const String& b) {
  char* c = new char[b.size];
  check(c == NULL, "String::operator= : Heap overflow");
  strcpy(c, b.wd);
  char* stoppers = new char[(int)strlen(b.delimiters)];
  check(stoppers == NULL, "String::operator= : Heap overflow");
  strcpy(stoppers, b.delimiters);
  init(c, stoppers);
  return *this;
}

String& String::operator =(const char* c) {
  size = strlen(c + 1);
  if(wd != NULL) delete []wd;
  wd = new char[size];
  check(wd == NULL, "String::operator= : Heap overflow");
  strcpy(wd, c);
  if(delimiters != NULL) delete []delimiters;
  delimiters = new char[3];
  check(wd == NULL, "String::operator= : Heap overflow");
  strcpy(delimiters, " \t\n");
  count = strlen(wd);
  return *this;
}

String::String(const char *c, const char *stoppers){
  init(c,stoppers);
}
String::String(char c){
  char temp[]={c,'\0'};
  init(temp);
}
void String::init(const char *c, const char *stoppers){
    char *temp = new char('\0');
  if(c == NULL)
    c = temp;
  check(stoppers == NULL,"(String(char*,char*))Null pointer");
  if(strlen(c)== 0)
    size = DEFAULT_SIZE;
  else
    size =strlen(c) + 1 + DEFAULT_SIZE;
  wd = new char[size];
  check(wd==NULL,"String(char *,char *)) heap overflow");
  delimiters = new char(strlen(stoppers) + 1);
  check(delimiters==NULL,"String(char *, char *))heapp overflow");
  strcpy(wd,c);
  strcpy(delimiters,stoppers);
  count = strlen(wd);
}

bool String::operator==(String&b)const{
  return strcmp(wd,b.wd)==0;
}
bool String::operator!=(String &b)const{
  return !(*this==b);
}

char String::operator [](const int index) const {
  check(index < 0 || index >= count, "String::operator [] const : Index out of bounds");
  return wd[index];
}

char& String::operator [](const int index) {
  check(index < 0 || index >= count, "String::operator [] const : Index out of bounds");
  return wd[index];
}

  ostream & operator<<(ostream &out,const String &b){
    out<<b.wd;
    return out;
  }

istream& operator>> (istream& in, String& b) {
  char temp;
  b.count = 0;
  while(!b.isDelimiter(in, temp)) {
    b.add(temp);
  }
  return in;
}

bool String::isDelimiter(istream& in, char& c) {
  in.get(c);
  if(!in.good()) {
    c = '\n';
  }
  for(int i = 0; i < (int)strlen(delimiters); ++i) {
    if(delimiters[i] == c) {
      return true;
    }
  }
  return false;
}

String & String::operator +(const String &w){
  char *temp;
  int tempSize = size +w.size;
  temp = new char[tempSize+1];
  check(temp==NULL,"String::heap overflow");
  strcpy(temp,wd);
  strcat(temp,w.wd);
  if(wd != NULL) delete [] wd;
  wd=temp;
  count = w.count + count;
  return *this;
}

bool String::operator >(const String& b) {
  return strcmp(wd, b.wd) > 0;
}

bool String::operator >(const char* c) {
  return strcmp(wd, c) > 0;
}

bool String::operator <(const String& b) {
  return strcmp(wd, b.wd) < 0;
}

bool String::operator <(const char* c) {
  return strcmp(wd, c) < 0;
}

bool String::operator >=(const String& b) {
  return strcmp(wd, b.wd) >= 0;
}

bool String::operator >=(const char* c) {
  return strcmp(wd, c) >= 0;
}

bool String::operator <=(const String& b) {
  return strcmp(wd, b.wd) <= 0;
}

bool String::operator <=(const char* c) {
  return strcmp(wd, c) <= 0;
}

bool String::operator ==(const char* c) {
  return strcmp(wd, c) == 0;
}

bool String::operator !=(const char* c) {
  return !(*this == c);
}

double String::asDouble() const {
  for(int i = 0; i < count; ++i) {
    check((wd[i] < '0' || wd[i] > '9') && wd[i] != '.', "String::asDouble() : Non-double string");
  }
  return atof(wd);
}

int String::asInt() const {
  for(int i = 0; i < count; ++i) {
    check(wd[i] < '0' || wd[i] > '9', "String::asInt() : Non-integer string");
  }
  return atoi(wd);
}

char* String::getStr() const {
  char* temp = new char[strlen(wd) + 1];
  check(temp == NULL, "String::getStr() : Heap overflow");
  strcpy(temp, wd);
  return temp;
}

int String::length() {
  return count;
}

void String::setDelimiters(const char* stoppers) {
  check(stoppers == NULL, "String::setDelimiters() : Null pointer");
  if(delimiters != NULL) delete []delimiters;
  delimiters = new char[strlen(stoppers) + 1];
  check(delimiters == NULL, "String::setDelimiters() : Heap overflow");
  strcpy(delimiters, stoppers);
}

String& String::add(char c) {
  if(count >= size - 1) {
    grow();
  }
  wd[count++] = c;
  wd[count] = '\0';
  return *this;
}

void String::grow() {
  size += DEFAULT_SIZE;
  char* temp = new char[size + 1];
  check(temp == NULL, "String::grow() : Heap overflow");
  strcpy(temp, wd);
  if(wd != NULL) delete []wd;
  wd = temp;
}

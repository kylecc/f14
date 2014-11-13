#include "hashtable.h"
#include <fstream>

void readFile(const char* filename, HashTable& h) {
  check(filename == NULL, "p6 readFile() : Invalid filename");
  ifstream fin;
  String str, num;
  fin.open(filename);
  check(!fin.good(), "p6 readFile() : Failed to open input file");
  fin >> str;
  while(fin.good()) {
    fin >> num;
    h.add(str, num.asInt());
    fin >> str;
  }
  fin.close();
}

int main()
{
    HashTable table(47);

    readFile("p6.dat", table);

    table+= "READ";
    table["READ"]=26;
    cout << table;

    table.remove("IDENTIFIER");
    cout << endl << "After Delete " << endl;
    cout << table;
    cout << "Expect 1: " << table.inTable("JUMPLE") << endl;
    cout << "Expect 2: " << table["PLUS"] << endl;

        }
//Expected Output:

/*Indice = 0 NULL
Indice = 1 NULL
Indice = 2 (READ, 26)--->NULL
Indice = 3 NULL
Indice = 4 (POP, 14)--->NULL
Indice = 5 NULL
Indice = 6 (ENTER, 8)--->NULL
Indice = 7 NULL
Indice = 8 (LBRACK, 9)--->NULL
Indice = 9 (JUMPE, 20)--->NULL
Indice = 10 (TIMES, 4)--->NULL
Indice = 11 (JUMPG, 17)--->NULL
Indice = 12 NULL
Indice = 13 NULL
Indice = 14 (RBRACK, 10)--->(DIVIDE, 5)--->NULL
Indice = 15 NULL
Indice = 16 (JUMPL, 16)--->NULL
Indice = 17 NULL
Indice = 18 NULL
Indice = 19 NULL
Indice = 20 (MINUS, 3)--->NULL
Indice = 21 (LPAR, 11)--->NULL
Indice = 22 NULL
Indice = 23 (DOLLAR, 22)--->NULL
Indice = 24 NULL
Indice = 25 NULL
Indice = 26 NULL
Indice = 27 (END, 23)--->(RPAR, 12)--->NULL
Indice = 28 NULL
Indice = 29 NULL
Indice = 30 (CLEAR, 6)--->(JUNK, 24)--->NULL
Indice = 31 NULL
Indice = 32 NULL
Indice = 33 (JUMPGE, 19)--->NULL
Indice = 34 (JUMP, 15)--->(IDENTIFIER, 1)--->(NUMBER, 0)--->NULL
Indice = 35 NULL
Indice = 36 NULL
Indice = 37 NULL
Indice = 38 (JUMPLE, 18)--->(PUSH, 13)--->NULL
Indice = 39 NULL
Indice = 40 (JUMPNE, 21)--->NULL
Indice = 41 (GETVALUE, 7)--->NULL
Indice = 42 (PLUS, 2)--->NULL
Indice = 43 NULL
Indice = 44 NULL
Indice = 45 NULL
Indice = 46 NULL

After Delete
Indice = 0 NULL
Indice = 1 NULL
Indice = 2 (READ, 26)--->NULL
Indice = 3 NULL
Indice = 4 (POP, 14)--->NULL
Indice = 5 NULL
Indice = 6 (ENTER, 8)--->NULL
Indice = 7 NULL
Indice = 8 (LBRACK, 9)--->NULL
Indice = 9 (JUMPE, 20)--->NULL
Indice = 10 (TIMES, 4)--->NULL
Indice = 11 (JUMPG, 17)--->NULL
Indice = 12 NULL
Indice = 13 NULL
Indice = 14 (RBRACK, 10)--->(DIVIDE, 5)--->NULL
Indice = 15 NULL
Indice = 16 (JUMPL, 16)--->NULL
Indice = 17 NULL
Indice = 18 NULL
Indice = 19 NULL
Indice = 20 (MINUS, 3)--->NULL
Indice = 21 (LPAR, 11)--->NULL
Indice = 22 NULL
Indice = 23 (DOLLAR, 22)--->NULL
Indice = 24 NULL
Indice = 25 NULL
Indice = 26 NULL
Indice = 27 (END, 23)--->(RPAR, 12)--->NULL
Indice = 28 NULL
Indice = 29 NULL
Indice = 30 (CLEAR, 6)--->(JUNK, 24)--->NULL
Indice = 31 NULL
Indice = 32 NULL
Indice = 33 (JUMPGE, 19)--->NULL
Indice = 34 (JUMP, 15)--->(NUMBER, 0)--->NULL
Indice = 35 NULL
Indice = 36 NULL
Indice = 37 NULL
Indice = 38 (JUMPLE, 18)--->(PUSH, 13)--->NULL
Indice = 39 NULL
Indice = 40 (JUMPNE, 21)--->NULL
Indice = 41 (GETVALUE, 7)--->NULL
Indice = 42 (PLUS, 2)--->NULL
Indice = 43 NULL
Indice = 44 NULL
Indice = 45 NULL
Indice = 46 NULL
Expect 1: 1
Expect 2: 2
*/

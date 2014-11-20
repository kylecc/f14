#include "lex.h"
#include "String.h"
#include "hashtable.h"
#include  <fstream>
using namespace std;

void testLexReset();

int main(){
        ifstream inkeywords;
        ifstream insymbols;
        ifstream program;
        Lex lex;
        inkeywords.open("keywords");
        lex.loadKeyWords(inkeywords);
        inkeywords.close();
        insymbols.open("symbols");
        lex.loadSymbols(insymbols);
        program.open("program");
        int tok;
        String line;
        line.setDelimiters("\n");
        program >> line;
        while(!program.eof()){
            cout<< line <<endl;
            lex.setString(line);
            tok=lex.next();
            while(tok!=lex.DOLLAR){
                cout<<"->";
                cout<<"['"<<lex.word()<<"', ";
                if(tok==lex.JUNK)
                    cout<< tok << ", JUNK";
                else if(tok==lex.NUMBER)
                    cout<<lex.word().asDouble() << ", NUMBER";
                else if(tok == lex.IDENTIFIER)
                    cout << tok << ", IDENTIFIER";
                else
                    cout << tok;
                cout<<"]";
                tok=lex.next();
            }
            cout<<"\n\n";
            program >> line;
        }
  int pos;
  lex.setString("ski JUMP contest");
  tok = lex.peek();
  cout<<"Expect 'ski' 1: '"<<lex.word()<<"' "<<tok<<"\n";
  tok=lex.next();
  cout<<"Expect 'ski' 1: '"<<lex.word()<<"' "<<tok<<"\n";
  lex.next();
  lex.next();
  lex.reset();
  tok=lex.next();
  cout<<"Again, expect 'ski' 1: '"<<lex.word()<<"' "<<tok<<"\n";
  pos=lex.position();
  lex.next();
  lex.next();
  cout<<"Should have 'contest': '"<<lex.word()<<"'"<<tok<<"\n";
  lex.reset(pos);
  tok=lex.next();
  cout<<"Should have 'JUMP' 15: '"<<lex.word()<<"' "<<tok<<endl;
}

/*
  PUSH POP
  ->['PUSH', 13]->['POP', 14]
q
  JUMPLE
  ->['JUMPLE', 18]

  enter
  ->['enter', 1, IDENTIFIER]

  25.6  x
  ->['25.6', 25.6, NUMBER]->['x', 1, IDENTIFIER]

  :
  ->[':', 24, JUNK]

  !
  ->['!', 24, JUNK]

  + - =
  ->['+', 2]->['-', 3]->['=', 24, JUNK]

  x123.5
  ->['x', 1, IDENTIFIER]->['123.5', 123.5, NUMBER]

  JUMP
  ->['JUMP', 15]
*/

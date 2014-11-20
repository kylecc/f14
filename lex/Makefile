#Kyle Coppola
#CSE 109 Fall 2014
#Makefile for p7
#SOLUTION

p7: p7.o lex.o hashtable.o hash.o linklist.o String.o check.o
	g++ -Wall -Werror -o p7 p7.o lex.o hashtable.o hash.o linklist.o String.o check.o

p7.o: p7.cc lex.h hashtable.h hash.h linklist.h String.h check.h
	g++ -c -Wall -Werror p7.cc

lex.o: lex.cc lex.h hashtable.h hash.h linklist.h String.h check.h
	g++ -c -Wall -Werror lex.cc

hashtable.o: hashtable.cc hashtable.h hash.h linklist.h String.h check.h
	g++ -c -Wall -Werror hashtable.cc

hash.o: hash.cc hash.h String.h check.h
	g++ -c -Wall -Werror hash.cc

linklist.o: linklist.cc linklist.h String.h check.h
	g++ -c -Wall -Werror linklist.cc

String.o: String.cc String.h check.h
	g++ -c -Wall -Werror String.cc

check.o: check.cc check.h
	g++ -c -Wall -Werror check.cc

clean:
	rm -rf *~ *.o \#* p7

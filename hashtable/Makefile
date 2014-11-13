#Kyle Coppola
#CSE 109 Fall 2014
#Makefile for p6
#SOLUTION

p6: p6.o hashtable.o hash.o linklist.o String.o check.o
	g++ -Wall -Werror -o p6 p6.o hashtable.o hash.o linklist.o String.o check.o

p6.o: p6.cc hashtable.h hash.h linklist.h String.h check.h
	g++ -c -Wall -Werror p6.cc

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
	rm -rf *~ *.o p6 String

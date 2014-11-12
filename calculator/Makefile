# Makefile for Calculator class

calculator: main.o calculator.o check.o
	g++ -Wall -Werror -o calculator main.o calculator.o check.o

main.o: main.cc calculator.h check.h
	g++ -c -Wall -Werror main.cc

calculator.o: calculator.cc calculator.h check.h
	g++ -c -Wall -Werror calculator.cc

check.o: check.cc check.h
	g++ -c -Wall -Werror check.cc

clean:
	rm -rf *.o *~ ./#* calculator

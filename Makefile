compile:
	g++ -std=c++17 -Wall -Wpedantic syntax.cpp lex.cpp parse.cpp main.cpp -o main
	./main

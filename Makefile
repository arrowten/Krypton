compile:
	g++ -std=c++17 -Wall -Wpedantic syntax.cpp lex.cpp main.cpp -o main
	./main

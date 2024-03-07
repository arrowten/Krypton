#include <iostream>
#include <string>
#include "lex.h"

int main() {
    std::string line;

    //Takes a string input
    while(true) {
        std::cout << "->: ";
        std::getline(std::cin, line);
        //Lexer object to tokenise the string
        Lexer* lex = new Lexer(line);
	Syntax_Token* token;

	while(true) {
		token = lex->next_token();

		if(token->_kind == Token_Kind::end_of_file_token) break;

		std::cout << token_kind_to_string(token) << ": \'" << token->_text << "\'\n";
	}

        //Return if empty
        if(line.empty()) {
            std::cout << "Invalid expression!\n";
            return -1;
        }
    }

    return 0;
}

#include "parse.h"
#include <iostream>

Parser::Parser(std::string text) {
    Lexer* lex = new Lexer(text);
    Syntax_Token* token;

    do {
        token = lex->next_token();

        //To store the tokens
        if(token->_kind != Token_Kind::whitespace_token && 
        token->_kind != Token_Kind::bad_token) {
            token_list.push_back(token);
        }

        if(token->_kind == Token_Kind::end_of_file_token) break;

        std::cout << token_kind_to_string(token) << ": \'" << token->_text << "\'\n";
    } while(token->_kind != Token_Kind::end_of_file_token);
}

Syntax_Token* Parser::peek(int offset) {
    int index = _position + offset;
    
    if(index >= token_list.size())
        return new Syntax_Token(Token_Kind::bad_token, _position, "");

    return token_list[index];
}
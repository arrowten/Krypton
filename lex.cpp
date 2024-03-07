#include "lex.h"

Lexer::Lexer(std::string text): _text {text} {}

char Lexer::current() {
    if(_position >= _text.length()) return '\0';

    return _text[_position];
}

void Lexer::next() {
    _position++;
}

Syntax_Token* Lexer::next_token() {
    //End of file
    if(_position >= _text.length()) 
        return new Syntax_Token(Token_Kind::end_of_file_token, _position, "\0");
    
    //Numbers
    if(std::isdigit(current())) {
        int start = _position;

        while(std::isdigit(current())) next();

        int length = _position - start;
        std::string num = _text.substr(start, length);

        return new Syntax_Token(Token_Kind::number_token, start, num);
    }

    //Whitespace
    if(std::isspace(current())) {
        int start = _position;

        while(std::isspace(current())) next();

        int length = _position - start;
        std::string space = _text.substr(start, length);

        return new Syntax_Token(Token_Kind::whitespace_token, start, space);
    }

    //Arithmetic tokens
    switch(current()) {
        case '+': 
            return new Syntax_Token(Token_Kind::plus_token, _position++, "+");
        case '-': 
            return new Syntax_Token(Token_Kind::minus_token, _position++, "-");
        case '*': 
            return new Syntax_Token(Token_Kind::star_token, _position++, "*");
        case '/': 
            return new Syntax_Token(Token_Kind::slash_token, _position++, "/");
        case '%': 
            return new Syntax_Token(Token_Kind::percent_token, _position++, "%");
        case '(': 
            return new Syntax_Token(Token_Kind::open_parenthesis_token, _position++, "(");
        case ')': 
            return new Syntax_Token(Token_Kind::close_parenthesis_token, _position++, ")");
    }

    return new Syntax_Token(Token_Kind::bad_token, _position++, _text.substr(_position - 1, 1));
}
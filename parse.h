#pragma once

#ifndef PARSE_H
#define PARSE_H

#include "lex.h"
#include <vector>

class Parser {
    public:
    int _position;
    //A vector to collect the tokens
    std::vector<Syntax_Token*> token_list;  

    Parser(std::string text);

    private:
    //Function to see the tokens
    Syntax_Token* peek(int offset);
    //Variable for pointing to the first token
    Syntax_Token* current = peek(0);
};

#endif

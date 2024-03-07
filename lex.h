#pragma once

#ifndef LEX_H
#define LEX_H

#include "syntax.h"

//The lexer class
class Lexer {
    public:
    Lexer(std::string text);

    //The function which takes tokens and scans them
    Syntax_Token* next_token();

    private:
    std::string _text;
    int _position;
    
    //Returns the current token
    char current();
    //Increments the position to point to next token
    void next();
};

#endif

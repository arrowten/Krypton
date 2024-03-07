#pragma once

#ifndef SYNTAX_TOKEN_H
#define SYNTAX_TOKEN_H

#include <string>

//The different kinds of tokens
enum class Token_Kind {
    number_token,
    whitespace_token,
    plus_token,
    minus_token,
    star_token,
    slash_token,
    percent_token,
    open_parenthesis_token,
    close_parenthesis_token,
    bad_token,
    end_of_file_token
};

//The syntax token class
class Syntax_Token {
    public:
    Token_Kind _kind;
    int _position;
    std::string _text;

    Syntax_Token(Token_Kind kind, int position, std::string text);
};

//Function to return the string for the kind of tokens
std::string token_kind_to_string(Syntax_Token* token);

#endif

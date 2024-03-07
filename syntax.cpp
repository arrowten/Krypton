#include "syntax.h"

Syntax_Token::Syntax_Token(Token_Kind kind, int position, std::string text):
_kind {kind}, _position {position}, _text {text} {}

std::string token_kind_to_string(Syntax_Token* token) {
    switch(token->_kind) {
        case Token_Kind::number_token:
            return "Number token";
        case Token_Kind::whitespace_token:
            return "Whitespace token";
        case Token_Kind::plus_token:
            return "Plus token";
        case Token_Kind::minus_token:
            return "Minus token";
        case Token_Kind::star_token:
            return "Star token";
        case Token_Kind::slash_token:
            return "Slash token";
        case Token_Kind::percent_token:
            return "Percent token";
        case Token_Kind::open_parenthesis_token:
            return "Open parenthesis token";
        case Token_Kind::close_parenthesis_token:
            return "Close parenthesis token";
        case Token_Kind::bad_token:
            return "Bad token";
        case Token_Kind::end_of_file_token:
            return "End of file token";
    }

    return "";
}
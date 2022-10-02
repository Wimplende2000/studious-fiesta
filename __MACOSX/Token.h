//
// Created by yep12 on 6/24/2022.
//

#ifndef UNTITLED1_TOKEN_H
#define UNTITLED1_TOKEN_H
#include <string>
#include <sstream>
using namespace std;


enum TokenType {
    COMMA,PERIOD,Q_MARK,LEFT_PAREN,RIGHT_PAREN,COLON,COLON_DASH,MULTIPLY,ADD,UNDEFINED,ID,SCHEMES,QUERIES,RULES,FACTS,STRING,END,COMMENT
};

class Token {
private:
    TokenType type;
    string contents;
public:
    unsigned int line;
    Token(TokenType type1, string contents1, unsigned int line1);
    string toString() const;
    string tokenDecipher(TokenType type) const;
};


Token::Token(TokenType type1, string contents1, unsigned int line1) {
    type= type1;
    contents = contents1;
    line = line1;
}

string Token::toString() const {
    stringstream out;
    out << "(" << tokenDecipher(type) << "," << "\"" << contents << "\"" << "," << line << ")";
    return out.str();
}

string Token::tokenDecipher(TokenType type) const {
    switch (type) {

        case COMMA:
            return "COMMA";

        case PERIOD:
            return "PERIOD";

        case Q_MARK:
            return "Q_MARK";

        case LEFT_PAREN:
            return "LEFT_PAREN";

        case RIGHT_PAREN:
            return "RIGHT_PAREN";

        case COLON:
            return "COLON";

        case COLON_DASH:
            return "COLON_DASH";

        case MULTIPLY:
            return "MULTIPLY";

        case ADD:
            return "ADD";

        case ID:
            return "ID";
        case SCHEMES:
            return "SCHEMES";

        case QUERIES:
            return "QUERIES";

        case FACTS:
            return "FACTS";
        case RULES:
            return "RULES";
        case STRING:
            return "STRING";
        case END:
            return "EOF";
        case COMMENT:
            return "COMMENT";
        case UNDEFINED:
            return "UNDEFINED";
        default:
            return "ADD TO SWITCH";
    }
}

#endif //UNTITLED1_TOKEN_H

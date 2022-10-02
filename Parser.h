//
// Created by yep12 on 10/1/2022.
//

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H
#include <vector>
#include "Token.h"
#include <iostream>
using namespace std;

class Parser {
private:
    vector<Token> tokens;
public:
//The order must be: Schemes, then Facts, then Rules, then Queries
    void startParse(){



    }


    TokenType tokenType() const {
        return tokens.at(0).type;
    }
    void advanceToken() {
        delete tokens.at(begin());
        tokens.erase(tokens.begin());
    }
    void throwError() {
        cout << "error" << endl;
    }





//MATCHING SYMBOL WITH WAS IS CUYRRENTLY IN THE STACK
    void match(TokenType t) {
        cout << "match: " << t << endl;
        if (tokenType() == t)
            advanceToken();
        else
            throwError();
    }



//ID LIST
    void idList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            match(ID);
            idList();
        } else {
            // lambda
        }
    }




    void scheme() {
        if (tokenType() == ID) {
            match(ID);
            match(LEFT_PAREN);
            match(ID);
            idList();
            match(RIGHT_PAREN);
        } else {
            throwError();
        }
    }



    void getParserVecSize(){cout << tokens.size();}
    Parser(const vector<Token>& tokens) : tokens(tokens) { }

};


#endif //UNTITLED_PARSER_H

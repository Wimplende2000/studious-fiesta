//
// Created by yep12 on 6/26/2022.
//

#ifndef UNTITLED1_RIGHT_PAREN_AUTOMATON_H
#define UNTITLED1_RIGHT_PAREN_AUTOMATON_H
#include "Automaton.h"
class RIGHT_PAREN_Automaton : public Automaton {
public:
    RIGHT_PAREN_Automaton() {
        type = TokenType::RIGHT_PAREN; // set the type
    }
private:
    void s0() {
        if (match(')')) {
            next();
            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }
};
#endif //UNTITLED1_RIGHT_PAREN_AUTOMATON_H

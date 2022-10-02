//
// Created by yep12 on 6/26/2022.
//

#ifndef UNTITLED1_COMMAAUTOMATON_H
#define UNTITLED1_COMMAAUTOMATON_H
#include "Automaton.h"
class CommaAutomaton : public Automaton {
public:
    CommaAutomaton() {
        type = TokenType::COMMA; // set the type
    }
private:
    void s0() {
        if (curr()==',') {
            next();
            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }
};
#endif //UNTITLED1_COMMAAUTOMATON_H

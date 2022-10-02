//
// Created by yep12 on 7/8/2022.
//

#ifndef UNTITLED1_EMPTYSTRING_H
#define UNTITLED1_EMPTYSTRING_H
#include "Automaton.h"
class EmptyStringAutomaton : public Automaton {
public:
    EmptyStringAutomaton() {
        type = TokenType::STRING; // set the type
    }
private:
    void s0() {
        if (match('\'')) {
            next();
            s1(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s1() {
        if (endOfFile()) {
            sError();
        }
        else if (match('\'')) {
            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }
};

#endif //UNTITLED1_EMPTYSTRING_H

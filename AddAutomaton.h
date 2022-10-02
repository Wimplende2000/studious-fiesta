//
// Created by yep12 on 6/26/2022.
//

#ifndef UNTITLED1_ADDAUTOMATON_H
#define UNTITLED1_ADDAUTOMATON_H
#include "Automaton.h"
class AddAutomaton : public Automaton {
public:
    AddAutomaton() {
        type = TokenType::ADD; // set the type
    }
private:
    void s0() {
        if (match('+')) {
            next();
            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }
};
#endif //UNTITLED1_ADDAUTOMATON_H

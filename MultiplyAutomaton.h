//
// Created by yep12 on 6/26/2022.
//

#ifndef UNTITLED1_MULTIPLYAUTOMATON_H
#define UNTITLED1_MULTIPLYAUTOMATON_H
#include "Automaton.h"
class MultiplyAutomaton : public Automaton {
public:
    MultiplyAutomaton() {
        type = TokenType::MULTIPLY; // set the type
    }
private:
    void s0() {
        if (match('*')) {
            next();
            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }
};
#endif //UNTITLED1_MULTIPLYAUTOMATON_H

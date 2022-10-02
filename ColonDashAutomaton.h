//
// Created by yep12 on 6/24/2022.
//

#ifndef UNTITLED1_COLONDASHAUTOMATON_H
#define UNTITLED1_COLONDASHAUTOMATON_H
#include "Automaton.h"
class ColonDashAutomaton : public Automaton {
public:
    ColonDashAutomaton() {
        type = TokenType::COLON_DASH; // set the type
    }
private:
    void s0() {
        if (match(':')) {
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
        else if (match('-')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};
#endif //UNTITLED1_COLONDASHAUTOMATON_H

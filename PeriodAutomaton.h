//
// Created by yep12 on 6/26/2022.
//

#ifndef UNTITLED1_PERIODAUTOMATON_H
#define UNTITLED1_PERIODAUTOMATON_H
#include "Automaton.h"
class PeriodAutomaton : public Automaton {
public:
    PeriodAutomaton() {
        type = TokenType::PERIOD; // set the type
    }
private:
    void s0() {
        if (match('.')) {
            next();
            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }
};
#endif //UNTITLED1_PERIODAUTOMATON_H

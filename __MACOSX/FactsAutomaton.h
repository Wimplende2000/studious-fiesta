//
// Created by yep12 on 6/26/2022.
//

#ifndef UNTITLED1_FACTSAUTOMATON_H
#define UNTITLED1_FACTSAUTOMATON_H

#include "Automaton.h"
class FactsAutomaton : public Automaton {
public:
    FactsAutomaton() {
        type = TokenType::FACTS; // set the type
    }
private:
    void s0() {
        if (match('F')) {
            next();
            s1(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }

    void s1() {
        if (match('a')) {
            next();
            s2(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s2() {
        if (match('c')) {
            next();
            s3(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s3() {
        if (match('t')) {
            next();
            s4(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s4() {
        if (endOfFile()) {
            sError();
        }
        else if (match('s')) {
            next();
            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }


};
#endif //UNTITLED1_FACTSAUTOMATON_H

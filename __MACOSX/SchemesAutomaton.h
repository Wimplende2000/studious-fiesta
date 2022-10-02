//
// Created by yep12 on 6/26/2022.
//

#ifndef UNTITLED1_SCHEMESAUTOMATON_H
#define UNTITLED1_SCHEMESAUTOMATON_H
#include "Automaton.h"
class SchemesAutomaton : public Automaton {
public:
    SchemesAutomaton() {
        type = TokenType::SCHEMES; // set the type
    }
private:
    void s0() {
        if (match('S')) {
            next();
            s1(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }

    void s1() {
        if (match('c')) {
            next();
            s2(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s2() {
        if (match('h')) {
            next();
            s3(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s3() {
        if (match('e')) {
            next();
            s4(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s4() {
        if (match('m')) {
            next();
            s5(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s5() {
        if (match('e')) {
            next();
            s6(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }

    void s6() {
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
#endif //UNTITLED1_SCHEMESAUTOMATON_H

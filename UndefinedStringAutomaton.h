//
// Created by yep12 on 7/6/2022.
//

#ifndef UNTITLED1_UNDEFINEDSTRINGAUTOMATON_H
#define UNTITLED1_UNDEFINEDSTRINGAUTOMATON_H
#include "Automaton.h"
class UndefinedStringAutomaton : public Automaton {
public:
    UndefinedStringAutomaton() {
        type = TokenType::UNDEFINED; // set the type
    }
private:
    void s0() {
        if (match('\'')) {
            next();
            s1();
        }
        else
            sError();
    }

    void s1() {
        if (endOfFile()) {
            return; // accept
        }
        else if(curr()!='\''){
            next();
            s1();
        }
        else
            sError();
    }


};
#endif //UNTITLED1_UNDEFINEDSTRINGAUTOMATON_H

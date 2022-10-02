//
// Created by yep12 on 6/24/2022.
//

#ifndef UNTITLED1_UNDEFINEDCHARAUTOMATON_H
#define UNTITLED1_UNDEFINEDCHARAUTOMATON_H
#include "Automaton.h"
class UndefinedCharAutomaton : public Automaton {
public:
    UndefinedCharAutomaton() {
        type = TokenType::UNDEFINED; // set the type
    }
private:
    void s0() {
        if((!isalnum(curr()))or(!isspace(curr())))
            next(); // read next character
        return; // accept the input
    }
};
#endif //UNTITLED1_UNDEFINEDCHARAUTOMATON_H

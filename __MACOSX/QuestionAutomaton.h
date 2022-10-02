//
// Created by yep12 on 6/26/2022.
//

#ifndef UNTITLED1_QUESTIONAUTOMATON_H
#define UNTITLED1_QUESTIONAUTOMATON_H
#include "Automaton.h"
class QuestionAutomaton : public Automaton {
public:
    QuestionAutomaton() {
        type = TokenType::Q_MARK; // set the type
    }
private:
    void s0() {
        if (match('?')) {
            next();
            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }
};
#endif //UNTITLED1_QUESTIONAUTOMATON_H

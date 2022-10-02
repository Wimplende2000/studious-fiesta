
#ifndef UNTITLED1_EOFAUTOMATON_H
#define UNTITLED1_EOFAUTOMATON_H
#include "Automaton.h"
class EOFAutomaton : public Automaton {
public:
    EOFAutomaton() {
        type = TokenType::END; // set the type
    }
private:
    void s0() {
        if (input.size()==1) {

            return; // this represents accepting the input
        }
        else {
            sError(); // this calls the error state
        }
    }
};
#endif //UNTITLED1_EOFAUTOMATON_H

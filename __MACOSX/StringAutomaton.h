#ifndef UNTITLED1_STRINGAUTOMATON_H
#define UNTITLED1_STRINGAUTOMATON_H
#include "Automaton.h"
#include <cctype>
class StringAutomaton : public Automaton {
public:
    StringAutomaton() {
        type = TokenType::STRING; // set the type
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
            type = TokenType::UNDEFINED;
            return; // accept
        }
        else if((curr()!='\'')){
            next();
            s1();
        }

        else if ('\'') {
            next();
            s2();
        }
        else
            sError();
    }
    void s2(){
        if (endOfFile()) {
            type = TokenType::UNDEFINED;
            return; // accept
        }
        else if(match('\'')){
            next();
            s1();
        }
    }
};
#endif //UNTITLED1_STRINGAUTOMATON_H

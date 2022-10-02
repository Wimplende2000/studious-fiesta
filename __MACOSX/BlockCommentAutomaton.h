#ifndef UNTITLED1_BLOCKCOMMENTAUTOMATON_H
#define UNTITLED1_BLOCKCOMMENTAUTOMATON_H
#include "Automaton.h"
class BlockCommentAutomaton : public Automaton {
public:
    BlockCommentAutomaton() {
        type = TokenType::COMMENT; // set the type
    }
private:
    void s0() {
        if (match('#')) {
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
        else if (match('|')) {
            next();
            s2();
        }
        else
            sError(); // this calls the error state
    }
    void s2() {
        if (endOfFile()) {
            type = UNDEFINED;
            return;
        }
        if (isspace(curr())or(isalnum(curr()))) {
            next();
            s2(); // call s1 as the transition
        }
        else if(curr()=='|'){
            next();
            s3();
        }
        else
            sError(); // this calls the error state
    }
    void s3() {
        if (endOfFile()) {
            sError();
        }
        if (curr()=='#') {
            return;
            s1(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
};
#endif //UNTITLED1_BLOCKCOMMENTAUTOMATON_H

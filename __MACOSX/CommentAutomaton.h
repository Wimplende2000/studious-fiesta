#ifndef UNTITLED1_COMMENTAUTOMATON_H
#define UNTITLED1_COMMENTAUTOMATON_H
#include "Automaton.h"
#include <cctype>

using namespace std;
class CommentAutomaton : public Automaton {
public:
    CommentAutomaton() {
        type = TokenType::COMMENT; // set the type
    }
private:
    void s0() {
        if (match('#')) {
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
        else if (match('|')){
            next();
            s3();
        }
        else{
            next();
            s2();
        }


    }

    void s2() {
        if (endOfFile()) {
            return; // accept
        }
        else if((curr()!='\n')){
            next();
            s2();
        }

    }


    void s3() {
        if (endOfFile()) {
            type = TokenType::UNDEFINED;

            return; // accept
        }
        else if (!match('|')){
            next();
            s3();
        }
        else if (match('|')){
            next();
            s4();
        }


    }


    void s4() {
        if (endOfFile()) {
            type = TokenType::UNDEFINED;

            return; // accept
        }
        else if (match('#')){
            next();
            return;
        }
        else if (match('|')){
            next();
            s4();
        }

        else if (!match('|')){
            next();
            s3();
        }

    }


};
#endif //UNTITLED1_COMMENTAUTOMATON_H

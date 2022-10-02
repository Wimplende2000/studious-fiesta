//
// Created by yep12 on 6/24/2022.
//

#ifndef UNTITLED1_LEXER_H
#define UNTITLED1_LEXER_H
#include <iostream>
#include <vector>
#include "Token.h"
#include "Automaton.h"

#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "UndefinedCharAutomaton.h"
#include "IDAutomaton.h"
#include "AddAutomaton.h"
#include "PeriodAutomaton.h"
#include "QuestionAutomaton.h"
#include "LEFT_PAREN_Automaton.h"
#include "RIGHT_PAREN_Automaton.h"
#include "MultiplyAutomaton.h"
#include "CommaAutomaton.h"
#include "SchemesAutomaton.h"
#include "QueriesAutomaton.h"
#include "RulesAutomaton.h"
#include "FactsAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "UndefinedStringAutomaton.h"
using namespace std;

class Lexer {
private:
    vector<Automaton*> automata;
    vector<Token> tokens;
    void initializeAutomata() {
        automata.push_back(new StringAutomaton());
        automata.push_back(new UndefinedStringAutomaton());
        automata.push_back(new CommentAutomaton());
        automata.push_back(new SchemesAutomaton);
        automata.push_back(new FactsAutomaton());
        automata.push_back(new QueriesAutomaton());
        automata.push_back(new RulesAutomaton());
        automata.push_back(new ColonAutomaton());
        automata.push_back(new CommaAutomaton());
        automata.push_back(new AddAutomaton());
        automata.push_back(new PeriodAutomaton());
        automata.push_back(new QuestionAutomaton());
        automata.push_back(new LEFT_PAREN_Automaton());
        automata.push_back(new RIGHT_PAREN_Automaton());
        automata.push_back(new IDAutomaton());
        automata.push_back(new MultiplyAutomaton());
        automata.push_back(new ColonDashAutomaton());
        automata.push_back(new UndefinedCharAutomaton());
    }
public:
    unsigned int newLine=1;

    vector<Token> run(string input) { // this should be in public
        initializeAutomata();
        while(input.size()>0){


            while (isspace(input.at(0))and(input.size()>1)) {
                if(input.at(0)=='\n'){

                    newLine++;
                }

                input.erase(0, 1);

            }


            Automaton* maxAutomaton = automata.at(0);
            unsigned int maxRead = 0;
            for (unsigned int i = 0; i < automata.size(); i++) {

                Automaton* currentAutomaton = automata.at(i);

                if(currentAutomaton->run(input)>maxRead){
                    maxRead = currentAutomaton->run(input);
                    maxAutomaton = currentAutomaton;

                }


            }
            if(input.size()==1){
                Token currToken = Token(END,"", newLine+1);
                cout << currToken.toString() << endl;
                tokens.push_back(currToken);
                cout << "Total Tokens = " << tokens.size();
                return tokens;
            }
            if(input.size()==0){
                Token currToken = Token(END,"", newLine+1);
                cout << currToken.toString() << endl;
                tokens.push_back(currToken);
                cout << "Total Tokens = " << tokens.size();
                return tokens;
            }
            Token currToken = Token(maxAutomaton->getType(),input.substr(0, maxRead), newLine);
            if((maxAutomaton->getType()==STRING)or(maxAutomaton->getType()==UNDEFINED)or((maxAutomaton->getType()==COMMENT))){
                newLine+=maxAutomaton->getNewLines();
            }
            cout << currToken.toString() << endl;
            input = input.substr(maxRead);
            tokens.push_back(currToken);
            if(input.size()==0){
                Token currToken = Token(END,"", newLine);
                cout << currToken.toString() << endl;
                tokens.push_back(currToken);
                cout << "Total Tokens = " << tokens.size();
                return tokens;
            }
//end of while loop
        }
        Token currToken = Token(END,"", newLine);
        cout << currToken.toString() << endl;
        tokens.push_back(currToken);
        cout << "Total Tokens = " << tokens.size();
        return tokens;
    }

};

#endif //UNTITLED1_LEXER_H

cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp AddAutomaton.h Automaton.h BlockCommentAutomaton.h ColonAutomaton.h ColonDashAutomaton.h CommaAutomaton.h CommentAutomaton.h EmptyString.h EOFAutomaton.h FactsAutomaton.h IDAutomaton.h LEFT_PAREN_Automaton.h Lexer.h MultiplyAutomaton.h PeriodAutomaton.h QueriesAutomaton.h QuestionAutomaton.h RIGHT_PAREN_Automaton.h RulesAutomaton.h SchemesAutomaton.h Token.h UndefinedCharAutomaton.h UndefinedStringAutomaton.h Predicate.h Rule.h DatalogProgam.h Parser.h)

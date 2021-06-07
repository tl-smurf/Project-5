//
// Created by tl_smurf on 5/3/2021.
//

#ifndef PROJECT_1_MATCHERAUTOMATON_H
#define PROJECT_1_MATCHERAUTOMATON_H
#include "Automaton.h"
#include <string>
#include <iostream>

class MatcherAutomaton : public Automaton {

private:
    std::string toMatch;
public:
    MatcherAutomaton(std::string toMatch, TokenType tokenType);
    virtual Token* CreateToken(std::string input, int lineNumber) { return new Token(type, input, lineNumber); }
    void S0(const std::string& input);

};


#endif //PROJECT_1_MATCHERAUTOMATON_H

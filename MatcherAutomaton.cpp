//
// Created by tl_smurf on 5/3/2021.
//

#include "MatcherAutomaton.h"

void MatcherAutomaton::S0(const std::string &input) {
    bool isMatch = true;
    this->inputRead = 0;
    for (unsigned int i = 0; i < toMatch.size(); i++) {
        if (input[i] != toMatch[i]) {
            isMatch = false;
            break;
        }
    }
    if (isMatch == true) {
        this->inputRead = (int)toMatch.size();
    }


}

MatcherAutomaton::MatcherAutomaton(std::string toMatch, TokenType tokenType) {
    this->toMatch = toMatch;
    this->type = tokenType;
}

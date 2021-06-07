//
// Created by tl_smurf on 5/3/2021.
//

#ifndef PROJECT_1_COMMENTAUTOMATON_H
#define PROJECT_1_COMMENTAUTOMATON_H

#include "Automaton.h"

class CommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);


public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_COMMENTAUTOMATON_H

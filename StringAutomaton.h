//
// Created by tl_smurf on 5/3/2021.
//

#ifndef PROJECT_1_STRINGAUTOMATON_H
#define PROJECT_1_STRINGAUTOMATON_H


#include "Automaton.h"

class StringAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    int numApost = 0;


public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //PROJECT_1_STRINGAUTOMATON_H

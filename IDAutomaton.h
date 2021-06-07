//
// Created by tl_smurf on 5/3/2021.
//
#include <cctype>
#include <string>
#include <iostream>
#ifndef PROJECT_1_IDAUTOMATON_H
#define PROJECT_1_IDAUTOMATON_H

#include "Automaton.h"

class IDAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_IDAUTOMATON_H

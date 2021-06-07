//
// Created by tl_smurf on 5/3/2021.
//

#include "CommentAutomaton.h"
#include <iostream>

void CommentAutomaton::S0(const std::string& input) {
     if (input[index] == '#') {inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        Serr();
    }
    else {
        S2(input);
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (input[index] == EOF) {
    }
    else if (input[index] == '\n') {
        //std::cout << "Hi" << std::endl;
    }
    else if (input[index] == '\r') {
        //std::cout << "Hi" << std::endl;
    }
    else {
        inputRead++;
        index++;
        S2(input); //TODO: Make sure this isn't causing problems
    }
}

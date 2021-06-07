//
// Created by tl_smurf on 5/4/2021.
//

#include "CommentBlockAutomaton.h"
#include <iostream>

void CommentBlockAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentBlockAutomaton::S1(const std::string& input) {
    if (input[index] ==  '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void CommentBlockAutomaton::S2(const std::string& input) { //This is for comment BLOCK
    if (index == (int)input.size()) {
        Serr();
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentBlockAutomaton::S3(const std::string& input) { //This is for comment BLOCK
    if (index == (int)input.size()) {
        Serr(); //TODO: Make this, and the one below it throw an undefined
    }
    else if (input[index] == '#') {
        inputRead++;
        index++;
    }
    else if (input[index] == '\n') {

    }
    else {
        inputRead++;
        index++;
        S2(input); //Might be S2
    }
}

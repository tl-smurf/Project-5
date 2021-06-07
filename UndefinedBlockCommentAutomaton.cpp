//
// Created by tl_smurf on 5/4/2021.
//

#include "UndefinedBlockCommentAutomaton.h"
#include <iostream>

void UndefinedBlockCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void UndefinedBlockCommentAutomaton::S1(const std::string& input) {
    if (input[index] ==  '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void UndefinedBlockCommentAutomaton::S2(const std::string& input) { //This is for comment BLOCK
    if (index == (int)input.size()) {
        //std::cout <<"We made it to the end\n";
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }

    else if (input[index] == '#') {
        inputRead++;
        index++;
        S2(input);
    }

    else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\r') {
        newLines++;
        inputRead++;
        index++;
        S2(input);
    }
}
void UndefinedBlockCommentAutomaton::S3(const std::string& input) {
    if (input[index] == '#') {
        Serr();
    }
    else if (input[index] == '\n'){
        inputRead++;
        newLines++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}
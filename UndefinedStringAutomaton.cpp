//
// Created by tl_smurf on 5/4/2021.
//

#include "UndefinedStringAutomaton.h"
#include <iostream>

void UndefinedStringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void UndefinedStringAutomaton::S1(const std::string& input) {
    if (input[index] ==  '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (index == (int)input.size()) {
    }
    else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S1(input);
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}

void UndefinedStringAutomaton::S2(const std::string& input) {
    if (input[index] ==  '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\n') {
        Serr();
    }
    else if (input[index] == '\r') {
        Serr();
    }
    else {
        Serr();
    }
}





/*void UndefinedStringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        S1(input);
    }
    else {
        Serr();
    }
}

void UndefinedStringAutomaton::S1(const std::string& input) {
    if (input[index] ==  '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == (int)input.size()) {
    std::cout <<"hello\n";
    }
    else if (input[index] == '\n') {
        inputRead++;
        index++;
        newLines++;
        S1(input);
    }
    else if (input[index] == '\r') {
        S1(input);
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }

}

void UndefinedStringAutomaton::S2(const std::string& input) {
    if (input[index] ==  '\'') {
        inputRead++;
        index++;
        //terminated = false;
        S1(input);
    }
    else if (input[index] == '\n') {
        Serr();
    }
    else if (input[index] == '\r') {
        Serr();
    }
    else if (input[index] == (int)input.size()) {
        Serr();
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}
*/


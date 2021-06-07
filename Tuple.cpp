//
// Created by tl_smurf on 5/15/2021.
//

#include "Tuple.h"
#include <iostream>

std::string Tuple::getValue(int index) {
    return values.at(index);
}

std::string Tuple::toString() {
    std::string outputString;
    for (unsigned int i = 0; i < values.size(); i++) {
        outputString += values.at(i);
    }
    return outputString;
}

int Tuple::size() {
    return values.size();
}

void Tuple::addValue(std::string valueIn) {

}

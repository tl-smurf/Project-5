//
// Created by tl_smurf on 5/15/2021.
//

#include "Header.h"

Header::Header() {
}

std::string Header::getString(int index) {
    return attributes.at(index);
}

void Header::setAttributes(std::vector<std::string> vectorIn) {
    attributes = vectorIn;
}




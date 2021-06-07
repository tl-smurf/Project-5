//
// Created by tl_smurf on 5/10/2021.
//

#include <iostream>
#include "Parameter.h"

std::string Parameter::toString() {
    return value;
}

std::string Parameter::getType() {
    return type;
}

Parameter::Parameter() {
    type = "";
    value = "";
    constant = false;
}

bool Parameter::isConstant() {
    return constant;
}

Parameter::Parameter(std::string tokentype, std::string val) {
    type = tokentype;
    value = val;
    if (tokentype == "STRING") {
        constant = true;
    }
    else if (tokentype == "ID"){
        constant = false;
    }
}

//
// Created by tl_smurf on 5/10/2021.
//

#include "Predicate.h"
#include <iostream>

std::string Predicate::toString() {
    std::string output;
    output += "" + name + "(";
    for (unsigned int i = 0; i < (parameter_vector.size() - 1); i++) {
        output += parameter_vector.at(i).toString();
        output += ",";
    }
    output += parameter_vector.at(parameter_vector.size() - 1).toString();
    output += ")";
    return output;
}

std::string Predicate::toStringRule() {
    std::string output;
    output += name + "(";
    for (unsigned int i = 0; i < (parameter_vector.size() - 1); i++) {
        output += parameter_vector.at(i).toString();
        output +=  ",";
    }
    output += parameter_vector.at(parameter_vector.size() - 1).toString();
    output += ")";
    return output;
}

std::string Predicate::toStringQuery() {
    std::string output;
    output += "  " + name + "(";
    for (unsigned int i = 0; i < (parameter_vector.size() - 1); i++) {
        output += parameter_vector.at(i).toString();
        output += ",";
    }
    output += parameter_vector.at(parameter_vector.size() - 1).toString();
    output += ")?\n";
    return output;
}

std::string Predicate::toStringFact() {
    std::string output;
    output += "  " + name + "(";
    for (unsigned int i = 0; i < (parameter_vector.size() - 1); i++) {
        output += parameter_vector.at(i).toString();
        output += ",";
    }
    output += parameter_vector.at(parameter_vector.size() - 1).toString();
    output += ").\n";
    return output;
}

Predicate::Predicate() {
    name = "";
    parameter_vector = std::vector<Parameter>();
}

Predicate::Predicate(std::string typeIn) {
    name = typeIn;
    parameter_vector = std::vector<Parameter>();
}

void Predicate::addParameter(Parameter parameterIn) {
    parameter_vector.push_back(parameterIn);
}

std::string Predicate::getName() {
    return name;
}

std::vector<Parameter> Predicate::getParameters() {
    return parameter_vector;
}
//
// Created by tl_smurf on 5/10/2021.
//

#include <iostream>
#include "Rule.h"
#include <string>

std::string Rule::toString() {
    std::string output;
    output += "";
    output += head_Predicate.toStringRule();
    output +=  " :- ";
    for (unsigned int i = 0; i < body_Predicates.size(); i++) {
        if (i == 0) {
            output += body_Predicates.at(i).toStringRule();
        }
        else {
            output +=  ",";
            output += body_Predicates.at(i).toStringRule();
        }
    }
    output +=  ".\n";
    return output;
}

std::vector<Predicate> Rule::getPredicateList(){
    return body_Predicates;
}

Rule::Rule() {
    head_Predicate = Predicate();
    body_Predicates = std::vector<Predicate>();
}

Rule::Rule(Predicate rulePredicateIn) {
    head_Predicate = rulePredicateIn;
    body_Predicates = std::vector<Predicate>();
}

Rule::Rule(Predicate rulePredicateIn, std::vector<Predicate> bodyPredicatesIn) {
    head_Predicate = rulePredicateIn;
    body_Predicates = bodyPredicatesIn;
}

void Rule::addPredicate(Predicate predicateIn) {
    body_Predicates.push_back(predicateIn);
}

Predicate Rule::getHeadlol() {
    return head_Predicate;
}

Predicate Rule::getPredicate() {
    std::string output;
    output += head_Predicate.toString() + " :- ";
    for(unsigned int i = 0; i < body_Predicates.size(); i++){
        if(i == 0)
            output += body_Predicates.at(i).toString();
        else
            output += "," + body_Predicates.at(i).toString();
    }
    output += ".";
    return output;
}




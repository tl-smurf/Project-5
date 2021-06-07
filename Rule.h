//
// Created by tl_smurf on 5/10/2021.
//

#ifndef PROJECT_2_RULE_H
#define PROJECT_2_RULE_H
#include <string>
#include <vector>
#include "Predicate.h"

class Rule {
private:
    Predicate head_Predicate;
    std::vector<Predicate> body_Predicates;
public:
    void addPredicate(Predicate predicateIn);
    std::string toString();
    Rule();
    Rule(Predicate rulePredicateIn);
    Rule(Predicate rulePredicateIn, std::vector<Predicate> bodyPredicatesIn);
    Predicate getPredicate();
    std::vector<Predicate> getPredicateList();

    Predicate getHeadlol();
};


#endif //PROJECT_2_RULE_H

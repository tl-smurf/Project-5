//
// Created by tl_smurf on 5/10/2021.
//

#ifndef PROJECT_2_DATALOGPROGRAM_H
#define PROJECT_2_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include <set>

class DatalogProgram {
private:

public:
    std::vector<Predicate> scheme_predicates;
    std::vector<Predicate> fact_predicates;
    std::vector<Predicate> query_predicates;
    std::vector<Rule> rules_vector;
    std::set<std::string> domain;
    void addScheme(Predicate predicateIn);
    void addFact(Predicate predicateIn);
    void addQuery(Predicate predicateIn);
    void addRule(Rule ruleIn);
    void addDomain(std::vector<Parameter> factParamIn);
    std::string toString();

    std::string intToString(int intin);
};


#endif //PROJECT_2_DATALOGPROGRAM_H

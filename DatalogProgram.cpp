//
// Created by tl_smurf on 5/10/2021.
//

#include "DatalogProgram.h"
#include <iostream>

std::string DatalogProgram::toString() {
    std::string outputString;
    outputString += "Schemes(" + intToString((int)scheme_predicates.size()) + "):\n";
    for (unsigned int i = 0; i < scheme_predicates.size(); i++) {
        outputString += scheme_predicates.at(i).toString();
    }
    outputString += "Facts(" + intToString((int)fact_predicates.size()) + "):\n";
    for (unsigned int i = 0; i < fact_predicates.size(); i++) {
        outputString += fact_predicates.at(i).toStringFact();
    }
    outputString += "Rules(" + intToString((int)rules_vector.size()) + "):\n";
    for (unsigned int i = 0; i < rules_vector.size(); i++) {
        outputString += rules_vector.at(i).toString();
    }
    outputString += "Queries(" + intToString((int)query_predicates.size()) + "):\n";
    for (unsigned int i = 0; i < query_predicates.size(); i++) {
            outputString += query_predicates.at(i).toStringQuery();
    }
    outputString += "Domain(" + intToString((int)domain.size()) + "):\n";
        std::set<std::string>::iterator domainIter;
        for (domainIter = domain.begin(); domainIter != domain.end(); domainIter++) {
            domainIter++;
            if (domainIter == domain.end()) {
                domainIter--;
                outputString += "  " + *domainIter;
            }
            else {
                domainIter--;
                outputString += "  " +  *domainIter + "\n";
            }
        }
    return outputString;

}

std::string DatalogProgram::intToString(int intin) {
    std::string outputString = std::to_string(intin);
    return outputString;
}

void DatalogProgram::addScheme(Predicate predicateIn) {
    scheme_predicates.push_back(predicateIn);
}

void DatalogProgram::addFact(Predicate predicateIn) {
    fact_predicates.push_back(predicateIn);
    addDomain(predicateIn.getParameters());
}

void DatalogProgram::addQuery(Predicate predicateIn) {
    query_predicates.push_back(predicateIn);
}

void DatalogProgram::addRule(Rule ruleIn) {
    rules_vector.push_back(ruleIn);
    addDomain(ruleIn.getPredicate().getParameters());
}

void DatalogProgram::addDomain(std::vector<Parameter> factParamIn) {
    for (unsigned int i = 0; i < factParamIn.size(); i++) {
        if (factParamIn.at(i).getType() == "STRING") {
            domain.insert(factParamIn.at(i).toString());
        }
    }

}



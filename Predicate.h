//
// Created by tl_smurf on 5/10/2021.
//

#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H
#include <string>
#include <vector>
#include "Parameter.h"

class Predicate {
private:
    std::string name;
    std::vector<Parameter> parameter_vector;
public:
    void addParameter(Parameter parameterIn);
    Predicate(std::string typeIn);
    Predicate();
    std::string toString();
    std::string toStringQuery();
    std::string getName();
    std::string toStringRule();
    std::vector<Parameter> getParameters();
    std::string toStringFact();
};


#endif //PROJECT_2_PREDICATE_H

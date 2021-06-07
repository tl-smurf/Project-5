//
// Created by tl_smurf on 5/15/2021.
//

#ifndef PROJECT_3_INTERPRETER_H
#define PROJECT_3_INTERPRETER_H
#include "Parser.h"
#include <string>
#include <iostream>
#include "Database.h"


class Interpreter {
private:

public:

    Interpreter();
    void Start(Parser parserIn);
    void toString();
    std::vector<Predicate> schemesList;
    std::vector<Predicate> factsList;
    std::vector<std::string> domain;
    std::vector<Rule> rulesList;
    std::vector<Predicate> queryList;
    std::vector<std::pair<int,int>> matchList;
    Database db;

            /*
             * for each scheme ‘s’
        create a relation using name and parameter values from ‘s’
        for each fact ‘f’
        make a tuple ‘t’ using the values from ‘f’
        add ‘t’ to relation with the same name as ‘f’
        for each query ‘q’
        get the relation ‘r’ with the same name as the query ‘q’
        select for each constant in the query ‘q’
        select for each pair of matching variables in ‘q’
        project using the positions of the variables in ‘q’
        rename to match the names of variables in ‘q’
        print the resulting relation
             */

    std::vector<std::string> makeAttList(Predicate predicateIn);

    std::vector<std::string> makeFactVector(Predicate predicateIn);



    Relation evaluatePredicate(Predicate P);
    Relation selectsFromRules(Predicate query);
    Relation projectFromRules(Predicate query, Relation r);
    Relation projectJoinify(Predicate query, Relation r);
    void renameify(std::string name, std::vector<std::string> parameters, Relation &renameRel);
    Relation Join(Relation one, Relation two);
    bool isJoinable(Tuple one, Tuple two, std::vector<std::string> paramOne, std::vector<std::string> paramTwo);




    void processDemRules();

    void schemify();

    void factify();

    void queryify();

    Header combineHeaders(Header one, Header two);

    Tuple combineTuples(Tuple tOne, Tuple tTwo, int lengthIn);
};


#endif //PROJECT_3_INTERPRETER_H

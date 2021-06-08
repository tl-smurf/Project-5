//
// Created by tl_smurf on 5/15/2021.
//

#ifndef PROJECT_3_INTERPRETER_H
#define PROJECT_3_INTERPRETER_H
#include "Parser.h"
#include <string>
#include <iostream>
#include "Database.h"
#include "Graph.h"


class Interpreter {
private:

public:

    Interpreter();

    //Variables
    std::vector<Predicate> schemesList;
    std::vector<Predicate> factsList;
    std::vector<Rule> rulesList;
    std::vector<Predicate> queryList;
    std::vector<std::pair<int,int>> matchList;
    Database db;
    std::vector<std::vector<Node>> sccs;
    Graph regGraph;
    Graph reverseGraph;

    //Functions

    Graph makeGraph();

    Graph revGraph();

    void Start(Parser parserIn);

    void toString();

    std::vector<std::string> makeAttList(Predicate predicateIn);

    std::vector<std::string> makeFactVector(Predicate predicateIn);

    Relation evaluatePredicate(Predicate P);

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

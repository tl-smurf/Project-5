//
// Created by tl_smurf on 5/10/2021.
//

#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H

#include <vector>
#include <set>
#include "Token.h"
#include "DatalogProgram.h"
#include <string>


class Parser {
protected:
    int index;
    DatalogProgram loggerPro;
    Predicate currPredicate;
    Rule currRule;
public:
    std::vector<Token*> token_vector;
    std::vector<Predicate> schemesList;
    std::vector<Predicate> factsList;
    std::vector<std::string> domain;
    std::vector<Rule> rulesList;
    std::vector<Predicate> queryList;
    Parser();
    Parser(std::vector<Token*> tokenVectorIn);
    ~Parser();
    std::string ErrorBoi(TokenType expectedTypeIn);
    void ParseDataLog();
    void ParseSchemeList();
    void ParseFactList();
    void ParseRuleList();
    void ParseQueryList();
    void ParseScheme();
    void ParseFact();
    void ParseRule();
    void ParseQuery();
    void ParseHeadPredicate();
    void ParsePredicate();
    void ParsePredicateList();
    void ParseParameterList();
    void ParseStringList();
    void ParseIdList();
    void ParseParameter();
    void Match(TokenType typeIn);

};


#endif //PROJECT_2_PARSER_H

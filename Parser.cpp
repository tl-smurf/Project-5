//
// Created by tl_smurf on 5/10/2021.
//
#include <iostream>
#include <string>
#include "Parser.h"

Parser::Parser(std::vector<Token*> tokenVectorIn) {
    std::string toOutput;
    index = 0;
    currPredicate = Predicate();
    currRule = Rule();
    for (unsigned int i = 0; i < tokenVectorIn.size(); i++) {
        token_vector.push_back(tokenVectorIn.at(i));
    }
    index = 0;
    try {
        ParseDataLog();
        toOutput = "Success!\n";
        toOutput += loggerPro.toString();

    }
    catch (std::string errorMsg) {
        toOutput = errorMsg;
    }
    //std::cout << toOutput;
}

Parser::~Parser() {
}

std::string Parser::ErrorBoi(TokenType expectedTypeIn) {
    switch(expectedTypeIn) {
        case TokenType::COMMA: return "COMMA"; break;
        case TokenType::PERIOD: return "PERIOD"; break;
        case TokenType::Q_MARK: return "Q_MARK"; break;
        case TokenType::LEFT_PAREN: return "LEFT_PAREN"; break;
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN"; break;
        case TokenType::COLON: return "COLON"; break;
        case TokenType::COLON_DASH: return "COLON_DASH"; break;
        case TokenType::MULTIPLY: return "MULTIPLY"; break;
        case TokenType::ADD: return "ADD"; break;
        case TokenType::SCHEMES: return "SCHEMES"; break;
        case TokenType::FACTS: return "FACTS"; break;
        case TokenType::RULES: return "RULES"; break;
        case TokenType::QUERIES: return "QUERIES"; break;
        case TokenType::ID: return "ID"; break;
        case TokenType::STRING: return "STRING"; break;
        case TokenType::COMMENT: return "COMMENT"; break;
        case TokenType::UNDEFINED: return "UNDEFINED"; break;
        case TokenType::EOF_TYPE: return "EOF"; break;
        default: return "UNDEFINED"; break;
        }
}

void Parser::Match(TokenType typeIn) {
    if (token_vector.at(index)->type_of_token == typeIn) {
        index++;

    }
    else {
        std::string errorString = "Failure!\n  ";
        errorString += token_vector.at(index)->toStringComposite();
        throw (errorString);
    }
}

void Parser::ParseDataLog() {
    Match(TokenType::SCHEMES);
    Match(TokenType::COLON);
    ParseScheme();
    ParseSchemeList();
    Match(TokenType::FACTS);
    Match(TokenType::COLON);
    ParseFactList();
    Match(TokenType::RULES);
    Match(TokenType::COLON);
    ParseRuleList();
    Match(TokenType::QUERIES);
    Match(TokenType::COLON);
    ParseQuery();
    ParseQueryList();
    Match(TokenType::EOF_TYPE);

    schemesList = loggerPro.scheme_predicates;
    factsList = loggerPro.fact_predicates;
    rulesList = loggerPro.rules_vector;
    queryList = loggerPro.query_predicates;

}

void Parser::ParseSchemeList() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        ParseScheme();
        ParseSchemeList();
    }
}

void Parser::ParseFactList() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        ParseFact();
        ParseFactList();
    }
}

void Parser::ParseRuleList() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        ParseRule();
        ParseRuleList();
    }
}

void Parser::ParseQueryList() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        ParseQuery();
        ParseQueryList();
    }
}

void Parser::ParseScheme() {
    currPredicate = Predicate(token_vector.at(index)->getValue());
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        Match(TokenType::ID);
        Match(TokenType::LEFT_PAREN);
        currPredicate.addParameter(Parameter(token_vector.at(index)->toString(), token_vector.at(index)->getValue()));
        Match(TokenType::ID);
        ParseIdList();
        Match(TokenType::RIGHT_PAREN);
        loggerPro.addScheme(currPredicate);
    }
    else {
        std::string errorString = "Failure!\n  ";
        errorString += token_vector.at(index)->toStringComposite();
        throw (errorString);
    }
}

void Parser::ParseFact() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        currPredicate = Predicate(token_vector.at(index)->getValue());
        Match(TokenType::ID);
        Match(TokenType::LEFT_PAREN);
        currPredicate.addParameter(Parameter(token_vector.at(index)->toString(), token_vector.at(index)->getValue()));
        Match(TokenType::STRING);
        ParseStringList();
        Match(TokenType::RIGHT_PAREN);
        Match(TokenType::PERIOD);
        loggerPro.addFact(currPredicate);
    }
    else {
        std::string errorString = "Failure!\n  ";
        errorString += token_vector.at(index)->toStringComposite();
        throw (errorString);
    }
}

void Parser::ParseRule() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        ParseHeadPredicate();
        currRule = Rule(currPredicate);
        Match(TokenType::COLON_DASH);
        ParsePredicate();
        ParsePredicateList();
        Match(TokenType::PERIOD);
        loggerPro.addRule(currRule);
    }
    else {
        std::string errorString = "Failure!\n  ";
        errorString += token_vector.at(index)->toStringComposite();
        throw (errorString);
    }
}

void Parser::ParseQuery() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        currPredicate = Predicate(token_vector.at(index)->getValue());
        ParsePredicate();
        Match(TokenType::Q_MARK);
        loggerPro.addQuery(currPredicate);
    }
    else {
        std::string errorString = "Failure!\n  ";
        errorString += token_vector.at(index)->toStringComposite();
        throw (errorString);
    }
}

void Parser::ParseHeadPredicate() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        currPredicate = Predicate(token_vector.at(index)->getValue());
        Match(TokenType::ID);
        Match(TokenType::LEFT_PAREN);
        currPredicate.addParameter(Parameter(token_vector.at(index)->toString(), token_vector.at(index)->getValue()));
        Match(TokenType::ID);
        ParseIdList();
        Match(TokenType::RIGHT_PAREN);
    }
    else {
        std::string errorString = "Failure!\n  ";
        errorString += token_vector.at(index)->toStringComposite();
        throw (errorString);
    }
}

void Parser::ParsePredicate() {
    if (token_vector.at(index)->type_of_token == TokenType::ID) {
        currPredicate = Predicate(token_vector.at(index)->getValue());
        Match(TokenType::ID);
        Match(TokenType::LEFT_PAREN);
        ParseParameter();
        if (token_vector.at(index)->type_of_token == TokenType::COMMA) {
            ParseParameterList();
        }
        Match(TokenType::RIGHT_PAREN);
        currRule.addPredicate(currPredicate);
    }
    else {
        std::string errorString = "Failure!\n  ";
        errorString += token_vector.at(index)->toStringComposite();
        throw (errorString);
    }
}

void Parser::ParsePredicateList() {
    if (token_vector.at(index)->type_of_token == TokenType::COMMA) {
        Match(TokenType::COMMA);
        ParsePredicate();
        if (token_vector.at(index)->type_of_token == TokenType::COMMA) {
            ParsePredicateList();
        }
    }
}

void Parser::ParseParameterList() {
    if (token_vector.at(index)->type_of_token == TokenType::COMMA) {
        Match(TokenType::COMMA);
        ParseParameter();
        ParseParameterList();
    }
}

void Parser::ParseStringList() {
    if (token_vector.at(index)->type_of_token == TokenType::COMMA) {
        Match(TokenType::COMMA);
        currPredicate.addParameter(Parameter(token_vector.at(index)->toString(), token_vector.at(index)->getValue()));
        Match(TokenType::STRING);
        ParseStringList();
    }
}

void Parser::ParseIdList() {
    if (token_vector.at(index)->type_of_token == TokenType::COMMA) {
        Match(TokenType::COMMA);
        currPredicate.addParameter(Parameter(token_vector.at(index)->toString(), token_vector.at(index)->getValue()));
        Match(TokenType::ID);
        ParseIdList();
    }
}

void Parser::ParseParameter() {
    if (token_vector.at(index)->type_of_token == TokenType::STRING) {
        currPredicate.addParameter(Parameter(token_vector.at(index)->toString(), token_vector.at(index)->getValue()));
        Match(TokenType::STRING);
    }
    else if (token_vector.at(index)->type_of_token == TokenType::ID) {
        currPredicate.addParameter(Parameter(token_vector.at(index)->toString(), token_vector.at(index)->getValue()));
        Match(TokenType::ID);
    }
}














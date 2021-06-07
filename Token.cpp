#include "Token.h"
#include <iostream>
#include <string>

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    type_of_token = type;
    token_string = description;
    token_start_line = line;

}

std::string Token::toString() {
    switch(type_of_token) {
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
    };

}

std::string Token::toStringComposite() {
    std::string output = "";
    std::string type = this->toString();
    std::string lineNum = std::to_string(token_start_line);
    output += "(";
    output += type;
    output += ",\"";
    output += token_string;
    output += "\",";
    output += lineNum;
    output += ")";
    output += "\n";
    return output;
}

std::string Token::getValue() {
    return token_string;
}



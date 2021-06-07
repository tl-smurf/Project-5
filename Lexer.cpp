#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommentAutomaton.h"
#include "FactsAutomaton.h"
#include "IDAutomaton.h"
#include "MatcherAutomaton.h"
#include "QueriesAutomaton.h"
#include "RulesAutomaton.h"
#include "SchemesAutomaton.h"
#include "StringAutomaton.h"
#include "CommentBlockAutomaton.h"
#include "UndefinedBlockCommentAutomaton.h"
#include "UndefinedStringAutomaton.h"


Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for (unsigned int i = 0; i < automata_vector.size(); i++) {
        //delete automata_vector.at(i);
    }
    for (unsigned int i = 0; i < tokens_vector.size(); i++) {
        //delete tokens_vector[i];
    }
}

void Lexer::CreateAutomata() {
    automata_vector.push_back(new MatcherAutomaton(",", TokenType::COMMA));
    automata_vector.push_back(new MatcherAutomaton(".", TokenType::PERIOD));
    automata_vector.push_back(new MatcherAutomaton("?", TokenType::Q_MARK));
    automata_vector.push_back(new MatcherAutomaton("(", TokenType::LEFT_PAREN));
    automata_vector.push_back(new MatcherAutomaton(")", TokenType::RIGHT_PAREN));
    automata_vector.push_back(new MatcherAutomaton("*", TokenType::MULTIPLY));
    automata_vector.push_back(new MatcherAutomaton("+", TokenType::ADD));
    automata_vector.push_back(new MatcherAutomaton(",", TokenType::COMMA));
    automata_vector.push_back(new UndefinedBlockCommentAutomaton());
    automata_vector.push_back(new UndefinedStringAutomaton());
    automata_vector.push_back(new StringAutomaton());
    automata_vector.push_back(new QueriesAutomaton());
    automata_vector.push_back(new RulesAutomaton());
    automata_vector.push_back(new SchemesAutomaton());
    automata_vector.push_back(new ColonAutomaton());
    automata_vector.push_back(new ColonDashAutomaton());
    automata_vector.push_back(new CommentBlockAutomaton());
    automata_vector.push_back(new CommentAutomaton());
    automata_vector.push_back(new FactsAutomaton());
    automata_vector.push_back(new IDAutomaton());
    automata_vector.push_back(new MatcherAutomaton("", TokenType::EOF_TYPE)); //TODO: FIX THIS, there's no way it's right
    // TODO: Add the other needed automata here
}

std::vector<Token*> Lexer::GiveMeTokensOrGiveMeDeath(std::string inputString) {
    Run(inputString);
    return tokens_vector;
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata_vector[0];  //set maxAutomaton to the first automaton in automata
        while(isspace(input[0])) {
            if (input[0] == '\n') {
                lineNumber++;
            }
            input = input.erase(0,1); //LOL
        }
        for (unsigned i = 0; i < automata_vector.size(); i++) {
            int inputRead = automata_vector[i]->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata_vector[i];
            }
        }
        if (maxRead >= 0) {
            if (maxRead == 0 && input.size() == 0) {
                Token* newToken = new Token(TokenType::EOF_TYPE,"", lineNumber);
                tokens_vector.push_back(newToken);
                break;
            }
            else if (maxRead == 0) {
                maxRead = 1;
                char c = input[0];
                std::string please(1, c);
                Token* newToken = new Token(TokenType::UNDEFINED,please, lineNumber);
                tokens_vector.push_back(newToken);

            }
            else {
                std::string tokenString = input.substr(0, maxRead);
                Token *newToken = maxAutomaton->CreateToken(tokenString, lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                if (newToken->type_of_token != TokenType::COMMENT) {
                    tokens_vector.push_back(newToken);
                }
                else {
                    
                }
            }
        }

        else {
            maxRead = 1;
            //std::cout << input[0] << std::endl;
            //std::string start = std::to_string(input[0]);
            char c = input[0];
            std::string please(1, c);
            Token* newToken = new Token(TokenType::UNDEFINED,please, lineNumber);
            tokens_vector.push_back(newToken);
        }
        //remove maxRead characters from input
        input = input.erase(0,maxRead);
    }

    //Token* newToken = new Token(TokenType::EOF_TYPE,"", lineNumber);
    //tokens_vector.push_back(newToken);
    if (tokens_vector.size() == 0) {
        Token* newToken = new Token(TokenType::EOF_TYPE,"",lineNumber);
        tokens_vector.push_back(newToken);
    }
    else if (tokens_vector[tokens_vector.size() - 1]->type_of_token != TokenType::EOF_TYPE) {
        Token* newToken = new Token(TokenType::EOF_TYPE,"",lineNumber);
        tokens_vector.push_back(newToken);
    }
}

std::string Lexer::toString(std::string& input) {

    Lexer::Run(input);
    std::string outputString = "";
    int numTokens = 0;
    for (unsigned i = 0; i < tokens_vector.size(); i++) {
        outputString += tokens_vector[i]->toStringComposite();
        numTokens++;
    }
    outputString += "Total Tokens = ";
    outputString += std::to_string(numTokens);
    return outputString;
}



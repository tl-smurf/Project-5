#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata_vector;
    std::vector<Token*> tokens_vector;
    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();
    std::string toString(std::string& input);
    void Run(std::string& input);

    // TODO: add other public methods here

    std::vector<Token *> GiveMeTokensOrGiveMeDeath(std::string inputString);
};

#endif // LEXER_H


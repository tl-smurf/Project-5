#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"
#include "Interpreter.h"
#include "Node.h"



using namespace std;

int main(int argc, char** argv) {
    //Final for Lab 5
    /*Interpreter* interprIt = new Interpreter();
    Lexer* lexerIt = new Lexer();
    ifstream inStream(argv[1]);
    stringstream strStream;
    strStream << inStream.rdbuf();
    string fileString = strStream.str();
    Parser ParseIt(lexerIt->GiveMeTokensOrGiveMeDeath(fileString));
    interprIt->Start(ParseIt);
    return 0;*/
    std::vector<Node> NodesList;
    for (unsigned int i = 0; i < 5; i++) {
        Node newTempNode;
        newTempNode.name = i;
        NodesList.push_back(newTempNode);
    }
    for (unsigned int i = 0; i < NodesList.size(); i++) {
        std::cout << NodesList.at(i).toString();
    }

    //Testing:

};
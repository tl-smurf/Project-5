//
// Created by tl_smurf on 5/4/2021.
//

#ifndef PROJECT_1_UNDEFINEDBLOCKCOMMENTAUTOMATON_H
#define PROJECT_1_UNDEFINEDBLOCKCOMMENTAUTOMATON_H
#include "Automaton.h"


class UndefinedBlockCommentAutomaton : public Automaton    {
    private:
        void S1(const std::string& input);
        void S2(const std::string& input);
        void S3(const std::string& input);

    public:
        UndefinedBlockCommentAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

        void S0(const std::string& input);
};


#endif //PROJECT_1_UNDEFINEDBLOCKCOMMENTAUTOMATON_H

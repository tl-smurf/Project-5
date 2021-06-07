#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    EOF_TYPE, //(EOF,"",line-of-end (which is the same as # of new lines)
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    std::string token_string;
    int token_start_line;
    //needs to read in token type an output based on that.
    //ex: (COLON_DASH,":-",token_start_line)

public:
    Token(TokenType type, std::string description, int line);
    Token();
    std::string toString();
    std::string toStringComposite();
    std::string getValue();
    TokenType type_of_token;
};

#endif // TOKEN_H


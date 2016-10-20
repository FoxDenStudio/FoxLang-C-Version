//
// Created by d4rkfly3r on 10/9/2016.
//

#ifndef FOXLANG_LEXER_H
#define FOXLANG_LEXER_H

#include <iostream>
#include "Tokens/Token.h"

namespace Lexer {
    using namespace Tokens;
    class Lexer {
    public:
        Lexer(const std::string input);

        ~Lexer();

        Token *getNextToken();

        const char getCurrentChar();

        const std::string getInputText();

        Token *getCurrentToken();

        unsigned long getCurrentPosition() const;

        unsigned long getCurrentLine() const;

        unsigned long getCurrentLinePosition() const;

    private:

        void syntaxError(const std::string cause);

        void advance();

        const char peek();

        void skipWhitespace();

        void skipComment();

        Token *number();

        Token *identification();

        const std::string inputText;
        char currentChar;
        Token *currentToken;
        unsigned long currentPosition;
        unsigned long currentLine;
        unsigned long currentLinePosition;
    };
}


#endif //FOXLANG_LEXER_H

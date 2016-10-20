//
// Created by d4rkfly3r on 10/9/2016.
//

#ifndef FOXLANG_TOKEN_H
#define FOXLANG_TOKEN_H

#include <string>
#include "TokenType.h"

namespace Lexer {
    namespace Tokens {
        class Token {
        public:
            Token(TokenType tokenType);

            virtual ~Token();

            virtual std::string toString();

            static const bool isVariableType(TokenType tokenType);

            static const bool isPrimaryMathOperator(TokenType tokenType);

            static const bool isSecondaryMathOperator(TokenType tokenType);

            const TokenType getTokenType();

        private:
            const TokenType tokenType;
        protected:
            const std::string typeToString(const TokenType type);
        };
    }
}

#endif //FOXLANG_TOKEN_H

//
// Created by d4rkfly3r on 10/19/2016.
//

#ifndef FOXLANG_OPERATORTOKEN_H
#define FOXLANG_OPERATORTOKEN_H

#include "Token.h"

namespace Lexer {
    namespace Tokens {
        class OperatorToken : public Token {
        public:
            OperatorToken(TokenType tokenType);

            virtual ~OperatorToken();

            const TokenType getOperator();

            virtual std::string toString() override;

        private:
            const TokenType operatorT;

        };
    }
}


#endif //FOXLANG_OPERATORTOKEN_H

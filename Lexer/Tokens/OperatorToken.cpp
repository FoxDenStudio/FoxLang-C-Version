//
// Created by d4rkfly3r on 10/19/2016.
//

#include "OperatorToken.h"

namespace Lexer {
    namespace Tokens {
        OperatorToken::OperatorToken(const TokenType tokenType) : Token(tokenType),
                                                                  operatorT(tokenType) {}

        OperatorToken::~OperatorToken() {

        }

        const TokenType OperatorToken::getOperator() {
            return operatorT;
        }
    }
}
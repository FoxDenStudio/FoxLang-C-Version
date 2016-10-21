//
// Created by d4rkfly3r on 10/9/2016.
//

#include "Token.h"
#include <typeinfo>

namespace Lexer {
    namespace Tokens {
        Token::Token(const TokenType tokenType) : tokenType(tokenType) {

        }

        Token::~Token() {

        }

        std::string Token::toString() {
            return "Token{}";
        }

        const bool Token::isVariableType(TokenType tokenType) {
            return tokenType == NUMBER;
        }

        const bool Token::isPrimaryMathOperator(TokenType tokenType) {
            return tokenType == MULTIPLY || tokenType == DIVIDE || tokenType == MODULO || tokenType == POWER ||
                   tokenType == SQRT;
        }

        const bool Token::isSecondaryMathOperator(TokenType tokenType) {
            return tokenType == PLUS || tokenType == MINUS;
        }

        const TokenType Token::getTokenType() {
            return tokenType;
        }

        const std::string Token::typeToString(const TokenType type) {
            return typeid(type).name();
        }
    }
}

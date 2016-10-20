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
            return tokenType == Devsi::DATA;
        }

        const bool Token::isPrimaryMathOperator(TokenType tokenType) {
            return tokenType == Devsi::PRIMARY_OP;
        }

        const bool Token::isSecondaryMathOperator(TokenType tokenType) {
            return tokenType == Devsi::SECONDARY_OP;
        }

        const TokenType Token::getTokenType() {
            return tokenType;
        }

        const std::string Token::typeToString(const TokenType type) {
            return typeid(type).name();
        }
    }
}

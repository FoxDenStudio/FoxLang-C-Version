//
// Created by d4rkfly3r on 10/19/2016.
//

#include "SymbolToken.h"

namespace Lexer {
    namespace Tokens {
        SymbolToken::SymbolToken(const TokenType tokenType) : tokenType(tokenType), IdentificationToken(tokenType, Token::typeToString(tokenType)) {

        }

        SymbolToken::~SymbolToken() {

        }

        std::string SymbolToken::toString() {
            std::string ret{};
            ret
                    .append("SymbolToken{")
                    .append(std::to_string(this->tokenType))
                    .append("}");
            return ret;
        }

    }
}

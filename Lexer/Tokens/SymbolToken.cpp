//
// Created by d4rkfly3r on 10/19/2016.
//

#include "SymbolToken.h"

namespace Lexer {
    namespace Tokens {
        SymbolToken::SymbolToken(const TokenType tokenType) : tokenType(tokenType), IdentificationToken(tokenType,
                                                                                                        Token::typeToString(
                                                                                                                tokenType)) {

        }

        SymbolToken::~SymbolToken() {

        }
    }
}

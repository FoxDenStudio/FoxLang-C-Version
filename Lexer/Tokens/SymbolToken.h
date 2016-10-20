//
// Created by d4rkfly3r on 10/19/2016.
//

#ifndef FOXLANG_SYMBOLTOKEN_H
#define FOXLANG_SYMBOLTOKEN_H

#include "TokenType.h"
#include "IdentificationToken.h"

namespace Lexer {
    namespace Tokens {
        class SymbolToken : public IdentificationToken {
        public:
            SymbolToken(const TokenType tokenType);

            virtual ~SymbolToken();

        private:
            const TokenType tokenType;
        };
    }
}

#endif //FOXLANG_SYMBOLTOKEN_H

//
// Created by d4rkfly3r on 10/19/2016.
//

#ifndef FOXLANG_IDENTIFICATIONTOKEN_H
#define FOXLANG_IDENTIFICATIONTOKEN_H

#include "Token.h"

namespace Lexer {
    namespace Tokens {
        class IdentificationToken : public Token {
        public:
            IdentificationToken(const std::string name);

            IdentificationToken(const TokenType symbol, const std::string name);

            virtual ~IdentificationToken();

            const std::string getName();

            virtual std::string toString() override ;

        private:
            const std::string name;

        };
    }
}

#endif //FOXLANG_IDENTIFICATIONTOKEN_H

//
// Created by d4rkfly3r on 10/9/2016.
//

#ifndef FOXLANG_NUMBERTOKEN_H
#define FOXLANG_NUMBERTOKEN_H

#include <string>
#include "Token.h"

namespace Lexer {
    namespace Tokens {
        class NumberToken : public Token {

        public:
            NumberToken(const int pre, const int post);

            virtual ~NumberToken();

            virtual std::string toString() override;

        private:
            const bool decimal;
            int pre, post;
        };
    }
}

#endif //FOXLANG_NUMBERTOKEN_H

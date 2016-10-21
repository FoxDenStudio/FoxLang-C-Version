//
// Created by d4rkfly3r on 10/20/2016.
//

#ifndef FOXLANG_BINDINGTOKEN_H
#define FOXLANG_BINDINGTOKEN_H

#include "Token.h"
#include <vector>

namespace Lexer {
    namespace Tokens {
        class BindingToken : public Token {
        public:
            BindingToken(const std::string package, const std::string name, const short dataCount, const std::vector<std::string> data);

            virtual ~BindingToken();

            virtual std::string toString() override;

        private:
            const std::string package;
            const std::string name;
            const short dataCount;
            const std::vector<std::string> data;
        };
    }
}

#endif //FOXLANG_BINDINGTOKEN_H

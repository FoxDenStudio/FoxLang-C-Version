//
// Created by d4rkfly3r on 10/9/2016.
//

#include <iostream>
#include "NumberToken.h"

namespace Lexer {
    namespace Tokens {
        NumberToken::NumberToken(const int pre, const int post) : decimal(post != -1), Token(TokenType::NUMBER) {
            this->pre = pre;
            if (decimal) {
                this->post = post;
            }
        }

        NumberToken::~NumberToken() {
        }

        std::string NumberToken::toString() {
            std::string ret{};
            return ret
                    .append("NumberToken{")
                    .append(std::string{(char) this->pre})
                    .append(".")
                    .append(std::string{(char) this->post})
                    .append("}");
        }
    }
}
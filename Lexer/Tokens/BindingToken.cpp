//
// Created by d4rkfly3r on 10/20/2016.
//

#include <iostream>
#include "BindingToken.h"

namespace Lexer {
    namespace Tokens {

        BindingToken::BindingToken(const std::string package, const std::string name, const short dataCount, const std::vector<std::string> data) : package(package), name(name), dataCount(dataCount), data(data), Token(TokenType::BINDING) {

        }

        BindingToken::~BindingToken() {
        }

        std::string BindingToken::toString() {
            std::string ret{};
            ret
                    .append("BindingToken{")
                    .append(this->package)
                    .append(", ")
                    .append(this->name)
                    .append(", [");

            for (int i = 0; i < dataCount; i++) {
                ret.append(data[i]);
                if (i != dataCount - 1) {
                    ret.append(", ");
                }
            }

            ret
                    .append("]")
                    .append("}");
            return ret;
        }
    }
}
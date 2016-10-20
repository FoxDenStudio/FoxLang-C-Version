//
// Created by d4rkfly3r on 10/19/2016.
//

#include "IdentificationToken.h"

namespace Lexer {
    namespace Tokens {
        IdentificationToken::IdentificationToken(const std::string name) : name(name),
                                                                           Token(TokenType::IDENTIFICATION) {

        }

        IdentificationToken::IdentificationToken(const TokenType tokenType, const std::string name) : name(name),
                                                                                                      Token(tokenType) {

        }


        IdentificationToken::~IdentificationToken() {

        }

        const std::string IdentificationToken::getName() {
            return name;
        }
    }
}
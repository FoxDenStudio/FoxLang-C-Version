//
// Created by d4rkfly3r on 10/19/2016.
//

#ifndef FOXLANG_TOKENTYPE_H
#define FOXLANG_TOKENTYPE_H


#include "Devsi.h"

namespace Lexer {
    namespace Tokens {
        enum TokenType {
            _EOF_ = Devsi::OTHER,
            START = Devsi::CONTROL,
            FINISH = Devsi::CONTROL,
            TILDA = Devsi::CONTROL,
            SEMICOLON = Devsi::CONTROL,
            ASSIGN = Devsi::CONTROL,
            SCRIPT = Devsi::CONTROL,
            DELETEMEM = Devsi::CONTROL,

            VARIABLE = Devsi::CONTROL,
            IDENTIFICATION = Devsi::CONTROL,
            LPAR = Devsi::OTHER,
            RPAR = Devsi::OTHER,
            COLON = Devsi::OTHER,
            COMMA = Devsi::OTHER,

            NUMBER = Devsi::DATA,

            PLUS = Devsi::SECONDARY_OP,
            MINUS = Devsi::SECONDARY_OP,

            MULTIPLY = Devsi::PRIMARY_OP,
            DIVIDE = Devsi::PRIMARY_OP,
            MODULO = Devsi::PRIMARY_OP,
            POWER = Devsi::PRIMARY_OP,
            SQRT = Devsi::PRIMARY_OP,
            _NULL_ = Devsi::OTHER

        };
    }
}

#endif //FOXLANG_TOKENTYPE_H

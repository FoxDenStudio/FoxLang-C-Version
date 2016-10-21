//
// Created by d4rkfly3r on 10/19/2016.
//

#ifndef FOXLANG_TOKENTYPE_H
#define FOXLANG_TOKENTYPE_H

namespace Lexer {
    namespace Tokens {
        enum TokenType {
            _EOF_ = -1,
            _NULL_ = 0,

            START = 21,
            FINISH = 22,
            TILDA = 23,
            SEMICOLON = 24,
            ASSIGN = 25,
            SCRIPT = 26,
            DELETEMEM = 27,

            VARIABLES = 28,
            IDENTIFICATION = 29,
            LPAR = 30,
            RPAR = 31,
            COLON = 32,
            COMMA = 33,

            NUMBER = 34,

            PLUS = 35,
            MINUS = 36,

            MULTIPLY = 37,
            DIVIDE = 38,
            MODULO = 39,
            POWER = 40,
            SQRT = 41,
            BINDING = 42,

            SET = 43,
            BLOCK = 44,
            AT = 45,
            TO = 46
        };
    }
}

#endif //FOXLANG_TOKENTYPE_H

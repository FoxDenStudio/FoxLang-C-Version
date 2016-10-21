#include <iostream>
#include "Lexer/Lexer.h"
#include "Lexer/Tokens/NumberToken.h"
#include <typeinfo>

using std::cout;
using std::endl;
using Lexer::TokenType;

int main() {

    std::string input{};
    input += "SET BLOCK AT 20,20,45 TO [[minecraft:stonebrick|damage=30|enchantment=2]];";
    Lexer::Lexer lexer{input};
    cout << lexer.getInputText() << endl;

    while (Lexer::Token *token = lexer.getNextToken()) {
        if (token->getTokenType() == TokenType::_EOF_) {
            break;
        }
        cout << token->toString() << endl;

        delete (token);
    }

    return 0;
}

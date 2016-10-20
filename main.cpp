#include <iostream>
#include "Lexer/Lexer.h"
#include "Lexer/Tokens/NumberToken.h"
#include <typeinfo>

using std::cout;
using std::endl;

int main() {

    Lexer::Lexer lexer{"5 SET BLOCK at 20,20,45 TO 'minecraft:stonebrick'"};
    cout << lexer.getInputText() << endl;

    Lexer::Token *token = lexer.getNextToken();
    if (dynamic_cast<Lexer::NumberToken *>(token)) {
        Lexer::NumberToken numberToken = *dynamic_cast<Lexer::NumberToken *>(token);
        cout << "yay: " << numberToken.toString() << endl;
    }

    delete (token);
//    cout << token.toString() << endl;

    return 0;
}

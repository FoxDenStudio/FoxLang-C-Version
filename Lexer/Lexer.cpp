//
// Created by d4rkfly3r on 10/9/2016.
//

#include "Lexer.h"
#include "Tokens/NumberToken.h"
#include "Tokens/OperatorToken.h"

namespace Lexer {
    using namespace Tokens;

    Lexer::Lexer(const std::string input) : inputText(input) {
        this->currentPosition = 0;
        this->currentLine = 0;
        this->currentLinePosition = 0;
        this->currentToken = new Token{TokenType::_NULL_};
        this->currentChar = this->inputText[this->currentPosition];
    }

    Lexer::~Lexer() {
        delete this->currentToken;
    }

    void Lexer::syntaxError(const std::string cause) {
        std::string errorMessage{};
        errorMessage.append("\n");
        errorMessage.append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~").append("\n")
                .append(this->inputText).append("\n")
                .append("\n")
                .append("Error at position: ").append(std::to_string(this->currentLinePosition)).append(" on line: ")
                .append(std::to_string(this->currentPosition)).append("\n")
                .append("Cause: ").append((cause.empty() ? "Unknown!" : cause)).append("\n")
                .append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~").append("\n");

        std::cout.flush();
        std::cerr.flush();
        std::cerr << errorMessage << std::endl;
        std::cerr.flush();
        exit(1);
    }

    void Lexer::advance() {
        char nextCharacter;
        if ((nextCharacter = this->peek()) != '\0') {
            this->currentPosition++;
            this->currentLinePosition++;
            this->currentChar = nextCharacter;
        } else {
            this->currentChar = '\0';
        }
    }

    const char Lexer::peek() {
        if (this->currentPosition + 1 > this->inputText.length()) {
            return '\0';
        } else {
            return this->inputText[this->currentPosition + 1];
        }
    }

    void Lexer::skipWhitespace() {
        while ((this->currentChar != '\0') &&
               (this->currentChar == ' ' || this->currentChar == '\t' || this->currentChar == '\n')) {
            if (this->currentChar == '\n') {
                this->currentLine++;
                this->currentLinePosition = 0;
            }
            this->advance();
        }
    }

    void Lexer::skipComment() {
        while (this->currentChar != '`') {
            this->advance();
        }
        this->advance();
    }

    Token *Lexer::number() {
        std::string resultStringPre{};
        while (this->currentChar != '\0' && isdigit(this->currentChar)) {
            resultStringPre += this->currentChar;
            this->advance();
        }
        if (this->currentChar != '\0' && this->currentChar == '.') {
            std::string resultStringPost{this->currentChar};
            this->advance();

            while (this->currentChar != '\0' && isdigit(this->currentChar)) {
                resultStringPost += this->currentChar;
                this->advance();
            }
            return new NumberToken{std::stoi(resultStringPre), std::stoi(resultStringPost)};
        }

        return new NumberToken{std::stoi(resultStringPre), -1};
    }

    Token *Lexer::identification() {
        std::string resultString = "";
        while (this->currentChar != '\0' && isalnum(this->currentChar)) {
            resultString += this->currentChar;
            this->advance();
        }

        return new IdentificationToken{resultString};
    };

    const char Lexer::getCurrentChar() {
        return this->currentChar;
    }

    const std::string Lexer::getInputText() {
        return inputText;
    }

    Token *Lexer::getCurrentToken() {
        return currentToken;
    }

    unsigned long Lexer::getCurrentPosition() const {
        return currentPosition;
    }

    unsigned long Lexer::getCurrentLine() const {
        return currentLine;
    }

    unsigned long Lexer::getCurrentLinePosition() const {
        return currentLinePosition;
    }

    Token *Lexer::getNextToken() {
        while (this->currentChar != '\0') {
            this->skipWhitespace();

            if (isdigit(this->currentChar)) {
                return this->number();
            }

            if (isalpha(this->currentChar)) {
                return this->identification();
            }

            switch (this->currentChar) {
                case '`':
                    this->advance();
                    this->skipComment();
                    break;
                case ':':
                    this->advance();
                    return (Token *) new SymbolToken{TokenType::COLON};
                case ',':
                    this->advance();
                    return (Token *) new SymbolToken{TokenType::COMMA};
                case '=':
                    this->advance();
                    if (this->currentChar != '=') {
                        return (Token *) new SymbolToken{TokenType::ASSIGN};
                    }
                    break;
                case ';':
                    this->advance();
                    return (Token *) new SymbolToken{TokenType::SEMICOLON};
                case '~':
                    this->advance();
                    return (Token *) new SymbolToken{TokenType::TILDA};
                case '+':
                    this->advance();
                    return (Token *) new OperatorToken{TokenType::PLUS};
                case '-':
                    this->advance();
                    this->skipWhitespace();
                    if (this->currentChar == '-') {
                        return (Token *) new OperatorToken{TokenType::PLUS};
                    }
                    return (Token *) new OperatorToken{TokenType::MINUS};
                case '*':
                    this->advance();
                    return (Token *) new OperatorToken{TokenType::MULTIPLY};
                case '/':
                    this->advance();
                    return (Token *) new OperatorToken{TokenType::DIVIDE};
                case '^':
                    this->advance();
                    return (Token *) new OperatorToken{TokenType::POWER};
                case '%':
                    this->advance();
                    return (Token *) new OperatorToken{TokenType::MODULO};
                case '(':
                    this->advance();
                    return (Token *) new SymbolToken{TokenType::LPAR};
                case ')':
                    this->advance();
                    return (Token *) new SymbolToken{TokenType::RPAR};
                default:
                    this->syntaxError("Invalid operator!");
            }
        }
        return new SymbolToken{Tokens::TokenType::_EOF_};
    }
}
}
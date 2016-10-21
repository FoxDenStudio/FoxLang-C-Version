cmake_minimum_required(VERSION 3.6)
project(FoxLang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Lexer/Tokens/Token.cpp Lexer/Tokens/Token.h Lexer/Lexer.cpp Lexer/Lexer.h Lexer/Tokens/NumberToken.cpp Lexer/Tokens/NumberToken.h Lexer/Tokens/TokenType.h Lexer/Tokens/SymbolToken.cpp Lexer/Tokens/SymbolToken.h Lexer/Tokens/IdentificationToken.cpp Lexer/Tokens/IdentificationToken.h Lexer/Tokens/OperatorToken.cpp Lexer/Tokens/OperatorToken.h Lexer/Tokens/BindingToken.cpp Lexer/Tokens/BindingToken.h)
add_executable(FoxLang ${SOURCE_FILES})
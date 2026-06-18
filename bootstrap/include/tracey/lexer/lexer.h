#ifndef LEXER_H
#define LEXER_H

#include <tracey/struct/lexer_struct.h>

void lexer_init(Lexer *lexer, const char *source, size_t source_len);

Token lexer_next(Lexer *lexer);

Token lexer_peek(Lexer *lexer);

bool lexer_is_eof(const Lexer *lexer);

const char *token_type_to_string(TokenType type);

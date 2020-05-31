/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN_TOK = 258,
    LPAREN_TOK = 259,
    RPAREN_TOK = 260,
    LCURLY_TOK = 261,
    RCURLY_TOK = 262,
    INT_TOK = 263,
    VOID_TOK = 264,
    FLOAT_TOK = 265,
    CHAR_TOK = 266,
    ID_TOK = 267,
    SEMICOLON_TOK = 268,
    COMMA_TOK = 269,
    NUM_TOK = 270,
    EQUAL_TOK = 271,
    ADD_TOK = 272,
    SUB_TOK = 273,
    MUL_TOK = 274,
    DIV_TOK = 275,
    NOT_TOK = 276,
    LESS_EQUAL_TO_TOK = 277,
    NOT_EQUAL_TO_TOK = 278,
    EQUAL_TO_TOK = 279,
    GREATER_EQUAL_TO_TOK = 280,
    GREATER_TOK = 281,
    LESS_TOK = 282,
    AND_TOK = 283,
    OR_TOK = 284,
    IF_TOK = 285,
    WHILE_TOK = 286
  };
#endif
/* Tokens.  */
#define MAIN_TOK 258
#define LPAREN_TOK 259
#define RPAREN_TOK 260
#define LCURLY_TOK 261
#define RCURLY_TOK 262
#define INT_TOK 263
#define VOID_TOK 264
#define FLOAT_TOK 265
#define CHAR_TOK 266
#define ID_TOK 267
#define SEMICOLON_TOK 268
#define COMMA_TOK 269
#define NUM_TOK 270
#define EQUAL_TOK 271
#define ADD_TOK 272
#define SUB_TOK 273
#define MUL_TOK 274
#define DIV_TOK 275
#define NOT_TOK 276
#define LESS_EQUAL_TO_TOK 277
#define NOT_EQUAL_TO_TOK 278
#define EQUAL_TO_TOK 279
#define GREATER_EQUAL_TO_TOK 280
#define GREATER_TOK 281
#define LESS_TOK 282
#define AND_TOK 283
#define OR_TOK 284
#define IF_TOK 285
#define WHILE_TOK 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

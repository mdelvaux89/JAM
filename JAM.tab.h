/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INTEGER = 259,
     DOUBLE = 260,
     FUNC = 261,
     CNUF = 262,
     IF = 263,
     FI = 264,
     ELSE = 265,
     ELSEIF = 266,
     FOR = 267,
     ROF = 268,
     LOOP = 269,
     POOL = 270,
     TRUE = 271,
     FALSE = 272,
     DIV = 273,
     MUL = 274,
     MINUS = 275,
     PLUS = 276,
     CEQ = 277,
     CNEQ = 278,
     CL = 279,
     CLE = 280,
     CG = 281,
     CGE = 282,
     AND = 283,
     OR = 284,
     LBRACKET = 285,
     RBRACKET = 286,
     ARROW = 287,
     COLON = 288,
     EQ = 289
   };
#endif
/* Tokens.  */
#define ID 258
#define INTEGER 259
#define DOUBLE 260
#define FUNC 261
#define CNUF 262
#define IF 263
#define FI 264
#define ELSE 265
#define ELSEIF 266
#define FOR 267
#define ROF 268
#define LOOP 269
#define POOL 270
#define TRUE 271
#define FALSE 272
#define DIV 273
#define MUL 274
#define MINUS 275
#define PLUS 276
#define CEQ 277
#define CNEQ 278
#define CL 279
#define CLE 280
#define CG 281
#define CGE 282
#define AND 283
#define OR 284
#define LBRACKET 285
#define RBRACKET 286
#define ARROW 287
#define COLON 288
#define EQ 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "JAM.y"
{
    int u_int;
    float u_float;
    char *u_string;
}
/* Line 1529 of yacc.c.  */
#line 123 "JAM.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


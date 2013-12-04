/* ####################################################################
# 
# Marcos Rivas R 1181599
#
# File name: tinyC_grammar.y   
#
# Description:  Bison file
#
#   
####################################################################
*/
%{
  #include <stdio.h>
  #include <string.h>
  void yyerror (char *string);
%}

  %token INTEGER
  %token VOID
  %token FLOAT
  %token DOUBLE
  %token LONG
  %token STRING

  %token PRINTF
  
  %token IF
  %token THEN
  %token ELSE
  %token WHILE
  %token DO
  %token READ
  %token WRITE
  %token ID
  %token NUMBER
  
  %token SEMI
  %token LPAREN
  %token RPAREN
  %token LBRACE
  %token RBRACE
  %token LBRACKET
  %token RBRACKET
  %token LT
  %token MT
  %token LOE
  %token MOE
  %token ASSIGN
  %token EQUALITY
  %token ITSNOT
  %token PLUS1
  %token MINUS1
  %token EQUALSM1
  %token EQUALSP1
  %token MOD
  %token EQ


  %token FLOAT_NUM
  %token INT_NUM
  

  %left PLUS
  %left MINUS
  %left TIMES
  %left DIV


%%

program : var_dec stmt_seq{printf("No errors in the code\n");}

var_dec : var_dec single_dec
              | /*epsilon*/

single_dec  : type ID SEMI

type          : INTEGER
              | FLOAT
              | DOUBLE
              | LONG

stmt_seq    : stmt_seq stmt  
            | /*epsilon*/

stmt        : IF exp THEN stmt
            | IF exp THEN stmt ELSE stmt
            | WHILE exp DO stmt
            | variable ASSIGN exp SEMI
            | variable EQUALSM1 exp SEMI
            | variable EQUALSP1 exp SEMI
            | PLUS1 variable SEMI
            | variable PLUS1 SEMI
            | MINUS1 variable SEMI
            | variable MINUS1 SEMI
            | READ LPAREN variable RPAREN SEMI
            | WRITE LPAREN exp RPAREN SEMI
            | PRINTF LPAREN STRING RPAREN SEMI
            | block

block       : LBRACE stmt_seq RBRACE

exp         : simple_exp LT simple_exp
            | simple_exp EQ simple_exp
            | simple_exp MT simple_exp
            | simple_exp LOE simple_exp
            | simple_exp ITSNOT simple_exp
            | simple_exp

simple_exp  : simple_exp PLUS term
            | simple_exp MINUS term
            | term

term        : term TIMES factor
            | term DIV factor
            | term MOD factor
            | factor

factor : LPAREN exp RPAREN
            | INT_NUM
            | FLOAT_NUM
            | variable

variable : ID

%%

#include "lex.yy.c"

void yyerror (char *string){
  printf ("%s \n",string);
}

main (){
  yyparse();
}

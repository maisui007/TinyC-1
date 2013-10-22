/* ####################################################################
# 
# Marcos Rivas R 1181599
# Omar Osorio Medina 1360426
# Tomás Perez Posada 1184912
#
# File name: tinyC.l
#
# Description:  Flex file
#
#   
####################################################################
*/
/*** Sección de declaraciones ***/

%{
	#include <string.h>
%}

%option noyywrap

NUMBER	    "-"?[0-9]+
IDENTIFIER	[A-Za-z_][A-Za-z0-9_]*
S 			 ([ \t]?)+
ENTERO		[0-9][0-9]*|0(c|C)[0-7]+|0(x|X)[0-9A-Fa-f]+|[0-9]*"."[0-9]+([eE][-+]?[0-9]+)?

%x C_COMMENT
%option yylineno

%%
[\n] 						{}
"/*"            			{ BEGIN(C_COMMENT);}
<C_COMMENT>"*/" 			{ BEGIN(INITIAL);}
<C_COMMENT>.    			{}

"//".*"\n"   		       	{}
\"[^"]*\"          		 	{
								return STRING;}
int  	  					{
								
								return INTEGER;
							}
void     	 				{return VOID;}
float     					{
							 	return FLOAT;
							}

printf    					{return PRINTF;}

if       		 			{return IF;}
then      					{return THEN;}
else      					{return ELSE;}
while   		  			{return WHILE;}
do   		  			    {return DO;}
read      					{return READ;}
write     				    {return WRITE;}

{IDENTIFIER}         		{
								
								yylval.name = strdup(yytext);
								return ID;
							}

{NUMBER}             		{
								yylval.ivalue = atoi(yytext);	
								return INT_NUM;
							}
{ENTERO}                    {
								yylval.value = atof(yytext);	
								return FLOAT_NUM;}


"("     					{return LPAREN;}
";"     					{return SEMI;}
")"     					{return RPAREN;}
"{"     					{return LBRACE;}
"}"     					{return RBRACE;}
"["     					{return LBRACKET;}
"]"     					{return RBRACKET;}

"<"                  		{return LT;}
">"                  		{return MT;}
"<="                  		{return LOE;}
">="                  		{return MOE;}
"=="                     	{return EQ;}
"!="                     	{return ITSNOT;}

"++"                     	{return PLUS1;}
"--"                     	{return MINUS1;}
"-="                     	{return EQUALSM1;}
"+="                     	{return EQUALSP1;}
"%"                     	{return MOD;}


"+"             			{return PLUS;}
"-"				            {return MINUS;}
"*" 			            {return TIMES;}
"/" 			            {return DIV;}
":="			            {return ASSIGN;}
[ \t] {}
.                           return yytext[0];



%%
/*** Sección de código en C ***/

%{
#include "myparser.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string token_text;
int num_lines = 1;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
MAIN	"main"
INT 	"int"
CHAR 	"char"
IF 		"if"
ELSE 	"else"
WHILE 	"while"
FOR 	"for"
IN 		"input"
OUT		"output"
WS				[ \t]*
LETTER			'[^'\n]'
ANNOTATION		\/\*(.|[\r\n])*?\*\/
ANNOTATIONO   	\/\/[^\n]*
ID				[A-Za-z_][A-Za-z0-9_]*
NUMBER			([1-9][0-9]*)|0
LBRACE 			\{
RBRACE 			\}
LPAREN 			\(
RPAREN 			\)
ASSIGN 	"="
ADD 	"+"
SUB 	"-"
MUL 	"*"
DIV 	"/"
MOD 	"%"
INC 	"++"
DEC 	"--"
B_AND	"&"
B_OR 	"|"
B_XOR 	"^"
B_NOT 	"~"
M_LEFT 	"<<"
M_RIGHT ">>"
EQ 		"=="
GRT 	">"
LET 	"<"
GRE 	">="
LEE 	"<="
NE 		"!="
AND 	"&&"
OR 		"||"
NOT 	"!"
COMMA	","
SEMICOLON 	";"
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here
"\n"    	{++num_lines;}
{MAIN}		{return MAIN;}
{INT}		{return INT;}
{CHAR} 		{return CHAR;}
{IF} 		{return IF;}
{ELSE}		{return ELSE;}
{WHILE} 	{return WHILE;}
{FOR} 		{return FOR;}
{IN}		{return IN;}
{OUT}		{return OUT;}
{LETTER}	{token_text = yytext; return LETTER;}
{ID}		{token_text = yytext; return ID;}
{NUMBER}	{token_text = yytext; return NUMBER;}
{LBRACE} 	{return LBRACE;}
{RBRACE} 	{return RBRACE;}
{LPAREN} 	{return LPAREN;}
{RPAREN} 	{return RPAREN;}
{ASSIGN}	{return ASSIGN;}
{ADD} 		{return ADD;}
{SUB} 		{return SUB;}
{MUL} 		{return MUL;}
{DIV} 		{return DIV;}
{MOD} 		{return MOD;}
{INC} 		{return INC;}
{DEC} 		{return DEC;}
{B_AND}		{return B_AND;}
{B_OR} 		{return B_OR;}
{B_XOR} 	{return B_XOR;}
{B_NOT} 	{return B_NOT;}
{M_LEFT} 	{return M_LEFT;}
{M_RIGHT} 	{return M_RIGHT;}
{EQ}		{return EQ;}
{GRT} 		{return GRT;}
{LET} 		{return LET;}
{GRE} 		{return GRE;}
{LEE} 		{return LEE;}
{NE} 		{return NE;}
{AND} 		{return AND;}
{OR} 		{return OR;}
{NOT} 		{return NOT;}
{COMMA}		{return COMMA;}
{SEMICOLON} {return SEMICOLON;}
{ANNOTATION}	{}
{ANNOTATIONO}	{}
{WS}			{}
%%

/////////////////////////////////////////////////////////////////////////////
// programs section
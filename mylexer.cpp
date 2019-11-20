/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 42 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 11/21/19
* Time: 00:20:00
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.
Date: 2018??11??1??
****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include "myparser.h"
#include <iostream>

#include <fstream>
#include <string>
using namespace std;

string token_text = "Hello";

int num_lines = 1;




#line 62 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 104 ".\\mylexer.l"

	// place any extra initialisation code here

#line 86 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 109 ".\\mylexer.l"

	// place any extra cleanup code here

#line 98 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 123 ".\\mylexer.l"

#line 170 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 124 ".\\mylexer.l"
++num_lines;
#line 177 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 125 ".\\mylexer.l"

#line 184 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 126 ".\\mylexer.l"

#line 191 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 127 ".\\mylexer.l"
return MAIN;
#line 198 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 128 ".\\mylexer.l"
return INT;
#line 205 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 129 ".\\mylexer.l"
return CHAR;
#line 212 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 130 ".\\mylexer.l"
return IF;
#line 219 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 131 ".\\mylexer.l"
return ELSE;
#line 226 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 132 ".\\mylexer.l"
return WHILE;
#line 233 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 133 ".\\mylexer.l"
return FOR;
#line 240 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 135 ".\\mylexer.l"
return STR;
#line 247 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 136 ".\\mylexer.l"
token_text = yytext;return LETTER;
#line 254 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 137 ".\\mylexer.l"

#line 261 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 138 ".\\mylexer.l"

#line 268 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 140 ".\\mylexer.l"
token_text = yytext;return ID;
#line 275 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 142 ".\\mylexer.l"
token_text = yytext;return NUMBER;
#line 282 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 144 ".\\mylexer.l"
return LBRACE;
#line 289 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 145 ".\\mylexer.l"
return RBRACE;
#line 296 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 146 ".\\mylexer.l"
return LPAREN;
#line 303 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 147 ".\\mylexer.l"
return RPAREN;
#line 310 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 148 ".\\mylexer.l"
return LBRACKET;
#line 317 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 149 ".\\mylexer.l"
return RBRACKET;
#line 324 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 151 ".\\mylexer.l"
return ASSIGN;
#line 331 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 152 ".\\mylexer.l"
return ADD;
#line 338 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 153 ".\\mylexer.l"
return SUB;
#line 345 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 154 ".\\mylexer.l"
return MUL;
#line 352 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 155 ".\\mylexer.l"
return DIV;
#line 359 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 156 ".\\mylexer.l"
return MOD;
#line 366 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 157 ".\\mylexer.l"
return INC;
#line 373 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 158 ".\\mylexer.l"
return DEC;
#line 380 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 160 ".\\mylexer.l"
return B_AND;
#line 387 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 161 ".\\mylexer.l"
return B_IOR;
#line 394 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 162 ".\\mylexer.l"
return B_EOR;
#line 401 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 163 ".\\mylexer.l"
return B_OPP;
#line 408 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 164 ".\\mylexer.l"
return M_LEFT;
#line 415 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 165 ".\\mylexer.l"
return M_RIGHT;
#line 422 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 167 ".\\mylexer.l"
return EQ;
#line 429 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 168 ".\\mylexer.l"
return GRT;
#line 436 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 169 ".\\mylexer.l"
return LET;
#line 443 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 170 ".\\mylexer.l"
return GRE;
#line 450 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 171 ".\\mylexer.l"
return LEE;
#line 457 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 172 ".\\mylexer.l"
return NE;
#line 464 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 174 ".\\mylexer.l"
return AND;
#line 471 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 175 ".\\mylexer.l"
return OR;
#line 478 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 176 ".\\mylexer.l"
return NOT;
#line 485 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 178 ".\\mylexer.l"
return COMMA;
#line 492 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 179 ".\\mylexer.l"
return SEMICOLON;
#line 499 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 194;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 4, 1 },
		{ 43, 68 },
		{ 53, 30 },
		{ 0, 74 },
		{ 68, 59 },
		{ 48, 22 },
		{ 49, 22 },
		{ 0, 10 },
		{ 43, 17 },
		{ 69, 59 },
		{ 54, 30 },
		{ 59, 74 },
		{ 41, 14 },
		{ 44, 17 },
		{ 74, 68 },
		{ 60, 74 },
		{ 45, 20 },
		{ 46, 20 },
		{ 50, 27 },
		{ 51, 28 },
		{ 52, 29 },
		{ 42, 16 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 55, 31 },
		{ 56, 32 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 0, 10 },
		{ 17, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 57, 34 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 58, 40 },
		{ 61, 44 },
		{ 62, 50 },
		{ 63, 51 },
		{ 64, 52 },
		{ 65, 54 },
		{ 66, 55 },
		{ 67, 56 },
		{ 38, 7 },
		{ 68, 60 },
		{ 70, 62 },
		{ 71, 63 },
		{ 72, 66 },
		{ 73, 67 },
		{ 39, 9 },
		{ 75, 73 },
		{ 37, 6 },
		{ 47, 21 },
		{ 24, 1 },
		{ 0, 0 },
		{ 25, 1 },
		{ 26, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 27, 1 },
		{ 0, 0 },
		{ 28, 1 },
		{ 29, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 30, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 31, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 32, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 23, 75 },
		{ 0, 0 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 75, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 3 },
		{ 0, 0, 2 },
		{ 0, 0, 1 },
		{ 0, 20, 46 },
		{ -7, 39, 0 },
		{ 0, 0, 29 },
		{ 0, 41, 32 },
		{ -40, -1, 0 },
		{ 0, 0, 20 },
		{ 0, 0, 21 },
		{ 0, 0, 27 },
		{ 0, -29, 25 },
		{ 0, 0, 47 },
		{ 0, -22, 26 },
		{ 0, -32, 28 },
		{ 0, 7, 17 },
		{ 0, 0, 48 },
		{ 0, -42, 40 },
		{ 0, 21, 24 },
		{ 0, -54, 39 },
		{ 75, 0, 16 },
		{ 0, 0, 22 },
		{ 0, 0, 23 },
		{ 0, 0, 34 },
		{ 75, -84, 16 },
		{ 75, -87, 16 },
		{ 75, -89, 16 },
		{ 75, -98, 16 },
		{ 75, -70, 16 },
		{ 75, -76, 16 },
		{ 0, 0, 18 },
		{ 0, -74, 33 },
		{ 0, 0, 19 },
		{ 0, 0, 35 },
		{ 0, 0, 43 },
		{ 0, 0, 12 },
		{ 0, 0, 44 },
		{ 0, 26, 0 },
		{ 0, 0, 30 },
		{ 0, 0, 31 },
		{ 74, 0, 0 },
		{ -44, 56, 14 },
		{ 0, 0, 36 },
		{ 0, 0, 42 },
		{ 0, 0, 38 },
		{ 0, 0, 41 },
		{ 0, 0, 37 },
		{ 75, -30, 16 },
		{ 75, -47, 16 },
		{ 75, -45, 16 },
		{ 75, 0, 8 },
		{ 75, -46, 16 },
		{ 75, -34, 16 },
		{ 75, -33, 16 },
		{ 0, 0, 45 },
		{ 0, 0, 13 },
		{ -43, -36, 0 },
		{ 74, 32, 0 },
		{ 0, 0, 15 },
		{ 75, -39, 16 },
		{ 75, -25, 16 },
		{ 75, 0, 11 },
		{ 75, 0, 6 },
		{ 75, -33, 16 },
		{ 75, -30, 16 },
		{ 60, -31, 0 },
		{ 0, 0, 14 },
		{ 75, 0, 7 },
		{ 75, 0, 9 },
		{ 75, 0, 5 },
		{ 75, -21, 16 },
		{ -43, -29, 14 },
		{ 0, 71, 10 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 182 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

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
* Time: 16:55:13
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

#include "myparser.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string token_text;
int num_lines = 1;

#line 48 "mylexer.cpp"
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
#line 22 ".\\mylexer.l"

	// place any extra initialisation code here

#line 72 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 27 ".\\mylexer.l"

	// place any extra cleanup code here

#line 84 "mylexer.cpp"
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
#line 82 ".\\mylexer.l"
++num_lines;
#line 156 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 83 ".\\mylexer.l"
return MAIN;
#line 163 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 84 ".\\mylexer.l"
return INT;
#line 170 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 85 ".\\mylexer.l"
return CHAR;
#line 177 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 86 ".\\mylexer.l"
return IF;
#line 184 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 87 ".\\mylexer.l"
return ELSE;
#line 191 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 88 ".\\mylexer.l"
return WHILE;
#line 198 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 89 ".\\mylexer.l"
return FOR;
#line 205 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 90 ".\\mylexer.l"
return IN;
#line 212 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 91 ".\\mylexer.l"
return OUT;
#line 219 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 92 ".\\mylexer.l"
token_text = yytext; return LETTER;
#line 226 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 93 ".\\mylexer.l"
token_text = yytext; return ID;
#line 233 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 94 ".\\mylexer.l"
token_text = yytext; return NUMBER;
#line 240 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 95 ".\\mylexer.l"
return LBRACE;
#line 247 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 96 ".\\mylexer.l"
return RBRACE;
#line 254 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 97 ".\\mylexer.l"
return LPAREN;
#line 261 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 98 ".\\mylexer.l"
return RPAREN;
#line 268 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 99 ".\\mylexer.l"
return ASSIGN;
#line 275 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 100 ".\\mylexer.l"
return ADD;
#line 282 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 101 ".\\mylexer.l"
return SUB;
#line 289 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 102 ".\\mylexer.l"
return MUL;
#line 296 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 103 ".\\mylexer.l"
return DIV;
#line 303 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 104 ".\\mylexer.l"
return MOD;
#line 310 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 105 ".\\mylexer.l"
return INC;
#line 317 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 106 ".\\mylexer.l"
return DEC;
#line 324 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 107 ".\\mylexer.l"
return B_AND;
#line 331 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 108 ".\\mylexer.l"
return B_OR;
#line 338 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 109 ".\\mylexer.l"
return B_XOR;
#line 345 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 110 ".\\mylexer.l"
return B_NOT;
#line 352 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 111 ".\\mylexer.l"
return M_LEFT;
#line 359 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 112 ".\\mylexer.l"
return M_RIGHT;
#line 366 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 113 ".\\mylexer.l"
return EQ;
#line 373 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 114 ".\\mylexer.l"
return GRT;
#line 380 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 115 ".\\mylexer.l"
return LET;
#line 387 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 116 ".\\mylexer.l"
return GRE;
#line 394 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 117 ".\\mylexer.l"
return LEE;
#line 401 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 118 ".\\mylexer.l"
return NE;
#line 408 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 119 ".\\mylexer.l"
return AND;
#line 415 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 120 ".\\mylexer.l"
return OR;
#line 422 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 121 ".\\mylexer.l"
return NOT;
#line 429 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 122 ".\\mylexer.l"
return COMMA;
#line 436 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 123 ".\\mylexer.l"
return SEMICOLON;
#line 443 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 124 ".\\mylexer.l"

#line 450 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 125 ".\\mylexer.l"

#line 457 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 126 ".\\mylexer.l"

#line 464 "mylexer.cpp"
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
		{ 3, 3 },
		{ 61, 51 },
		{ 45, 21 },
		{ 46, 21 },
		{ 44, 20 },
		{ 62, 51 },
		{ 0, 8 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 50, 27 },
		{ 39, 14 },
		{ 40, 15 },
		{ 47, 24 },
		{ 3, 1 },
		{ 5, 1 },
		{ 3, 3 },
		{ 41, 15 },
		{ 51, 27 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 0, 8 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 48, 25 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 42, 19 },
		{ 43, 19 },
		{ 49, 26 },
		{ 36, 7 },
		{ 52, 28 },
		{ 53, 29 },
		{ 54, 30 },
		{ 55, 32 },
		{ 56, 37 },
		{ 0, 41 },
		{ 58, 47 },
		{ 59, 48 },
		{ 60, 49 },
		{ 35, 5 },
		{ 63, 52 },
		{ 64, 53 },
		{ 65, 54 },
		{ 66, 57 },
		{ 67, 58 },
		{ 68, 59 },
		{ 69, 61 },
		{ 70, 63 },
		{ 71, 64 },
		{ 72, 65 },
		{ 57, 66 },
		{ 73, 69 },
		{ 74, 71 },
		{ 75, 72 },
		{ 76, 74 },
		{ 38, 12 },
		{ 0, 0 },
		{ 23, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 24, 1 },
		{ 0, 0 },
		{ 25, 1 },
		{ 26, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 27, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 28, 1 },
		{ 0, 0 },
		{ 29, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 30, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 76 },
		{ 0, 0 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 },
		{ 22, 76 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 76, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 45 },
		{ 0, 0, 1 },
		{ 0, 7, 40 },
		{ 0, 0, 23 },
		{ 0, 20, 26 },
		{ -37, -1, 0 },
		{ 0, 0, 16 },
		{ 0, 0, 17 },
		{ 0, 0, 21 },
		{ 0, 41, 19 },
		{ 0, 0, 41 },
		{ 0, -24, 20 },
		{ 0, -20, 22 },
		{ 0, 0, 13 },
		{ 0, -38, 13 },
		{ 0, 0, 42 },
		{ 0, -5, 34 },
		{ 0, -54, 18 },
		{ 0, -56, 33 },
		{ 76, 0, 12 },
		{ 0, 0, 28 },
		{ 76, -81, 12 },
		{ 76, -58, 12 },
		{ 76, -54, 12 },
		{ 76, -82, 12 },
		{ 76, -38, 12 },
		{ 76, -57, 12 },
		{ 76, -43, 12 },
		{ 0, 0, 14 },
		{ 0, -62, 27 },
		{ 0, 0, 15 },
		{ 0, 0, 29 },
		{ 0, 0, 37 },
		{ 0, 0, 38 },
		{ 0, 24, 0 },
		{ 0, 0, 24 },
		{ 0, 0, 25 },
		{ 66, 0, 0 },
		{ -41, 54, 44 },
		{ 0, 0, 30 },
		{ 0, 0, 36 },
		{ 0, 0, 32 },
		{ 0, 0, 35 },
		{ 0, 0, 31 },
		{ 76, -32, 12 },
		{ 76, -49, 12 },
		{ 76, -47, 12 },
		{ 76, 0, 5 },
		{ 76, -108, 12 },
		{ 76, -36, 12 },
		{ 76, -46, 12 },
		{ 76, -34, 12 },
		{ 0, 0, 39 },
		{ 0, 0, 11 },
		{ 66, 25, 0 },
		{ 76, -41, 12 },
		{ 76, -27, 12 },
		{ 76, 0, 8 },
		{ 76, -42, 12 },
		{ 76, 0, 3 },
		{ 76, -34, 12 },
		{ 76, -35, 12 },
		{ 76, -30, 12 },
		{ -40, 37, 43 },
		{ 76, 0, 4 },
		{ 76, 0, 6 },
		{ 76, -36, 12 },
		{ 76, 0, 2 },
		{ 76, -36, 12 },
		{ 76, -19, 12 },
		{ 76, 0, 9 },
		{ 76, -33, 12 },
		{ 76, 0, 7 },
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
		0
	};
	yybackup = backup;
}
#line 127 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

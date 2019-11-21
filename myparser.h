/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 23 of your 30 day trial period.
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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 11/21/19
* Time: 19:05:21
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 339 ".\\myparser.y"

	// place any extra class members here
	// virtual int yygettoken();

#line 70 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 354 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif

#line 83 "myparser.h"
#define NUMBER 257
#define ID 258
#define ADD 259
#define SUB 260
#define MUL 261
#define DIV 262
#define MOD 263
#define INC 264
#define DEC 265
#define B_AND 266
#define B_OR 267
#define B_XOR 268
#define B_NOT 269
#define M_LEFT 270
#define M_RIGHT 271
#define MAIN 272
#define INT 273
#define CHAR 274
#define IF 275
#define ELSE 276
#define WHILE 277
#define FOR 278
#define IN 279
#define OUT 280
#define LETTER 281
#define EQ 282
#define GRT 283
#define LET 284
#define GRE 285
#define LEE 286
#define NE 287
#define AND 288
#define OR 289
#define NOT 290
#define LBRACE 291
#define RBRACE 292
#define LPAREN 293
#define RPAREN 294
#define SEMICOLON 295
#define COMMA 296
#define ASSIGN 297
#define USUB 298
#endif

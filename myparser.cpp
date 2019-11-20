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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 11/21/19
* Time: 00:20:00
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.
Date: 2018??11??1??
****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include "mylexer.h"
#include "myparser.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#define MAXCHILDREN 5

using namespace std;
extern string token_text;
extern int num_lines;

int num_int = 0;
int num_char = 0;

typedef enum{n_main,braced_stmt,stmts,stmt,decl_stmt,type,id,assign_stmt,expr,factor,n_num,letter,while_stmt,if_stmt,for_stmt} Nonterminal;
typedef enum {StmtK,ExpK,TypeK} NodeKind;
typedef enum {IfK,WhileK,ForK,AssignK,ReadK,WriteK,DeclK,Stmts} StmtKind;
typedef enum {OpK,ConstK,IdK} ExpKind;
typedef enum {Void,Integer,Char,Boolean} ExpType;

int node_num = 0;

class Var
{
	public:
		string name;
		int num;	//某类型的第几个变量
		ExpType type;	//变量类型
		Var(){type = Void;}
};

//定义符号表
typedef map<string, Var*> VarTable;

class VarList
{
	public:
		VarTable table;
		
		VarList(){}
		Var* GetID(string name)
		{
			if(table.find(name) != table.end())
			{
				return table.find(name)->second;
			}
			Var* res = new Var();
			res->name = name;
			this->table[name] = res;
			return res;
		}

		Var* GetID(char* c_name)
		{
			string name = c_name;
			if(table.find(name) != table.end())
			{
				return table.find(name)->second;
			}
			Var* res = new Var();
			res->name = name;
			this->table[name] = res;
			return res;
		}
}m_list;

//定义一个节点
class TreeNode
{
public:
	int line;	// 第几行
	int num;	//节点编号
	union{int op; //操作符类型 token
		int val;	//int常数值
		char c_value; 
		char* name;	//ID名
		} attr;

	NodeKind nodekind;	//节点类型
	union{StmtKind stmt; ExpKind expr;} kind;
	TreeNode* children[MAXCHILDREN];	//子节点
	TreeNode* sibling;	//兄弟节点用到地方： stmts

	ExpType type;	//类型

	TreeNode()
	{
		this->num = node_num++;
		this->line = num_lines;
		for (int i = 0; i<MAXCHILDREN; i++)
		{
			this->children[i] = NULL;
		}
		this->sibling = NULL;
	}

	//向兄弟链表的最后一位加个弟弟
	void newBrother(TreeNode* bro)
	{
		TreeNode *tmp = this;
		while(tmp->sibling != NULL)
		{
			tmp = tmp->sibling;
		}
		tmp->sibling = bro;
	}

	static TreeNode* newStmtNode(StmtKind kind)
	{
		TreeNode* t = new TreeNode();
		t->nodekind = StmtK;
		t->kind.stmt = kind;
		return t;
	}

	static TreeNode* newExprNode(ExpKind kind)
	{
		TreeNode* t = new TreeNode();
		t->nodekind = ExpK;
		t->kind.expr = kind;
		t->type = Void;
		return t;
	}

	static TreeNode* newOpNode(int token)
	{
		TreeNode* res = newExprNode(OpK);
		res->attr.op = token;
		return res;
	}

	// 弹幕运算符的语句
	static TreeNode* newSingleNode(int token,TreeNode* fr)
	{
		TreeNode* res = newOpNode(token);
		res->children[0] = fr;
		return res;
	}

	// 双目运算符的语句
	static TreeNode* newDoubleNode(int token,TreeNode* fr,TreeNode* sc)
	{
		TreeNode* res = newOpNode(token);
		res->children[0] = fr;
		res->children[1] = sc;
		return res;
	}

	// 字母节点
	static TreeNode* newLetterNode(string str)
	{
		TreeNode* res = newExprNode(ConstK);
		res->attr.c_value = str[0];
		res->type = Char;
		return res;
	}

	// 数字节点
	static TreeNode* newIntNode(string str)
	{
		TreeNode* res = newExprNode(ConstK);
		res->attr.val = stoi(str);
		res->type = Integer;
		return res;
	}

	// 变量节点
	static TreeNode* newIdNode(string str)
	{
		TreeNode* res = newExprNode(IdK);
		res->type = Void;
		res->attr.name = (char*)(m_list.GetID(str)->name.data());
		return res;
	}

	// 展示每个节点
	void display()
	{
		for(int i=0;i<MAXCHILDREN;i++)
		{
			if(this->children[i] != NULL)
				this->children[i]->display();
		}
		if(this->sibling != NULL)
		{
			this->sibling->display();
		}
		this->printNode();
	}

	void printNode()
	{
		cout<<this->num<<":\t";
		switch(this->nodekind)
		{
			case StmtK:
				this->printStmt();
				break;
			case ExpK:
				this->printExp();
				break;
			case TypeK:
				this->printType();
				break;
		}
		cout<<"Children: ";
		for(int i=0;i<MAXCHILDREN;i++)
		{
			if(this->children[i] != NULL)
				cout<<" "<<this->children[i]->num;
		}
		if(this->sibling !=NULL)
		{
			cout<<" "<<this->sibling->num;
		}
		cout<<endl;
	}

	void printType()
	{
		cout<<"Type\t\t";
		switch(this->type)
		{
			case Integer:
				cout<<"Interger\t";
				break;
			case Char:
				cout<<"Char\t\t";
				break;
		}
	}

	void printStmt()
	{
		string stmt_list[] = {"If Stmt","While Stmt","For Stmt","Assign Stmt","Read Stmt","Write Stmt","Decl Stmt","Stmts"};
		cout<<stmt_list[this->kind.stmt]<<"\t\t\t";
	}

	void printExp()
	{
		switch(this->kind.expr)
		{
			case OpK:
				cout<<"Expr\t\t";
				this->printOp();
				break;
			case ConstK:
				this->printConst();
				break;
			case IdK:
				cout<<"ID\t\t";
				this->printId();
				break;
		}
	}

	void printOp()
	{
		switch(this->attr.op)
		{
			case ADD:
				cout<<"OP: +\t\t";
				break;
			case SUB:
				cout<<"OP: -\t\t";
				break;
			case MUL:
				cout<<"OP: *\t\t";
				break;
			case DIV:
				cout<<"OP: /\t\t";
				break;
			case MOD:
				cout<<"OP: %\t\t";
				break;
			case USUB:
				cout<<"OP: -\t\t";
				break;
			case INC:
				cout<<"OP: ++\t\t";
				break;
			case DEC:
				cout<<"OP: --\t\t";
				break;
			case M_LEFT:
				cout<<"OP: <<\t\t";
				break;
			case M_RIGHT:
				cout<<"OP: >>\t\t";
				break;
			case EQ:
				cout<<"OP: ==\t\t";
				break;
			case GRT:
				cout<<"OP: >\t\t";
				break;
			case LET:
				cout<<"OP: <\t\t";
				break;
			case GRE:
				cout<<"OP: >=\t\t";
				break;
			case LEE:
				cout<<"OP: <=\t\t";
				break;
			case NE:
				cout<<"OP: !=\t\t";
				break;
			case AND:
				cout<<"OP: &&\t\t";
				break;
			case OR:
				cout<<"OP: ||\t\t";
				break;
			case NOT:
				cout<<"OP: !\t\t";
				break;
			case B_AND:
				cout<<"OP: &\t\t";
				break;
			case B_EOR:
				cout<<"OP: ^\t\t";
				break;
			case B_IOR:
				cout<<"OP: |\t\t";
				break;
			case B_OPP:
				cout<<"OP: ~\t\t";
				break;
		}
	}

	void printId()
	{
		cout<<string(this->attr.name)<<"\t\t";
	}

	void printConst()
	{
		switch(this->type)
		{
			case Char:
				cout<<"Char\t\t";
				cout<<this->attr.c_value<<"\t\t";
				break;
			case Integer:
				cout<<"Integer\t\t";
				cout<<this->attr.val<<"\t\t";
				break;
		}
	}
}*root;


#line 404 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 380 ".\\myparser.y"

	// place any extra initialisation code here

#line 428 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 385 ".\\myparser.y"

	// place any extra cleanup code here

#line 442 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 450 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(4 - 4);
			(*(YYSTYPE YYFAR*)yyvalptr)->display();
		
#line 555 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 459 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
			
#line 570 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 463 ".\\myparser.y"

				//$$ = NULL; 不能直接赋值NULL
				(*(YYSTYPE YYFAR*)yyvalptr) = new TreeNode();
			
#line 586 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 470 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(Stmts);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
			(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(2 - 2);
		
#line 603 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 476 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 618 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 483 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
		
#line 633 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 487 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 648 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 491 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 663 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 495 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 678 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 499 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 693 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 503 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
		
#line 708 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 507 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = new TreeNode();
		
#line 723 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 513 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(DeclK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
			
#line 740 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 521 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new TreeNode();
		(*(YYSTYPE YYFAR*)yyvalptr)->nodekind = TypeK;
		(*(YYSTYPE YYFAR*)yyvalptr)->type = Integer;
	
#line 757 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 527 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new TreeNode();
		(*(YYSTYPE YYFAR*)yyvalptr)->nodekind = TypeK;
		(*(YYSTYPE YYFAR*)yyvalptr)->type = Char;
	
#line 774 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 535 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
			(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(3 - 3);
		
#line 790 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 540 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
			(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(3 - 3);
		
#line 806 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 545 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 821 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 549 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 836 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 556 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newIdNode(token_text);
	
#line 851 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 565 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(AssignK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
			
#line 868 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 573 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(ADD,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 883 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 577 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(SUB,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 898 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 581 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(MUL,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 913 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 585 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(DIV,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 928 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 589 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(MOD,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 943 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 593 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(USUB,yyattribute(2 - 2));
		
#line 958 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 597 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(INC,yyattribute(1 - 2));
		
#line 973 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 601 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(DEC,yyattribute(1 - 2));
		
#line 988 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 605 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(INC,yyattribute(2 - 2));
		
#line 1003 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 609 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(DEC,yyattribute(2 - 2));
		
#line 1018 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 613 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(M_LEFT,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1033 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 617 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(M_RIGHT,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1048 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 621 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(EQ,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1063 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 625 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(GRT,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1078 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 629 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(LET,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1093 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 633 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(GRE,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1108 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 637 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(LEE,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1123 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 641 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(NE,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1138 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 645 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(AND,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1153 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 649 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newDoubleNode(OR,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1168 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 653 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(NOT,yyattribute(2 - 2));
		
#line 1183 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 657 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(B_AND,yyattribute(2 - 2));
		
#line 1198 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 661 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(B_EOR,yyattribute(2 - 2));
		
#line 1213 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 665 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(B_IOR,yyattribute(2 - 2));
		
#line 1228 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 669 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newSingleNode(B_OPP,yyattribute(2 - 2));
		
#line 1243 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 673 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1258 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 677 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1273 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 683 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1288 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 687 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1303 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 691 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1318 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 695 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
		
#line 1333 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 701 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newIntNode(token_text);
	
#line 1348 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 707 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newLetterNode(token_text);
		
#line 1363 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 713 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(WhileK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 5);
			
#line 1380 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 721 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(IfK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 5);
		
#line 1397 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 727 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(IfK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 7);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 7);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(7 - 7);
		
#line 1415 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 736 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 9);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 9);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(7 - 9);
			(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(9 - 9);
		
#line 1434 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 744 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 8);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 8);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(8 - 8);
			
#line 1452 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 751 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 8);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(6 - 8);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(8 - 8);
			
#line 1470 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 758 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 7);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(7 - 7);
			
#line 1487 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 764 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(4 - 8);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(6 - 8);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(8 - 8);
			
#line 1505 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 771 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(4 - 7);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(7 - 7);
			
#line 1522 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 777 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(5 - 7);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(7 - 7);
			
#line 1539 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 783 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(6 - 6);
			
#line 1555 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "NUMBER", 257 },
		{ "ID", 258 },
		{ "ADD", 259 },
		{ "SUB", 260 },
		{ "MUL", 261 },
		{ "DIV", 262 },
		{ "MOD", 263 },
		{ "INC", 264 },
		{ "DEC", 265 },
		{ "B_AND", 266 },
		{ "B_IOR", 267 },
		{ "B_EOR", 268 },
		{ "B_OPP", 269 },
		{ "M_LEFT", 270 },
		{ "M_RIGHT", 271 },
		{ "MAIN", 272 },
		{ "INT", 273 },
		{ "CHAR", 274 },
		{ "IF", 275 },
		{ "ELSE", 276 },
		{ "WHILE", 277 },
		{ "FOR", 278 },
		{ "LETTER", 280 },
		{ "EQ", 281 },
		{ "GRT", 282 },
		{ "LET", 283 },
		{ "GRE", 284 },
		{ "LEE", 285 },
		{ "NE", 286 },
		{ "AND", 287 },
		{ "OR", 288 },
		{ "NOT", 289 },
		{ "LBRACE", 290 },
		{ "RBRACE", 291 },
		{ "LPAREN", 292 },
		{ "RPAREN", 293 },
		{ "SEMICOLON", 296 },
		{ "COMMA", 297 },
		{ "ASSIGN", 298 },
		{ "USUB", 299 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: main",
		"main: MAIN LPAREN RPAREN braced_stmt",
		"braced_stmt: LBRACE stmts RBRACE",
		"braced_stmt: LBRACE RBRACE",
		"stmts: stmt stmts",
		"stmts: stmt",
		"stmt: decl_stmt SEMICOLON",
		"stmt: braced_stmt",
		"stmt: while_stmt",
		"stmt: if_stmt",
		"stmt: for_stmt",
		"stmt: expr SEMICOLON",
		"stmt: SEMICOLON",
		"decl_stmt: type idlist",
		"type: INT",
		"type: CHAR",
		"idlist: id COMMA idlist",
		"idlist: assign_stmt COMMA idlist",
		"idlist: id",
		"idlist: assign_stmt",
		"id: ID",
		"assign_stmt: id ASSIGN expr",
		"expr: expr ADD expr",
		"expr: expr SUB expr",
		"expr: expr MUL expr",
		"expr: expr DIV expr",
		"expr: expr MOD expr",
		"expr: SUB expr",
		"expr: expr INC",
		"expr: expr DEC",
		"expr: INC expr",
		"expr: DEC expr",
		"expr: expr M_LEFT expr",
		"expr: expr M_RIGHT expr",
		"expr: expr EQ expr",
		"expr: expr GRT expr",
		"expr: expr LET expr",
		"expr: expr GRE expr",
		"expr: expr LEE expr",
		"expr: expr NE expr",
		"expr: expr AND expr",
		"expr: expr OR expr",
		"expr: NOT expr",
		"expr: B_AND expr",
		"expr: B_EOR expr",
		"expr: B_IOR expr",
		"expr: B_OPP expr",
		"expr: factor",
		"expr: assign_stmt",
		"factor: id",
		"factor: num",
		"factor: letter",
		"factor: LPAREN expr RPAREN",
		"num: NUMBER",
		"letter: LETTER",
		"while_stmt: WHILE LPAREN expr RPAREN stmt",
		"if_stmt: IF LPAREN expr RPAREN stmt",
		"if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt",
		"for_stmt: FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt",
		"for_stmt: FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt",
		"for_stmt: FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt",
		"for_stmt: FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt",
		"for_stmt: FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt",
		"for_stmt: FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt",
		"for_stmt: FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt",
		"for_stmt: FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 3, 1 },
		{ 2, 2, 2 },
		{ 3, 2, 3 },
		{ 3, 1, 4 },
		{ 4, 2, 5 },
		{ 4, 1, 6 },
		{ 4, 1, 7 },
		{ 4, 1, 8 },
		{ 4, 1, 9 },
		{ 4, 2, 10 },
		{ 4, 1, 11 },
		{ 5, 2, 12 },
		{ 6, 1, 13 },
		{ 6, 1, 14 },
		{ 7, 3, 15 },
		{ 7, 3, 16 },
		{ 7, 1, 17 },
		{ 7, 1, 18 },
		{ 8, 1, 19 },
		{ 9, 3, 20 },
		{ 10, 3, 21 },
		{ 10, 3, 22 },
		{ 10, 3, 23 },
		{ 10, 3, 24 },
		{ 10, 3, 25 },
		{ 10, 2, 26 },
		{ 10, 2, 27 },
		{ 10, 2, 28 },
		{ 10, 2, 29 },
		{ 10, 2, 30 },
		{ 10, 3, 31 },
		{ 10, 3, 32 },
		{ 10, 3, 33 },
		{ 10, 3, 34 },
		{ 10, 3, 35 },
		{ 10, 3, 36 },
		{ 10, 3, 37 },
		{ 10, 3, 38 },
		{ 10, 3, 39 },
		{ 10, 3, 40 },
		{ 10, 2, 41 },
		{ 10, 2, 42 },
		{ 10, 2, 43 },
		{ 10, 2, 44 },
		{ 10, 2, 45 },
		{ 10, 1, 46 },
		{ 10, 1, 47 },
		{ 11, 1, 48 },
		{ 11, 1, 49 },
		{ 11, 1, 50 },
		{ 11, 3, 51 },
		{ 12, 1, 52 },
		{ 13, 1, 53 },
		{ 14, 5, 54 },
		{ 15, 5, 55 },
		{ 15, 7, 56 },
		{ 16, 9, 57 },
		{ 16, 8, 58 },
		{ 16, 8, 59 },
		{ 16, 7, 60 },
		{ 16, 8, 61 },
		{ 16, 7, 62 },
		{ 16, 7, 63 },
		{ 16, 6, 64 }
	};
	yyreduction = reduction;

	yytokenaction_size = 370;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 29, YYAT_SHIFT, 7 },
		{ 29, YYAT_SHIFT, 8 },
		{ 113, YYAT_ERROR, 0 },
		{ 29, YYAT_SHIFT, 9 },
		{ 120, YYAT_SHIFT, 127 },
		{ 113, YYAT_SHIFT, 121 },
		{ 118, YYAT_SHIFT, 125 },
		{ 29, YYAT_SHIFT, 10 },
		{ 29, YYAT_SHIFT, 11 },
		{ 29, YYAT_SHIFT, 12 },
		{ 29, YYAT_SHIFT, 13 },
		{ 29, YYAT_SHIFT, 14 },
		{ 29, YYAT_SHIFT, 15 },
		{ 88, YYAT_SHIFT, 63 },
		{ 88, YYAT_SHIFT, 64 },
		{ 112, YYAT_SHIFT, 119 },
		{ 29, YYAT_SHIFT, 16 },
		{ 29, YYAT_SHIFT, 17 },
		{ 29, YYAT_SHIFT, 18 },
		{ 111, YYAT_SHIFT, 117 },
		{ 29, YYAT_SHIFT, 19 },
		{ 29, YYAT_SHIFT, 20 },
		{ 110, YYAT_SHIFT, 116 },
		{ 29, YYAT_SHIFT, 21 },
		{ 90, YYAT_SHIFT, 58 },
		{ 90, YYAT_SHIFT, 59 },
		{ 90, YYAT_SHIFT, 60 },
		{ 90, YYAT_SHIFT, 61 },
		{ 90, YYAT_SHIFT, 62 },
		{ 90, YYAT_SHIFT, 63 },
		{ 90, YYAT_SHIFT, 64 },
		{ 107, YYAT_SHIFT, 114 },
		{ 29, YYAT_SHIFT, 22 },
		{ 29, YYAT_SHIFT, 5 },
		{ 133, YYAT_SHIFT, 7 },
		{ 29, YYAT_SHIFT, 24 },
		{ 104, YYAT_SHIFT, 112 },
		{ 133, YYAT_SHIFT, 9 },
		{ 103, YYAT_SHIFT, 111 },
		{ 29, YYAT_SHIFT, 25 },
		{ 102, YYAT_SHIFT, 109 },
		{ 133, YYAT_SHIFT, 10 },
		{ 133, YYAT_SHIFT, 11 },
		{ 133, YYAT_SHIFT, 12 },
		{ 133, YYAT_SHIFT, 13 },
		{ 133, YYAT_SHIFT, 14 },
		{ 133, YYAT_SHIFT, 15 },
		{ 87, YYAT_SHIFT, 63 },
		{ 87, YYAT_SHIFT, 64 },
		{ 83, YYAT_SHIFT, 8 },
		{ 133, YYAT_SHIFT, 16 },
		{ 133, YYAT_SHIFT, 17 },
		{ 133, YYAT_SHIFT, 18 },
		{ 80, YYAT_SHIFT, 104 },
		{ 133, YYAT_SHIFT, 19 },
		{ 133, YYAT_SHIFT, 20 },
		{ 79, YYAT_SHIFT, 102 },
		{ 133, YYAT_SHIFT, 21 },
		{ 78, YYAT_SHIFT, 101 },
		{ 129, YYAT_SHIFT, 58 },
		{ 129, YYAT_SHIFT, 59 },
		{ 129, YYAT_SHIFT, 60 },
		{ 129, YYAT_SHIFT, 61 },
		{ 129, YYAT_SHIFT, 62 },
		{ 129, YYAT_SHIFT, 63 },
		{ 129, YYAT_SHIFT, 64 },
		{ 133, YYAT_SHIFT, 22 },
		{ 133, YYAT_SHIFT, 5 },
		{ 77, YYAT_SHIFT, 100 },
		{ 133, YYAT_SHIFT, 24 },
		{ 129, YYAT_SHIFT, 65 },
		{ 129, YYAT_SHIFT, 66 },
		{ 76, YYAT_ERROR, 0 },
		{ 133, YYAT_SHIFT, 25 },
		{ 89, YYAT_SHIFT, 58 },
		{ 89, YYAT_SHIFT, 59 },
		{ 89, YYAT_SHIFT, 60 },
		{ 89, YYAT_SHIFT, 61 },
		{ 89, YYAT_SHIFT, 62 },
		{ 89, YYAT_SHIFT, 63 },
		{ 89, YYAT_SHIFT, 64 },
		{ 129, YYAT_SHIFT, 67 },
		{ 129, YYAT_SHIFT, 68 },
		{ 129, YYAT_SHIFT, 69 },
		{ 129, YYAT_SHIFT, 70 },
		{ 129, YYAT_SHIFT, 71 },
		{ 129, YYAT_SHIFT, 72 },
		{ 129, YYAT_SHIFT, 73 },
		{ 129, YYAT_SHIFT, 74 },
		{ 86, YYAT_SHIFT, 63 },
		{ 86, YYAT_SHIFT, 64 },
		{ 53, YYAT_SHIFT, 82 },
		{ 53, YYAT_SHIFT, 76 },
		{ 129, YYAT_SHIFT, 133 },
		{ 99, YYAT_SHIFT, 58 },
		{ 99, YYAT_SHIFT, 59 },
		{ 99, YYAT_SHIFT, 60 },
		{ 99, YYAT_SHIFT, 61 },
		{ 99, YYAT_SHIFT, 62 },
		{ 99, YYAT_SHIFT, 63 },
		{ 99, YYAT_SHIFT, 64 },
		{ 42, YYAT_SHIFT, 63 },
		{ 42, YYAT_SHIFT, 64 },
		{ 41, YYAT_SHIFT, 63 },
		{ 41, YYAT_SHIFT, 64 },
		{ 99, YYAT_SHIFT, 65 },
		{ 99, YYAT_SHIFT, 66 },
		{ 85, YYAT_SHIFT, 60 },
		{ 85, YYAT_SHIFT, 61 },
		{ 85, YYAT_SHIFT, 62 },
		{ 85, YYAT_SHIFT, 63 },
		{ 85, YYAT_SHIFT, 64 },
		{ 40, YYAT_SHIFT, 63 },
		{ 40, YYAT_SHIFT, 64 },
		{ 54, YYAT_SHIFT, 83 },
		{ 51, YYAT_SHIFT, 81 },
		{ 99, YYAT_SHIFT, 67 },
		{ 99, YYAT_SHIFT, 68 },
		{ 99, YYAT_SHIFT, 69 },
		{ 99, YYAT_SHIFT, 70 },
		{ 99, YYAT_SHIFT, 71 },
		{ 99, YYAT_SHIFT, 72 },
		{ 99, YYAT_SHIFT, 73 },
		{ 99, YYAT_SHIFT, 74 },
		{ 98, YYAT_SHIFT, 58 },
		{ 98, YYAT_SHIFT, 59 },
		{ 98, YYAT_SHIFT, 60 },
		{ 98, YYAT_SHIFT, 61 },
		{ 98, YYAT_SHIFT, 62 },
		{ 98, YYAT_SHIFT, 63 },
		{ 98, YYAT_SHIFT, 64 },
		{ 49, YYAT_SHIFT, 79 },
		{ 35, YYAT_SHIFT, 76 },
		{ 34, YYAT_SHIFT, 75 },
		{ 33, YYAT_SHIFT, 57 },
		{ 98, YYAT_SHIFT, 65 },
		{ 98, YYAT_SHIFT, 66 },
		{ 84, YYAT_SHIFT, 60 },
		{ 84, YYAT_SHIFT, 61 },
		{ 84, YYAT_SHIFT, 62 },
		{ 84, YYAT_SHIFT, 63 },
		{ 84, YYAT_SHIFT, 64 },
		{ 32, YYAT_SHIFT, 56 },
		{ 20, YYAT_SHIFT, 49 },
		{ 19, YYAT_SHIFT, 48 },
		{ 18, YYAT_SHIFT, 47 },
		{ 98, YYAT_SHIFT, 67 },
		{ 98, YYAT_SHIFT, 68 },
		{ 98, YYAT_SHIFT, 69 },
		{ 98, YYAT_SHIFT, 70 },
		{ 98, YYAT_SHIFT, 71 },
		{ 98, YYAT_SHIFT, 72 },
		{ 98, YYAT_SHIFT, 73 },
		{ 97, YYAT_SHIFT, 58 },
		{ 97, YYAT_SHIFT, 59 },
		{ 97, YYAT_SHIFT, 60 },
		{ 97, YYAT_SHIFT, 61 },
		{ 97, YYAT_SHIFT, 62 },
		{ 97, YYAT_SHIFT, 63 },
		{ 97, YYAT_SHIFT, 64 },
		{ 5, YYAT_SHIFT, 23 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 97, YYAT_SHIFT, 65 },
		{ 97, YYAT_SHIFT, 66 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 97, YYAT_SHIFT, 67 },
		{ 97, YYAT_SHIFT, 68 },
		{ 97, YYAT_SHIFT, 69 },
		{ 97, YYAT_SHIFT, 70 },
		{ 97, YYAT_SHIFT, 71 },
		{ 97, YYAT_SHIFT, 72 },
		{ 45, YYAT_SHIFT, 58 },
		{ 45, YYAT_SHIFT, 59 },
		{ 45, YYAT_SHIFT, 60 },
		{ 45, YYAT_SHIFT, 61 },
		{ 45, YYAT_SHIFT, 62 },
		{ 45, YYAT_SHIFT, 63 },
		{ 45, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 45, YYAT_SHIFT, 65 },
		{ 45, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 45, YYAT_SHIFT, 67 },
		{ 45, YYAT_SHIFT, 68 },
		{ 45, YYAT_SHIFT, 69 },
		{ 45, YYAT_SHIFT, 70 },
		{ 45, YYAT_SHIFT, 71 },
		{ 45, YYAT_SHIFT, 72 },
		{ 44, YYAT_SHIFT, 58 },
		{ 44, YYAT_SHIFT, 59 },
		{ 44, YYAT_SHIFT, 60 },
		{ 44, YYAT_SHIFT, 61 },
		{ 44, YYAT_SHIFT, 62 },
		{ 44, YYAT_SHIFT, 63 },
		{ 44, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 44, YYAT_SHIFT, 65 },
		{ 44, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 44, YYAT_SHIFT, 67 },
		{ 44, YYAT_SHIFT, 68 },
		{ 44, YYAT_SHIFT, 69 },
		{ 44, YYAT_SHIFT, 70 },
		{ 44, YYAT_SHIFT, 71 },
		{ 44, YYAT_SHIFT, 72 },
		{ 43, YYAT_SHIFT, 58 },
		{ 43, YYAT_SHIFT, 59 },
		{ 43, YYAT_SHIFT, 60 },
		{ 43, YYAT_SHIFT, 61 },
		{ 43, YYAT_SHIFT, 62 },
		{ 43, YYAT_SHIFT, 63 },
		{ 43, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 43, YYAT_SHIFT, 65 },
		{ 43, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 43, YYAT_SHIFT, 67 },
		{ 43, YYAT_SHIFT, 68 },
		{ 43, YYAT_SHIFT, 69 },
		{ 43, YYAT_SHIFT, 70 },
		{ 43, YYAT_SHIFT, 71 },
		{ 43, YYAT_SHIFT, 72 },
		{ 96, YYAT_SHIFT, 58 },
		{ 96, YYAT_SHIFT, 59 },
		{ 96, YYAT_SHIFT, 60 },
		{ 96, YYAT_SHIFT, 61 },
		{ 96, YYAT_SHIFT, 62 },
		{ 96, YYAT_SHIFT, 63 },
		{ 96, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 96, YYAT_SHIFT, 65 },
		{ 96, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 91, YYAT_SHIFT, 58 },
		{ 91, YYAT_SHIFT, 59 },
		{ 91, YYAT_SHIFT, 60 },
		{ 91, YYAT_SHIFT, 61 },
		{ 91, YYAT_SHIFT, 62 },
		{ 91, YYAT_SHIFT, 63 },
		{ 91, YYAT_SHIFT, 64 },
		{ 96, YYAT_SHIFT, 68 },
		{ 96, YYAT_SHIFT, 69 },
		{ 96, YYAT_SHIFT, 70 },
		{ 96, YYAT_SHIFT, 71 },
		{ 91, YYAT_SHIFT, 65 },
		{ 91, YYAT_SHIFT, 66 },
		{ 121, YYAT_ERROR, 0 },
		{ 121, YYAT_ERROR, 0 },
		{ 121, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 121, YYAT_ERROR, 0 },
		{ 121, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 91, YYAT_SHIFT, 68 },
		{ 91, YYAT_SHIFT, 69 },
		{ 91, YYAT_SHIFT, 70 },
		{ 91, YYAT_SHIFT, 71 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 121, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 121, YYAT_SHIFT, 128 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 121, YYAT_ERROR, 0 },
		{ 95, YYAT_SHIFT, 58 },
		{ 95, YYAT_SHIFT, 59 },
		{ 95, YYAT_SHIFT, 60 },
		{ 95, YYAT_SHIFT, 61 },
		{ 95, YYAT_SHIFT, 62 },
		{ 95, YYAT_SHIFT, 63 },
		{ 95, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 95, YYAT_SHIFT, 65 },
		{ 95, YYAT_SHIFT, 66 },
		{ 94, YYAT_SHIFT, 58 },
		{ 94, YYAT_SHIFT, 59 },
		{ 94, YYAT_SHIFT, 60 },
		{ 94, YYAT_SHIFT, 61 },
		{ 94, YYAT_SHIFT, 62 },
		{ 94, YYAT_SHIFT, 63 },
		{ 94, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 94, YYAT_SHIFT, 65 },
		{ 94, YYAT_SHIFT, 66 },
		{ 93, YYAT_SHIFT, 58 },
		{ 93, YYAT_SHIFT, 59 },
		{ 93, YYAT_SHIFT, 60 },
		{ 93, YYAT_SHIFT, 61 },
		{ 93, YYAT_SHIFT, 62 },
		{ 93, YYAT_SHIFT, 63 },
		{ 93, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 93, YYAT_SHIFT, 65 },
		{ 93, YYAT_SHIFT, 66 },
		{ 92, YYAT_SHIFT, 58 },
		{ 92, YYAT_SHIFT, 59 },
		{ 92, YYAT_SHIFT, 60 },
		{ 92, YYAT_SHIFT, 61 },
		{ 92, YYAT_SHIFT, 62 },
		{ 92, YYAT_SHIFT, 63 },
		{ 92, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 92, YYAT_SHIFT, 65 },
		{ 92, YYAT_SHIFT, 66 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -105, 1, YYAT_ERROR, 0 },
		{ -126, 1, YYAT_ERROR, 0 },
		{ 163, 1, YYAT_ERROR, 0 },
		{ -131, 1, YYAT_ERROR, 0 },
		{ -129, 1, YYAT_ERROR, 0 },
		{ -131, 1, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ -147, 1, YYAT_ERROR, 0 },
		{ -148, 1, YYAT_ERROR, 0 },
		{ -149, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 83 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ -257, 1, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -149, 1, YYAT_ERROR, 0 },
		{ -162, 1, YYAT_ERROR, 0 },
		{ -163, 1, YYAT_DEFAULT, 113 },
		{ -166, 1, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ -152, 1, YYAT_REDUCE, 27 },
		{ -161, 1, YYAT_REDUCE, 30 },
		{ -163, 1, YYAT_REDUCE, 31 },
		{ -22, 1, YYAT_REDUCE, 43 },
		{ -50, 1, YYAT_REDUCE, 45 },
		{ -78, 1, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ -165, 1, YYAT_DEFAULT, 104 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ -178, 1, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -206, 1, YYAT_REDUCE, 18 },
		{ -183, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -221, 1, YYAT_DEFAULT, 121 },
		{ -225, 1, YYAT_DEFAULT, 129 },
		{ -235, 1, YYAT_DEFAULT, 129 },
		{ -240, 1, YYAT_DEFAULT, 104 },
		{ -243, 1, YYAT_DEFAULT, 113 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_DEFAULT, 83 },
		{ -209, 1, YYAT_ERROR, 0 },
		{ -124, 1, YYAT_REDUCE, 22 },
		{ -154, 1, YYAT_REDUCE, 23 },
		{ -175, 1, YYAT_REDUCE, 24 },
		{ -217, 1, YYAT_REDUCE, 25 },
		{ -251, 1, YYAT_REDUCE, 26 },
		{ -185, 1, YYAT_REDUCE, 32 },
		{ -235, 1, YYAT_REDUCE, 33 },
		{ 22, 1, YYAT_REDUCE, 34 },
		{ 98, 1, YYAT_REDUCE, 35 },
		{ 85, 1, YYAT_REDUCE, 36 },
		{ 72, 1, YYAT_REDUCE, 37 },
		{ 59, 1, YYAT_REDUCE, 38 },
		{ 6, 1, YYAT_REDUCE, 39 },
		{ -106, 1, YYAT_REDUCE, 40 },
		{ -135, 1, YYAT_REDUCE, 41 },
		{ -165, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -253, 1, YYAT_DEFAULT, 121 },
		{ -258, 1, YYAT_DEFAULT, 113 },
		{ -260, 1, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -245, 1, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -271, 1, YYAT_DEFAULT, 129 },
		{ -274, 1, YYAT_DEFAULT, 121 },
		{ -278, 1, YYAT_DEFAULT, 121 },
		{ -291, 1, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -287, 1, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -289, 1, YYAT_DEFAULT, 129 },
		{ 21, 1, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -200, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ -223, 1, YYAT_DEFAULT, 83 },
		{ 0, 0, YYAT_REDUCE, 58 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 67;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 133, 28 },
		{ 128, 132 },
		{ 133, 134 },
		{ 133, 33 },
		{ 133, 26 },
		{ 83, 106 },
		{ 83, 53 },
		{ 83, 54 },
		{ 133, 34 },
		{ 29, 55 },
		{ 29, 29 },
		{ 127, 131 },
		{ 133, 27 },
		{ 133, 30 },
		{ 133, 31 },
		{ 121, 35 },
		{ 121, 36 },
		{ 121, 129 },
		{ 121, 37 },
		{ 121, 38 },
		{ 121, 39 },
		{ 125, 130 },
		{ 119, 126 },
		{ 117, 124 },
		{ 116, 123 },
		{ 114, 122 },
		{ 112, 120 },
		{ 111, 118 },
		{ 109, 115 },
		{ 104, 113 },
		{ 102, 110 },
		{ 101, 108 },
		{ 100, 107 },
		{ 82, 105 },
		{ 79, 103 },
		{ 76, 99 },
		{ 74, 98 },
		{ 73, 97 },
		{ 72, 96 },
		{ 71, 95 },
		{ 70, 94 },
		{ 69, 93 },
		{ 68, 92 },
		{ 67, 91 },
		{ 66, 90 },
		{ 65, 89 },
		{ 62, 88 },
		{ 61, 87 },
		{ 60, 86 },
		{ 59, 85 },
		{ 58, 84 },
		{ 49, 80 },
		{ 48, 78 },
		{ 47, 77 },
		{ 26, 52 },
		{ 24, 51 },
		{ 22, 50 },
		{ 15, 46 },
		{ 14, 45 },
		{ 13, 44 },
		{ 12, 43 },
		{ 11, 42 },
		{ 10, 41 },
		{ 9, 40 },
		{ 5, 32 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 65, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 63, -1 },
		{ 61, 29 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 53, 121 },
		{ 52, 121 },
		{ 51, 121 },
		{ 50, 121 },
		{ 49, 121 },
		{ 48, 121 },
		{ 47, 121 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 46, 121 },
		{ 0, -1 },
		{ 45, 121 },
		{ 0, -1 },
		{ 47, 83 },
		{ 0, -1 },
		{ 0, -1 },
		{ 6, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 43, 121 },
		{ 42, 121 },
		{ 41, 121 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 40, 121 },
		{ 39, 121 },
		{ 38, 121 },
		{ 37, 121 },
		{ 36, 121 },
		{ 0, -1 },
		{ 0, -1 },
		{ 35, 121 },
		{ 34, 121 },
		{ 33, 121 },
		{ 32, 121 },
		{ 31, 121 },
		{ 30, 121 },
		{ 29, 121 },
		{ 28, 121 },
		{ 27, 121 },
		{ 26, 121 },
		{ 0, -1 },
		{ 25, 121 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 121 },
		{ 0, -1 },
		{ 0, -1 },
		{ 26, 83 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 28, 133 },
		{ 27, 133 },
		{ 20, 121 },
		{ 0, -1 },
		{ 19, 121 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 133 },
		{ 0, -1 },
		{ 17, 121 },
		{ 16, 121 },
		{ 0, -1 },
		{ 21, 133 },
		{ 0, -1 },
		{ 20, 133 },
		{ 19, 133 },
		{ 0, -1 },
		{ 18, 133 },
		{ 0, -1 },
		{ 7, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 17, 133 },
		{ 0, -1 },
		{ 7, 133 },
		{ -3, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 121 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 792 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	freopen("input.txt","r",stdin);
	if(parser.yycreate(&lexer))
	{
		if(lexer.yycreate(&parser))
		{
			n = parser.yyparse();
		}
	}
	freopen("CON","r",stdin);
	cout<<endl<<endl;
	system("pause");
	return n;
}

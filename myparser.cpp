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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 11/21/19
* Time: 19:05:21
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
int node_num = 0;

typedef enum {n_main,braced_stmt,comp_stmt,stmt,decl_stmt,type,id,assign_stmt,expr,factor,n_num,letter,while_stmt,if_stmt,for_stmt,in_stmt,out_stmt} Nonterminal;
typedef enum {StmtK,ExpK,TypeK} NodeKind;
typedef enum {IfK,WhileK,ForK,AssignK,InK,OutK,DeclK,CompK} StmtKind;
typedef enum {OpK,ConstK,IdK} ExpKind;
typedef enum {Void,Integer,Char} ExpType;

class Var
{
public:
	string name;
	int num;		//某类型的第几个变量

	ExpType type;	//变量类型
	Var(){ type = Void; }
};

class VarList
{
private:
	map<string, Var*> table;
public:
	VarList() {}
	Var* GetID(string name)
	{
		if(table.find(name) != table.end())  // 找到
			return table.find(name)->second;
		Var* res = new Var();
		res->name = name;
		this->table[name] = res;
		return res;
	}
}symbolTable;

//定义一个节点

class TreeNode
{
public:
	TreeNode* children[MAXCHILDREN];	//子节点

	TreeNode* sibling;					//兄弟节点
	int line;		// 第几行

	int num;		//节点编号
	NodeKind nodekind;	//节点类型
	union { StmtKind stmt; ExpKind expr; } kind;
	union { int op; 	//操作符类型

		int val;		//常数值

		char* name;		//ID
		char char_val;	//字符值 
	} attr;
	ExpType type;		//变量类型

	TreeNode()
	{
		for (int i = 0; i < MAXCHILDREN; i++)
			this->children[i] = NULL;
		this->sibling = NULL;
		this->num = node_num++;
		this->line = num_lines;
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
		TreeNode* t = newExprNode(OpK);
		t->attr.op = token;
		return t;
	}

	// 字母
	static TreeNode* newLetterNode(string str)
	{
		TreeNode* res = newExprNode(ConstK);
		res->attr.char_val = str[0];
		res->type = Char;
		return res;
	}

	// 数字
	static TreeNode* newIntNode(string str)
	{
		TreeNode* res = newExprNode(ConstK);
		res->attr.val = stoi(str);
		res->type = Integer;
		return res;
	}

	// 变量
	static TreeNode* newIdNode(string str)
	{
		TreeNode* res = newExprNode(IdK);
		res->type = Void;
		res->attr.name = (char*)(symbolTable.GetID(str)->name.data());
		return res;
	}

	// 单目运算符

	static TreeNode* newUnaryNode(int token, TreeNode* fr)
	{
		TreeNode* t = newOpNode(token);
		t->children[0] = fr;
		return t;
	}

	// 双目运算符

	static TreeNode* newBinaryNode(int token, TreeNode* fr, TreeNode* sc)
	{
		TreeNode* t = newOpNode(token);
		t->children[0] = fr;
		t->children[1] = sc;
		return t;
	}
	
	void printType()
	{
		cout << "Type\t\t";
		switch(this->type) {
			case Integer:
				cout << "Interger\t";
				break;
			case Char:
				cout << "Char\t\t";
				break;
		}
	}

	void printStmt()
	{
		string stmt_list[] = { "If Stmt","While Stmt","For Stmt","Assign Stmt","Input Stmt","Output Stmt","Decl Stmt","Compound Stmt" };
		cout << stmt_list[this->kind.stmt] << "\t\t\t";
	}

	void printExp()
	{
		switch(this->kind.expr) {
			case OpK:
				cout << "Expr\t\t";
				this->printOp();
				break;
			case ConstK:
				this->printConst();
				break;
			case IdK:
				cout << "ID\t\t";
				this->printId();
				break;
		}
	}

	void printOp()
	{
		switch(this->attr.op) {
			case ADD:
				cout << "OP: +\t\t";
				break;
			case SUB:
				cout << "OP: -\t\t";
				break;
			case MUL:
				cout << "OP: *\t\t";
				break;
			case DIV:
				cout << "OP: /\t\t";
				break;
			case MOD:
				cout << "OP: %\t\t";
				break;
			case USUB:
				cout << "OP: -\t\t";
				break;
			case INC:
				cout << "OP: ++\t\t";
				break;
			case DEC:
				cout << "OP: --\t\t";
				break;
			case M_LEFT:
				cout << "OP: <<\t\t";
				break;
			case M_RIGHT:
				cout << "OP: >>\t\t";
				break;
			case EQ:
				cout << "OP: ==\t\t";
				break;
			case GRT:
				cout << "OP: >\t\t";
				break;
			case LET:
				cout << "OP: <\t\t";
				break;
			case GRE:
				cout << "OP: >=\t\t";
				break;
			case LEE:
				cout << "OP: <=\t\t";
				break;
			case NE:
				cout << "OP: !=\t\t";
				break;
			case AND:
				cout << "OP: &&\t\t";
				break;
			case OR:
				cout << "OP: ||\t\t";
				break;
			case NOT:
				cout << "OP: !\t\t";
				break;
			case B_AND:
				cout << "OP: &\t\t";
				break;
			case B_XOR:
				cout << "OP: ^\t\t";
				break;
			case B_OR:
				cout << "OP: |\t\t";
				break;
			case B_NOT:
				cout << "OP: ~\t\t";
				break;
		}
	}

	void printId()
	{
		cout << string(this->attr.name) << "\t\t";
	}

	void printConst()
	{
		switch(this->type) {
			case Char:
				cout << "Char\t\t";
				cout << this->attr.char_val << "\t\t";
				break;
			case Integer:
				cout << "Integer\t\t";
				cout << this->attr.val << "\t\t";
				break;
		}
	}

	void printNode()
	{
		cout << this->num << ":\t";
		switch(this->nodekind) {
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
		cout << "Children: ";
		for(int i=0; i<MAXCHILDREN; i++) {
			if(this->children[i] != NULL)
			{
				cout << " " << this->children[i]->num;
				TreeNode* temp=this->children[i];
				while(temp->sibling!=NULL)
		        {
		            cout << " " << temp->sibling->num;
		            temp=temp->sibling;
		        }
			}
		}

		/*cout<<"    brother:  ";
		TreeNode* temp=this;
		while(temp->sibling!=NULL)
		{
		   cout << " " << temp->sibling->num;
		   temp=temp->sibling;
		}*/

		//if(this->sibling != NULL)
		//	cout << " " << this->sibling->num;

		cout << endl;
	}

	// 打印语法树

	void display()
	{
		for(int i = 0; i < MAXCHILDREN; i++) {
			if(this->children[i] != NULL)
				this->children[i]->display();
		}
		if(this->sibling != NULL)
			this->sibling->display();
		this->printNode();
	}

}*root;


#line 369 "myparser.cpp"
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
#line 345 ".\\myparser.y"

	// place any extra initialisation code here

#line 393 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 350 ".\\myparser.y"

	// place any extra cleanup code here

#line 407 "myparser.cpp"
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
#line 398 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(4 - 4); (*(YYSTYPE YYFAR*)yyvalptr)->display(); 
#line 517 "myparser.cpp"
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
#line 401 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3); 
#line 530 "myparser.cpp"
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
#line 402 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = new TreeNode(); 
#line 543 "myparser.cpp"
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
#line 406 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(CompK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
			(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(2 - 2);
		
#line 560 "myparser.cpp"
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
#line 411 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 573 "myparser.cpp"
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
#line 415 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
		
#line 588 "myparser.cpp"
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
#line 419 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 603 "myparser.cpp"
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
#line 423 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 618 "myparser.cpp"
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
#line 427 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 633 "myparser.cpp"
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
#line 431 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 648 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 435 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 663 "myparser.cpp"
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
#line 439 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 678 "myparser.cpp"
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
#line 443 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
		
#line 693 "myparser.cpp"
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
#line 447 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = new TreeNode();
		
#line 708 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 453 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(DeclK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
			
#line 725 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 461 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new TreeNode();
		(*(YYSTYPE YYFAR*)yyvalptr)->nodekind = TypeK;
		(*(YYSTYPE YYFAR*)yyvalptr)->type = Integer;
	
#line 742 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 467 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new TreeNode();
		(*(YYSTYPE YYFAR*)yyvalptr)->nodekind = TypeK;
		(*(YYSTYPE YYFAR*)yyvalptr)->type = Char;
	
#line 759 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 475 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
			(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(3 - 3);
		
#line 775 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 480 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
			(*(YYSTYPE YYFAR*)yyvalptr)->sibling = yyattribute(3 - 3);
		
#line 791 "myparser.cpp"
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
#line 485 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 806 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 489 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 821 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 495 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newIdNode(token_text);
	
#line 836 "myparser.cpp"
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
#line 501 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(AssignK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
			
#line 853 "myparser.cpp"
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
#line 509 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(ADD,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 868 "myparser.cpp"
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
#line 513 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(SUB,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 883 "myparser.cpp"
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
#line 517 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(MUL,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 898 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 521 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(DIV,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 913 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 525 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(MOD,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 928 "myparser.cpp"
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
#line 529 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(USUB,yyattribute(2 - 2));
		
#line 943 "myparser.cpp"
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
#line 533 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(INC,yyattribute(1 - 2));
		
#line 958 "myparser.cpp"
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
#line 537 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(DEC,yyattribute(1 - 2));
		
#line 973 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 541 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(INC,yyattribute(2 - 2));
		
#line 988 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 545 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(DEC,yyattribute(2 - 2));
		
#line 1003 "myparser.cpp"
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
#line 549 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(M_LEFT,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1018 "myparser.cpp"
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
#line 553 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(M_RIGHT,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1033 "myparser.cpp"
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
#line 557 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(EQ,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1048 "myparser.cpp"
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
#line 561 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(GRT,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1063 "myparser.cpp"
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
#line 565 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(LET,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1078 "myparser.cpp"
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
#line 569 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(GRE,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1093 "myparser.cpp"
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
#line 573 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(LEE,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1108 "myparser.cpp"
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
#line 577 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(NE,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1123 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 581 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(AND,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1138 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 585 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newBinaryNode(OR,yyattribute(1 - 3),yyattribute(3 - 3));
		
#line 1153 "myparser.cpp"
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
#line 589 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(NOT,yyattribute(2 - 2));
		
#line 1168 "myparser.cpp"
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
#line 593 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(B_AND,yyattribute(2 - 2));
		
#line 1183 "myparser.cpp"
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
#line 597 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(B_XOR,yyattribute(2 - 2));
		
#line 1198 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 601 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(B_OR,yyattribute(2 - 2));
		
#line 1213 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 605 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newUnaryNode(B_NOT,yyattribute(2 - 2));
		
#line 1228 "myparser.cpp"
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
#line 609 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1243 "myparser.cpp"
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
#line 613 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1258 "myparser.cpp"
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
#line 619 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1273 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 623 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1288 "myparser.cpp"
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
#line 627 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1303 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 631 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
		
#line 1318 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 637 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newIntNode(token_text);
	
#line 1333 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 643 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newLetterNode(token_text);
		
#line 1348 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 649 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(WhileK);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 5);
			
#line 1365 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 657 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(InK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
		
#line 1381 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 664 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(OutK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
		
#line 1397 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 671 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(IfK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 5);
		
#line 1414 "myparser.cpp"
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
#line 677 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(IfK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 7);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 7);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(7 - 7);
		
#line 1432 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 686 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 9);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 9);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(7 - 9);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(9 - 9);
		
#line 1451 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 694 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 8);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 8);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(8 - 8);
		
#line 1469 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 701 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 8);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(6 - 8);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(8 - 8);
		
#line 1487 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 708 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 7);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(7 - 7);
		
#line 1504 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 714 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(4 - 8);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(6 - 8);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(8 - 8);
		
#line 1522 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 721 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(4 - 7);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(7 - 7);
		
#line 1539 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 727 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(5 - 7);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(7 - 7);
		
#line 1556 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 733 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = TreeNode::newStmtNode(ForK);
			(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(6 - 6);
		
#line 1572 "myparser.cpp"
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
		{ "B_OR", 267 },
		{ "B_XOR", 268 },
		{ "B_NOT", 269 },
		{ "M_LEFT", 270 },
		{ "M_RIGHT", 271 },
		{ "MAIN", 272 },
		{ "INT", 273 },
		{ "CHAR", 274 },
		{ "IF", 275 },
		{ "ELSE", 276 },
		{ "WHILE", 277 },
		{ "FOR", 278 },
		{ "IN", 279 },
		{ "OUT", 280 },
		{ "LETTER", 281 },
		{ "EQ", 282 },
		{ "GRT", 283 },
		{ "LET", 284 },
		{ "GRE", 285 },
		{ "LEE", 286 },
		{ "NE", 287 },
		{ "AND", 288 },
		{ "OR", 289 },
		{ "NOT", 290 },
		{ "LBRACE", 291 },
		{ "RBRACE", 292 },
		{ "LPAREN", 293 },
		{ "RPAREN", 294 },
		{ "SEMICOLON", 295 },
		{ "COMMA", 296 },
		{ "ASSIGN", 297 },
		{ "USUB", 298 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: main",
		"main: MAIN LPAREN RPAREN braced_stmt",
		"braced_stmt: LBRACE comp_stmt RBRACE",
		"braced_stmt: LBRACE RBRACE",
		"comp_stmt: stmt comp_stmt",
		"comp_stmt: stmt",
		"stmt: decl_stmt SEMICOLON",
		"stmt: braced_stmt",
		"stmt: while_stmt",
		"stmt: in_stmt",
		"stmt: out_stmt",
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
		"expr: B_XOR expr",
		"expr: B_OR expr",
		"expr: B_NOT expr",
		"expr: factor",
		"expr: assign_stmt",
		"factor: id",
		"factor: num",
		"factor: letter",
		"factor: LPAREN expr RPAREN",
		"num: NUMBER",
		"letter: LETTER",
		"while_stmt: WHILE LPAREN expr RPAREN stmt",
		"in_stmt: IN LPAREN expr RPAREN SEMICOLON",
		"out_stmt: OUT LPAREN expr RPAREN SEMICOLON",
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
		{ 4, 1, 10 },
		{ 4, 1, 11 },
		{ 4, 2, 12 },
		{ 4, 1, 13 },
		{ 5, 2, 14 },
		{ 6, 1, 15 },
		{ 6, 1, 16 },
		{ 7, 3, 17 },
		{ 7, 3, 18 },
		{ 7, 1, 19 },
		{ 7, 1, 20 },
		{ 8, 1, 21 },
		{ 9, 3, 22 },
		{ 10, 3, 23 },
		{ 10, 3, 24 },
		{ 10, 3, 25 },
		{ 10, 3, 26 },
		{ 10, 3, 27 },
		{ 10, 2, 28 },
		{ 10, 2, 29 },
		{ 10, 2, 30 },
		{ 10, 2, 31 },
		{ 10, 2, 32 },
		{ 10, 3, 33 },
		{ 10, 3, 34 },
		{ 10, 3, 35 },
		{ 10, 3, 36 },
		{ 10, 3, 37 },
		{ 10, 3, 38 },
		{ 10, 3, 39 },
		{ 10, 3, 40 },
		{ 10, 3, 41 },
		{ 10, 3, 42 },
		{ 10, 2, 43 },
		{ 10, 2, 44 },
		{ 10, 2, 45 },
		{ 10, 2, 46 },
		{ 10, 2, 47 },
		{ 10, 1, 48 },
		{ 10, 1, 49 },
		{ 11, 1, 50 },
		{ 11, 1, 51 },
		{ 11, 1, 52 },
		{ 11, 3, 53 },
		{ 12, 1, 54 },
		{ 13, 1, 55 },
		{ 14, 5, 56 },
		{ 15, 5, 57 },
		{ 16, 5, 58 },
		{ 17, 5, 59 },
		{ 17, 7, 60 },
		{ 18, 9, 61 },
		{ 18, 8, 62 },
		{ 18, 8, 63 },
		{ 18, 7, 64 },
		{ 18, 8, 65 },
		{ 18, 7, 66 },
		{ 18, 7, 67 },
		{ 18, 6, 68 }
	};
	yyreduction = reduction;

	yytokenaction_size = 389;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 29, YYAT_SHIFT, 7 },
		{ 29, YYAT_SHIFT, 8 },
		{ 132, YYAT_SHIFT, 139 },
		{ 29, YYAT_SHIFT, 9 },
		{ 123, YYAT_ERROR, 0 },
		{ 123, YYAT_SHIFT, 133 },
		{ 130, YYAT_SHIFT, 137 },
		{ 29, YYAT_SHIFT, 10 },
		{ 29, YYAT_SHIFT, 11 },
		{ 29, YYAT_SHIFT, 12 },
		{ 29, YYAT_SHIFT, 13 },
		{ 29, YYAT_SHIFT, 14 },
		{ 29, YYAT_SHIFT, 15 },
		{ 94, YYAT_SHIFT, 65 },
		{ 94, YYAT_SHIFT, 66 },
		{ 122, YYAT_SHIFT, 131 },
		{ 29, YYAT_SHIFT, 16 },
		{ 29, YYAT_SHIFT, 17 },
		{ 29, YYAT_SHIFT, 18 },
		{ 121, YYAT_SHIFT, 129 },
		{ 29, YYAT_SHIFT, 19 },
		{ 29, YYAT_SHIFT, 20 },
		{ 29, YYAT_SHIFT, 21 },
		{ 29, YYAT_SHIFT, 22 },
		{ 29, YYAT_SHIFT, 23 },
		{ 96, YYAT_SHIFT, 60 },
		{ 96, YYAT_SHIFT, 61 },
		{ 96, YYAT_SHIFT, 62 },
		{ 96, YYAT_SHIFT, 63 },
		{ 96, YYAT_SHIFT, 64 },
		{ 96, YYAT_SHIFT, 65 },
		{ 96, YYAT_SHIFT, 66 },
		{ 145, YYAT_SHIFT, 7 },
		{ 29, YYAT_SHIFT, 24 },
		{ 29, YYAT_SHIFT, 5 },
		{ 145, YYAT_SHIFT, 9 },
		{ 29, YYAT_SHIFT, 26 },
		{ 120, YYAT_SHIFT, 128 },
		{ 29, YYAT_SHIFT, 27 },
		{ 145, YYAT_SHIFT, 10 },
		{ 145, YYAT_SHIFT, 11 },
		{ 145, YYAT_SHIFT, 12 },
		{ 145, YYAT_SHIFT, 13 },
		{ 145, YYAT_SHIFT, 14 },
		{ 145, YYAT_SHIFT, 15 },
		{ 93, YYAT_SHIFT, 65 },
		{ 93, YYAT_SHIFT, 66 },
		{ 117, YYAT_SHIFT, 126 },
		{ 145, YYAT_SHIFT, 16 },
		{ 145, YYAT_SHIFT, 17 },
		{ 145, YYAT_SHIFT, 18 },
		{ 114, YYAT_SHIFT, 125 },
		{ 145, YYAT_SHIFT, 19 },
		{ 145, YYAT_SHIFT, 20 },
		{ 145, YYAT_SHIFT, 21 },
		{ 145, YYAT_SHIFT, 22 },
		{ 145, YYAT_SHIFT, 23 },
		{ 95, YYAT_SHIFT, 60 },
		{ 95, YYAT_SHIFT, 61 },
		{ 95, YYAT_SHIFT, 62 },
		{ 95, YYAT_SHIFT, 63 },
		{ 95, YYAT_SHIFT, 64 },
		{ 95, YYAT_SHIFT, 65 },
		{ 95, YYAT_SHIFT, 66 },
		{ 113, YYAT_SHIFT, 124 },
		{ 145, YYAT_SHIFT, 24 },
		{ 145, YYAT_SHIFT, 5 },
		{ 112, YYAT_SHIFT, 122 },
		{ 145, YYAT_SHIFT, 26 },
		{ 111, YYAT_SHIFT, 121 },
		{ 145, YYAT_SHIFT, 27 },
		{ 141, YYAT_SHIFT, 60 },
		{ 141, YYAT_SHIFT, 61 },
		{ 141, YYAT_SHIFT, 62 },
		{ 141, YYAT_SHIFT, 63 },
		{ 141, YYAT_SHIFT, 64 },
		{ 141, YYAT_SHIFT, 65 },
		{ 141, YYAT_SHIFT, 66 },
		{ 92, YYAT_SHIFT, 65 },
		{ 92, YYAT_SHIFT, 66 },
		{ 79, YYAT_SHIFT, 105 },
		{ 79, YYAT_SHIFT, 82 },
		{ 141, YYAT_SHIFT, 67 },
		{ 141, YYAT_SHIFT, 68 },
		{ 91, YYAT_SHIFT, 62 },
		{ 91, YYAT_SHIFT, 63 },
		{ 91, YYAT_SHIFT, 64 },
		{ 91, YYAT_SHIFT, 65 },
		{ 91, YYAT_SHIFT, 66 },
		{ 90, YYAT_SHIFT, 62 },
		{ 90, YYAT_SHIFT, 63 },
		{ 90, YYAT_SHIFT, 64 },
		{ 90, YYAT_SHIFT, 65 },
		{ 90, YYAT_SHIFT, 66 },
		{ 141, YYAT_SHIFT, 69 },
		{ 141, YYAT_SHIFT, 70 },
		{ 141, YYAT_SHIFT, 71 },
		{ 141, YYAT_SHIFT, 72 },
		{ 141, YYAT_SHIFT, 73 },
		{ 141, YYAT_SHIFT, 74 },
		{ 141, YYAT_SHIFT, 75 },
		{ 141, YYAT_SHIFT, 76 },
		{ 46, YYAT_SHIFT, 65 },
		{ 46, YYAT_SHIFT, 66 },
		{ 45, YYAT_SHIFT, 65 },
		{ 45, YYAT_SHIFT, 66 },
		{ 141, YYAT_SHIFT, 145 },
		{ 107, YYAT_SHIFT, 60 },
		{ 107, YYAT_SHIFT, 61 },
		{ 107, YYAT_SHIFT, 62 },
		{ 107, YYAT_SHIFT, 63 },
		{ 107, YYAT_SHIFT, 64 },
		{ 107, YYAT_SHIFT, 65 },
		{ 107, YYAT_SHIFT, 66 },
		{ 44, YYAT_SHIFT, 65 },
		{ 44, YYAT_SHIFT, 66 },
		{ 110, YYAT_SHIFT, 119 },
		{ 106, YYAT_SHIFT, 8 },
		{ 107, YYAT_SHIFT, 67 },
		{ 107, YYAT_SHIFT, 68 },
		{ 88, YYAT_SHIFT, 114 },
		{ 87, YYAT_SHIFT, 113 },
		{ 86, YYAT_SHIFT, 112 },
		{ 85, YYAT_SHIFT, 110 },
		{ 84, YYAT_SHIFT, 109 },
		{ 83, YYAT_SHIFT, 108 },
		{ 82, YYAT_ERROR, 0 },
		{ 80, YYAT_SHIFT, 106 },
		{ 57, YYAT_SHIFT, 89 },
		{ 53, YYAT_SHIFT, 85 },
		{ 107, YYAT_SHIFT, 69 },
		{ 107, YYAT_SHIFT, 70 },
		{ 107, YYAT_SHIFT, 71 },
		{ 107, YYAT_SHIFT, 72 },
		{ 107, YYAT_SHIFT, 73 },
		{ 107, YYAT_SHIFT, 74 },
		{ 107, YYAT_SHIFT, 75 },
		{ 107, YYAT_SHIFT, 76 },
		{ 104, YYAT_SHIFT, 60 },
		{ 104, YYAT_SHIFT, 61 },
		{ 104, YYAT_SHIFT, 62 },
		{ 104, YYAT_SHIFT, 63 },
		{ 104, YYAT_SHIFT, 64 },
		{ 104, YYAT_SHIFT, 65 },
		{ 104, YYAT_SHIFT, 66 },
		{ 40, YYAT_SHIFT, 82 },
		{ 36, YYAT_SHIFT, 81 },
		{ 34, YYAT_SHIFT, 77 },
		{ 32, YYAT_SHIFT, 59 },
		{ 104, YYAT_SHIFT, 67 },
		{ 104, YYAT_SHIFT, 68 },
		{ 22, YYAT_SHIFT, 55 },
		{ 21, YYAT_SHIFT, 54 },
		{ 20, YYAT_SHIFT, 53 },
		{ 19, YYAT_SHIFT, 52 },
		{ 18, YYAT_SHIFT, 51 },
		{ 5, YYAT_SHIFT, 25 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 104, YYAT_SHIFT, 69 },
		{ 104, YYAT_SHIFT, 70 },
		{ 104, YYAT_SHIFT, 71 },
		{ 104, YYAT_SHIFT, 72 },
		{ 104, YYAT_SHIFT, 73 },
		{ 104, YYAT_SHIFT, 74 },
		{ 104, YYAT_SHIFT, 75 },
		{ 103, YYAT_SHIFT, 60 },
		{ 103, YYAT_SHIFT, 61 },
		{ 103, YYAT_SHIFT, 62 },
		{ 103, YYAT_SHIFT, 63 },
		{ 103, YYAT_SHIFT, 64 },
		{ 103, YYAT_SHIFT, 65 },
		{ 103, YYAT_SHIFT, 66 },
		{ 0, YYAT_SHIFT, 1 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 103, YYAT_SHIFT, 67 },
		{ 103, YYAT_SHIFT, 68 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 103, YYAT_SHIFT, 69 },
		{ 103, YYAT_SHIFT, 70 },
		{ 103, YYAT_SHIFT, 71 },
		{ 103, YYAT_SHIFT, 72 },
		{ 103, YYAT_SHIFT, 73 },
		{ 103, YYAT_SHIFT, 74 },
		{ 49, YYAT_SHIFT, 60 },
		{ 49, YYAT_SHIFT, 61 },
		{ 49, YYAT_SHIFT, 62 },
		{ 49, YYAT_SHIFT, 63 },
		{ 49, YYAT_SHIFT, 64 },
		{ 49, YYAT_SHIFT, 65 },
		{ 49, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 49, YYAT_SHIFT, 67 },
		{ 49, YYAT_SHIFT, 68 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 49, YYAT_SHIFT, 69 },
		{ 49, YYAT_SHIFT, 70 },
		{ 49, YYAT_SHIFT, 71 },
		{ 49, YYAT_SHIFT, 72 },
		{ 49, YYAT_SHIFT, 73 },
		{ 49, YYAT_SHIFT, 74 },
		{ 48, YYAT_SHIFT, 60 },
		{ 48, YYAT_SHIFT, 61 },
		{ 48, YYAT_SHIFT, 62 },
		{ 48, YYAT_SHIFT, 63 },
		{ 48, YYAT_SHIFT, 64 },
		{ 48, YYAT_SHIFT, 65 },
		{ 48, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 48, YYAT_SHIFT, 67 },
		{ 48, YYAT_SHIFT, 68 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 48, YYAT_SHIFT, 69 },
		{ 48, YYAT_SHIFT, 70 },
		{ 48, YYAT_SHIFT, 71 },
		{ 48, YYAT_SHIFT, 72 },
		{ 48, YYAT_SHIFT, 73 },
		{ 48, YYAT_SHIFT, 74 },
		{ 47, YYAT_SHIFT, 60 },
		{ 47, YYAT_SHIFT, 61 },
		{ 47, YYAT_SHIFT, 62 },
		{ 47, YYAT_SHIFT, 63 },
		{ 47, YYAT_SHIFT, 64 },
		{ 47, YYAT_SHIFT, 65 },
		{ 47, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 47, YYAT_SHIFT, 67 },
		{ 47, YYAT_SHIFT, 68 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 47, YYAT_SHIFT, 69 },
		{ 47, YYAT_SHIFT, 70 },
		{ 47, YYAT_SHIFT, 71 },
		{ 47, YYAT_SHIFT, 72 },
		{ 47, YYAT_SHIFT, 73 },
		{ 47, YYAT_SHIFT, 74 },
		{ 102, YYAT_SHIFT, 60 },
		{ 102, YYAT_SHIFT, 61 },
		{ 102, YYAT_SHIFT, 62 },
		{ 102, YYAT_SHIFT, 63 },
		{ 102, YYAT_SHIFT, 64 },
		{ 102, YYAT_SHIFT, 65 },
		{ 102, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 67 },
		{ 102, YYAT_SHIFT, 68 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 97, YYAT_SHIFT, 60 },
		{ 97, YYAT_SHIFT, 61 },
		{ 97, YYAT_SHIFT, 62 },
		{ 97, YYAT_SHIFT, 63 },
		{ 97, YYAT_SHIFT, 64 },
		{ 97, YYAT_SHIFT, 65 },
		{ 97, YYAT_SHIFT, 66 },
		{ 102, YYAT_SHIFT, 70 },
		{ 102, YYAT_SHIFT, 71 },
		{ 102, YYAT_SHIFT, 72 },
		{ 102, YYAT_SHIFT, 73 },
		{ 97, YYAT_SHIFT, 67 },
		{ 97, YYAT_SHIFT, 68 },
		{ 133, YYAT_ERROR, 0 },
		{ 133, YYAT_ERROR, 0 },
		{ 133, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 133, YYAT_ERROR, 0 },
		{ 133, YYAT_ERROR, 0 },
		{ 133, YYAT_ERROR, 0 },
		{ 133, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 97, YYAT_SHIFT, 70 },
		{ 97, YYAT_SHIFT, 71 },
		{ 97, YYAT_SHIFT, 72 },
		{ 97, YYAT_SHIFT, 73 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 133, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 133, YYAT_SHIFT, 140 },
		{ 133, YYAT_ERROR, 0 },
		{ 101, YYAT_SHIFT, 60 },
		{ 101, YYAT_SHIFT, 61 },
		{ 101, YYAT_SHIFT, 62 },
		{ 101, YYAT_SHIFT, 63 },
		{ 101, YYAT_SHIFT, 64 },
		{ 101, YYAT_SHIFT, 65 },
		{ 101, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 101, YYAT_SHIFT, 67 },
		{ 101, YYAT_SHIFT, 68 },
		{ 100, YYAT_SHIFT, 60 },
		{ 100, YYAT_SHIFT, 61 },
		{ 100, YYAT_SHIFT, 62 },
		{ 100, YYAT_SHIFT, 63 },
		{ 100, YYAT_SHIFT, 64 },
		{ 100, YYAT_SHIFT, 65 },
		{ 100, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 100, YYAT_SHIFT, 67 },
		{ 100, YYAT_SHIFT, 68 },
		{ 99, YYAT_SHIFT, 60 },
		{ 99, YYAT_SHIFT, 61 },
		{ 99, YYAT_SHIFT, 62 },
		{ 99, YYAT_SHIFT, 63 },
		{ 99, YYAT_SHIFT, 64 },
		{ 99, YYAT_SHIFT, 65 },
		{ 99, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 99, YYAT_SHIFT, 67 },
		{ 99, YYAT_SHIFT, 68 },
		{ 98, YYAT_SHIFT, 60 },
		{ 98, YYAT_SHIFT, 61 },
		{ 98, YYAT_SHIFT, 62 },
		{ 98, YYAT_SHIFT, 63 },
		{ 98, YYAT_SHIFT, 64 },
		{ 98, YYAT_SHIFT, 65 },
		{ 98, YYAT_SHIFT, 66 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 98, YYAT_SHIFT, 67 },
		{ 98, YYAT_SHIFT, 68 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -97, 1, YYAT_ERROR, 0 },
		{ -133, 1, YYAT_ERROR, 0 },
		{ 159, 1, YYAT_ERROR, 0 },
		{ -136, 1, YYAT_ERROR, 0 },
		{ -134, 1, YYAT_ERROR, 0 },
		{ -136, 1, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -138, 1, YYAT_ERROR, 0 },
		{ -139, 1, YYAT_ERROR, 0 },
		{ -140, 1, YYAT_ERROR, 0 },
		{ -141, 1, YYAT_ERROR, 0 },
		{ -142, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ -257, 1, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -147, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -148, 1, YYAT_DEFAULT, 123 },
		{ 0, 0, YYAT_DEFAULT, 106 },
		{ -146, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ -152, 1, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ -150, 1, YYAT_REDUCE, 29 },
		{ -160, 1, YYAT_REDUCE, 32 },
		{ -162, 1, YYAT_REDUCE, 33 },
		{ -4, 1, YYAT_REDUCE, 45 },
		{ -33, 1, YYAT_REDUCE, 47 },
		{ -62, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ -166, 1, YYAT_DEFAULT, 112 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ -166, 1, YYAT_DEFAULT, 141 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_DEFAULT, 82 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ -216, 1, YYAT_REDUCE, 20 },
		{ -169, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -168, 1, YYAT_DEFAULT, 133 },
		{ -169, 1, YYAT_DEFAULT, 141 },
		{ -170, 1, YYAT_DEFAULT, 141 },
		{ -172, 1, YYAT_DEFAULT, 112 },
		{ -173, 1, YYAT_DEFAULT, 123 },
		{ -173, 1, YYAT_DEFAULT, 141 },
		{ -174, 1, YYAT_DEFAULT, 141 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ -172, 1, YYAT_REDUCE, 24 },
		{ -177, 1, YYAT_REDUCE, 25 },
		{ -186, 1, YYAT_REDUCE, 26 },
		{ -219, 1, YYAT_REDUCE, 27 },
		{ -251, 1, YYAT_REDUCE, 28 },
		{ -202, 1, YYAT_REDUCE, 34 },
		{ -234, 1, YYAT_REDUCE, 35 },
		{ 42, 1, YYAT_REDUCE, 36 },
		{ 117, 1, YYAT_REDUCE, 37 },
		{ 104, 1, YYAT_REDUCE, 38 },
		{ 91, 1, YYAT_REDUCE, 39 },
		{ 78, 1, YYAT_REDUCE, 40 },
		{ 25, 1, YYAT_REDUCE, 41 },
		{ -91, 1, YYAT_REDUCE, 42 },
		{ -121, 1, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_DEFAULT, 106 },
		{ -141, 1, YYAT_ERROR, 0 },
		{ -152, 1, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ -178, 1, YYAT_DEFAULT, 133 },
		{ -226, 1, YYAT_DEFAULT, 123 },
		{ -228, 1, YYAT_DEFAULT, 82 },
		{ -231, 1, YYAT_ERROR, 0 },
		{ -244, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ -229, 1, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ -257, 1, YYAT_DEFAULT, 141 },
		{ -275, 1, YYAT_DEFAULT, 133 },
		{ -279, 1, YYAT_DEFAULT, 133 },
		{ -290, 1, YYAT_DEFAULT, 141 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ -288, 1, YYAT_DEFAULT, 141 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ -292, 1, YYAT_DEFAULT, 141 },
		{ 41, 1, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ -188, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ -225, 1, YYAT_DEFAULT, 106 },
		{ 0, 0, YYAT_REDUCE, 62 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 71;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 145, 28 },
		{ 140, 144 },
		{ 145, 146 },
		{ 145, 32 },
		{ 145, 35 },
		{ 106, 116 },
		{ 106, 79 },
		{ 106, 80 },
		{ 145, 34 },
		{ 29, 58 },
		{ 29, 29 },
		{ 139, 143 },
		{ 145, 31 },
		{ 145, 30 },
		{ 145, 37 },
		{ 145, 33 },
		{ 145, 38 },
		{ 133, 40 },
		{ 133, 41 },
		{ 133, 141 },
		{ 133, 43 },
		{ 133, 42 },
		{ 133, 39 },
		{ 137, 142 },
		{ 131, 138 },
		{ 129, 136 },
		{ 128, 135 },
		{ 126, 134 },
		{ 122, 132 },
		{ 121, 130 },
		{ 119, 127 },
		{ 112, 123 },
		{ 110, 120 },
		{ 109, 118 },
		{ 108, 117 },
		{ 105, 115 },
		{ 85, 111 },
		{ 82, 107 },
		{ 76, 104 },
		{ 75, 103 },
		{ 74, 102 },
		{ 73, 101 },
		{ 72, 100 },
		{ 71, 99 },
		{ 70, 98 },
		{ 69, 97 },
		{ 68, 96 },
		{ 67, 95 },
		{ 64, 94 },
		{ 63, 93 },
		{ 62, 92 },
		{ 61, 91 },
		{ 60, 90 },
		{ 55, 88 },
		{ 54, 87 },
		{ 53, 86 },
		{ 52, 84 },
		{ 51, 83 },
		{ 35, 78 },
		{ 26, 57 },
		{ 24, 56 },
		{ 15, 50 },
		{ 14, 49 },
		{ 13, 48 },
		{ 12, 47 },
		{ 11, 46 },
		{ 10, 45 },
		{ 9, 44 },
		{ 5, 36 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 69, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 67, -1 },
		{ 65, 29 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 133 },
		{ 56, 133 },
		{ 55, 133 },
		{ 54, 133 },
		{ 53, 133 },
		{ 52, 133 },
		{ 51, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, 133 },
		{ 0, -1 },
		{ 49, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 6, 145 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 51, 106 },
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
		{ 47, 133 },
		{ 46, 133 },
		{ 45, 133 },
		{ 44, 133 },
		{ 43, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 42, 133 },
		{ 41, 133 },
		{ 40, 133 },
		{ 39, 133 },
		{ 38, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 133 },
		{ 36, 133 },
		{ 35, 133 },
		{ 34, 133 },
		{ 33, 133 },
		{ 32, 133 },
		{ 31, 133 },
		{ 30, 133 },
		{ 29, 133 },
		{ 28, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 27, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 26, 133 },
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
		{ 0, -1 },
		{ 0, -1 },
		{ 28, 106 },
		{ -2, -1 },
		{ 0, -1 },
		{ 30, 145 },
		{ 29, 145 },
		{ 22, 133 },
		{ 0, -1 },
		{ 21, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 26, 145 },
		{ 0, -1 },
		{ 19, 133 },
		{ 18, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 23, 145 },
		{ 0, -1 },
		{ 22, 145 },
		{ 21, 145 },
		{ 0, -1 },
		{ 20, 145 },
		{ 0, -1 },
		{ 9, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 19, 145 },
		{ 0, -1 },
		{ 7, 145 },
		{ -3, 145 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 133 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 738 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section
int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	freopen("input.txt", "r", stdin);
	if(parser.yycreate(&lexer)) {
		if(lexer.yycreate(&parser))
			n = parser.yyparse();
	}
	return n;
}

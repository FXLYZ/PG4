%{
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

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here
	// virtual int yygettoken();
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

%include {
#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif
}

// place any declarations here
%token NUMBER	//十进制数
%token ID
%token ADD SUB // 加减
%token MUL DIV	//乘除
%token MOD INC DEC
%token B_AND B_OR B_XOR B_NOT M_LEFT M_RIGHT
%token MAIN	INT CHAR IF ELSE WHILE FOR IN OUT
%token LETTER
%token EQ GRT LET GRE LEE NE
%token AND OR NOT 
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON COMMA
%token ASSIGN
%token USUB

//优先级

%right ASSIGN
%left OR
%left AND  
%left B_OR
%left B_XOR
%left B_AND
%left EQ NE
%left GRT LET GRE LEE
%left M_LEFT M_RIGHT
%left ADD SUB
%left MUL DIV MOD
%right USUB
%right INC DEC
%right B_NOT NOT

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here

main:	MAIN LPAREN RPAREN braced_stmt { $$ = $4; $$->display(); }
	;

braced_stmt:	LBRACE comp_stmt RBRACE { $$ = $2; }
			|	LBRACE	RBRACE{ $$ = new TreeNode(); }
			;

comp_stmt:	stmt comp_stmt
		{
			$$ = TreeNode::newStmtNode(CompK);
			$$->children[0] = $1;
			$$->sibling = $2;
		}	
		|	stmt{ $$ = $1; }
		;

stmt: decl_stmt SEMICOLON
		{
			$$ = $1;
		}
		| braced_stmt
		{
			$$ = $1;
		}
		| while_stmt
		{
			$$ = $1;
		}
		| in_stmt
		{
			$$ = $1;
		}
		| out_stmt
		{
			$$ = $1;
		}
		| if_stmt
		{
			$$ = $1;
		}
		| for_stmt
		{
			$$ = $1;
		}
		| expr SEMICOLON
		{
			$$ = $1;
		}
		| SEMICOLON
		{
			$$ = new TreeNode();
		}
		;

decl_stmt: 	type idlist
			{
				$$ = TreeNode::newStmtNode(DeclK);
				$$->children[0] = $1;
				$$->children[1] = $2;
			}
			;

type:	INT
	{
		$$ = new TreeNode();
		$$->nodekind = TypeK;
		$$->type = Integer;
	}
	|	CHAR
	{
		$$ = new TreeNode();
		$$->nodekind = TypeK;
		$$->type = Char;
	}
	;

idlist:	id COMMA idlist
		{
			$$ = $1;
			$$->sibling = $3;
		}
		|	assign_stmt	COMMA idlist
		{
			$$ = $1;
			$$->sibling = $3;
		}
		|	id
		{
			$$ = $1;
		}
		|	assign_stmt
		{
			$$ = $1;
		}
		;

id: ID 
	{
		$$ = TreeNode::newIdNode(token_text);
	}
	;

assign_stmt: id ASSIGN expr
			{
				$$ = TreeNode::newStmtNode(AssignK);
				$$->children[0] = $1;
				$$->children[1] = $3;
			}
			;

expr: expr ADD expr
		{
			$$ = TreeNode::newBinaryNode(ADD,$1,$3);
		}
		| expr SUB expr
		{
			$$ = TreeNode::newBinaryNode(SUB,$1,$3);
		}
		| expr MUL expr
		{
			$$ = TreeNode::newBinaryNode(MUL,$1,$3);
		}
		| expr DIV expr
		{
			$$ = TreeNode::newBinaryNode(DIV,$1,$3);
		}
		| expr MOD expr
		{
			$$ = TreeNode::newBinaryNode(MOD,$1,$3);
		}
		| SUB expr %prec USUB
		{
			$$ = TreeNode::newUnaryNode(USUB,$2);
		}
		| expr INC
		{
			$$ = TreeNode::newUnaryNode(INC,$1);
		}
		| expr DEC
		{
			$$ = TreeNode::newUnaryNode(DEC,$1);
		}
		| INC expr
		{
			$$ = TreeNode::newUnaryNode(INC,$2);
		}
		| DEC expr
		{
			$$ = TreeNode::newUnaryNode(DEC,$2);
		}
		| expr M_LEFT expr
		{
			$$ = TreeNode::newBinaryNode(M_LEFT,$1,$3);
		}
		| expr M_RIGHT expr
		{
			$$ = TreeNode::newBinaryNode(M_RIGHT,$1,$3);
		}
		| expr EQ expr
		{
			$$ = TreeNode::newBinaryNode(EQ,$1,$3);
		}
		| expr GRT expr
		{
			$$ = TreeNode::newBinaryNode(GRT,$1,$3);
		}
		| expr LET expr
		{
			$$ = TreeNode::newBinaryNode(LET,$1,$3);
		}
		| expr GRE expr
		{
			$$ = TreeNode::newBinaryNode(GRE,$1,$3);
		}
		| expr LEE expr
		{
			$$ = TreeNode::newBinaryNode(LEE,$1,$3);
		}
		| expr NE expr
		{
			$$ = TreeNode::newBinaryNode(NE,$1,$3);
		}
		| expr AND expr
		{
			$$ = TreeNode::newBinaryNode(AND,$1,$3);
		}
		| expr OR expr
		{
			$$ = TreeNode::newBinaryNode(OR,$1,$3);
		}
		| NOT expr
		{
			$$ = TreeNode::newUnaryNode(NOT,$2);
		}
		| B_AND expr
		{
			$$ = TreeNode::newUnaryNode(B_AND,$2);
		}
		| B_XOR expr
		{
			$$ = TreeNode::newUnaryNode(B_XOR,$2);
		}
		| B_OR expr
		{
			$$ = TreeNode::newUnaryNode(B_OR,$2);
		}
		| B_NOT expr
		{
			$$ = TreeNode::newUnaryNode(B_NOT,$2);
		}
		| factor
		{
			$$ = $1;
		}
		| assign_stmt
		{
			$$ = $1;
		}
		;

factor: id
		{
			$$ = $1;
		}
		| num
		{
			$$ = $1;
		}
		| letter
		{
			$$ = $1;
		}
		| LPAREN expr RPAREN
		{
			$$ = $2;
		}
		;

num: NUMBER
	{
		$$ = TreeNode::newIntNode(token_text);
	}
	;

letter: LETTER
		{
			$$ = TreeNode::newLetterNode(token_text);
		}
		;

while_stmt: WHILE LPAREN expr RPAREN stmt
			{
				$$ = TreeNode::newStmtNode(WhileK);
				$$->children[0] = $3;
				$$->children[1] = $5;
			}
			;

in_stmt: IN LPAREN expr RPAREN SEMICOLON
		{
			$$ = TreeNode::newStmtNode(InK);
			$$->children[0] = $3;
		}
		;

out_stmt: OUT LPAREN expr RPAREN SEMICOLON
		{
			$$ = TreeNode::newStmtNode(OutK);
			$$->children[0] = $3;
		}
		;

if_stmt: IF LPAREN expr RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(IfK);
			$$->children[0] = $3;
			$$->children[1] = $5;
		}
		| IF LPAREN expr RPAREN stmt ELSE stmt
		{
			$$ = TreeNode::newStmtNode(IfK);
			$$->children[0] = $3;
			$$->children[1] = $5;
			$$->children[2] = $7;
		}
		;

for_stmt: FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(ForK);
			$$->children[0] = $3;
			$$->children[1] = $5;
			$$->children[2] = $7;
			$$->children[3] = $9;
		}
		| FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(ForK);
			$$->children[0] = $3;
			$$->children[1] = $5;
			$$->children[2] = $8;
		}
		| FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(ForK);
			$$->children[0] = $3;
			$$->children[1] = $6;
			$$->children[2] = $8;
		}
		| FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(ForK);
			$$->children[0] = $3;
			$$->children[1] = $7;
		}
		| FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(ForK);
			$$->children[0] = $4;
			$$->children[1] = $6;
			$$->children[2] = $8;
		}
		| FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(ForK);
			$$->children[0] = $4;
			$$->children[1] = $7;
		}
		| FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(ForK);
			$$->children[0] = $5;
			$$->children[1] = $7;
		}
		| FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt
		{
			$$ = TreeNode::newStmtNode(ForK);
			$$->children[0] = $6;
		}
		;
%%

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
#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 42 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 11/21/19
# Time: 00:20:00
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : main $end

    1  main : MAIN LPAREN RPAREN braced_stmt

    2  braced_stmt : LBRACE stmts RBRACE
    3              | LBRACE RBRACE

    4  stmts : stmt stmts
    5        | stmt

    6  stmt : decl_stmt SEMICOLON
    7       | braced_stmt
    8       | while_stmt
    9       | if_stmt
   10       | for_stmt
   11       | expr SEMICOLON
   12       | SEMICOLON

   13  decl_stmt : type idlist

   14  type : INT
   15       | CHAR

   16  idlist : id COMMA idlist
   17         | assign_stmt COMMA idlist
   18         | id
   19         | assign_stmt

   20  id : ID

   21  assign_stmt : id ASSIGN expr

   22  expr : expr ADD expr
   23       | expr SUB expr
   24       | expr MUL expr
   25       | expr DIV expr
   26       | expr MOD expr
   27       | SUB expr
   28       | expr INC
   29       | expr DEC
   30       | INC expr
   31       | DEC expr
   32       | expr M_LEFT expr
   33       | expr M_RIGHT expr
   34       | expr EQ expr
   35       | expr GRT expr
   36       | expr LET expr
   37       | expr GRE expr
   38       | expr LEE expr
   39       | expr NE expr
   40       | expr AND expr
   41       | expr OR expr
   42       | NOT expr
   43       | B_AND expr
   44       | B_EOR expr
   45       | B_IOR expr
   46       | B_OPP expr
   47       | factor
   48       | assign_stmt

   49  factor : id
   50         | num
   51         | letter
   52         | LPAREN expr RPAREN

   53  num : NUMBER

   54  letter : LETTER

   55  while_stmt : WHILE LPAREN expr RPAREN stmt

   56  if_stmt : IF LPAREN expr RPAREN stmt
   57          | IF LPAREN expr RPAREN stmt ELSE stmt

   58  for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt
   59           | FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt
   60           | FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt
   61           | FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt
   62           | FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt
   63           | FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt
   64           | FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt
   65           | FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt


##############################################################################
# States
##############################################################################

state 0
	$accept : . main $end

	MAIN  shift 1

	main  goto 2


state 1
	main : MAIN . LPAREN RPAREN braced_stmt

	LPAREN  shift 3


state 2
	$accept : main . $end  (0)

	$end  accept


state 3
	main : MAIN LPAREN . RPAREN braced_stmt

	RPAREN  shift 4


state 4
	main : MAIN LPAREN RPAREN . braced_stmt

	LBRACE  shift 5

	braced_stmt  goto 6


state 5
	braced_stmt : LBRACE . stmts RBRACE
	braced_stmt : LBRACE . RBRACE

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	RBRACE  shift 23
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 29
	if_stmt  goto 30
	for_stmt  goto 31
	stmts  goto 32
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 6
	main : MAIN LPAREN RPAREN braced_stmt .  (1)

	.  reduce 1


state 7
	num : NUMBER .  (53)

	.  reduce 53


state 8
	id : ID .  (20)

	.  reduce 20


state 9
	expr : SUB . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 40
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 10
	expr : INC . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 41
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 11
	expr : DEC . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 42
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 12
	expr : B_AND . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 43
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 13
	expr : B_IOR . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 44
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 14
	expr : B_EOR . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 45
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 15
	expr : B_OPP . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 46
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 16
	type : INT .  (14)

	.  reduce 14


state 17
	type : CHAR .  (15)

	.  reduce 15


state 18
	if_stmt : IF . LPAREN expr RPAREN stmt
	if_stmt : IF . LPAREN expr RPAREN stmt ELSE stmt

	LPAREN  shift 47


state 19
	while_stmt : WHILE . LPAREN expr RPAREN stmt

	LPAREN  shift 48


state 20
	for_stmt : FOR . LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON SEMICOLON RPAREN stmt

	LPAREN  shift 49


state 21
	letter : LETTER .  (54)

	.  reduce 54


state 22
	expr : NOT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 50
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 23
	braced_stmt : LBRACE RBRACE .  (3)

	.  reduce 3


state 24
	factor : LPAREN . expr RPAREN

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 51
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 25
	stmt : SEMICOLON .  (12)

	.  reduce 12


state 26
	decl_stmt : type . idlist

	ID  shift 8

	idlist  goto 52
	id  goto 53
	assign_stmt  goto 54


state 27
	stmt : while_stmt .  (8)

	.  reduce 8


state 28
	stmt : braced_stmt .  (7)

	.  reduce 7


state 29
	stmts : stmt . stmts
	stmts : stmt .  (5)

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25
	.  reduce 5

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 29
	if_stmt  goto 30
	for_stmt  goto 31
	stmts  goto 55
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 30
	stmt : if_stmt .  (9)

	.  reduce 9


state 31
	stmt : for_stmt .  (10)

	.  reduce 10


state 32
	braced_stmt : LBRACE stmts . RBRACE

	RBRACE  shift 56


state 33
	stmt : decl_stmt . SEMICOLON

	SEMICOLON  shift 57


state 34
	stmt : expr . SEMICOLON
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	SEMICOLON  shift 75


state 35
	assign_stmt : id . ASSIGN expr
	factor : id .  (49)

	ASSIGN  shift 76
	.  reduce 49


state 36
	expr : assign_stmt .  (48)

	.  reduce 48


state 37
	expr : factor .  (47)

	.  reduce 47


state 38
	factor : num .  (50)

	.  reduce 50


state 39
	factor : letter .  (51)

	.  reduce 51


state 40
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : SUB expr .  (27)
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	INC  shift 63
	DEC  shift 64
	.  reduce 27


state 41
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : INC expr .  (30)
	expr : expr . GRT expr

	INC  shift 63
	DEC  shift 64
	.  reduce 30


state 42
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : DEC expr .  (31)
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	INC  shift 63
	DEC  shift 64
	.  reduce 31


state 43
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : B_AND expr .  (43)
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	.  reduce 43


state 44
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : B_IOR expr .  (45)
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	.  reduce 45


state 45
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : B_EOR expr .  (44)
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	.  reduce 44


state 46
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : B_OPP expr .  (46)
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	.  reduce 46


state 47
	if_stmt : IF LPAREN . expr RPAREN stmt
	if_stmt : IF LPAREN . expr RPAREN stmt ELSE stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 77
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 48
	while_stmt : WHILE LPAREN . expr RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 78
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 49
	for_stmt : FOR LPAREN . expr SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON SEMICOLON RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24
	SEMICOLON  shift 79

	expr  goto 80
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 50
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr
	expr : NOT expr .  (42)

	.  reduce 42


state 51
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	factor : LPAREN expr . RPAREN
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	RPAREN  shift 81


state 52
	decl_stmt : type idlist .  (13)

	.  reduce 13


state 53
	idlist : id . COMMA idlist
	idlist : id .  (18)
	assign_stmt : id . ASSIGN expr

	COMMA  shift 82
	ASSIGN  shift 76
	.  reduce 18


state 54
	idlist : assign_stmt . COMMA idlist
	idlist : assign_stmt .  (19)

	COMMA  shift 83
	.  reduce 19


state 55
	stmts : stmt stmts .  (4)

	.  reduce 4


state 56
	braced_stmt : LBRACE stmts RBRACE .  (2)

	.  reduce 2


state 57
	stmt : decl_stmt SEMICOLON .  (6)

	.  reduce 6


state 58
	expr : expr ADD . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 84
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 59
	expr : expr SUB . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 85
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 60
	expr : expr MUL . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 86
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 61
	expr : expr DIV . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 87
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 62
	expr : expr MOD . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 88
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 63
	expr : expr INC .  (28)

	.  reduce 28


state 64
	expr : expr DEC .  (29)

	.  reduce 29


state 65
	expr : expr M_LEFT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 89
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 66
	expr : expr M_RIGHT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 90
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 67
	expr : expr EQ . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 91
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 68
	expr : expr GRT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 92
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 69
	expr : expr LET . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 93
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 70
	expr : expr GRE . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 94
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 71
	expr : expr LEE . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 95
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 72
	expr : expr NE . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 96
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 73
	expr : expr AND . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 97
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 74
	expr : expr OR . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 98
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 75
	stmt : expr SEMICOLON .  (11)

	.  reduce 11


state 76
	assign_stmt : id ASSIGN . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24

	expr  goto 99
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 77
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	if_stmt : IF LPAREN expr . RPAREN stmt
	if_stmt : IF LPAREN expr . RPAREN stmt ELSE stmt
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	RPAREN  shift 100


state 78
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	while_stmt : WHILE LPAREN expr . RPAREN stmt
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	RPAREN  shift 101


state 79
	for_stmt : FOR LPAREN SEMICOLON . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . SEMICOLON RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24
	SEMICOLON  shift 102

	expr  goto 103
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 80
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	for_stmt : FOR LPAREN expr . SEMICOLON expr SEMICOLON RPAREN stmt
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr
	for_stmt : FOR LPAREN expr . SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr . SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr . SEMICOLON SEMICOLON RPAREN stmt

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	SEMICOLON  shift 104


state 81
	factor : LPAREN expr RPAREN .  (52)

	.  reduce 52


state 82
	idlist : id COMMA . idlist

	ID  shift 8

	idlist  goto 105
	id  goto 53
	assign_stmt  goto 54


state 83
	idlist : assign_stmt COMMA . idlist

	ID  shift 8

	idlist  goto 106
	id  goto 53
	assign_stmt  goto 54


state 84
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr ADD expr .  (22)
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	.  reduce 22


state 85
	expr : expr SUB expr .  (23)
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	.  reduce 23


state 86
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr MUL expr .  (24)
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	INC  shift 63
	DEC  shift 64
	.  reduce 24


state 87
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr DIV expr .  (25)
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	INC  shift 63
	DEC  shift 64
	.  reduce 25


state 88
	expr : expr . SUB expr
	expr : expr MOD expr .  (26)
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	INC  shift 63
	DEC  shift 64
	.  reduce 26


state 89
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr M_LEFT expr .  (32)
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	.  reduce 32


state 90
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr M_RIGHT expr .  (33)
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	.  reduce 33


state 91
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr EQ expr .  (34)
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	.  reduce 34


state 92
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr GRT expr .  (35)
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	.  reduce 35


state 93
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr LET expr .  (36)
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	.  reduce 36


state 94
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr GRE expr .  (37)
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	.  reduce 37


state 95
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr LEE expr .  (38)
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	.  reduce 38


state 96
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr NE expr .  (39)
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	.  reduce 39


state 97
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr AND expr .  (40)
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	.  reduce 40


state 98
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr OR expr .  (41)
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	.  reduce 41


state 99
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	assign_stmt : id ASSIGN expr .  (21)
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	.  reduce 21


state 100
	if_stmt : IF LPAREN expr RPAREN . stmt
	if_stmt : IF LPAREN expr RPAREN . stmt ELSE stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 107
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 101
	while_stmt : WHILE LPAREN expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 108
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 102
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON . expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON . RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24
	RPAREN  shift 109

	expr  goto 110
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 103
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr
	for_stmt : FOR LPAREN SEMICOLON expr . SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON expr . SEMICOLON expr RPAREN stmt

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	SEMICOLON  shift 111


state 104
	for_stmt : FOR LPAREN expr SEMICOLON . expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . SEMICOLON RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24
	SEMICOLON  shift 112

	expr  goto 113
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 105
	idlist : id COMMA idlist .  (16)

	.  reduce 16


state 106
	idlist : assign_stmt COMMA idlist .  (17)

	.  reduce 17


107: shift-reduce conflict (shift 114, reduce 56) on ELSE
state 107
	if_stmt : IF LPAREN expr RPAREN stmt .  (56)
	if_stmt : IF LPAREN expr RPAREN stmt . ELSE stmt

	ELSE  shift 114
	.  reduce 56


state 108
	while_stmt : WHILE LPAREN expr RPAREN stmt .  (55)

	.  reduce 55


state 109
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 115
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 110
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr . RPAREN stmt

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	RPAREN  shift 116


state 111
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON . RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON . expr RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24
	RPAREN  shift 117

	expr  goto 118
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 112
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON . expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON . RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24
	RPAREN  shift 119

	expr  goto 120
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 113
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	for_stmt : FOR LPAREN expr SEMICOLON expr . SEMICOLON RPAREN stmt
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr
	for_stmt : FOR LPAREN expr SEMICOLON expr . SEMICOLON expr RPAREN stmt

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	SEMICOLON  shift 121


state 114
	if_stmt : IF LPAREN expr RPAREN stmt ELSE . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 122
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 115
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt .  (65)

	.  reduce 65


state 116
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 123
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 117
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 124
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 118
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr . RPAREN stmt

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	RPAREN  shift 125


state 119
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 126
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 120
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr . RPAREN stmt

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	RPAREN  shift 127


state 121
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON . RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON . expr RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	LETTER  shift 21
	NOT  shift 22
	LPAREN  shift 24
	RPAREN  shift 128

	expr  goto 129
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 122
	if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt .  (57)

	.  reduce 57


state 123
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt .  (64)

	.  reduce 64


state 124
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt .  (63)

	.  reduce 63


state 125
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 130
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 126
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt .  (61)

	.  reduce 61


state 127
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 131
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 128
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 132
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 129
	expr : expr . SUB expr
	expr : expr . MOD expr
	expr : expr . INC
	expr : expr . DEC
	expr : expr . ADD expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . OR expr
	expr : expr . AND expr
	expr : expr . M_LEFT expr
	expr : expr . LEE expr
	expr : expr . LET expr
	expr : expr . NE expr
	expr : expr . EQ expr
	expr : expr . M_RIGHT expr
	expr : expr . GRE expr
	expr : expr . GRT expr
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr . RPAREN stmt

	ADD  shift 58
	SUB  shift 59
	MUL  shift 60
	DIV  shift 61
	MOD  shift 62
	INC  shift 63
	DEC  shift 64
	M_LEFT  shift 65
	M_RIGHT  shift 66
	EQ  shift 67
	GRT  shift 68
	LET  shift 69
	GRE  shift 70
	LEE  shift 71
	NE  shift 72
	AND  shift 73
	OR  shift 74
	RPAREN  shift 133


state 130
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt .  (62)

	.  reduce 62


state 131
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt .  (60)

	.  reduce 60


state 132
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt .  (59)

	.  reduce 59


state 133
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_IOR  shift 13
	B_EOR  shift 14
	B_OPP  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	LETTER  shift 21
	NOT  shift 22
	LBRACE  shift 5
	LPAREN  shift 24
	SEMICOLON  shift 25

	type  goto 26
	while_stmt  goto 27
	braced_stmt  goto 28
	stmt  goto 134
	if_stmt  goto 30
	for_stmt  goto 31
	decl_stmt  goto 33
	expr  goto 34
	id  goto 35
	assign_stmt  goto 36
	factor  goto 37
	num  goto 38
	letter  goto 39


state 134
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt .  (58)

	.  reduce 58


##############################################################################
# Summary
##############################################################################

State 107 contains 1 shift-reduce conflict(s)


42 token(s), 17 nonterminal(s)
66 grammar rule(s), 135 state(s)


##############################################################################
# End of File
##############################################################################

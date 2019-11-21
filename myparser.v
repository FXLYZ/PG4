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
# Time: 16:55:13
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : main $end

    1  main : MAIN LPAREN RPAREN braced_stmt

    2  braced_stmt : LBRACE comp_stmt RBRACE
    3              | LBRACE RBRACE

    4  comp_stmt : stmt comp_stmt
    5            | stmt

    6  stmt : decl_stmt SEMICOLON
    7       | braced_stmt
    8       | while_stmt
    9       | in_stmt
   10       | out_stmt
   11       | if_stmt
   12       | for_stmt
   13       | expr SEMICOLON
   14       | SEMICOLON

   15  decl_stmt : type idlist

   16  type : INT
   17       | CHAR

   18  idlist : id COMMA idlist
   19         | assign_stmt COMMA idlist
   20         | id
   21         | assign_stmt

   22  id : ID

   23  assign_stmt : id ASSIGN expr

   24  expr : expr ADD expr
   25       | expr SUB expr
   26       | expr MUL expr
   27       | expr DIV expr
   28       | expr MOD expr
   29       | SUB expr
   30       | expr INC
   31       | expr DEC
   32       | INC expr
   33       | DEC expr
   34       | expr M_LEFT expr
   35       | expr M_RIGHT expr
   36       | expr EQ expr
   37       | expr GRT expr
   38       | expr LET expr
   39       | expr GRE expr
   40       | expr LEE expr
   41       | expr NE expr
   42       | expr AND expr
   43       | expr OR expr
   44       | NOT expr
   45       | B_AND expr
   46       | B_XOR expr
   47       | B_OR expr
   48       | B_NOT expr
   49       | factor
   50       | assign_stmt

   51  factor : id
   52         | num
   53         | letter
   54         | LPAREN expr RPAREN

   55  num : NUMBER

   56  letter : LETTER

   57  while_stmt : WHILE LPAREN expr RPAREN stmt

   58  in_stmt : IN LPAREN expr RPAREN SEMICOLON

   59  out_stmt : OUT LPAREN expr RPAREN SEMICOLON

   60  if_stmt : IF LPAREN expr RPAREN stmt
   61          | IF LPAREN expr RPAREN stmt ELSE stmt

   62  for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt
   63           | FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt
   64           | FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt
   65           | FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt
   66           | FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt
   67           | FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt
   68           | FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt
   69           | FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt


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
	braced_stmt : LBRACE . comp_stmt RBRACE
	braced_stmt : LBRACE . RBRACE

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	RBRACE  shift 25
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	comp_stmt  goto 33
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 36
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 6
	main : MAIN LPAREN RPAREN braced_stmt .  (1)

	.  reduce 1


state 7
	num : NUMBER .  (55)

	.  reduce 55


state 8
	id : ID .  (22)

	.  reduce 22


state 9
	expr : SUB . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 44
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 10
	expr : INC . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 45
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 11
	expr : DEC . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 46
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 12
	expr : B_AND . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 47
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 13
	expr : B_OR . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 48
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 14
	expr : B_XOR . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 49
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 15
	expr : B_NOT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 50
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 16
	type : INT .  (16)

	.  reduce 16


state 17
	type : CHAR .  (17)

	.  reduce 17


state 18
	if_stmt : IF . LPAREN expr RPAREN stmt
	if_stmt : IF . LPAREN expr RPAREN stmt ELSE stmt

	LPAREN  shift 51


state 19
	while_stmt : WHILE . LPAREN expr RPAREN stmt

	LPAREN  shift 52


state 20
	for_stmt : FOR . LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR . LPAREN SEMICOLON SEMICOLON RPAREN stmt

	LPAREN  shift 53


state 21
	in_stmt : IN . LPAREN expr RPAREN SEMICOLON

	LPAREN  shift 54


state 22
	out_stmt : OUT . LPAREN expr RPAREN SEMICOLON

	LPAREN  shift 55


state 23
	letter : LETTER .  (56)

	.  reduce 56


state 24
	expr : NOT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 56
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 25
	braced_stmt : LBRACE RBRACE .  (3)

	.  reduce 3


state 26
	factor : LPAREN . expr RPAREN

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 57
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 27
	stmt : SEMICOLON .  (14)

	.  reduce 14


state 28
	stmt : decl_stmt . SEMICOLON

	SEMICOLON  shift 58


state 29
	stmt : expr . SEMICOLON
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	SEMICOLON  shift 76


state 30
	decl_stmt : type . idlist

	ID  shift 8

	idlist  goto 77
	id  goto 78
	assign_stmt  goto 79


state 31
	stmt : braced_stmt .  (7)

	.  reduce 7


state 32
	stmt : in_stmt .  (9)

	.  reduce 9


state 33
	braced_stmt : LBRACE comp_stmt . RBRACE

	RBRACE  shift 80


state 34
	stmt : while_stmt .  (8)

	.  reduce 8


state 35
	stmt : out_stmt .  (10)

	.  reduce 10


state 36
	comp_stmt : stmt . comp_stmt
	comp_stmt : stmt .  (5)

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27
	.  reduce 5

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	comp_stmt  goto 81
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 36
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 37
	stmt : for_stmt .  (12)

	.  reduce 12


state 38
	stmt : if_stmt .  (11)

	.  reduce 11


state 39
	factor : letter .  (53)

	.  reduce 53


state 40
	assign_stmt : id . ASSIGN expr
	factor : id .  (51)

	ASSIGN  shift 82
	.  reduce 51


state 41
	expr : assign_stmt .  (50)

	.  reduce 50


state 42
	expr : factor .  (49)

	.  reduce 49


state 43
	factor : num .  (52)

	.  reduce 52


state 44
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : SUB expr .  (29)
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	INC  shift 64
	DEC  shift 65
	.  reduce 29


state 45
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : INC expr .  (32)
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	INC  shift 64
	DEC  shift 65
	.  reduce 32


state 46
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr
	expr : DEC expr .  (33)

	INC  shift 64
	DEC  shift 65
	.  reduce 33


state 47
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : B_AND expr .  (45)
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	.  reduce 45


state 48
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : B_OR expr .  (47)
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	.  reduce 47


state 49
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : B_XOR expr .  (46)
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	.  reduce 46


state 50
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : B_NOT expr .  (48)
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	.  reduce 48


state 51
	if_stmt : IF LPAREN . expr RPAREN stmt
	if_stmt : IF LPAREN . expr RPAREN stmt ELSE stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 83
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 52
	while_stmt : WHILE LPAREN . expr RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 84
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 53
	for_stmt : FOR LPAREN . expr SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . expr SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN . SEMICOLON SEMICOLON RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26
	SEMICOLON  shift 85

	expr  goto 86
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 54
	in_stmt : IN LPAREN . expr RPAREN SEMICOLON

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 87
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 55
	out_stmt : OUT LPAREN . expr RPAREN SEMICOLON

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 88
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 56
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : NOT expr .  (44)
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	.  reduce 44


state 57
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	factor : LPAREN expr . RPAREN
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 89


state 58
	stmt : decl_stmt SEMICOLON .  (6)

	.  reduce 6


state 59
	expr : expr ADD . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 90
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 60
	expr : expr SUB . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 91
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 61
	expr : expr MUL . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 92
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 62
	expr : expr DIV . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 93
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 63
	expr : expr MOD . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 94
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 64
	expr : expr INC .  (30)

	.  reduce 30


state 65
	expr : expr DEC .  (31)

	.  reduce 31


state 66
	expr : expr M_LEFT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 95
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 67
	expr : expr M_RIGHT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 96
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 68
	expr : expr EQ . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 97
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 69
	expr : expr GRT . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 98
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 70
	expr : expr LET . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 99
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 71
	expr : expr GRE . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 100
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 72
	expr : expr LEE . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 101
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 73
	expr : expr NE . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 102
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 74
	expr : expr AND . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 103
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 75
	expr : expr OR . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 104
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 76
	stmt : expr SEMICOLON .  (13)

	.  reduce 13


state 77
	decl_stmt : type idlist .  (15)

	.  reduce 15


state 78
	assign_stmt : id . ASSIGN expr
	idlist : id .  (20)
	idlist : id . COMMA idlist

	COMMA  shift 105
	ASSIGN  shift 82
	.  reduce 20


state 79
	idlist : assign_stmt . COMMA idlist
	idlist : assign_stmt .  (21)

	COMMA  shift 106
	.  reduce 21


state 80
	braced_stmt : LBRACE comp_stmt RBRACE .  (2)

	.  reduce 2


state 81
	comp_stmt : stmt comp_stmt .  (4)

	.  reduce 4


state 82
	assign_stmt : id ASSIGN . expr

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26

	expr  goto 107
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 83
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	if_stmt : IF LPAREN expr . RPAREN stmt
	if_stmt : IF LPAREN expr . RPAREN stmt ELSE stmt
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 108


state 84
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	while_stmt : WHILE LPAREN expr . RPAREN stmt
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 109


state 85
	for_stmt : FOR LPAREN SEMICOLON . expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . expr SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON . SEMICOLON RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26
	SEMICOLON  shift 110

	expr  goto 111
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 86
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	for_stmt : FOR LPAREN expr . SEMICOLON expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr . SEMICOLON SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr . SEMICOLON SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN expr . SEMICOLON expr SEMICOLON RPAREN stmt
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	SEMICOLON  shift 112


state 87
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	in_stmt : IN LPAREN expr . RPAREN SEMICOLON
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 113


state 88
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	out_stmt : OUT LPAREN expr . RPAREN SEMICOLON
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 114


state 89
	factor : LPAREN expr RPAREN .  (54)

	.  reduce 54


state 90
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr ADD expr .  (24)
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	.  reduce 24


state 91
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr SUB expr .  (25)
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	.  reduce 25


state 92
	expr : expr . INC
	expr : expr . DEC
	expr : expr MUL expr .  (26)
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	INC  shift 64
	DEC  shift 65
	.  reduce 26


state 93
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr DIV expr .  (27)
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	INC  shift 64
	DEC  shift 65
	.  reduce 27


state 94
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr MOD expr .  (28)
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	INC  shift 64
	DEC  shift 65
	.  reduce 28


state 95
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr M_LEFT expr .  (34)
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	.  reduce 34


state 96
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr M_RIGHT expr .  (35)
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	.  reduce 35


state 97
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr EQ expr .  (36)
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	.  reduce 36


state 98
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr GRT expr .  (37)
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	.  reduce 37


state 99
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr LET expr .  (38)
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	.  reduce 38


state 100
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr GRE expr .  (39)
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	.  reduce 39


state 101
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr LEE expr .  (40)
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	.  reduce 40


state 102
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr NE expr .  (41)
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	.  reduce 41


state 103
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr AND expr .  (42)
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	.  reduce 42


state 104
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr OR expr .  (43)
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	.  reduce 43


state 105
	idlist : id COMMA . idlist

	ID  shift 8

	idlist  goto 115
	id  goto 78
	assign_stmt  goto 79


state 106
	idlist : assign_stmt COMMA . idlist

	ID  shift 8

	idlist  goto 116
	id  goto 78
	assign_stmt  goto 79


state 107
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	assign_stmt : id ASSIGN expr .  (23)
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	.  reduce 23


state 108
	if_stmt : IF LPAREN expr RPAREN . stmt
	if_stmt : IF LPAREN expr RPAREN . stmt ELSE stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 117
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 109
	while_stmt : WHILE LPAREN expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 118
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 110
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON . expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON . RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26
	RPAREN  shift 119

	expr  goto 120
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 111
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	for_stmt : FOR LPAREN SEMICOLON expr . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON expr . SEMICOLON RPAREN stmt
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	SEMICOLON  shift 121


state 112
	for_stmt : FOR LPAREN expr SEMICOLON . expr SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . SEMICOLON RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON . expr SEMICOLON RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26
	SEMICOLON  shift 122

	expr  goto 123
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 113
	in_stmt : IN LPAREN expr RPAREN . SEMICOLON

	SEMICOLON  shift 124


state 114
	out_stmt : OUT LPAREN expr RPAREN . SEMICOLON

	SEMICOLON  shift 125


state 115
	idlist : id COMMA idlist .  (18)

	.  reduce 18


state 116
	idlist : assign_stmt COMMA idlist .  (19)

	.  reduce 19


117: shift-reduce conflict (shift 126, reduce 60) on ELSE
state 117
	if_stmt : IF LPAREN expr RPAREN stmt .  (60)
	if_stmt : IF LPAREN expr RPAREN stmt . ELSE stmt

	ELSE  shift 126
	.  reduce 60


state 118
	while_stmt : WHILE LPAREN expr RPAREN stmt .  (57)

	.  reduce 57


state 119
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 127
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 120
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr . RPAREN stmt

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 128


state 121
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON . expr RPAREN stmt
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON . RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26
	RPAREN  shift 129

	expr  goto 130
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 122
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON . expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON . RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26
	RPAREN  shift 131

	expr  goto 132
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 123
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	for_stmt : FOR LPAREN expr SEMICOLON expr . SEMICOLON expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON expr . SEMICOLON RPAREN stmt
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	SEMICOLON  shift 133


state 124
	in_stmt : IN LPAREN expr RPAREN SEMICOLON .  (58)

	.  reduce 58


state 125
	out_stmt : OUT LPAREN expr RPAREN SEMICOLON .  (59)

	.  reduce 59


state 126
	if_stmt : IF LPAREN expr RPAREN stmt ELSE . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 134
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 127
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt .  (69)

	.  reduce 69


state 128
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 135
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 129
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 136
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 130
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr . RPAREN stmt
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 137


state 131
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 138
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 132
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr . RPAREN stmt
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 139


state 133
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON . expr RPAREN stmt
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON . RPAREN stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	LETTER  shift 23
	NOT  shift 24
	LPAREN  shift 26
	RPAREN  shift 140

	expr  goto 141
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 134
	if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt .  (61)

	.  reduce 61


state 135
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt .  (68)

	.  reduce 68


state 136
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt .  (67)

	.  reduce 67


state 137
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 142
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 138
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt .  (65)

	.  reduce 65


state 139
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 143
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 140
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 144
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 141
	expr : expr . INC
	expr : expr . DEC
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . OR expr
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr . RPAREN stmt
	expr : expr . GRT expr
	expr : expr . LEE expr
	expr : expr . AND expr
	expr : expr . LET expr
	expr : expr . GRE expr
	expr : expr . EQ expr
	expr : expr . NE expr
	expr : expr . M_LEFT expr
	expr : expr . M_RIGHT expr

	ADD  shift 59
	SUB  shift 60
	MUL  shift 61
	DIV  shift 62
	MOD  shift 63
	INC  shift 64
	DEC  shift 65
	M_LEFT  shift 66
	M_RIGHT  shift 67
	EQ  shift 68
	GRT  shift 69
	LET  shift 70
	GRE  shift 71
	LEE  shift 72
	NE  shift 73
	AND  shift 74
	OR  shift 75
	RPAREN  shift 145


state 142
	for_stmt : FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt .  (66)

	.  reduce 66


state 143
	for_stmt : FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt .  (64)

	.  reduce 64


state 144
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt .  (63)

	.  reduce 63


state 145
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN . stmt

	NUMBER  shift 7
	ID  shift 8
	SUB  shift 9
	INC  shift 10
	DEC  shift 11
	B_AND  shift 12
	B_OR  shift 13
	B_XOR  shift 14
	B_NOT  shift 15
	INT  shift 16
	CHAR  shift 17
	IF  shift 18
	WHILE  shift 19
	FOR  shift 20
	IN  shift 21
	OUT  shift 22
	LETTER  shift 23
	NOT  shift 24
	LBRACE  shift 5
	LPAREN  shift 26
	SEMICOLON  shift 27

	decl_stmt  goto 28
	expr  goto 29
	type  goto 30
	braced_stmt  goto 31
	in_stmt  goto 32
	while_stmt  goto 34
	out_stmt  goto 35
	stmt  goto 146
	for_stmt  goto 37
	if_stmt  goto 38
	letter  goto 39
	id  goto 40
	assign_stmt  goto 41
	factor  goto 42
	num  goto 43


state 146
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt .  (62)

	.  reduce 62


##############################################################################
# Summary
##############################################################################

State 117 contains 1 shift-reduce conflict(s)


44 token(s), 19 nonterminal(s)
70 grammar rule(s), 147 state(s)


##############################################################################
# End of File
##############################################################################

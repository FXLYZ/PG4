#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 23 of your 30 day trial period.
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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 11/21/19
# Time: 19:05:21
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  "\n"

    2  "main"

    3  "int"

    4  "char"

    5  "if"

    6  "else"

    7  "while"

    8  "for"

    9  "input"

   10  "output"

   11  '[^'\n]'

   12  [A-Za-z_][A-Za-z0-9_]*

   13  ([1-9][0-9]*)|0

   14  \{

   15  \}

   16  \(

   17  \)

   18  "="

   19  "+"

   20  "-"

   21  "*"

   22  "/"

   23  "%"

   24  "++"

   25  "--"

   26  "&"

   27  "|"

   28  "^"

   29  "~"

   30  "<<"

   31  ">>"

   32  "=="

   33  ">"

   34  "<"

   35  ">="

   36  "<="

   37  "!="

   38  "&&"

   39  "||"

   40  "!"

   41  ","

   42  ";"

   43  \/\*(.|[\r\n])*?\*\/

   44  \/\/[^\n]*

   45  [ \t]*


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x25               goto 6
	0x26               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2f               goto 15
	0x30               goto 16
	0x31 - 0x39 (9)    goto 17
	0x3b               goto 18
	0x3c               goto 19
	0x3d               goto 20
	0x3e               goto 21
	0x41 - 0x5a (26)   goto 22
	0x5e               goto 23
	0x5f               goto 22
	0x61 - 0x62 (2)    goto 22
	0x63               goto 24
	0x64               goto 22
	0x65               goto 25
	0x66               goto 26
	0x67 - 0x68 (2)    goto 22
	0x69               goto 27
	0x6a - 0x6c (3)    goto 22
	0x6d               goto 28
	0x6e               goto 22
	0x6f               goto 29
	0x70 - 0x76 (7)    goto 22
	0x77               goto 30
	0x78 - 0x7a (3)    goto 22
	0x7b               goto 31
	0x7c               goto 32
	0x7d               goto 33
	0x7e               goto 34


state 2
	^INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x25               goto 6
	0x26               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2f               goto 15
	0x30               goto 16
	0x31 - 0x39 (9)    goto 17
	0x3b               goto 18
	0x3c               goto 19
	0x3d               goto 20
	0x3e               goto 21
	0x41 - 0x5a (26)   goto 22
	0x5e               goto 23
	0x5f               goto 22
	0x61 - 0x62 (2)    goto 22
	0x63               goto 24
	0x64               goto 22
	0x65               goto 25
	0x66               goto 26
	0x67 - 0x68 (2)    goto 22
	0x69               goto 27
	0x6a - 0x6c (3)    goto 22
	0x6d               goto 28
	0x6e               goto 22
	0x6f               goto 29
	0x70 - 0x76 (7)    goto 22
	0x77               goto 30
	0x78 - 0x7a (3)    goto 22
	0x7b               goto 31
	0x7c               goto 32
	0x7d               goto 33
	0x7e               goto 34


state 3
	0x09               goto 3
	0x20               goto 3

	match 45


state 4
	match 1


state 5
	0x3d               goto 35

	match 40


state 6
	match 23


state 7
	0x26               goto 36

	match 26


state 8
	0x00 - 0x09 (10)   goto 37
	0x0b - 0x26 (28)   goto 37
	0x28 - 0xff (216)  goto 37


state 9
	match 16


state 10
	match 17


state 11
	match 21


state 12
	0x2b               goto 38

	match 19


state 13
	match 41


state 14
	0x2d               goto 39

	match 20


state 15
	0x2a               goto 40
	0x2f               goto 41

	match 22


state 16
	match 13


state 17
	0x30 - 0x39 (10)   goto 17

	match 13


state 18
	match 42


state 19
	0x3c               goto 42
	0x3d               goto 43

	match 34


state 20
	0x3d               goto 44

	match 18


state 21
	0x3d               goto 45
	0x3e               goto 46

	match 33


state 22
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 12


state 23
	match 28


state 24
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x67 (7)    goto 22
	0x68               goto 47
	0x69 - 0x7a (18)   goto 22

	match 12


state 25
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 48
	0x6d - 0x7a (14)   goto 22

	match 12


state 26
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 49
	0x70 - 0x7a (11)   goto 22

	match 12


state 27
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x65 (5)    goto 22
	0x66               goto 50
	0x67 - 0x6d (7)    goto 22
	0x6e               goto 51
	0x6f - 0x7a (12)   goto 22

	match 12


state 28
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61               goto 52
	0x62 - 0x7a (25)   goto 22

	match 12


state 29
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 53
	0x76 - 0x7a (5)    goto 22

	match 12


state 30
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x67 (7)    goto 22
	0x68               goto 54
	0x69 - 0x7a (18)   goto 22

	match 12


state 31
	match 14


state 32
	0x7c               goto 55

	match 27


state 33
	match 15


state 34
	match 29


state 35
	match 37


state 36
	match 38


state 37
	0x27               goto 56


state 38
	match 24


state 39
	match 25


state 40
	0x00 - 0x29 (42)   goto 40
	0x2a               goto 57
	0x2b - 0xff (213)  goto 40


state 41
	0x00 - 0x09 (10)   goto 41
	0x0b - 0xff (245)  goto 41

	match 44


state 42
	match 30


state 43
	match 36


state 44
	match 32


state 45
	match 35


state 46
	match 31


state 47
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61               goto 58
	0x62 - 0x7a (25)   goto 22

	match 12


state 48
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x72 (18)   goto 22
	0x73               goto 59
	0x74 - 0x7a (7)    goto 22

	match 12


state 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 60
	0x73 - 0x7a (8)    goto 22

	match 12


state 50
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 5


state 51
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6f (15)   goto 22
	0x70               goto 61
	0x71 - 0x73 (3)    goto 22
	0x74               goto 62
	0x75 - 0x7a (6)    goto 22

	match 12


state 52
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 63
	0x6a - 0x7a (17)   goto 22

	match 12


state 53
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 64
	0x75 - 0x7a (6)    goto 22

	match 12


state 54
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 65
	0x6a - 0x7a (17)   goto 22

	match 12


state 55
	match 39


state 56
	match 11


state 57
	0x00 - 0x29 (42)   goto 40
	0x2a               goto 57
	0x2b - 0x2e (4)    goto 40
	0x2f               goto 66
	0x30 - 0xff (208)  goto 40


state 58
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 67
	0x73 - 0x7a (8)    goto 22

	match 12


state 59
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 68
	0x66 - 0x7a (21)   goto 22

	match 12


state 60
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 8


state 61
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 69
	0x76 - 0x7a (5)    goto 22

	match 12


state 62
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 3


state 63
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 70
	0x6f - 0x7a (12)   goto 22

	match 12


state 64
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6f (15)   goto 22
	0x70               goto 71
	0x71 - 0x7a (10)   goto 22

	match 12


state 65
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 72
	0x6d - 0x7a (14)   goto 22

	match 12


state 66
	0x00 - 0x29 (42)   goto 40
	0x2a               goto 57
	0x2b - 0xff (213)  goto 40

	match 43


state 67
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 4


state 68
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 6


state 69
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 73
	0x75 - 0x7a (6)    goto 22

	match 12


state 70
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 2


state 71
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 74
	0x76 - 0x7a (5)    goto 22

	match 12


state 72
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 75
	0x66 - 0x7a (21)   goto 22

	match 12


state 73
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 9


state 74
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 76
	0x75 - 0x7a (6)    goto 22

	match 12


state 75
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 7


state 76
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 10


#############################################################################
# Summary
#############################################################################

1 start state(s)
45 expression(s), 76 state(s)


#############################################################################
# End of File
#############################################################################

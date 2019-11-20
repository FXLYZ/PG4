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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 11/21/19
# Time: 00:20:00
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  " "

    2  "\n"

    3  "\t"

4: expression is never matched
    4  ""

    5  "main"

    6  "int"

    7  "char"

    8  "if"

    9  "else"

   10  "while"

   11  "for"

   12  \"[^\"]*\"

   13  '[^'\n]'

   14  (\/\*(".*"|[^\*"]|(\*)+[^\/])*(\*)*\*\/)|(\/\/[^\n]*)

   15  \/\/.*\n

   16  [_a-zA-Z][_a-zA-Z0-9]*

   17  [0-9]+

   18  "{"

   19  "}"

   20  "("

   21  ")"

   22  "["

   23  "]"

   24  "="

   25  "+"

   26  "-"

   27  "*"

   28  "/"

   29  "%"

   30  "++"

   31  "--"

   32  "&"

   33  "|"

   34  "^"

   35  "~"

   36  "<<"

   37  ">>"

   38  "=="

   39  ">"

   40  "<"

   41  ">="

   42  "<="

   43  "!="

   44  "&&"

   45  "||"

   46  "!"

   47  ","

   48  ";"


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 5
	0x21               goto 6
	0x22               goto 7
	0x25               goto 8
	0x26               goto 9
	0x27               goto 10
	0x28               goto 11
	0x29               goto 12
	0x2a               goto 13
	0x2b               goto 14
	0x2c               goto 15
	0x2d               goto 16
	0x2f               goto 17
	0x30 - 0x39 (10)   goto 18
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x41 - 0x5a (26)   goto 23
	0x5b               goto 24
	0x5d               goto 25
	0x5e               goto 26
	0x5f               goto 23
	0x61 - 0x62 (2)    goto 23
	0x63               goto 27
	0x64               goto 23
	0x65               goto 28
	0x66               goto 29
	0x67 - 0x68 (2)    goto 23
	0x69               goto 30
	0x6a - 0x6c (3)    goto 23
	0x6d               goto 31
	0x6e - 0x76 (9)    goto 23
	0x77               goto 32
	0x78 - 0x7a (3)    goto 23
	0x7b               goto 33
	0x7c               goto 34
	0x7d               goto 35
	0x7e               goto 36


state 2
	^INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 5
	0x21               goto 6
	0x22               goto 7
	0x25               goto 8
	0x26               goto 9
	0x27               goto 10
	0x28               goto 11
	0x29               goto 12
	0x2a               goto 13
	0x2b               goto 14
	0x2c               goto 15
	0x2d               goto 16
	0x2f               goto 17
	0x30 - 0x39 (10)   goto 18
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x41 - 0x5a (26)   goto 23
	0x5b               goto 24
	0x5d               goto 25
	0x5e               goto 26
	0x5f               goto 23
	0x61 - 0x62 (2)    goto 23
	0x63               goto 27
	0x64               goto 23
	0x65               goto 28
	0x66               goto 29
	0x67 - 0x68 (2)    goto 23
	0x69               goto 30
	0x6a - 0x6c (3)    goto 23
	0x6d               goto 31
	0x6e - 0x76 (9)    goto 23
	0x77               goto 32
	0x78 - 0x7a (3)    goto 23
	0x7b               goto 33
	0x7c               goto 34
	0x7d               goto 35
	0x7e               goto 36


state 3
	match 3


state 4
	match 2


state 5
	match 1


state 6
	0x3d               goto 37

	match 46


state 7
	0x00 - 0x21 (34)   goto 7
	0x22               goto 38
	0x23 - 0xff (221)  goto 7


state 8
	match 29


state 9
	0x26               goto 39

	match 32


state 10
	0x00 - 0x09 (10)   goto 40
	0x0b - 0x26 (28)   goto 40
	0x28 - 0xff (216)  goto 40


state 11
	match 20


state 12
	match 21


state 13
	match 27


state 14
	0x2b               goto 41

	match 25


state 15
	match 47


state 16
	0x2d               goto 42

	match 26


state 17
	0x2a               goto 43
	0x2f               goto 44

	match 28


state 18
	0x30 - 0x39 (10)   goto 18

	match 17


state 19
	match 48


state 20
	0x3c               goto 45
	0x3d               goto 46

	match 40


state 21
	0x3d               goto 47

	match 24


state 22
	0x3d               goto 48
	0x3e               goto 49

	match 39


state 23
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 16


state 24
	match 22


state 25
	match 23


state 26
	match 34


state 27
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x67 (7)    goto 23
	0x68               goto 50
	0x69 - 0x7a (18)   goto 23

	match 16


state 28
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 51
	0x6d - 0x7a (14)   goto 23

	match 16


state 29
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 52
	0x70 - 0x7a (11)   goto 23

	match 16


state 30
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x65 (5)    goto 23
	0x66               goto 53
	0x67 - 0x6d (7)    goto 23
	0x6e               goto 54
	0x6f - 0x7a (12)   goto 23

	match 16


state 31
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61               goto 55
	0x62 - 0x7a (25)   goto 23

	match 16


state 32
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x67 (7)    goto 23
	0x68               goto 56
	0x69 - 0x7a (18)   goto 23

	match 16


state 33
	match 18


state 34
	0x7c               goto 57

	match 33


state 35
	match 19


state 36
	match 35


state 37
	match 43


state 38
	match 12


state 39
	match 44


state 40
	0x27               goto 58


state 41
	match 30


state 42
	match 31


state 43
	0x00 - 0x21 (34)   goto 43
	0x23 - 0x29 (7)    goto 43
	0x2a               goto 59
	0x2b - 0x2d (3)    goto 43
	0x2e               goto 60
	0x2f - 0xff (209)  goto 43


state 44
	0x00 - 0x09 (10)   goto 44
	0x0a               goto 61
	0x0b - 0xff (245)  goto 44

	match 14


state 45
	match 36


state 46
	match 42


state 47
	match 38


state 48
	match 41


state 49
	match 37


state 50
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61               goto 62
	0x62 - 0x7a (25)   goto 23

	match 16


state 51
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x72 (18)   goto 23
	0x73               goto 63
	0x74 - 0x7a (7)    goto 23

	match 16


state 52
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 64
	0x73 - 0x7a (8)    goto 23

	match 16


state 53
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 8


state 54
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 65
	0x75 - 0x7a (6)    goto 23

	match 16


state 55
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 66
	0x6a - 0x7a (17)   goto 23

	match 16


state 56
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 67
	0x6a - 0x7a (17)   goto 23

	match 16


state 57
	match 45


state 58
	match 13


state 59
	0x00 - 0x29 (42)   goto 43
	0x2a               goto 68
	0x2b - 0x2e (4)    goto 43
	0x2f               goto 69
	0x30 - 0xff (208)  goto 43


state 60
	0x00 - 0x21 (34)   goto 43
	0x23 - 0x29 (7)    goto 43
	0x2a               goto 68
	0x2b - 0x2d (3)    goto 43
	0x2e               goto 60
	0x2f - 0xff (209)  goto 43


state 61
	match 15


state 62
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 70
	0x73 - 0x7a (8)    goto 23

	match 16


state 63
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 71
	0x66 - 0x7a (21)   goto 23

	match 16


state 64
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 11


state 65
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 6


state 66
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6d (13)   goto 23
	0x6e               goto 72
	0x6f - 0x7a (12)   goto 23

	match 16


state 67
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 73
	0x6d - 0x7a (14)   goto 23

	match 16


state 68
	0x00 - 0x21 (34)   goto 43
	0x22               goto 43
	0x23 - 0x29 (7)    goto 43
	0x2a               goto 68
	0x2b - 0x2d (3)    goto 43
	0x2e               goto 60
	0x2f               goto 74
	0x30 - 0xff (208)  goto 43


state 69
	match 14


state 70
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 7


state 71
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 9


state 72
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 5


state 73
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 75
	0x66 - 0x7a (21)   goto 23

	match 16


state 74
	0x00 - 0x21 (34)   goto 43
	0x23 - 0x29 (7)    goto 43
	0x2a               goto 59
	0x2b - 0x2d (3)    goto 43
	0x2e               goto 60
	0x2f - 0xff (209)  goto 43

	match 14


state 75
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 10


#############################################################################
# Summary
#############################################################################

Expression 4 is never matched


1 start state(s)
48 expression(s), 75 state(s)


#############################################################################
# End of File
#############################################################################

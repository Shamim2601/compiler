.MODEL SMALL
.STACK 400H
.DATA
NUMBER_STRING DB '00000$'
t1 DW ?
t2 DW ?
t3 DW ?

.CODE
main PROC	;func_definition
MOV AX,@DATA 
MOV DS,AX	;initializing data segment

L1:	;Scope 1.1 starts
PUSH t1
PUSH 3
POP BX	;variable ASSIGNOP logic_expression
POP AX
MOV t1, BX
PUSH t2
PUSH 8
POP BX	;variable ASSIGNOP logic_expression
POP AX
MOV t2, BX
PUSH t1
PUSH 3
POP BX	;simple_expression RELOP simple_expression
POP AX
CMP AX, BX
JNE L3
L2:
MOV BX, 1
JMP L4
L3:
MOV BX, 0
L4:
PUSH BX
L5:	;Scope 1.1.1 starts
PUSH t2
INC t2	;variable INCOP
PUSH t2

MOV AX, t2
CALL PRINT	;PRINTLN LPAREN ID RPAREN SEMICOLON
L6:	;Scope 1.1.1 ends
PUSH 0
L7:	;Scope 1.1 ends

MOV AH, 4CH 
INT 21H		;return 0
main ENDP

PRINT PROC
CMP AX, 0
JNL NORMAL 
PUSH AX
MOV DL, 45
MOV AH, 2
INT 21H 
POP AX
NEG AX
NORMAL:
LEA SI, NUMBER_STRING
ADD SI, 5
PRINT_LOOP:
DEC SI
XOR DX, DX
MOV CX, 10
DIV CX
ADD DL, '0'
MOV [SI], DL
CMP AX, 0
JNE PRINT_LOOP
MOV DX, SI
MOV AH, 9
INT 21H
MOV AH, 2	;printing newline
MOV DL, 0DH
INT 21H
MOV DL, 0AH
INT 21H
RET
PRINT ENDP

END MAIN
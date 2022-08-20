.MODEL SMALL
.STACK 400H
.DATA
NUMBER_STRING DB '00000$'
t1 DW ?
t2 DW ?

.CODE
main PROC
MOV AX,@DATA 
MOV DS,AX

MOV t1, 0
MOV t2, 0
PUSH t1
PUSH 3
POP BX
NEG BX
PUSH BX
POP BX
POP AX
MOV t1, BX
PUSH t2
PUSH t1
PUSH 2
POP BX
POP AX
ADD BX, AX
PUSH BX
POP BX
POP AX
MOV t2, BX

MOV AX, t1
CALL PRINT

MOV AX, t2
CALL PRINT
PUSH 0

MOV AH, 4CH 
INT 21H
main ENDP

PRINT PROC
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
.MODEL SMALL
.STACK 400H
.DATA
NUMBER_STRING DB '00000$'
t1 DW ?
t2 DW ?
t3 DW ?

.CODE
main PROC
MOV AX,@DATA 
MOV DS,AX

MOV t1, 0
MOV t2, 0
MOV t3, 0
MOV BX, t2
PUSH BX
PUSH 589
POP BX
POP AX
MOV t2, BX
MOV BX, t1
PUSH BX
PUSH 34
POP BX
POP AX
MOV t1, BX

MOV AX, t1
CALL PRINT

MOV AX, t2
CALL PRINT

MOV AX, t3
CALL PRINT

MOV AH, 4CH 
INT 21H
main ENDP

PRINT PROC
LEA SI, NUMBER_STRING
ADD SI, 5
PRINT_LOOP:
DEC SI
MOV DX, 0
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
.MODEL SMALL
.STACK 400H
.DATA
t0 dw ?
t1 dw ?

main PROC
MOV AX,@DATA 
MOV DS,AX
MOV AH, 4CH 
INT 21H
main ENDP

END MAIN
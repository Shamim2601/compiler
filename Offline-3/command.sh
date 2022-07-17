yacc -d -y 1805060.y
g++ -w -c -o y.o y.tab.c
flex 1805060.l
g++ -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
g++ y.o l.o -lfl
./a.out input.txt
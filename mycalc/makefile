mycalc:y.tab.c lex.yy.c
	gcc -o mycalc y.tab.c lex.yy.c -ly -ll

y.tab.c:mycalc.y
	yacc -dv mycalc.y

lex.yy.c:mycalc.l
	lex mycalc.l
	
clean:
	rm -f mycalc *.c *.h *.output
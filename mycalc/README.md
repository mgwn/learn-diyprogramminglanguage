#笔记
在Mac环境中，使用原书的命令  

	gcc -o mycalc y.tab.c lex.yy.c
会报错，需要使用  
	
	gcc -o mycalc y.tab.c lex.yy.c -ly -ll

或者直接使用这里写好的makefile

##补全
补全了2.5节原书缺少的部分代码修改
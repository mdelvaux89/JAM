all:
	bison -d JAM.y
	flex -o JAM.lex.c JAM.lex
	g++ -o JAM JAM.lex.c JAM.tab.c -lfl -lm

clean:
	rm -rf JAM.lex.c JAM.tab.c JAM.tab.h JAM


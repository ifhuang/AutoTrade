pwd
bison -d -t el.y
lex el.l
cp lex.yy.c ../lex/lex.yy.cpp
cp el.tab.c ../lex/el.tab.cpp
cp el.tab.h ../lex/

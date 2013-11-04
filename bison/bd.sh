pwd
bison -d -t -Wall el.y
cp el.tab.c ../lex/bison/el.tab.cpp
cp el.tab.h ../lex/bison/

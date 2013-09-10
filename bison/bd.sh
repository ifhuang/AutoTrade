pwd
bison -d -t -Wall el.y
cp el.tab.c ../lex/el.tab.cpp
cp el.tab.h ../lex/

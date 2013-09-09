pwd
bison -d -t el.y
cp el.tab.c ../lex/el.tab.cpp
cp el.tab.h ../lex/

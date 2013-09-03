pwd
bison -d el.y
lex el.l
cp lex.yy.c /cygdrive/e/projects/el/lex/lex.yy.cpp
cp el.tab.c /cygdrive/e/projects/el/lex/el.tab.cpp
cp el.tab.h /cygdrive/e/projects/el/lex/
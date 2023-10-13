%{
#include <stdio.h>
%}

%%

expr: TERM
| expr PLUS TERM
| expr MINUS TERM
;

TERM: NUMBER;

NUMBER: [0-9]+;

%%

int main(void) {
  yyparse();
  return 0;
}


\\Flexical analyzer file
%%

[0-9]+ {
  yylval = atoi(yytext);
  return NUMBER;
}

"+" {
  return PLUS;
}

"-" {
  return MINUS;
}

%%

int main(void) {
  yylex();
  return 0;
}


\\Commands
yacc -d expr.y
flex expr.l
gcc -o expr expr.tab.c lex.yy.c

./expr 5 + 5 
This outputs the sum
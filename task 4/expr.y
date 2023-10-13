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
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
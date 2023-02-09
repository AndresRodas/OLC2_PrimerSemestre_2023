%{
    #include <stdio.h>
    #include "y.tab.h"
    void yyerror(char *);
%}

%option noyywrap
DIGIT [0-9]
NUM {DIGIT}+

%%
{NUM}           { yylval = atoi(yytext); return NUMBER; }
[-()+*/;]       { return *yytext; }
"evaluar"       { return EVALUAR; }
[[:blank:]] ;
.               yyerror("caracter no válido");

%%

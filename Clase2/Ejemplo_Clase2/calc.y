%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *s);
%}

%token NUMBER EVALUAR
%start INICIO
%left '+' '-'
%left '*' '/'

%%
    INICIO : EVALUAR '(' Expr ')' ';' 
    {
        printf("\nEl Resultado es: %d\n", $3);
        return 0;
    };

    Expr : Expr '+' Expr { $$ = $1 + $3; }
        | Expr '-' Expr { $$ = $1 - $3; }
        | Expr '*' Expr { $$ = $1 * $3; }
        | Expr '/' Expr { $$ = $1 / $3; }
        | NUMBER { $$ = $1; }
    ;
%%

int main(){
    return(yyparse());
}

void yyerror(char *s){
    printf("\n%s\n", s);
}

int yywrap(){
    return 1;
}
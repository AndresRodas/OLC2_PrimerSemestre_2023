/* se convierte con: flex --verbose lexer.l*/
/* opcciones para encapsulamiento */

%option reentrant noyywrap nounput batch noinput
%option debug
/*%option outfile="lexer.cpp" */
/* %option header-file="lexer.hpp"*/
%{
    #include <iostream>
    // definicion del tipo de funcion del retorno de simbolos
    // yy::Parser ¿Por qué?
    // yy es el namespace de parser
    // Parser es el nombre de la clase que lo envuelve (wapper)
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx)
    // definición de acciones
    #define YY_USER_ACTION loc.columns(yyleng);
    // defincion de caracter EOF
    #define yyterminate() return Parser::make_END(loc)
    //se incrusta el parser
    #include "parser.hpp"


    using namespace yy;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yy::Parser::token token;
    typedef yy::Parser::token_type token_type;
/// código adicinoal aquí

%}

/* ============== INICIO DE SCANNER ==========  */


/* expresiones regulares */

DIGITO [0-9]
LETRAS [a-zA-ZñÑ]
NUMERO {DIGITO}+
ID  {LETRAS}({DIGITO}|{LETRAS}|"_")*

%%

%{
// inicia la lectura
    loc.step();
%}

    /* inicia la defincion de tokens   */



    /* caracteres ignorados */

"//"[^\n]*\n            ; /* comentarios de una linea */

[ \t\v\r\n\f]             ; /* caracteres en blanco */
    /* Lexemas */
    /* defincion moderna
        token::ID ID sin caracteres especiales
    */
    /* defincion clásica / para caracteres especiales */

"+"     return Parser::symbol_type( token::SUMA, loc );
"-"     return Parser::symbol_type( token::MENOS, loc );
"*"     return Parser::symbol_type( token::POR, loc );
"/"     return Parser::symbol_type( token::DIV, loc );

">"     return Parser::symbol_type( token::MAY, loc );
"<"     return Parser::symbol_type( token::MEN, loc );
">="     return Parser::symbol_type( token::MAY_IG, loc );
"<="     return Parser::symbol_type( token::MEN_IG, loc );
"!="     return Parser::symbol_type( token::DIF, loc );
"=="     return Parser::symbol_type( token::IG, loc );

"&&"     return Parser::symbol_type( token::AND, loc );
"||"     return Parser::symbol_type( token::OR, loc );

";"     return Parser::symbol_type( token_type(';'), loc );
"="     return Parser::symbol_type( token_type('='), loc );
"."     return Parser::symbol_type( token_type('.'), loc );
","     return Parser::symbol_type( token_type(','), loc );

"("     return Parser::symbol_type( token::PARA, loc );
")"     return Parser::symbol_type( token::PARC, loc );
"{"     return Parser::symbol_type( token::LLAVA, loc );
"}"     return Parser::symbol_type( token::LLAVC, loc );
"["     return Parser::symbol_type( token::CORA, loc );
"]"     return Parser::symbol_type( token::CORC, loc );


    /* TOKENS  */
"printf"    return Parser::symbol_type( token::PRINTF, loc );
"void"    return Parser::symbol_type( token::VOID, loc );
"int"    return Parser::symbol_type( token::INT, loc );
"string"    return Parser::symbol_type( token::TSTRING, loc );
"boolean"    return Parser::symbol_type( token::BOOLEAN, loc );
"main"    return Parser::symbol_type( token::RMAIN, loc );
"true"    return Parser::symbol_type( token::RTRUE, loc );
"false"    return Parser::symbol_type( token::RFALSE, loc );
"if"    return Parser::symbol_type( token::RIF, loc );
"else"    return Parser::symbol_type( token::RELSE, loc );
"struct"    return Parser::symbol_type( token::STRUCT, loc );
"return"    return Parser::symbol_type( token::RRETURN, loc );
"array"    return Parser::symbol_type( token::ARRAY, loc );

{ID}  return Parser::make_ID(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
\"(\\.|[^"\\])*\" return Parser::make_STRING (yytext, loc);

.  {std::cerr<<loc <<": "<<"error token no esperado"<<  std::endl; }

    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return Parser::make_END(loc);} */



%%


 // más código - normalmente para manejo de errores


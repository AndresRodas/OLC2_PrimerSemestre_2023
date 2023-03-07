/* comando   bison --verbose -o parser.cpp  parser.y */

/* Se requiere una versión minima de Bison */
%require  "3.0.4"
/* Se usa el skeleton más recienta para c++ */
%skeleton "lalr1.cc"

/* indica que se deben de crear archivos de cabeceras (.h)*/
%defines

/* indica el namespace que contiene al parser */
%define api.prefix{yy}

/* indica la clase que envuelve al parser */
%define api.parser.class {Parser}

/* indica que se generaran clases de tipo locations que leerá el lexer*/
%locations

/* indica que se deben crear contructores y funciones tipo make_TOKEN para cada token */
%define api.token.constructor

/* indica que se utilizará la notacion $1 -> $$ de los no terminales */
%define api.value.type variant

/* indica que el analizador mostrara un trace cuando haya un error*/
%define parse.trace

/* indica que el analizador mostrará los errores de forma descriptiva */
/* %define parse.error verbose */

%code requires 
{
    /* cabeceras iniciales */
    #include <iostream> 
    #include <string> 
    #include <vector>
    #include "parserctx.hpp"

    /* expresiones */
    #include "../Clase4/Expression/primitive.hpp"
    #include "../Clase4/Expression/access.hpp"
    #include "../Clase4/Expression/array_access.hpp"
    #include "../Clase4/Expression/struct_access.hpp"
    #include "../Clase4/Expression/operation.hpp"
    #include "../Clase4/Environment/type.h"
    #include "../Clase4/Interfaces/expression.hpp"
    #include "../Clase4/Expression/map_struct_dec.hpp"
    #include "../Clase4/Expression/list_expression.hpp"
    
    /* instrucciones */
    #include "../Clase4/Interfaces/instruction.hpp"
    #include "../Clase4/Instruction/print.hpp"
    #include "../Clase4/Instruction/list_instruction.hpp"
    #include "../Clase4/Instruction/func_main.hpp"
    #include "../Clase4/Instruction/func_if.hpp"
    #include "../Clase4/Instruction/declaration.hpp"
    #include "../Clase4/Instruction/dec_struct.hpp"
    #include "../Clase4/Instruction/create_struct.hpp"
}

/* enlace con la función del retorno de simbolos */
%code { yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); }

/* token de salida*/
%token END 0;

/*tokens*/
%token <std::string> NUMERO ID STRING SUMA MENOS POR DIV PRINTF RIF RELSE
%token <std::string> VOID INT TSTRING BOOLEAN PARA PARC RMAIN LLAVA LLAVC RTRUE RFALSE CORA CORC
%token <std::string> MAY MEN MAY_IG MEN_IG DIF IG AND OR STRUCT
%token ';' '=' '.' ','

/* precedencia de operadores */
%left AND OR
%left IG DIF
%left MEN MEN_IG MAY MAY_IG
%left SUMA MENOS
%left POR DIV

/* instancia de la clase que creamos */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* definicion de no terminales */
%type<expression*> PRIMITIVE;
%type<expression*> EXP;
%type<expression*> BOOL;
%type<expression*> LIST_ARR;
%type<func_main*> START;
%type<list_instruction*> LIST_INST;
%type<list_instruction*> ELSEIF_LIST;
%type<list_instruction*> ELSE;
%type<list_expression*> EXP_LIST;
%type<func_main*> MAIN;
%type<instruction*> INSTRUCTION;
%type<instruction*> PRINT;
%type<instruction*> DECLARATION;
%type<instruction*> IF;
%type<instruction*> ELSEIF;
%type<instruction*> STRUCT_DECLARATION;
%type<instruction*> STRUCT_CREATION;
%type<TipoDato> TYPES;
%type<map_struct_dec*> DEC_LIST; 

/* printer */
%printer { yyoutput << $$; } <*>;

/* inicio de la grámatica */
%%

%start START;

START : MAIN
    {
        ctx.Main = $1;
        ctx.Salida = "!Ejecución realizada con éxito!";
        $$ = $1;
    }
;

MAIN : VOID RMAIN PARA PARC LLAVA LIST_INST LLAVC 
{
    $$ = new func_main(0, 0, $1, $6);
}
;

LIST_INST : LIST_INST INSTRUCTION 
        { 
            $1->newInst($2);
            $$ = $1;
        }  
        | INSTRUCTION 
        {
            $$ = new list_instruction();
            $$->newInst($1);
        }
;

INSTRUCTION : PRINT ';' { $$ = $1; }
            | DECLARATION ';' { $$ = $1; }
            | IF { $$ = $1; } 
            | STRUCT_DECLARATION { $$ = $1; }
            | STRUCT_CREATION { $$ = $1; }
;

PRINT : PRINTF PARA EXP PARC { $$ = new print(0,0,$3); }
;

DECLARATION : TYPES ID '=' EXP { $$ = new declaration(0,0,$1,$2,$4); }
;

IF : RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE 
    {
        $$ = new func_if(0,0,$2,$4,$6,$7);
    }
    | RIF EXP LLAVA LIST_INST LLAVC ELSE 
    {
        $$ = new func_if(0,0,$2,$4,nullptr,$6);
    }
;

ELSEIF_LIST : ELSEIF_LIST ELSEIF 
        { 
            $1->newInst($2);
            $$ = $1;
        }  
        | ELSEIF 
        {
            $$ = new list_instruction();
            $$->newInst($1);
        }
;

ELSEIF : RELSE RIF EXP LLAVA LIST_INST LLAVC 
        {
            $$ = new func_if(0,0,$3,$5, nullptr, nullptr);
        }
;

ELSE : RELSE LLAVA LIST_INST LLAVC { $$ = $3; }
    | %empty { }
;

STRUCT_DECLARATION : STRUCT ID LLAVA DEC_LIST LLAVC {$$ = new dec_struct(0,0,$4,$2); }
;

DEC_LIST : DEC_LIST TYPES ID ';' 
        {
            $1->newMap($3,$2);
            $$ = $1;
        }
        | TYPES ID ';' 
        {   
            $$ = new map_struct_dec();
            $$->newMap($2, $1);
        }
;

STRUCT_CREATION : STRUCT ID ID '=' LLAVA EXP_LIST LLAVC 
                {
                    $$ = new create_struct(0,0,$2,$3,$6);
                }
;

EXP_LIST : EXP_LIST ',' EXP 
        {
            $1->newExp($3);
            $$ = $1;
        }
        | EXP 
        {
            $$ = new list_expression();
            $$->newExp($1);
        }
;

TYPES : INT { $$ = INTEGER; }
    | TSTRING { $$ = STRING; }
    | BOOLEAN { $$ = BOOL; }
;

EXP : EXP SUMA EXP { $$ = new operation(0, 0, $1, $3, "+"); }
    | EXP MENOS EXP { $$ = new operation(0, 0, $1, $3, "-"); }
    | EXP POR EXP { $$ = new operation(0, 0, $1, $3, "*"); }
    | EXP DIV EXP { $$ = new operation(0, 0, $1, $3, "/"); }
    | EXP MEN EXP { $$ = new operation(0, 0, $1, $3, "<"); }
    | EXP MAY EXP { $$ = new operation(0, 0, $1, $3, ">"); }
    | EXP MEN_IG EXP { $$ = new operation(0, 0, $1, $3, "<="); }
    | EXP MAY_IG EXP { $$ = new operation(0, 0, $1, $3, ">="); }
    | EXP DIF EXP { $$ = new operation(0, 0, $1, $3, "!="); }
    | EXP IG EXP { $$ = new operation(0, 0, $1, $3, "=="); }
    | EXP AND EXP { $$ = new operation(0, 0, $1, $3, "&&"); }
    | EXP OR EXP { $$ = new operation(0, 0, $1, $3, "||"); }
    | PARA EXP PARC { $$ = $2; }
    | PRIMITIVE { $$ = $1; }
;

PRIMITIVE : NUMERO
        {
            int num = stoi($1);
            $$ = new primitive(0,0,INTEGER,"",num,false);
        }
        | STRING 
        { 
            std::string str1 = $1.erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            $$ = new primitive(0,0,STRING,str2,0,false);
        }
        | BOOL { $$ = $1; }
        | LIST_ARR { $$ = $1; }
;

BOOL : RTRUE { $$ = new primitive(0,0,BOOL,"",0,true); }
    | RFALSE { $$ = new primitive(0,0,BOOL,"",0,false); }
;

LIST_ARR : LIST_ARR CORA EXP CORC { $$ = new array_access(0,0,$1,$3); }
        | LIST_ARR '.' ID { $$ = new struct_access(0,0,$1,$3); }
        | ID {$$ = new access(0,0,$1); }  
;

%%

/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}


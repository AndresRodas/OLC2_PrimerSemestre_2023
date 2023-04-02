#include "parserctx.hpp"
#include "Parser/location.hh"
#include "Parser/parser.hpp"
#include "Parser/lex.yy.c"

namespace OCL2Calc {
ParserCtx::ParserCtx()
{
    //inicializa lexer
    yylex_init(&lexer);
    // creacion location
    loc = new yy::location();
    // creacion parser
    Parser = new yy::Parser(lexer, *loc, *this);
    Salida = "";
}

ParserCtx::~ParserCtx(){
    yylex_destroy(lexer);
    delete loc;
    delete Parser;
}

std::string ParserCtx::Analizar(std::string entrada){
    // cargamos la entrada
    yy_scan_string(entrada .c_str(), lexer );
    // se muestra el debug
    this->Parser->set_debug_level(true);
    //se analiza
    this->Parser->parse();
    return "";
}

}

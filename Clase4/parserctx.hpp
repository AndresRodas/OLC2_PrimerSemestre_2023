#ifndef PARSERCTX_HPP
#define PARSERCTX_HPP
#include "Instruction/func_main.hpp"
#include "Interfaces/expression.hpp"
#include <string>

namespace yy {
class Parser;
class location;
}

namespace OCL2Calc {
class ParserCtx
{
public:
    void* lexer;
    yy::location* loc;
    yy::Parser* Parser;
    std::string Salida;
    instruction *Main;

    ParserCtx();
    ~ParserCtx();
    std::string Analizar(std::string entrada);
};

}

#endif // PARSERCTX_HPP

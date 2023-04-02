#include "call_exp.hpp"
#include "Expression/map_struct_dec.hpp"
#include "Instruction/list_instruction.hpp"

call_exp::call_exp(int line, int col, std::string id, list_expression *explist)
{
    Line = line;
    Col = col;
    Id = id;
    ExpList = explist;
}

symbol call_exp::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    return sym;
}

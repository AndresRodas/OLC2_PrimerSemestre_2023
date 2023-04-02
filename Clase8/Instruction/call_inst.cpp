#include "call_inst.hpp"
#include "Expression/map_struct_dec.hpp"
#include "Instruction/list_instruction.hpp"

call_inst::call_inst(int line, int col, std::string id, list_expression *explist)
{
    Line = line;
    Col = col;
    Id = id;
    ExpList = explist;
}

void call_inst::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    std::cout << "execute\n";
}


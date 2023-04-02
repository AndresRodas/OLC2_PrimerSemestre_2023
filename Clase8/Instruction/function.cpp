#include "function.hpp"

function::function(int line, int col, TipoDato tipo, std::string id, map_struct_dec *paramlist, list_instruction *instlist)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    ParamList = paramlist;
    InstList = instlist;
}

void function::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    std::cout << "execute\n";
}

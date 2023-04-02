#include "struct_access.hpp"

struct_access::struct_access(int line,int col, expression* structexp, std::string id)
{
    Line = line;
    Col = col;
    StructExp = structexp;
    Id = id;
}

symbol struct_access::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    return sym;
}
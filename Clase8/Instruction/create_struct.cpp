#include "create_struct.hpp"

create_struct::create_struct(int line,int col, std::string idstruct, std::string id, list_expression *explist)
{
    Line = line;
    Col = col;
    IdStruct = idstruct;
    Id = id;
    ExpList = explist;
}

void create_struct::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    std::cout << "execute\n";
}

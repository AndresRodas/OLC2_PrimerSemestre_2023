#include "dec_struct.hpp"

dec_struct::dec_struct(int line, int col, map_struct_dec *array, std::string id)
{
    Line = line;
    Col = col;
    Array = array;
    Id = id;
}

void dec_struct::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    std::cout << "execute\n";
}


#include "map_struct_dec.hpp"

map_struct_dec::map_struct_dec()
{

}

value map_struct_dec::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val("", false, NULO);
    return val;
}

void map_struct_dec::newMap(std::string id, TipoDato tipo)
{
    ListDec[id] = tipo;
}

#include "map_struct_dec.hpp"

map_struct_dec::map_struct_dec()
{

}

symbol map_struct_dec::ejecutar(environment *env, ast *tree)
{
    symbol sym (0,0,"",NULO,nullptr);
    return sym;
}

void map_struct_dec::newMap(std::string id, TipoDato tipo)
{
    ListDec[id] = tipo;
}

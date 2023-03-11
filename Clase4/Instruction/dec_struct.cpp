#include "dec_struct.hpp"

dec_struct::dec_struct(int line, int col, map_struct_dec *array, std::string id)
{
    Line = line;
    Col = col;
    Array = array;
    Id = id;
}

void dec_struct::ejecutar(environment *env, ast *tree)
{
//    map<std::string, TipoDato>::iterator i;
//    for(i = Array->ListDec.begin(); i != Array->ListDec.end(); ++i){
//        std::cout << i->first << ": " << i->second << std::endl;
//    }
    env->SaveStruct(Array->ListDec,Id, tree);
}

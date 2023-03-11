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

void function::ejecutar(environment *env, ast *tree)
{
    std::cout << "Ejecutando la funcion "<< Id << std::endl;
    func_symbol funcSym = func_symbol(Line, Col, Tipo, Id, ParamList, InstList);
    env->SaveFunc(funcSym, Id, tree);
}

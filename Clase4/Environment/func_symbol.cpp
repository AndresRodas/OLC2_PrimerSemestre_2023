#include "func_symbol.hpp"

func_symbol::func_symbol()
{

}


func_symbol::func_symbol(int line,int col,TipoDato tipo,std::string id,void* param,void* inst)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    ParamList = param;
    InstList = inst;
}

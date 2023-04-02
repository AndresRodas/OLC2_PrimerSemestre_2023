#ifndef FUNC_SYMBOL_HPP
#define FUNC_SYMBOL_HPP

#include "Environment/type.h"
#include <string>

class func_symbol
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string Id;
    void *ParamList; //map_struct_dec
    void *InstList; //list_instruction
    func_symbol();
    func_symbol(int,int,TipoDato,std::string,void*,void*);
};

#endif // FUNC_SYMBOL_HPP

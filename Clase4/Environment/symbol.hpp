#ifndef SYMBOL_HPP
#define SYMBOL_HPP
#include <iostream>
#include "type.h"

class symbol
{
public:
    int Line;
    int Col;
    std::string Id;
    TipoDato Tipo;
    std::string StrVal;
    int NumVal;

    symbol(int line, int col, std::string id, TipoDato tipo, std::string strval, int numval);
};

#endif // SYMBOL_HPP

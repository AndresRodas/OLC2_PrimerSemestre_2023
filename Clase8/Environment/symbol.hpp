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
    int Posicion;
    symbol();
    symbol(int line, int col, std::string id, TipoDato tipo, int posicion);
};

#endif // SYMBOL_HPP

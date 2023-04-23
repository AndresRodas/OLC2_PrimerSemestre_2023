#include "symbol.hpp"
symbol::symbol()
{

}

symbol::symbol(int line, int col, std::string id, TipoDato tipo, int posicion)
{
    Line = line;
    Col = col;
    Id = id;
    Tipo = tipo;
    Posicion = posicion;
}

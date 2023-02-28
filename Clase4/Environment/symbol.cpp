#include "symbol.hpp"
symbol::symbol()
{

}

symbol::symbol(int line, int col, std::string id, TipoDato tipo, void* value){
    Line = line;
    Col = col;
    Id = id;
    Tipo = tipo;
    Value = value;
}

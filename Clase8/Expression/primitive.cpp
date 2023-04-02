#include "primitive.hpp"

primitive::primitive(int line, int col, TipoDato tipo, std::string strval, int numval, bool boolval){
    Line = line;
    Col = col;
    Tipo = tipo;
    strVal = strval;
    numVal = numval;
    boolVal = boolval;
}

symbol primitive::ejecutar(environment *env, ast* tree, generator_code *gen)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    return sym;
}

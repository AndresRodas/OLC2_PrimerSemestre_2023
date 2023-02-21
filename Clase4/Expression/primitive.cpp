#include "primitive.hpp"

primitive::primitive(int line, int col, TipoDato tipo, std::string StrVal, int NumVal){
    this->Line = line;
    this->Col = col;
    this->Tipo = tipo;
    this->StrVal = StrVal;
    this->NumVal = NumVal;
}

symbol primitive::ejecutar(environment *env, ast* tree)
{
    symbol sym = *new symbol(this->Line,this->Col,"",this->Tipo,this->StrVal,this->NumVal);
    return sym;
}

#include "value.hpp"

value::value(std::string value, bool istemp, TipoDato tipo)
{
    Value = value;
    IsTemp = istemp;
    TipoExpresion = tipo;
    TrueLvl = QVector<std::string>();
    FalseLvl = QVector<std::string>();
}

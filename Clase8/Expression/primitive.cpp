#include "primitive.hpp"

primitive::primitive(int line, int col, TipoDato tipo, std::string strval, int numval, bool boolval){
    Line = line;
    Col = col;
    Tipo = tipo;
    strVal = strval;
    numVal = numval;
    boolVal = boolval;
}

value primitive::ejecutar(environment *env, ast* tree, generator_code *gen)
{
    value val("", false, NULO);

    switch (Tipo) {
    case INTEGER:
        val = value(std::to_string(numVal),false,Tipo);
        break;
    case STRING:
        //nuevo temporal
        std::string newTemp = gen->newTemp();
        //igualar a Heap Pointer
        gen->AddAssign(newTemp, "H");
        //recorrer cadena
        for (int i = 0; i < strVal.length(); i++) {
            //se agrega ascii a heap
            gen->AddSetHeap("(int)H", std::to_string(int(strVal[i])));
            //suma heap pointer
            gen->AddExpression("H", "H", "1", "+");
        }
        //caracteres de escape
        gen->AddSetHeap("(int)H", "-1");
        gen->AddExpression("H", "H", "1", "+");
        gen->AddBr();
        val = value(newTemp,true,Tipo);
        break;
    }

    return val;
}

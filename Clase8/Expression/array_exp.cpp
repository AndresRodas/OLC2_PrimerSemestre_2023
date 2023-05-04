#include "array_exp.hpp"
#include <QDebug>
array_exp::array_exp(int line, int col, list_expression *explist)
{
    Line = line;
    Col = col;
    ExpList = explist;
}

value array_exp::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value result;
    value val;
    TipoDato arrType;
    int size = ExpList->ListExp.size();
    //generando array
    gen->AddComment("Generando Array");
    std::string newtmp1 = gen->newTemp();
    std::string newtmp2 = gen->newTemp();
    gen->AddAssign(newtmp1, "H");
    gen->AddExpression(newtmp2, newtmp1, "1", "+");
    gen->AddSetHeap("(int)H", std::to_string(size));
    gen->AddExpression("H","H",std::to_string(size+1),"+");
    //se recorre la lista de expresiones
    for(int i=0; i < ExpList->ListExp.size(); i++)
    {
        val = ExpList->ListExp[i]->ejecutar(env, tree, gen);
        arrType = val.TipoExpresion;
        gen->AddSetHeap("(int)"+newtmp2, val.Value);
        gen->AddExpression(newtmp2, newtmp2, "1", "+");
    }
    result = value(newtmp1,true,ARRAY);
    return result;
}

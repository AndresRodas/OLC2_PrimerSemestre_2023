#include "operation.hpp"

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    Line = line;
    Col = col;
    Op_izq = op_izq;
    Op_der = op_der;
    Operator = operador;
}

symbol operation::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    std::string new_temp = gen->newTemp();
    gen->AddExpression(new_temp,"5","2","+");
    gen->AddExpression(new_temp,"6","7","-");
    return sym;
}

#include "operation.hpp"

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    Line = line;
    Col = col;
    Op_izq = op_izq;
    Op_der = op_der;
    Operator = operador;
}

value operation::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val ("",false,NULO);
    value op1 = Op_izq->ejecutar(env, tree, gen);
    value op2 = Op_der->ejecutar(env, tree, gen);

    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    TipoDato Matrz[5][5] = {
        {INTEGER, FLOAT, STRING, INTEGER, NULO},
        {FLOAT, FLOAT, STRING, FLOAT, NULO},
        {STRING, STRING, STRING, STRING, NULO},
        {INTEGER, FLOAT, STRING, BOOL, NULO},
        {NULO, NULO, NULO, NULO, NULO}
    };

    TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
    std::string newTemp = gen->newTemp();
    if(Operator == "+")
    {
        if(Dominante == INTEGER)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para suma";
        }
    }
    else if(Operator == "-")
    {
        if(Dominante == INTEGER)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"-");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para resta";
        }
    }
    else if(Operator == "*")
    {
        if(Dominante == INTEGER)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"*");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
        }
    }
    else if(Operator == "/")
    {
        if(Dominante == INTEGER)
        {
            gen->AddComment("Agregar validacion division cero");
            gen->AddExpression(newTemp,op1.Value,op2.Value,"/");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para división";
        }
    }

    return val;
}

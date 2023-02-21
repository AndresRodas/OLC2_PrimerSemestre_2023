#include "operation.hpp"

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    this->Line = line;
    this->Col = col;
    this->Op_izq = op_izq;
    this->Op_der = op_der;
    this->Operator = operador;
}

symbol operation::ejecutar(environment *env, ast *tree)
{
    symbol sym = *new symbol(this->Line,this->Col,"",NULO,"",0);
    symbol op1 = this->Op_izq->ejecutar(env, tree);
    symbol op2 = this->Op_der->ejecutar(env, tree);

    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    int Matrz[4][4] = {
        {INTEGER, FLOAT, STRING, NULO},
        {FLOAT, FLOAT, STRING, NULO},
        {STRING, STRING, STRING, NULO},
        {NULO, NULO, NULO, NULO}
    };

    int Dominante = Matrz[op1.Tipo][op2.Tipo];

    if(this->Operator == "+")
    {
        if(Dominante == INTEGER)
        {
            sym = *new symbol(this->Line,this->Col,"",op1.Tipo,"",op1.NumVal+op2.NumVal);
        }
        else if(Dominante == STRING)
        {
            sym = *new symbol(this->Line,this->Col,"",op1.Tipo,op1.StrVal+op2.StrVal,0);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto";
        }
    }
    else if(this->Operator == "-")
    {
        if(Dominante == INTEGER)
        {
            sym = *new symbol(this->Line,this->Col,"",op1.Tipo,"",op1.NumVal-op2.NumVal);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto";
        }
    }
    else if(this->Operator == "*")
    {
        if(Dominante == INTEGER)
        {
            sym = *new symbol(this->Line,this->Col,"",op1.Tipo,"",op1.NumVal*op2.NumVal);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto";
        }
    }
    else if(this->Operator == "/")
    {
        if(Dominante == INTEGER)
        {
            sym = *new symbol(this->Line,this->Col,"",op1.Tipo,"",op1.NumVal/op2.NumVal);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto";
        }
    }
    return sym;
}

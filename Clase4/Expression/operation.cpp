#include "operation.hpp"

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    Line = line;
    Col = col;
    Op_izq = op_izq;
    Op_der = op_der;
    Operator = operador;
}

symbol operation::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol op1 = Op_izq->ejecutar(env, tree);
    symbol op2 = Op_der->ejecutar(env, tree);


    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    TipoDato Matrz[5][5] = {
        {INTEGER, FLOAT, STRING, INTEGER, NULO},
        {FLOAT, FLOAT, STRING, FLOAT, NULO},
        {STRING, STRING, STRING, STRING, NULO},
        {INTEGER, FLOAT, STRING, BOOL, NULO},
        {NULO, NULO, NULO, NULO, NULO}
    };

    TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];

    if(Operator == "+")
    {
        if(Dominante == INTEGER)
        {
            int result = *static_cast<int*>(op1.Value) + *static_cast<int*>(op2.Value);
            sym = symbol(Line,Col,"",Dominante,&result);
        }
        else if(Dominante == STRING)
        {
            std::string *val1 = (std::string *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            std::string result = *val1 + *val2;
            sym = symbol(Line,Col,"",op1.Tipo,&result);
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
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 - *val2;
            sym = symbol(Line,Col,"",Dominante,&result);
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
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 * *val2;
            sym = symbol(Line,Col,"",Dominante,&result);
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
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            if(*val2 != 0)
            {
                int result = *val1 / *val2;
                sym = symbol(Line,Col,"",Dominante,&result);
            }
            else
            {
                //se reporta un error
                tree->ErrorOut += "Error: no se puede dividir cero";
            }
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para división";
        }
    }
    else if(Operator == "<")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 < *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
        }
    }
    else if(Operator == ">")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 > *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
        }
    }
    else if(Operator == "<=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 <= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
        }
    }
    else if(Operator == ">=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 >= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
        }
    }
    else if(Operator == "!=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == STRING)
        {
            std::string *val1 = (std::string *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
        }
    }
    else if(Operator == "==")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == STRING)
        {
            std::string *val1 = (std::string *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
        }
    }
    return sym;
}

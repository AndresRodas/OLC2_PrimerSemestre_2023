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

    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    TipoDato Matrz[5][5] = {
        {INTEGER, FLOAT, STRING, INTEGER, NULO},
        {FLOAT, FLOAT, STRING, FLOAT, NULO},
        {STRING, STRING, STRING, STRING, NULO},
        {INTEGER, FLOAT, STRING, BOOL, NULO},
        {NULO, NULO, NULO, NULO, NULO}
    };

    std::string newTemp = gen->newTemp();
    if(Operator == "+")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
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
    else if(Operator == "<")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "<", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == ">")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, ">", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == ">=")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, ">=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == "<=")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "<=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == "==")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "==", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == "!=")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "!=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == "&&")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        //se agregan etiquetas verdaderas de op1
        for(int i=0; i < op1.TrueLvl.size(); i++)
        {
            gen->AddLabel(op1.TrueLvl[i]);
        }
        value op2 = Op_der->ejecutar(env, tree, gen);

        val = value("", false, BOOL);

        val.TrueLvl += op2.TrueLvl;
        val.FalseLvl += op1.FalseLvl;
        val.FalseLvl += op2.FalseLvl;

        return val;
    }
    else if(Operator == "||")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        //se agregan etiquetas falsas de op1
        for(int i=0; i < op1.FalseLvl.size(); i++)
        {
            gen->AddLabel(op1.FalseLvl[i]);
        }
        value op2 = Op_der->ejecutar(env, tree, gen);

        val = value("", false, BOOL);

        val.TrueLvl += op1.TrueLvl;
        val.TrueLvl += op2.TrueLvl;
        val.FalseLvl += op2.FalseLvl;
        return val;
    }
    else if(Operator == "!")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        if(op1.TipoExpresion == BOOL)
        {
            val = value("", false, BOOL);
            val.TrueLvl += op1.FalseLvl;
            val.FalseLvl += op1.TrueLvl;
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion lógica";
        }
    }
    return val;
}

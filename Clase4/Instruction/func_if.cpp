#include "func_if.hpp"

func_if::func_if(int line, int col, expression *condition, instruction *block, instruction *elseifblock, instruction *elseblock)
{
    Line = line;
    Col = col;
    Condition = condition;
    Block = block;
    ElseIfBlock = elseifblock;
    ElseBlock = elseblock;
}

void func_if::ejecutar(environment *env, ast *tree)
{

    symbol sym = Condition->ejecutar(env, tree);

    if(sym.Tipo == BOOL)
    {
        //si se cumple el if
        bool *val = (bool *)sym.Value;
        if(*val)
        {
            //ejecuta el bloque
            Block->ejecutar(env, tree);
            //valida si es else if
            if(tree->ElseIfFlag)
            {
                tree->ElseIfFlag = false;
                tree->IfReturn = true;
            }
            return;
        }
        //si no se cumple y existe else if
        if(ElseIfBlock != nullptr)
        {
            //flag de else if
            tree->ElseIfFlag = true;
            tree->IfReturn = false;
            ElseIfBlock->ejecutar(env, tree);
            //validación return
            if(tree->IfReturn)
            {
                return;
            }
        }
        //si aun no se cumple y existe else
        if(ElseBlock != nullptr)
        {
            ElseBlock->ejecutar(env, tree);
        }

    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Error: tipo incorrecto para If";
    }

}

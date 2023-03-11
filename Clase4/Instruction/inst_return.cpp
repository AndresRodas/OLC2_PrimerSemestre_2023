#include "inst_return.hpp"

inst_return::inst_return(int line, int col, expression *exp)
{
    Line = line;
    Col = col;
    Exp = exp;
}

void inst_return::ejecutar(environment *env, ast *tree)
{
    if(Exp != nullptr)
    {
        symbol sym = Exp->ejecutar(env, tree);
        tree->ListReturn.push_back(sym);
    }
}

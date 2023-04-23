#include "access.hpp"

access::access(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;
}

value access::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val;
    gen->AddComment("Llamando una variable");
    symbol retSym = env->GetVariable(Id, env, tree);
    std::string newTemp1 = gen->newTemp();
    std::string newTemp2 = gen->newTemp();

    if(gen->MainCode)
    {
        gen->AddGetStack(std::to_string(retSym.Posicion),newTemp2);
    }
    else
    {
        gen->AddExpression(newTemp1, "P", std::to_string(retSym.Posicion), "+");
        gen->AddGetStack("(int)"+newTemp1, newTemp2);
    }

    val = value(newTemp2, true, retSym.Tipo);
    return val;
}

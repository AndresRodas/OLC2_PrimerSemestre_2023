#include "array_exp.hpp"

array_exp::array_exp(int line, int col, list_expression *explist)
{
    Line = line;
    Col = col;
    ExpList = explist;
}

value array_exp::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val("", false, NULO);
    return val;
}

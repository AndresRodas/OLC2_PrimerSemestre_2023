#include "array_exp.hpp"

array_exp::array_exp(int line, int col, list_expression *explist)
{
    Line = line;
    Col = col;
    ExpList = explist;
}

symbol array_exp::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    return sym;
}

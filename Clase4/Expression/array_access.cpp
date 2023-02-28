#include "array_access.hpp"

array_access::array_access(int line, int col, expression *array, expression *index)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index;
}

symbol array_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    return sym;
}

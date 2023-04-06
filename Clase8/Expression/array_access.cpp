#include "array_access.hpp"

array_access::array_access(int line, int col, expression *array, expression *index)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index;
}

value array_access::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val("", false, NULO);
    return val;
}

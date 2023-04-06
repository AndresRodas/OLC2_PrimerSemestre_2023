#include "access.hpp"

access::access(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;
}

value access::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val("", false, NULO);
    return val;
}

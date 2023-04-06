#ifndef STRUCT_ACCESS_HPP
#define STRUCT_ACCESS_HPP
#include "Interfaces/expression.hpp"

class struct_access : public expression
{
public:
    int Line;
    int Col;
    expression *StructExp;
    std::string Id;

    struct_access(int,int, expression*, std::string);
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // STRUCT_ACCESS_HPP

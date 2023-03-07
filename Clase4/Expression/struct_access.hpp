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
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // STRUCT_ACCESS_HPP

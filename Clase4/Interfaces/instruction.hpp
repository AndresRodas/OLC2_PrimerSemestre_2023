#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP
#include "Environment/ast.hpp"
#include "Environment/environment.hpp"


class instruction
{
public:
    virtual void ejecutar(environment *env, ast *tree) = 0;
};

#endif // INSTRUCTION_HPP

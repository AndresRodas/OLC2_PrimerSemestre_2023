#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP
#include "Environment/ast.hpp"
#include "Environment/environment.hpp"
#include "Environment/generator_code.hpp"

class instruction
{
public:
    virtual void ejecutar(environment *env, ast *tree, generator_code *gen) = 0;
};

#endif // INSTRUCTION_HPP

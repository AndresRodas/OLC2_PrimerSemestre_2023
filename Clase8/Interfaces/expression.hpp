#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include "Environment/ast.hpp"
#include "Environment/generator_code.hpp"
#include "Environment/symbol.hpp"
#include "Environment/environment.hpp"
#include "Environment/value.hpp"

class expression
{
public:
    virtual value ejecutar(environment *env, ast *tree, generator_code *gen) = 0;
};

#endif // EXPRESSION_HPP

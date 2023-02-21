#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include "Environment/ast.hpp"
#include "Environment/symbol.hpp"
#include "Environment/environment.hpp"

class expression
{
public:
    virtual symbol ejecutar(environment *env, ast *tree) = 0;
};

#endif // EXPRESSION_HPP

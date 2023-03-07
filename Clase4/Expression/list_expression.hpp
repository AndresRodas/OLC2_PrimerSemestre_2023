#ifndef LIST_EXPRESSION_HPP
#define LIST_EXPRESSION_HPP
#include "Interfaces/expression.hpp"
#include "QVector"

class list_expression
{
public:
    QVector<expression*> ListExp;
    void newExp(expression *exp);
    list_expression();
};

#endif // LIST_EXPRESSION_HPP

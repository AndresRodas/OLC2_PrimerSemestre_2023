#include "list_expression.hpp"

list_expression::list_expression()
{
    ListExp = QVector<expression*>();
}

void list_expression::newExp(expression *exp)
{
    ListExp.push_back(exp);
}

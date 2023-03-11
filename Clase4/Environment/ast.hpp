#ifndef AST_HPP
#define AST_HPP
#include "Environment/symbol.hpp"
#include <string>
#include <QVector>

class ast
{
public:
    std::string ConsoleOut;
    std::string ErrorOut;
    std::string GraphOut;
    bool ElseIfFlag;
    bool IfReturn;
    QVector<symbol> ListReturn;
    ast();
};

#endif // AST_HPP

#ifndef AST_HPP
#define AST_HPP
#include <string>

class ast
{
public:
    std::string ConsoleOut;
    std::string ErrorOut;
    std::string GraphOut;
    bool ElseIfFlag;
    bool IfReturn;
    ast();
};

#endif // AST_HPP

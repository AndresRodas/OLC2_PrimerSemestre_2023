#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include "QVector"

class generator_code
{
public:
    int Temporal;
    int Label;
    QVector<std::string> Code;
    QVector<std::string> FuncCode;
    QVector<std::string> TempList;
    bool MainCode;
    std::string FinalCode;

    generator_code();
    std::string newTemp();
    std::string newLabel();
    void AddIf(std::string left, std::string right, std::string op, std::string label);
    void AddGoto(std::string label);
    void AddExpression(std::string target, std::string left, std::string right, std::string op);
    void AddAssign(std::string target, std::string val);

    void GenerateFinalCode();

};

#endif // GENERATOR_HPP

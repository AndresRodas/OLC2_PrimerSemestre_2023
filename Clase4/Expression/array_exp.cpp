#include "array_exp.hpp"

array_exp::array_exp(int line, int col, list_expression *explist)
{
    Line = line;
    Col = col;
    ExpList = explist;
}

symbol array_exp::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    QVector<symbol> Arr = QVector<symbol>();
    for(int i=0; i < ExpList->ListExp.size(); ++i){
        Arr.push_back(ExpList->ListExp[i]->ejecutar(env, tree));
    }
    this->ArrTemp = Arr;
    sym = symbol(Line, Col, "", ARRAY, &ArrTemp);
    return sym;
}

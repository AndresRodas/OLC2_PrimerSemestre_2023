#include "array_access.hpp"

array_access::array_access(int line, int col, expression *array, expression *index)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index;
}

symbol array_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol symArr = Array->ejecutar(env, tree);
    symbol symInd = Index->ejecutar(env, tree);
    //validando tipo array
    if(symArr.Tipo == ARRAY && symInd.Tipo == INTEGER)
    {
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        QVector<symbol> result = *Arr;
        int *val = (int *)symInd.Value;
        sym = result[*val];
    }

    return sym;
}

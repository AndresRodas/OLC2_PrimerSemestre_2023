#include "array_access.hpp"

array_access::array_access(int line, int col, expression *array, expression *index)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index;
}

value array_access::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value tempArray, tempIndex, result;
    tempArray = Array->ejecutar(env, tree, gen);
    tempIndex = Index->ejecutar(env, tree, gen);
    //llamada
    gen->AddComment("Accediendo a un arreglo");
    std::string newTmp = gen->newTemp();
    std::string lvl1 = gen->newLabel();
    std::string lvl2 = gen->newLabel();
    std::string lvl3 = gen->newLabel();
    gen->AddIf(tempIndex.Value, "0", "<", lvl1);
    std::string tmp = gen->newTemp();
    gen->AddGetHeap(tmp, "(int)"+tempArray.Value);
    gen->AddIf(tempIndex.Value, tmp, ">", lvl1);

    gen->AddGoto(lvl2);
    gen->AddLabel(lvl1);
    gen->AddPrintf("c", "66");
    gen->AddPrintf("c", "111");
    gen->AddPrintf("c", "117");
    gen->AddPrintf("c", "110");
    gen->AddPrintf("c", "100");
    gen->AddPrintf("c", "115");
    gen->AddPrintf("c", "69");
    gen->AddPrintf("c", "114");
    gen->AddPrintf("c", "114");
    gen->AddPrintf("c", "111");
    gen->AddPrintf("c", "114");
    gen->AddGoto(lvl3);
    gen->AddLabel(lvl2);

    gen->AddExpression(newTmp, tempArray.Value, tempIndex.Value, "+");
    gen->AddExpression(newTmp, newTmp, "1", "+");
    std::string newTmp2 = gen->newTemp();
    gen->AddGetHeap(newTmp2, "(int)"+newTmp);
    gen->AddLabel(lvl3);
    result = value(newTmp2, true, INTEGER);
    return result;

}

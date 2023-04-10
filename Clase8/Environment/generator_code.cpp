#include "generator_code.hpp"
#include <iostream>

generator_code::generator_code()
{
    Temporal = 1;
    Label = 1;
    Code = QVector<std::string>();
    FuncCode = QVector<std::string>();
    TempList = QVector<std::string>();
    Natives = QVector<std::string>();
    MainCode = false;
    PrintStringFlag = true;
    FinalCode = "";
}
// Generar un nuevo temporal
std::string generator_code::newTemp()
{
    std::string temp = "t"+std::to_string(Temporal);
    Temporal += 1;
    TempList.push_back(temp);
    return temp;
}
// Genera una nueva etiqueta
std::string generator_code::newLabel()
{
    int temp = Label;
    Label += 1;
    return "L"+std::to_string(temp); //
}
// Agregando una instruccion if
void generator_code::AddIf(std::string left, std::string right, std::string op, std::string label)
{
    if(MainCode)
    {
        Code.append("if(" + left + " " + op + " " + right + ") goto " + label + ";\n");
    }
    else
    {
        FuncCode.append("if(" + left + " " + op + " " + right + ") goto " + label + ";\n");
    }
}

// Agregando un salto
void generator_code::AddGoto(std::string label )
{
    if(MainCode)
    {
        Code.append("goto " + label + ";\n");
    }
    else
    {
        FuncCode.append("goto " + label + ";\n");
    }

}

// Agregando una expresion
void generator_code::AddExpression(std::string target, std::string left, std::string right, std::string op)
{
    if(MainCode)
    {
        Code.append(target + " = " + left + " " + op + " " + right + ";\n");
    }
    else
    {
        FuncCode.append(target + " = " + left + " " + op + " " + right + ";\n");
    }

}

// Agregando una etiqueta
void generator_code::AddLabel(std::string label)
{
    if(MainCode)
    {
        Code.append(label + ":\n");
    }
    else
    {
        FuncCode.append(label + ":\n");
    }

}

// Agregando una asignacion
void generator_code::AddAssign(std::string target, std::string val)
{
    if(MainCode)
    {
        Code.append(target + " = " + val + ";\n");
    }
    else
    {
        FuncCode.append(target + " = " + val + ";\n");
    }

}

// Agregando un comentario
void generator_code::AddComment(std::string val)
{
    if(MainCode)
    {
        Code.append("// "+val+"\n");
    }
    else
    {
        FuncCode.append("// "+val+"\n");
    }

}

//set heap
void generator_code::AddSetHeap(std::string index, std::string value) {
    if (MainCode)
    {
        Code.append("heap[" + index + "] = " + value + ";\n");
    }
    else
    {
        FuncCode.append("heap[" + index + "] = " + value + ";\n");
    }
}

//agrega un salto de linea
void generator_code::AddBr()
{
    if (MainCode)
    {
        Code.append("\n");
    }
    else
    {
        FuncCode.append("\n");
    }
}

//agrega un printf
void  generator_code::AddPrintf(std::string typePrint, std::string value)
{
    if (MainCode)
    {
        Code.append("printf(\"%" + typePrint + "\", " + value + ");\n");
    }
    else
    {
        FuncCode.append("printf(\"%" + typePrint + "\", " + value + ");\n");
    }
}

void generator_code::GeneratePrintString()
{
    if (PrintStringFlag)
    {
        //generando temporales y etiquetas
        std::string newTemp1 = newTemp();
        std::string newTemp2 = newTemp();
        std::string newTemp3 = newTemp();
        std::string newLvl1 = newLabel();
        std::string newLvl2 = newLabel();
        //se genera la funcion printstring
        Natives.append("void olc3d_printString() {\n");
        Natives.append("\t" + newTemp1 + " = P + 1;\n");
        Natives.append("\t" + newTemp2 + " = stack[(int)" + newTemp1 + "];\n");
        Natives.append("\t" + newLvl2 + ":\n");
        Natives.append("\t" + newTemp3 + " = heap[(int)" + newTemp2 + "];\n");
        Natives.append("\tif(" + newTemp3 + " == -1) goto " + newLvl1 + ";\n");
        Natives.append("\tprintf(\"%c\", (char)" + newTemp3 + ");\n");
        Natives.append("\t" + newTemp2 + " = " + newTemp2 + " + 1;\n");
        Natives.append("\tgoto " + newLvl2 + ";\n");
        Natives.append("\t" + newLvl1 + ":\n");
        Natives.append("\treturn;\n");
        Natives.append("}\n\n");
        PrintStringFlag = false;
    }
}

//agregar headers
void generator_code::GenerateFinalCode()
{
    //creando cabecera
    FinalCode += "//****************** Clase 10 ******************\n\n";
    FinalCode += "#include <stdio.h>\n";
    FinalCode += "float stack[100000];\n";
    FinalCode += "float heap[100000];\n";
    FinalCode += "float P;\n";
    FinalCode += "float H;\n";
    //agregando temporales
    std::string tmpDec = "float "+TempList[0];
    for(int i=1; i< TempList.size(); i++){
        tmpDec += ", "+TempList[i];
    }
    tmpDec += ";\n\n";
    FinalCode += tmpDec;
    //agregando funciones
    for(int i=0; i<FuncCode.size(); i++){
        FinalCode += FuncCode[i];
    }
    //agregando funciones nativas
    for(int i=0; i<Natives.size(); i++){
        FinalCode += Natives[i];
    }
    //agregando main()
    FinalCode += "int main()\n{\n";
    for(int i=0; i<Code.size(); i++){
        FinalCode += "\t";
        FinalCode += Code[i];
    }
    FinalCode += "\treturn 0;\n}";
}

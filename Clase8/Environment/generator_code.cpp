#include "generator_code.hpp"

generator_code::generator_code()
{
    Code = QVector<std::string>();
    FuncCode = QVector<std::string>();
    TempList = QVector<std::string>();
}
// Generar un nuevo temporal
std::string generator_code::newTemp()
{
    std::string temp = "t"+std::to_string(Temporal);
    Temporal++;
    TempList.push_back(temp);
    return temp; //
}
// Genera una nueva etiqueta
std::string generator_code::newLabel()
{
    int temp = Label;
    Label++;
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

//agregar headers
void generator_code::GenerateFinalCode()
{
    //creando cabecera
    FinalCode += "*******AQUI SE AGREGAN LOS HEADERS*******";
    FinalCode += "********declaracion de includes**********";
    FinalCode += "**declaracion de temporales y etiquetas**";
    //agregando funciones
    for(int i=0; i<FuncCode.size(); i++){
        FinalCode += FuncCode[i];
    }
    //agregando main()
    FinalCode += "int main()\n{\n";
    for(int i=0; i<Code.size(); i++){
        FinalCode += "\t";
        FinalCode += Code[i];
    }
    FinalCode += "\treturn 0;\n}";
}

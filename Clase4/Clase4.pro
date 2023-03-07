QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Environment/ast.cpp \
    Environment/environment.cpp \
    Environment/symbol.cpp \
    Expression/access.cpp \
    Expression/array_access.cpp \
    Expression/list_expression.cpp \
    Expression/map_struct_dec.cpp \
    Expression/operation.cpp \
    Expression/primitive.cpp \
    Expression/struct_access.cpp \
    Instruction/create_struct.cpp \
    Instruction/dec_struct.cpp \
    Instruction/declaration.cpp \
    Instruction/func_if.cpp \
    Instruction/func_main.cpp \
    Instruction/list_instruction.cpp \
    Instruction/print.cpp \
    Interfaces/expression.cpp \
    Interfaces/expression.cpp \
    Interfaces/instruction.cpp \
    Parser/lex.yy.c \
    Parser/parser.cpp \
    main.cpp \
    mainwindow.cpp \
    parserctx.cpp

HEADERS += \
    Environment/ast.hpp \
    Environment/environment.hpp \
    Environment/symbol.hpp \
    Environment/type.h \
    Expression/access.hpp \
    Expression/array_access.hpp \
    Expression/list_expression.hpp \
    Expression/map_struct_dec.hpp \
    Expression/operation.hpp \
    Expression/primitive.hpp \
    Expression/struct_access.hpp \
    Instruction/create_struct.hpp \
    Instruction/dec_struct.hpp \
    Instruction/declaration.hpp \
    Instruction/func_if.hpp \
    Instruction/func_main.hpp \
    Instruction/list_instruction.hpp \
    Instruction/print.hpp \
    Interfaces/expression.hpp \
    Interfaces/expression.hpp \
    Interfaces/instruction.hpp \
    Parser/lexer.l \
    Parser/location.hh \
    Parser/parser.hpp \
    Parser/parser.y \
    Parser/position.hh \
    Parser/stack.hh \
    mainwindow.hpp \
    parserctx.hpp \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Parser/parser.output \
    Parser/parser.output \
    Parser/parser.output

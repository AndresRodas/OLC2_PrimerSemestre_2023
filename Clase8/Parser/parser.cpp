// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 68 "parser.y"
 yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); 

#line 49 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 141 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (void *scanner_yyarg, yy::location& loc_yyarg, class OCL2Calc::ParserCtx & ctx_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      ctx (ctx_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.YY_MOVE_OR_COPY< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        value.YY_MOVE_OR_COPY< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.YY_MOVE_OR_COPY< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.YY_MOVE_OR_COPY< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.YY_MOVE_OR_COPY< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        value.YY_MOVE_OR_COPY< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_ARRAY: // ARRAY
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.move< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        value.move< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        value.move< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_ARRAY: // ARRAY
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.copy< TipoDato > (that.value);
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        value.copy< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.copy< func_main* > (that.value);
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.copy< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.copy< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.copy< list_instruction* > (that.value);
        break;

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        value.copy< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_ARRAY: // ARRAY
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.move< TipoDato > (that.value);
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        value.move< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (that.value);
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.move< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (that.value);
        break;

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        value.move< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_ARRAY: // ARRAY
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_NUMERO: // NUMERO
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 626 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 632 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 638 "parser.cpp"
        break;

      case symbol_kind::S_SUMA: // SUMA
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 644 "parser.cpp"
        break;

      case symbol_kind::S_MENOS: // MENOS
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 650 "parser.cpp"
        break;

      case symbol_kind::S_POR: // POR
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 656 "parser.cpp"
        break;

      case symbol_kind::S_DIV: // DIV
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 662 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 668 "parser.cpp"
        break;

      case symbol_kind::S_RIF: // RIF
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 674 "parser.cpp"
        break;

      case symbol_kind::S_RELSE: // RELSE
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 680 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 686 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 692 "parser.cpp"
        break;

      case symbol_kind::S_TSTRING: // TSTRING
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 698 "parser.cpp"
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 704 "parser.cpp"
        break;

      case symbol_kind::S_PARA: // PARA
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 710 "parser.cpp"
        break;

      case symbol_kind::S_PARC: // PARC
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 716 "parser.cpp"
        break;

      case symbol_kind::S_RMAIN: // RMAIN
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 722 "parser.cpp"
        break;

      case symbol_kind::S_LLAVA: // LLAVA
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 728 "parser.cpp"
        break;

      case symbol_kind::S_LLAVC: // LLAVC
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 734 "parser.cpp"
        break;

      case symbol_kind::S_RTRUE: // RTRUE
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 740 "parser.cpp"
        break;

      case symbol_kind::S_RFALSE: // RFALSE
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 746 "parser.cpp"
        break;

      case symbol_kind::S_CORA: // CORA
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 752 "parser.cpp"
        break;

      case symbol_kind::S_CORC: // CORC
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 758 "parser.cpp"
        break;

      case symbol_kind::S_MAY: // MAY
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 764 "parser.cpp"
        break;

      case symbol_kind::S_MEN: // MEN
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 770 "parser.cpp"
        break;

      case symbol_kind::S_MAY_IG: // MAY_IG
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 776 "parser.cpp"
        break;

      case symbol_kind::S_MEN_IG: // MEN_IG
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 782 "parser.cpp"
        break;

      case symbol_kind::S_DIF: // DIF
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 788 "parser.cpp"
        break;

      case symbol_kind::S_IG: // IG
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 794 "parser.cpp"
        break;

      case symbol_kind::S_AND: // AND
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 800 "parser.cpp"
        break;

      case symbol_kind::S_OR: // OR
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 806 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 812 "parser.cpp"
        break;

      case symbol_kind::S_RRETURN: // RRETURN
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 818 "parser.cpp"
        break;

      case symbol_kind::S_ARRAY: // ARRAY
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 824 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 830 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 836 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 842 "parser.cpp"
        break;

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 848 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 854 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 860 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 866 "parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 872 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 878 "parser.cpp"
        break;

      case symbol_kind::S_DECLARATION: // DECLARATION
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 884 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 890 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 896 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF: // ELSEIF
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 902 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 908 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 914 "parser.cpp"
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 920 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 926 "parser.cpp"
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 932 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 938 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 944 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 950 "parser.cpp"
        break;

      case symbol_kind::S_BOOL: // BOOL
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 956 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 962 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 968 "parser.cpp"
        break;

      case symbol_kind::S_CALL_INST: // CALL_INST
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 974 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, loc, ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_TYPES: // TYPES
        yylhs.value.emplace< TipoDato > ();
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        yylhs.value.emplace< expression* > ();
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        yylhs.value.emplace< func_main* > ();
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
      case symbol_kind::S_CALL_INST: // CALL_INST
        yylhs.value.emplace< instruction* > ();
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        yylhs.value.emplace< list_expression* > ();
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        yylhs.value.emplace< list_instruction* > ();
        break;

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        yylhs.value.emplace< map_struct_dec* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_ARRAY: // ARRAY
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // START: MAIN
#line 126 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1315 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 133 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1326 "parser.cpp"
    break;

  case 4: // LIST_FUNC: LIST_FUNC FUNCTION
#line 142 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1335 "parser.cpp"
    break;

  case 5: // LIST_FUNC: FUNCTION
#line 147 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1344 "parser.cpp"
    break;

  case 6: // FUNCTION: TYPES ID PARA FUNC_LIST PARC LLAVA LIST_INST LLAVC
#line 154 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());
        }
#line 1352 "parser.cpp"
    break;

  case 7: // FUNCTION: TYPES ID PARA PARC LLAVA LIST_INST LLAVC
#line 158 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());
        }
#line 1360 "parser.cpp"
    break;

  case 8: // FUNC_LIST: FUNC_LIST ',' TYPES ID
#line 164 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1369 "parser.cpp"
    break;

  case 9: // FUNC_LIST: TYPES ID
#line 169 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), yystack_[1].value.as < TipoDato > ());
        }
#line 1378 "parser.cpp"
    break;

  case 10: // MAIN: VOID RMAIN PARA PARC LLAVA LIST_INST LLAVC
#line 176 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1386 "parser.cpp"
    break;

  case 11: // LIST_INST: LIST_INST INSTRUCTION
#line 182 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1395 "parser.cpp"
    break;

  case 12: // LIST_INST: INSTRUCTION
#line 187 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1404 "parser.cpp"
    break;

  case 13: // INSTRUCTION: PRINT ';'
#line 193 "parser.y"
                                { std::cout << "entra a instruc print"; yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1410 "parser.cpp"
    break;

  case 14: // INSTRUCTION: DECLARATION ';'
#line 194 "parser.y"
                              { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1416 "parser.cpp"
    break;

  case 15: // INSTRUCTION: IF
#line 195 "parser.y"
                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1422 "parser.cpp"
    break;

  case 16: // INSTRUCTION: STRUCT_DECLARATION
#line 196 "parser.y"
                                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1428 "parser.cpp"
    break;

  case 17: // INSTRUCTION: STRUCT_CREATION
#line 197 "parser.y"
                              { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1434 "parser.cpp"
    break;

  case 18: // INSTRUCTION: CALL_INST
#line 198 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1440 "parser.cpp"
    break;

  case 19: // INSTRUCTION: RETURN ';'
#line 199 "parser.y"
                         { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1446 "parser.cpp"
    break;

  case 20: // RETURN: RRETURN EXP
#line 202 "parser.y"
                     { yylhs.value.as < instruction* > () = new inst_return(0,0,yystack_[0].value.as < expression* > ()); }
#line 1452 "parser.cpp"
    break;

  case 21: // RETURN: RRETURN
#line 203 "parser.y"
              { yylhs.value.as < instruction* > () = new inst_return(0,0,nullptr); }
#line 1458 "parser.cpp"
    break;

  case 22: // PRINT: PRINTF PARA EXP PARC
#line 206 "parser.y"
                             { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1464 "parser.cpp"
    break;

  case 23: // DECLARATION: TYPES ID '=' EXP
#line 209 "parser.y"
                               { yylhs.value.as < instruction* > () = new declaration(0,0,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ()); }
#line 1470 "parser.cpp"
    break;

  case 24: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
#line 213 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[5].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());
    }
#line 1478 "parser.cpp"
    break;

  case 25: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSE
#line 217 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());
    }
#line 1486 "parser.cpp"
    break;

  case 26: // ELSEIF_LIST: ELSEIF_LIST ELSEIF
#line 223 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1495 "parser.cpp"
    break;

  case 27: // ELSEIF_LIST: ELSEIF
#line 228 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1504 "parser.cpp"
    break;

  case 28: // ELSEIF: RELSE RIF EXP LLAVA LIST_INST LLAVC
#line 235 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1512 "parser.cpp"
    break;

  case 29: // ELSE: RELSE LLAVA LIST_INST LLAVC
#line 240 "parser.y"
                                   { yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > (); }
#line 1518 "parser.cpp"
    break;

  case 30: // ELSE: %empty
#line 241 "parser.y"
             { }
#line 1524 "parser.cpp"
    break;

  case 31: // STRUCT_DECLARATION: STRUCT ID LLAVA DEC_LIST LLAVC
#line 244 "parser.y"
                                                    {yylhs.value.as < instruction* > () = new dec_struct(0,0,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ()); }
#line 1530 "parser.cpp"
    break;

  case 32: // DEC_LIST: DEC_LIST TYPES ID ';'
#line 248 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1539 "parser.cpp"
    break;

  case 33: // DEC_LIST: TYPES ID ';'
#line 253 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 1548 "parser.cpp"
    break;

  case 34: // STRUCT_CREATION: STRUCT ID ID '=' LLAVA EXP_LIST LLAVC
#line 260 "parser.y"
                {
                    yylhs.value.as < instruction* > () = new create_struct(0,0,yystack_[5].value.as < std::string > (),yystack_[4].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());
                }
#line 1556 "parser.cpp"
    break;

  case 35: // EXP_LIST: EXP_LIST ',' EXP
#line 266 "parser.y"
        {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 1565 "parser.cpp"
    break;

  case 36: // EXP_LIST: EXP
#line 271 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 1574 "parser.cpp"
    break;

  case 37: // TYPES: INT
#line 277 "parser.y"
            { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1580 "parser.cpp"
    break;

  case 38: // TYPES: TSTRING
#line 278 "parser.y"
              { yylhs.value.as < TipoDato > () = STRING; }
#line 1586 "parser.cpp"
    break;

  case 39: // TYPES: BOOLEAN
#line 279 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1592 "parser.cpp"
    break;

  case 40: // TYPES: VOID
#line 280 "parser.y"
           { yylhs.value.as < TipoDato > () = NULO; }
#line 1598 "parser.cpp"
    break;

  case 41: // TYPES: ARRAY
#line 281 "parser.y"
            { yylhs.value.as < TipoDato > () = ARRAY; }
#line 1604 "parser.cpp"
    break;

  case 42: // EXP: EXP SUMA EXP
#line 284 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1610 "parser.cpp"
    break;

  case 43: // EXP: EXP MENOS EXP
#line 285 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1616 "parser.cpp"
    break;

  case 44: // EXP: EXP POR EXP
#line 286 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1622 "parser.cpp"
    break;

  case 45: // EXP: EXP DIV EXP
#line 287 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1628 "parser.cpp"
    break;

  case 46: // EXP: EXP MEN EXP
#line 288 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 1634 "parser.cpp"
    break;

  case 47: // EXP: EXP MAY EXP
#line 289 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 1640 "parser.cpp"
    break;

  case 48: // EXP: EXP MEN_IG EXP
#line 290 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 1646 "parser.cpp"
    break;

  case 49: // EXP: EXP MAY_IG EXP
#line 291 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 1652 "parser.cpp"
    break;

  case 50: // EXP: EXP DIF EXP
#line 292 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 1658 "parser.cpp"
    break;

  case 51: // EXP: EXP IG EXP
#line 293 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 1664 "parser.cpp"
    break;

  case 52: // EXP: EXP AND EXP
#line 294 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 1670 "parser.cpp"
    break;

  case 53: // EXP: EXP OR EXP
#line 295 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 1676 "parser.cpp"
    break;

  case 54: // EXP: PARA EXP PARC
#line 296 "parser.y"
                    { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 1682 "parser.cpp"
    break;

  case 55: // EXP: LLAVA EXP_LIST LLAVC
#line 297 "parser.y"
                           { yylhs.value.as < expression* > () = new array_exp(0,0,yystack_[1].value.as < list_expression* > ()); }
#line 1688 "parser.cpp"
    break;

  case 56: // EXP: PRIMITIVE
#line 298 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1694 "parser.cpp"
    break;

  case 57: // EXP: CALL_EXP
#line 299 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1700 "parser.cpp"
    break;

  case 58: // PRIMITIVE: NUMERO
#line 303 "parser.y"
        {
            int num = stoi(yystack_[0].value.as < std::string > ());
            yylhs.value.as < expression* > () = new primitive(0,0,INTEGER,"",num,false);
        }
#line 1709 "parser.cpp"
    break;

  case 59: // PRIMITIVE: STRING
#line 308 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(0,0,STRING,str2,0,false);
        }
#line 1719 "parser.cpp"
    break;

  case 60: // PRIMITIVE: BOOL
#line 313 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1725 "parser.cpp"
    break;

  case 61: // PRIMITIVE: LIST_ARR
#line 314 "parser.y"
                   { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1731 "parser.cpp"
    break;

  case 62: // BOOL: RTRUE
#line 317 "parser.y"
             { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,true); }
#line 1737 "parser.cpp"
    break;

  case 63: // BOOL: RFALSE
#line 318 "parser.y"
             { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,false); }
#line 1743 "parser.cpp"
    break;

  case 64: // LIST_ARR: LIST_ARR CORA EXP CORC
#line 321 "parser.y"
                                  { yylhs.value.as < expression* > () = new array_access(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 1749 "parser.cpp"
    break;

  case 65: // LIST_ARR: LIST_ARR '.' ID
#line 322 "parser.y"
                          { yylhs.value.as < expression* > () = new struct_access(0,0,yystack_[2].value.as < expression* > (),yystack_[0].value.as < std::string > ()); }
#line 1755 "parser.cpp"
    break;

  case 66: // LIST_ARR: ID
#line 323 "parser.y"
             {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ()); }
#line 1761 "parser.cpp"
    break;

  case 67: // CALL_EXP: ID PARA EXP_LIST PARC
#line 326 "parser.y"
                                 { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 1767 "parser.cpp"
    break;

  case 68: // CALL_EXP: ID PARA PARC
#line 327 "parser.y"
                       { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[2].value.as < std::string > (),nullptr); }
#line 1773 "parser.cpp"
    break;

  case 69: // CALL_INST: ID PARA EXP_LIST PARC ';'
#line 330 "parser.y"
                                      { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[4].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());}
#line 1779 "parser.cpp"
    break;

  case 70: // CALL_INST: ID PARA PARC ';'
#line 331 "parser.y"
                           { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[3].value.as < std::string > (),nullptr); }
#line 1785 "parser.cpp"
    break;


#line 1789 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char Parser::yypact_ninf_ = -47;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      37,   -10,   -47,   -47,   -47,   -47,    10,    37,   -47,   -47,
      15,    22,   -47,   -47,   -47,    26,    27,    75,    24,   -47,
      28,   -15,    42,   182,   182,    29,   112,   -47,    40,    57,
     347,    73,   347,    20,   -47,    63,    64,    65,   -47,   -47,
     -47,   100,   -47,    71,   182,   104,   322,   347,   -47,    62,
     -47,   347,   347,   -47,   -47,   193,   -47,   -47,   -17,   -47,
      43,   280,   -47,   -47,   -47,   -47,   -47,    56,   -47,    99,
     -47,    81,   -14,   280,   221,   343,   237,     0,   347,   347,
     347,   347,   182,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   119,    91,   112,   347,   -47,   -47,    94,   347,
     -47,   -47,    -3,   -47,   -47,     8,     8,   -47,   -47,   126,
      90,    90,    90,    90,   308,   308,   293,   293,   250,   -47,
     118,   151,   128,   280,   -47,   280,   -47,   131,   -47,   347,
     -47,   140,   108,    -6,   131,   -47,   -47,     2,   113,   -47,
     347,   182,   -47,   -47,   -47,   -47,   265,   142,   182,   -47,
     169,   -47
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    40,    37,    38,    39,    41,     0,     0,     5,     2,
       0,     0,     1,     4,     3,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,    21,     0,    12,     0,     0,     0,    15,    16,
      17,     0,    18,     0,     0,     0,     0,     0,    58,    66,
      59,     0,     0,    62,    63,     0,    56,    60,    61,    57,
       0,    20,    10,    11,    19,    13,    14,     0,     7,     0,
       8,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,    70,     0,     0,
      22,    68,     0,    54,    55,    42,    43,    44,    45,     0,
      47,    46,    49,    48,    50,    51,    52,    53,     0,    65,
       0,     0,     0,    23,    69,    35,    67,    30,    64,     0,
      31,     0,     0,     0,    30,    27,    25,     0,     0,    33,
       0,     0,    26,    24,    34,    32,     0,     0,     0,    29,
       0,    28
  };

  const short
  Parser::yypgoto_[] =
  {
     -47,   -47,   -47,   144,   -47,   147,   -24,   -31,   -47,   -47,
     -47,   -47,   -47,    25,    34,   -47,   -47,   -47,   -46,     1,
     -19,   -47,   -47,   -47,   -47,   -47
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     6,     7,     8,    21,     9,    33,    34,    35,    36,
      37,    38,   134,   135,   136,    39,   121,    40,    72,    41,
      73,    56,    57,    58,    59,    42
  };

  const unsigned char
  Parser::yytable_[] =
  {
      43,    10,    63,    25,    98,   140,    77,    91,    10,    11,
      12,    55,    63,    61,   141,   126,    80,    81,    22,    15,
      69,   104,    92,   144,    28,    26,    99,    45,    74,   102,
      29,    30,    76,    19,     2,     3,     4,    99,    63,    16,
      99,    62,    99,    17,    23,    18,    27,    93,    24,    44,
       1,     2,     3,     4,    31,    32,     5,    46,   109,   105,
     106,   107,   108,    94,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     5,    47,    28,   123,    60,    63,    75,
     125,    29,    30,   137,    19,     2,     3,     4,    19,     2,
       3,     4,    68,    20,    95,   122,    78,    79,    80,    81,
      64,    65,    66,    28,    67,    31,    32,     5,    70,    29,
      30,     5,    19,     2,     3,     4,    63,   147,    97,    63,
      96,   146,   131,   119,   150,    19,     2,     3,     4,   120,
      28,   124,   132,    31,    32,     5,    29,    30,   129,    19,
       2,     3,     4,   133,   138,   139,    28,   127,     5,     0,
     145,    13,    29,    30,    14,    19,     2,     3,     4,   142,
      31,    32,     5,   149,    19,     2,     3,     4,   143,     0,
       0,     0,   130,    28,     0,     0,    31,    32,     5,    29,
      30,     0,    19,     2,     3,     4,    28,     5,     0,     0,
     151,     0,    29,    30,     0,    19,     2,     3,     4,    78,
      79,    80,    81,    31,    32,     5,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,    31,    32,     5,    83,
      84,    85,    86,    87,    88,    89,    90,    78,    79,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,     0,    78,    79,    80,    81,    83,    84,    85,
      86,    87,    88,    89,    90,   103,    78,    79,    80,    81,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    78,    79,    80,    81,   128,    83,    84,    85,    86,
      87,    88,    89,    90,     0,   148,    78,    79,    80,    81,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    78,
      79,    80,    81,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    78,    79,    80,    81,     0,    83,
      84,    85,    86,    87,    88,    48,    49,    50,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,    51,
      71,     0,    52,     0,    53,    54,    48,    49,    50,     0,
      48,    49,    50,     0,     0,     0,     0,     0,     0,     0,
      51,   101,     0,    52,    51,    53,    54,    52,     0,    53,
      54
  };

  const short
  Parser::yycheck_[] =
  {
      24,     0,    33,    18,    18,    11,    52,    24,     7,    19,
       0,    30,    43,    32,    20,    18,     8,     9,    17,     4,
      44,    21,    39,    21,     4,    40,    40,    26,    47,    75,
      10,    11,    51,    13,    14,    15,    16,    40,    69,    17,
      40,    21,    40,    17,    20,    18,     4,     4,    20,    20,
      13,    14,    15,    16,    34,    35,    36,    17,    82,    78,
      79,    80,    81,    20,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    36,    17,     4,    95,     4,   109,    17,
      99,    10,    11,   129,    13,    14,    15,    16,    13,    14,
      15,    16,    21,    18,    38,    94,     6,     7,     8,     9,
      37,    37,    37,     4,     4,    34,    35,    36,     4,    10,
      11,    36,    13,    14,    15,    16,   147,   141,    37,   150,
      21,   140,   121,     4,   148,    13,    14,    15,    16,    38,
       4,    37,     4,    34,    35,    36,    10,    11,    20,    13,
      14,    15,    16,    12,     4,    37,     4,    21,    36,    -1,
      37,     7,    10,    11,     7,    13,    14,    15,    16,   134,
      34,    35,    36,    21,    13,    14,    15,    16,   134,    -1,
      -1,    -1,    21,     4,    -1,    -1,    34,    35,    36,    10,
      11,    -1,    13,    14,    15,    16,     4,    36,    -1,    -1,
      21,    -1,    10,    11,    -1,    13,    14,    15,    16,     6,
       7,     8,     9,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    34,    35,    36,    26,
      27,    28,    29,    30,    31,    32,    33,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,     6,     7,     8,     9,    26,    27,    28,
      29,    30,    31,    32,    33,    18,     6,     7,     8,     9,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,     6,     7,     8,     9,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    20,     6,     7,     8,     9,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     6,
       7,     8,     9,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,     6,     7,     8,     9,    -1,    26,
      27,    28,    29,    30,    31,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,    17,
      18,    -1,    20,    -1,    22,    23,     3,     4,     5,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    17,    22,    23,    20,    -1,    22,
      23
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    14,    15,    16,    36,    42,    43,    44,    46,
      60,    19,     0,    44,    46,     4,    17,    17,    18,    13,
      18,    45,    60,    20,    20,    18,    40,     4,     4,    10,
      11,    34,    35,    47,    48,    49,    50,    51,    52,    56,
      58,    60,    66,    47,    20,    60,    17,    17,     3,     4,
       5,    17,    20,    22,    23,    61,    62,    63,    64,    65,
       4,    61,    21,    48,    37,    37,    37,     4,    21,    47,
       4,    18,    59,    61,    61,    17,    61,    59,     6,     7,
       8,     9,    20,    26,    27,    28,    29,    30,    31,    32,
      33,    24,    39,     4,    20,    38,    21,    37,    18,    40,
      18,    18,    59,    18,    21,    61,    61,    61,    61,    47,
      61,    61,    61,    61,    61,    61,    61,    61,    61,     4,
      38,    57,    60,    61,    37,    61,    18,    21,    25,    20,
      21,    60,     4,    12,    53,    54,    55,    59,     4,    37,
      11,    20,    54,    55,    21,    37,    61,    47,    20,    21,
      47,    21
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      49,    49,    50,    51,    52,    52,    53,    53,    54,    55,
      55,    56,    57,    57,    58,    59,    59,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    63,    63,    64,    64,    64,    65,    65,    66,
      66
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     8,     7,     4,     2,
       7,     2,     1,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     4,     4,     7,     6,     2,     1,     6,     4,
       0,     5,     4,     3,     7,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     1,     4,     3,     5,
       4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING", "SUMA",
  "MENOS", "POR", "DIV", "PRINTF", "RIF", "RELSE", "VOID", "INT",
  "TSTRING", "BOOLEAN", "PARA", "PARC", "RMAIN", "LLAVA", "LLAVC", "RTRUE",
  "RFALSE", "CORA", "CORC", "MAY", "MEN", "MAY_IG", "MEN_IG", "DIF", "IG",
  "AND", "OR", "STRUCT", "RRETURN", "ARRAY", "';'", "'='", "'.'", "','",
  "$accept", "START", "LIST_FUNC", "FUNCTION", "FUNC_LIST", "MAIN",
  "LIST_INST", "INSTRUCTION", "RETURN", "PRINT", "DECLARATION", "IF",
  "ELSEIF_LIST", "ELSEIF", "ELSE", "STRUCT_DECLARATION", "DEC_LIST",
  "STRUCT_CREATION", "EXP_LIST", "TYPES", "EXP", "PRIMITIVE", "BOOL",
  "LIST_ARR", "CALL_EXP", "CALL_INST", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   125,   125,   132,   141,   146,   153,   157,   163,   168,
     175,   181,   186,   193,   194,   195,   196,   197,   198,   199,
     202,   203,   206,   209,   212,   216,   222,   227,   234,   240,
     241,   244,   247,   252,   259,   265,   270,   277,   278,   279,
     280,   281,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   302,   307,
     313,   314,   317,   318,   321,   322,   323,   326,   327,   330,
     331
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2237 "parser.cpp"

#line 334 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
        std::cerr << l << ": " << m << std::endl;
}


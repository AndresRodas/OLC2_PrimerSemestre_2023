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
#line 67 "parser.y"
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
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 622 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 628 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 634 "parser.cpp"
        break;

      case symbol_kind::S_SUMA: // SUMA
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 640 "parser.cpp"
        break;

      case symbol_kind::S_MENOS: // MENOS
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 646 "parser.cpp"
        break;

      case symbol_kind::S_POR: // POR
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 652 "parser.cpp"
        break;

      case symbol_kind::S_DIV: // DIV
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 658 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 664 "parser.cpp"
        break;

      case symbol_kind::S_RIF: // RIF
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 670 "parser.cpp"
        break;

      case symbol_kind::S_RELSE: // RELSE
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 676 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 682 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 688 "parser.cpp"
        break;

      case symbol_kind::S_TSTRING: // TSTRING
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 694 "parser.cpp"
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 700 "parser.cpp"
        break;

      case symbol_kind::S_PARA: // PARA
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 706 "parser.cpp"
        break;

      case symbol_kind::S_PARC: // PARC
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 712 "parser.cpp"
        break;

      case symbol_kind::S_RMAIN: // RMAIN
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 718 "parser.cpp"
        break;

      case symbol_kind::S_LLAVA: // LLAVA
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 724 "parser.cpp"
        break;

      case symbol_kind::S_LLAVC: // LLAVC
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 730 "parser.cpp"
        break;

      case symbol_kind::S_RTRUE: // RTRUE
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 736 "parser.cpp"
        break;

      case symbol_kind::S_RFALSE: // RFALSE
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 742 "parser.cpp"
        break;

      case symbol_kind::S_CORA: // CORA
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 748 "parser.cpp"
        break;

      case symbol_kind::S_CORC: // CORC
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 754 "parser.cpp"
        break;

      case symbol_kind::S_MAY: // MAY
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 760 "parser.cpp"
        break;

      case symbol_kind::S_MEN: // MEN
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 766 "parser.cpp"
        break;

      case symbol_kind::S_MAY_IG: // MAY_IG
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 772 "parser.cpp"
        break;

      case symbol_kind::S_MEN_IG: // MEN_IG
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 778 "parser.cpp"
        break;

      case symbol_kind::S_DIF: // DIF
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 784 "parser.cpp"
        break;

      case symbol_kind::S_IG: // IG
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 790 "parser.cpp"
        break;

      case symbol_kind::S_AND: // AND
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 796 "parser.cpp"
        break;

      case symbol_kind::S_OR: // OR
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 802 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 808 "parser.cpp"
        break;

      case symbol_kind::S_RRETURN: // RRETURN
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 814 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 820 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 826 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 832 "parser.cpp"
        break;

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 838 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 844 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 850 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 856 "parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 862 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 868 "parser.cpp"
        break;

      case symbol_kind::S_DECLARATION: // DECLARATION
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 874 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 880 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 886 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF: // ELSEIF
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 892 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 898 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 904 "parser.cpp"
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 910 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 916 "parser.cpp"
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 922 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 928 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 934 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 940 "parser.cpp"
        break;

      case symbol_kind::S_BOOL: // BOOL
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 946 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 952 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 958 "parser.cpp"
        break;

      case symbol_kind::S_CALL_INST: // CALL_INST
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 964 "parser.cpp"
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
#line 125 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1304 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 132 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1315 "parser.cpp"
    break;

  case 4: // LIST_FUNC: LIST_FUNC FUNCTION
#line 141 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1324 "parser.cpp"
    break;

  case 5: // LIST_FUNC: FUNCTION
#line 146 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1333 "parser.cpp"
    break;

  case 6: // FUNCTION: TYPES ID PARA FUNC_LIST PARC LLAVA LIST_INST LLAVC
#line 153 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());
        }
#line 1341 "parser.cpp"
    break;

  case 7: // FUNCTION: TYPES ID PARA PARC LLAVA LIST_INST LLAVC
#line 157 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());
        }
#line 1349 "parser.cpp"
    break;

  case 8: // FUNC_LIST: FUNC_LIST ',' TYPES ID
#line 163 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1358 "parser.cpp"
    break;

  case 9: // FUNC_LIST: TYPES ID
#line 168 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), yystack_[1].value.as < TipoDato > ());
        }
#line 1367 "parser.cpp"
    break;

  case 10: // MAIN: VOID RMAIN PARA PARC LLAVA LIST_INST LLAVC
#line 175 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1375 "parser.cpp"
    break;

  case 11: // LIST_INST: LIST_INST INSTRUCTION
#line 181 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1384 "parser.cpp"
    break;

  case 12: // LIST_INST: INSTRUCTION
#line 186 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1393 "parser.cpp"
    break;

  case 13: // INSTRUCTION: PRINT ';'
#line 192 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1399 "parser.cpp"
    break;

  case 14: // INSTRUCTION: DECLARATION ';'
#line 193 "parser.y"
                              { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1405 "parser.cpp"
    break;

  case 15: // INSTRUCTION: IF
#line 194 "parser.y"
                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1411 "parser.cpp"
    break;

  case 16: // INSTRUCTION: STRUCT_DECLARATION
#line 195 "parser.y"
                                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1417 "parser.cpp"
    break;

  case 17: // INSTRUCTION: STRUCT_CREATION
#line 196 "parser.y"
                              { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1423 "parser.cpp"
    break;

  case 18: // INSTRUCTION: CALL_INST
#line 197 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1429 "parser.cpp"
    break;

  case 19: // INSTRUCTION: RETURN ';'
#line 198 "parser.y"
                         { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1435 "parser.cpp"
    break;

  case 20: // RETURN: RRETURN EXP
#line 201 "parser.y"
                     { yylhs.value.as < instruction* > () = new inst_return(0,0,yystack_[0].value.as < expression* > ()); }
#line 1441 "parser.cpp"
    break;

  case 21: // RETURN: RRETURN
#line 202 "parser.y"
              { yylhs.value.as < instruction* > () = new inst_return(0,0,nullptr); }
#line 1447 "parser.cpp"
    break;

  case 22: // PRINT: PRINTF PARA EXP PARC
#line 205 "parser.y"
                             { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1453 "parser.cpp"
    break;

  case 23: // DECLARATION: TYPES ID '=' EXP
#line 208 "parser.y"
                               { yylhs.value.as < instruction* > () = new declaration(0,0,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ()); }
#line 1459 "parser.cpp"
    break;

  case 24: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
#line 212 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[5].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());
    }
#line 1467 "parser.cpp"
    break;

  case 25: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSE
#line 216 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());
    }
#line 1475 "parser.cpp"
    break;

  case 26: // ELSEIF_LIST: ELSEIF_LIST ELSEIF
#line 222 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1484 "parser.cpp"
    break;

  case 27: // ELSEIF_LIST: ELSEIF
#line 227 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1493 "parser.cpp"
    break;

  case 28: // ELSEIF: RELSE RIF EXP LLAVA LIST_INST LLAVC
#line 234 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1501 "parser.cpp"
    break;

  case 29: // ELSE: RELSE LLAVA LIST_INST LLAVC
#line 239 "parser.y"
                                   { yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > (); }
#line 1507 "parser.cpp"
    break;

  case 30: // ELSE: %empty
#line 240 "parser.y"
             { }
#line 1513 "parser.cpp"
    break;

  case 31: // STRUCT_DECLARATION: STRUCT ID LLAVA DEC_LIST LLAVC
#line 243 "parser.y"
                                                    {yylhs.value.as < instruction* > () = new dec_struct(0,0,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ()); }
#line 1519 "parser.cpp"
    break;

  case 32: // DEC_LIST: DEC_LIST TYPES ID ';'
#line 247 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1528 "parser.cpp"
    break;

  case 33: // DEC_LIST: TYPES ID ';'
#line 252 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 1537 "parser.cpp"
    break;

  case 34: // STRUCT_CREATION: STRUCT ID ID '=' LLAVA EXP_LIST LLAVC
#line 259 "parser.y"
                {
                    yylhs.value.as < instruction* > () = new create_struct(0,0,yystack_[5].value.as < std::string > (),yystack_[4].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());
                }
#line 1545 "parser.cpp"
    break;

  case 35: // EXP_LIST: EXP_LIST ',' EXP
#line 265 "parser.y"
        {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 1554 "parser.cpp"
    break;

  case 36: // EXP_LIST: EXP
#line 270 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 1563 "parser.cpp"
    break;

  case 37: // TYPES: INT
#line 276 "parser.y"
            { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1569 "parser.cpp"
    break;

  case 38: // TYPES: TSTRING
#line 277 "parser.y"
              { yylhs.value.as < TipoDato > () = STRING; }
#line 1575 "parser.cpp"
    break;

  case 39: // TYPES: BOOLEAN
#line 278 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1581 "parser.cpp"
    break;

  case 40: // TYPES: VOID
#line 279 "parser.y"
           { yylhs.value.as < TipoDato > () = NULO; }
#line 1587 "parser.cpp"
    break;

  case 41: // EXP: EXP SUMA EXP
#line 282 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1593 "parser.cpp"
    break;

  case 42: // EXP: EXP MENOS EXP
#line 283 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1599 "parser.cpp"
    break;

  case 43: // EXP: EXP POR EXP
#line 284 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1605 "parser.cpp"
    break;

  case 44: // EXP: EXP DIV EXP
#line 285 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1611 "parser.cpp"
    break;

  case 45: // EXP: EXP MEN EXP
#line 286 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 1617 "parser.cpp"
    break;

  case 46: // EXP: EXP MAY EXP
#line 287 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 1623 "parser.cpp"
    break;

  case 47: // EXP: EXP MEN_IG EXP
#line 288 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 1629 "parser.cpp"
    break;

  case 48: // EXP: EXP MAY_IG EXP
#line 289 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 1635 "parser.cpp"
    break;

  case 49: // EXP: EXP DIF EXP
#line 290 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 1641 "parser.cpp"
    break;

  case 50: // EXP: EXP IG EXP
#line 291 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 1647 "parser.cpp"
    break;

  case 51: // EXP: EXP AND EXP
#line 292 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 1653 "parser.cpp"
    break;

  case 52: // EXP: EXP OR EXP
#line 293 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 1659 "parser.cpp"
    break;

  case 53: // EXP: PARA EXP PARC
#line 294 "parser.y"
                    { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 1665 "parser.cpp"
    break;

  case 54: // EXP: CALL_EXP
#line 295 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1671 "parser.cpp"
    break;

  case 55: // EXP: PRIMITIVE
#line 296 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1677 "parser.cpp"
    break;

  case 56: // PRIMITIVE: NUMERO
#line 300 "parser.y"
        {
            int num = stoi(yystack_[0].value.as < std::string > ());
            yylhs.value.as < expression* > () = new primitive(0,0,INTEGER,"",num,false);
        }
#line 1686 "parser.cpp"
    break;

  case 57: // PRIMITIVE: STRING
#line 305 "parser.y"
        { 
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(0,0,STRING,str2,0,false);
        }
#line 1696 "parser.cpp"
    break;

  case 58: // PRIMITIVE: BOOL
#line 310 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1702 "parser.cpp"
    break;

  case 59: // PRIMITIVE: LIST_ARR
#line 311 "parser.y"
                   { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1708 "parser.cpp"
    break;

  case 60: // BOOL: RTRUE
#line 314 "parser.y"
             { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,true); }
#line 1714 "parser.cpp"
    break;

  case 61: // BOOL: RFALSE
#line 315 "parser.y"
             { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,false); }
#line 1720 "parser.cpp"
    break;

  case 62: // LIST_ARR: LIST_ARR CORA EXP CORC
#line 318 "parser.y"
                                  { yylhs.value.as < expression* > () = new array_access(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 1726 "parser.cpp"
    break;

  case 63: // LIST_ARR: LIST_ARR '.' ID
#line 319 "parser.y"
                          { yylhs.value.as < expression* > () = new struct_access(0,0,yystack_[2].value.as < expression* > (),yystack_[0].value.as < std::string > ()); }
#line 1732 "parser.cpp"
    break;

  case 64: // LIST_ARR: ID
#line 320 "parser.y"
             {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ()); }
#line 1738 "parser.cpp"
    break;

  case 65: // CALL_EXP: ID PARA EXP_LIST PARC
#line 323 "parser.y"
                                 { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 1744 "parser.cpp"
    break;

  case 66: // CALL_EXP: ID PARA PARC
#line 324 "parser.y"
                       { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[2].value.as < std::string > (),nullptr); }
#line 1750 "parser.cpp"
    break;

  case 67: // CALL_INST: ID PARA EXP_LIST PARC ';'
#line 327 "parser.y"
                                      { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[4].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());}
#line 1756 "parser.cpp"
    break;

  case 68: // CALL_INST: ID PARA PARC ';'
#line 328 "parser.y"
                           { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[3].value.as < std::string > (),nullptr); }
#line 1762 "parser.cpp"
    break;


#line 1766 "parser.cpp"

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





  const signed char Parser::yypact_ninf_ = -71;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      82,    -8,   -71,   -71,   -71,    14,    82,   -71,   -71,    27,
      16,   -71,   -71,   -71,    19,    33,   194,    34,   -71,    43,
     -14,    69,   184,   184,    54,   308,   -71,    61,    62,   151,
      77,   151,    73,   -71,    46,    49,    55,   -71,   -71,   -71,
      86,   -71,    89,   184,    97,    35,   151,   -71,    92,   -71,
     151,   -71,   -71,    15,   -71,   -71,   -19,   -71,    12,   266,
     -71,   -71,   -71,   -71,   -71,    74,   -71,   115,   -71,    70,
     -12,   266,   195,   297,   223,   151,   151,   151,   151,   184,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   108,
      78,   308,   151,   -71,   -71,    81,   151,   -71,   -71,   -10,
     -71,    41,    41,   -71,   -71,   130,   319,   319,   319,   319,
     279,   279,   208,   208,   236,   -71,   102,   296,   123,   266,
     -71,   266,   -71,   120,   -71,   151,   -71,   129,    99,    -2,
     120,   -71,   -71,   -11,   101,   -71,   151,   184,   -71,   -71,
     -71,   -71,   251,   156,   184,   -71,   171,   -71
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    40,    37,    38,    39,     0,     0,     5,     2,     0,
       0,     1,     4,     3,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
       0,    21,     0,    12,     0,     0,     0,    15,    16,    17,
       0,    18,     0,     0,     0,     0,     0,    56,    64,    57,
       0,    60,    61,     0,    55,    58,    59,    54,     0,    20,
      10,    11,    19,    13,    14,     0,     7,     0,     8,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,    68,     0,     0,    22,    66,     0,
      53,    41,    42,    43,    44,     0,    46,    45,    48,    47,
      49,    50,    51,    52,     0,    63,     0,     0,     0,    23,
      67,    35,    65,    30,    62,     0,    31,     0,     0,     0,
      30,    27,    25,     0,     0,    33,     0,     0,    26,    24,
      34,    32,     0,     0,     0,    29,     0,    28
  };

  const short
  Parser::yypgoto_[] =
  {
     -71,   -71,   -71,   132,   -71,   133,   -23,   -30,   -71,   -71,
     -71,   -71,   -71,    17,    18,   -71,   -71,   -71,   -70,     1,
     -16,   -71,   -71,   -71,   -71,   -71
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,     7,    20,     8,    32,    33,    34,    35,
      36,    37,   130,   131,   132,    38,   117,    39,    70,    40,
      71,    54,    55,    56,    57,    41
  };

  const unsigned char
  Parser::yytable_[] =
  {
      42,     9,    61,    99,    24,    88,    95,     9,   122,   136,
     140,    10,    61,    53,    11,    59,    90,    21,   137,    89,
      67,    75,    76,    77,    78,    25,    44,    96,    96,    96,
      72,    14,    91,    15,    74,    79,    16,    61,    47,    48,
      49,    80,    81,    82,    83,    84,    85,    86,    87,    77,
      78,    17,    50,    69,    22,   133,   105,    51,    52,   101,
     102,   103,   104,    23,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    26,    43,    61,   119,    27,    45,    46,
     121,    58,    62,    28,    29,    63,    18,     2,     3,     4,
      65,    64,   118,    27,    60,     1,     2,     3,     4,    28,
      29,    68,    18,     2,     3,     4,    94,    30,    31,    73,
      66,    92,   115,    61,   143,   116,    61,   120,   127,    27,
     142,   146,   125,    30,    31,    28,    29,   128,    18,     2,
       3,     4,   129,   134,    27,   135,    93,   141,    12,    13,
      28,    29,     0,    18,     2,     3,     4,   138,   139,    30,
      31,   123,     0,     0,    47,    48,    49,     0,     0,     0,
      27,     0,     0,     0,    30,    31,    28,    29,    50,    18,
       2,     3,     4,    51,    52,    27,     0,   145,     0,     0,
       0,    28,    29,     0,    18,     2,     3,     4,    27,     0,
      30,    31,   147,     0,    28,    29,     0,    18,     2,     3,
       4,    75,    76,    77,    78,    30,    31,    18,     2,     3,
       4,     0,    19,    97,    75,    76,    77,    78,    30,    31,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    75,
      76,    77,    78,     0,    80,    81,    82,    83,    84,    85,
       0,   100,    75,    76,    77,    78,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    75,    76,    77,
      78,   124,    80,    81,    82,    83,    84,    85,    86,    87,
       0,   144,    75,    76,    77,    78,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    75,    76,    77,    78,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      47,    48,    49,     0,     0,    80,    81,    82,    83,    18,
       2,     3,     4,     0,    50,    98,     0,   126,     0,    51,
      52,    18,     2,     3,     4,    75,    76,    77,    78
  };

  const short
  Parser::yycheck_[] =
  {
      23,     0,    32,    73,    18,    24,    18,     6,    18,    11,
      21,    19,    42,    29,     0,    31,     4,    16,    20,    38,
      43,     6,     7,     8,     9,    39,    25,    39,    39,    39,
      46,     4,    20,    17,    50,    20,    17,    67,     3,     4,
       5,    26,    27,    28,    29,    30,    31,    32,    33,     8,
       9,    18,    17,    18,    20,   125,    79,    22,    23,    75,
      76,    77,    78,    20,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     4,    20,   105,    92,     4,    17,    17,
      96,     4,    36,    10,    11,    36,    13,    14,    15,    16,
       4,    36,    91,     4,    21,    13,    14,    15,    16,    10,
      11,     4,    13,    14,    15,    16,    36,    34,    35,    17,
      21,    37,     4,   143,   137,    37,   146,    36,   117,     4,
     136,   144,    20,    34,    35,    10,    11,     4,    13,    14,
      15,    16,    12,     4,     4,    36,    21,    36,     6,     6,
      10,    11,    -1,    13,    14,    15,    16,   130,   130,    34,
      35,    21,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    34,    35,    10,    11,    17,    13,
      14,    15,    16,    22,    23,     4,    -1,    21,    -1,    -1,
      -1,    10,    11,    -1,    13,    14,    15,    16,     4,    -1,
      34,    35,    21,    -1,    10,    11,    -1,    13,    14,    15,
      16,     6,     7,     8,     9,    34,    35,    13,    14,    15,
      16,    -1,    18,    18,     6,     7,     8,     9,    34,    35,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     6,
       7,     8,     9,    -1,    26,    27,    28,    29,    30,    31,
      -1,    18,     6,     7,     8,     9,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,     6,     7,     8,
       9,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    20,     6,     7,     8,     9,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,     6,     7,     8,     9,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
       3,     4,     5,    -1,    -1,    26,    27,    28,    29,    13,
      14,    15,    16,    -1,    17,    18,    -1,    21,    -1,    22,
      23,    13,    14,    15,    16,     6,     7,     8,     9
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    14,    15,    16,    41,    42,    43,    45,    59,
      19,     0,    43,    45,     4,    17,    17,    18,    13,    18,
      44,    59,    20,    20,    18,    39,     4,     4,    10,    11,
      34,    35,    46,    47,    48,    49,    50,    51,    55,    57,
      59,    65,    46,    20,    59,    17,    17,     3,     4,     5,
      17,    22,    23,    60,    61,    62,    63,    64,     4,    60,
      21,    47,    36,    36,    36,     4,    21,    46,     4,    18,
      58,    60,    60,    17,    60,     6,     7,     8,     9,    20,
      26,    27,    28,    29,    30,    31,    32,    33,    24,    38,
       4,    20,    37,    21,    36,    18,    39,    18,    18,    58,
      18,    60,    60,    60,    60,    46,    60,    60,    60,    60,
      60,    60,    60,    60,    60,     4,    37,    56,    59,    60,
      36,    60,    18,    21,    25,    20,    21,    59,     4,    12,
      52,    53,    54,    58,     4,    36,    11,    20,    53,    54,
      21,    36,    60,    46,    20,    21,    46,    21
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      45,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    49,    50,    51,    51,    52,    52,    53,    54,
      54,    55,    56,    56,    57,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      62,    62,    63,    63,    63,    64,    64,    65,    65
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     8,     7,     4,     2,
       7,     2,     1,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     4,     4,     7,     6,     2,     1,     6,     4,
       0,     5,     4,     3,     7,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     4,     3,     5,     4
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
  "AND", "OR", "STRUCT", "RRETURN", "';'", "'='", "'.'", "','", "$accept",
  "START", "LIST_FUNC", "FUNCTION", "FUNC_LIST", "MAIN", "LIST_INST",
  "INSTRUCTION", "RETURN", "PRINT", "DECLARATION", "IF", "ELSEIF_LIST",
  "ELSEIF", "ELSE", "STRUCT_DECLARATION", "DEC_LIST", "STRUCT_CREATION",
  "EXP_LIST", "TYPES", "EXP", "PRIMITIVE", "BOOL", "LIST_ARR", "CALL_EXP",
  "CALL_INST", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   124,   124,   131,   140,   145,   152,   156,   162,   167,
     174,   180,   185,   192,   193,   194,   195,   196,   197,   198,
     201,   202,   205,   208,   211,   215,   221,   226,   233,   239,
     240,   243,   246,   251,   258,   264,   269,   276,   277,   278,
     279,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   299,   304,   310,   311,
     314,   315,   318,   319,   320,   323,   324,   327,   328
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
#line 2198 "parser.cpp"

#line 331 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}


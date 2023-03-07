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
#line 63 "parser.y"
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
        value.YY_MOVE_OR_COPY< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.YY_MOVE_OR_COPY< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.YY_MOVE_OR_COPY< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.YY_MOVE_OR_COPY< list_instruction* > (YY_MOVE (that.value));
        break;

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
        value.move< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (YY_MOVE (that.value));
        break;

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
        value.copy< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.copy< func_main* > (that.value);
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        value.copy< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.copy< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.copy< list_instruction* > (that.value);
        break;

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
        value.move< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (that.value);
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        value.move< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (that.value);
        break;

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
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 594 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 600 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 606 "parser.cpp"
        break;

      case symbol_kind::S_SUMA: // SUMA
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 612 "parser.cpp"
        break;

      case symbol_kind::S_MENOS: // MENOS
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 618 "parser.cpp"
        break;

      case symbol_kind::S_POR: // POR
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 624 "parser.cpp"
        break;

      case symbol_kind::S_DIV: // DIV
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 630 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 636 "parser.cpp"
        break;

      case symbol_kind::S_RIF: // RIF
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 642 "parser.cpp"
        break;

      case symbol_kind::S_RELSE: // RELSE
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 648 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 654 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 660 "parser.cpp"
        break;

      case symbol_kind::S_TSTRING: // TSTRING
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 666 "parser.cpp"
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 672 "parser.cpp"
        break;

      case symbol_kind::S_PARA: // PARA
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 678 "parser.cpp"
        break;

      case symbol_kind::S_PARC: // PARC
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 684 "parser.cpp"
        break;

      case symbol_kind::S_RMAIN: // RMAIN
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 690 "parser.cpp"
        break;

      case symbol_kind::S_LLAVA: // LLAVA
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 696 "parser.cpp"
        break;

      case symbol_kind::S_LLAVC: // LLAVC
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 702 "parser.cpp"
        break;

      case symbol_kind::S_RTRUE: // RTRUE
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 708 "parser.cpp"
        break;

      case symbol_kind::S_RFALSE: // RFALSE
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 714 "parser.cpp"
        break;

      case symbol_kind::S_CORA: // CORA
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 720 "parser.cpp"
        break;

      case symbol_kind::S_CORC: // CORC
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 726 "parser.cpp"
        break;

      case symbol_kind::S_MAY: // MAY
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 732 "parser.cpp"
        break;

      case symbol_kind::S_MEN: // MEN
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 738 "parser.cpp"
        break;

      case symbol_kind::S_MAY_IG: // MAY_IG
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 744 "parser.cpp"
        break;

      case symbol_kind::S_MEN_IG: // MEN_IG
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 750 "parser.cpp"
        break;

      case symbol_kind::S_DIF: // DIF
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 756 "parser.cpp"
        break;

      case symbol_kind::S_IG: // IG
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 762 "parser.cpp"
        break;

      case symbol_kind::S_AND: // AND
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 768 "parser.cpp"
        break;

      case symbol_kind::S_OR: // OR
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 774 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 780 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 786 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 792 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 798 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 804 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 810 "parser.cpp"
        break;

      case symbol_kind::S_DECLARATION: // DECLARATION
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 816 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 822 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 828 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF: // ELSEIF
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 834 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 840 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 846 "parser.cpp"
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 852 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 858 "parser.cpp"
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 864 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 870 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 876 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 882 "parser.cpp"
        break;

      case symbol_kind::S_BOOL: // BOOL
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 888 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 107 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 894 "parser.cpp"
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
        yylhs.value.emplace< expression* > ();
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        yylhs.value.emplace< func_main* > ();
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        yylhs.value.emplace< instruction* > ();
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        yylhs.value.emplace< list_expression* > ();
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        yylhs.value.emplace< list_instruction* > ();
        break;

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
#line 115 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1226 "parser.cpp"
    break;

  case 3: // MAIN: VOID RMAIN PARA PARC LLAVA LIST_INST LLAVC
#line 123 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1234 "parser.cpp"
    break;

  case 4: // LIST_INST: LIST_INST INSTRUCTION
#line 129 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1243 "parser.cpp"
    break;

  case 5: // LIST_INST: INSTRUCTION
#line 134 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1252 "parser.cpp"
    break;

  case 6: // INSTRUCTION: PRINT ';'
#line 140 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1258 "parser.cpp"
    break;

  case 7: // INSTRUCTION: DECLARATION ';'
#line 141 "parser.y"
                              { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1264 "parser.cpp"
    break;

  case 8: // INSTRUCTION: IF
#line 142 "parser.y"
                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1270 "parser.cpp"
    break;

  case 9: // INSTRUCTION: STRUCT_DECLARATION
#line 143 "parser.y"
                                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1276 "parser.cpp"
    break;

  case 10: // INSTRUCTION: STRUCT_CREATION
#line 144 "parser.y"
                              { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1282 "parser.cpp"
    break;

  case 11: // PRINT: PRINTF PARA EXP PARC
#line 147 "parser.y"
                             { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1288 "parser.cpp"
    break;

  case 12: // DECLARATION: TYPES ID '=' EXP
#line 150 "parser.y"
                               { yylhs.value.as < instruction* > () = new declaration(0,0,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ()); }
#line 1294 "parser.cpp"
    break;

  case 13: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
#line 154 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[5].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());
    }
#line 1302 "parser.cpp"
    break;

  case 14: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSE
#line 158 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());
    }
#line 1310 "parser.cpp"
    break;

  case 15: // ELSEIF_LIST: ELSEIF_LIST ELSEIF
#line 164 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1319 "parser.cpp"
    break;

  case 16: // ELSEIF_LIST: ELSEIF
#line 169 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1328 "parser.cpp"
    break;

  case 17: // ELSEIF: RELSE RIF EXP LLAVA LIST_INST LLAVC
#line 176 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1336 "parser.cpp"
    break;

  case 18: // ELSE: RELSE LLAVA LIST_INST LLAVC
#line 181 "parser.y"
                                   { yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > (); }
#line 1342 "parser.cpp"
    break;

  case 19: // ELSE: %empty
#line 182 "parser.y"
             { }
#line 1348 "parser.cpp"
    break;

  case 20: // STRUCT_DECLARATION: STRUCT ID LLAVA DEC_LIST LLAVC
#line 185 "parser.y"
                                                    {yylhs.value.as < instruction* > () = new dec_struct(0,0,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ()); }
#line 1354 "parser.cpp"
    break;

  case 21: // DEC_LIST: DEC_LIST TYPES ID ';'
#line 189 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1363 "parser.cpp"
    break;

  case 22: // DEC_LIST: TYPES ID ';'
#line 194 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 1372 "parser.cpp"
    break;

  case 23: // STRUCT_CREATION: STRUCT ID ID '=' LLAVA EXP_LIST LLAVC
#line 201 "parser.y"
                {
                    yylhs.value.as < instruction* > () = new create_struct(0,0,yystack_[5].value.as < std::string > (),yystack_[4].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());
                }
#line 1380 "parser.cpp"
    break;

  case 24: // EXP_LIST: EXP_LIST ',' EXP
#line 207 "parser.y"
        {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 1389 "parser.cpp"
    break;

  case 25: // EXP_LIST: EXP
#line 212 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 1398 "parser.cpp"
    break;

  case 26: // TYPES: INT
#line 218 "parser.y"
            { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1404 "parser.cpp"
    break;

  case 27: // TYPES: TSTRING
#line 219 "parser.y"
              { yylhs.value.as < TipoDato > () = STRING; }
#line 1410 "parser.cpp"
    break;

  case 28: // TYPES: BOOLEAN
#line 220 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1416 "parser.cpp"
    break;

  case 29: // EXP: EXP SUMA EXP
#line 223 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1422 "parser.cpp"
    break;

  case 30: // EXP: EXP MENOS EXP
#line 224 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1428 "parser.cpp"
    break;

  case 31: // EXP: EXP POR EXP
#line 225 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1434 "parser.cpp"
    break;

  case 32: // EXP: EXP DIV EXP
#line 226 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1440 "parser.cpp"
    break;

  case 33: // EXP: EXP MEN EXP
#line 227 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 1446 "parser.cpp"
    break;

  case 34: // EXP: EXP MAY EXP
#line 228 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 1452 "parser.cpp"
    break;

  case 35: // EXP: EXP MEN_IG EXP
#line 229 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 1458 "parser.cpp"
    break;

  case 36: // EXP: EXP MAY_IG EXP
#line 230 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 1464 "parser.cpp"
    break;

  case 37: // EXP: EXP DIF EXP
#line 231 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 1470 "parser.cpp"
    break;

  case 38: // EXP: EXP IG EXP
#line 232 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 1476 "parser.cpp"
    break;

  case 39: // EXP: EXP AND EXP
#line 233 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 1482 "parser.cpp"
    break;

  case 40: // EXP: EXP OR EXP
#line 234 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 1488 "parser.cpp"
    break;

  case 41: // EXP: PARA EXP PARC
#line 235 "parser.y"
                    { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 1494 "parser.cpp"
    break;

  case 42: // EXP: PRIMITIVE
#line 236 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1500 "parser.cpp"
    break;

  case 43: // PRIMITIVE: NUMERO
#line 240 "parser.y"
        {
            int num = stoi(yystack_[0].value.as < std::string > ());
            yylhs.value.as < expression* > () = new primitive(0,0,INTEGER,"",num,false);
        }
#line 1509 "parser.cpp"
    break;

  case 44: // PRIMITIVE: STRING
#line 245 "parser.y"
        { 
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(0,0,STRING,str2,0,false);
        }
#line 1519 "parser.cpp"
    break;

  case 45: // PRIMITIVE: BOOL
#line 250 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1525 "parser.cpp"
    break;

  case 46: // PRIMITIVE: LIST_ARR
#line 251 "parser.y"
                   { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1531 "parser.cpp"
    break;

  case 47: // BOOL: RTRUE
#line 254 "parser.y"
             { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,true); }
#line 1537 "parser.cpp"
    break;

  case 48: // BOOL: RFALSE
#line 255 "parser.y"
             { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,false); }
#line 1543 "parser.cpp"
    break;

  case 49: // LIST_ARR: LIST_ARR CORA EXP CORC
#line 258 "parser.y"
                                  { yylhs.value.as < expression* > () = new array_access(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 1549 "parser.cpp"
    break;

  case 50: // LIST_ARR: LIST_ARR '.' ID
#line 259 "parser.y"
                          { yylhs.value.as < expression* > () = new struct_access(0,0,yystack_[2].value.as < expression* > (),yystack_[0].value.as < std::string > ()); }
#line 1555 "parser.cpp"
    break;

  case 51: // LIST_ARR: ID
#line 260 "parser.y"
             {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ()); }
#line 1561 "parser.cpp"
    break;


#line 1565 "parser.cpp"

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





  const signed char Parser::yypact_ninf_ = -55;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      -4,    -7,    13,   -55,     1,   -55,    20,    19,     0,    33,
     214,   -55,   -55,   -55,    45,   174,   -55,    23,    24,   -55,
     -55,   -55,    56,   214,   -55,   -55,   -55,   214,   -55,   -55,
      37,   -55,   -55,    11,    32,   -55,   -55,   -55,   -55,    35,
      68,    96,   214,   214,   214,   214,     0,   214,   214,   214,
     214,   214,   214,   214,   214,   214,    79,    36,    40,   214,
     -55,   -55,    -2,    -2,   -55,   -55,   182,    73,    73,    73,
      73,   219,   219,   152,   152,   109,   -55,    64,    26,    81,
     139,    75,   -55,   214,   -55,    85,    55,    -3,    75,   -55,
     -55,   -19,   139,    58,   -55,   214,     0,   -55,   -55,   -55,
     214,   -55,   124,   190,   139,     0,   -55,   199,   -55
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,    26,    27,    28,     0,     0,     5,     0,     0,     8,
       9,    10,     0,     0,    43,    51,    44,     0,    47,    48,
       0,    42,    45,    46,     0,     3,     4,     6,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    41,    29,    30,    31,    32,     0,    34,    33,    36,
      35,    37,    38,    39,    40,     0,    50,     0,     0,     0,
      12,    19,    49,     0,    20,     0,     0,     0,    19,    16,
      14,     0,    25,     0,    22,     0,     0,    15,    13,    23,
       0,    21,     0,     0,    24,     0,    18,     0,    17
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -55,   -55,   -55,   -43,   -15,   -55,   -55,   -55,   -55,     3,
      18,   -55,   -55,   -55,   -55,   -54,   -22,   -55,   -55,   -55
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,    15,    16,    17,    18,    19,    88,    89,
      90,    20,    78,    21,    91,    22,    30,    31,    32,    33
  };

  const signed char
  Parser::yytable_[] =
  {
      36,    40,    99,    66,    79,    41,    44,    45,    95,     1,
       9,    10,     4,     5,    11,    12,    13,    96,     6,   100,
      62,    63,    64,    65,    85,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    14,    55,    57,    80,     7,     8,
      11,    12,    13,    42,    43,    44,    45,    84,    56,    34,
      23,    36,    58,   103,    11,    12,    13,    46,    37,    38,
      39,    92,   107,    47,    48,    49,    50,    51,    52,    53,
      54,    59,    77,   102,    42,    43,    44,    45,   104,    42,
      43,    44,    45,    76,    83,    86,    60,    87,    36,    93,
      94,    97,    36,   101,    47,    48,    49,    50,    51,    52,
      53,    54,    42,    43,    44,    45,    98,     0,     0,     0,
       0,     0,     0,     0,    61,    42,    43,    44,    45,     0,
       0,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      42,    43,    44,    45,    82,    47,    48,    49,    50,    51,
      52,    53,    54,     0,   105,    42,    43,    44,    45,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    42,    43,
      44,    45,     0,     0,     0,    47,    48,    49,    50,    51,
      52,    53,    54,     0,     0,     0,     0,     0,    47,    48,
      49,    50,    51,    52,     9,    10,     0,     0,    11,    12,
      13,     0,     9,    10,     0,    35,    11,    12,    13,     0,
       9,    10,     0,    81,    11,    12,    13,     0,    14,     9,
      10,   106,     0,    11,    12,    13,    14,    24,    25,    26,
     108,     0,     0,     0,    14,    42,    43,    44,    45,     0,
       0,    27,     0,    14,     0,     0,    28,    29,     0,     0,
       0,     0,     0,     0,     0,    47,    48,    49,    50
  };

  const signed char
  Parser::yycheck_[] =
  {
      15,    23,    21,    46,    58,    27,     8,     9,    11,    13,
      10,    11,    19,     0,    14,    15,    16,    20,    17,    38,
      42,    43,    44,    45,    78,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    34,    24,     4,    59,    18,    20,
      14,    15,    16,     6,     7,     8,     9,    21,    37,     4,
      17,    66,    20,    96,    14,    15,    16,    20,    35,    35,
       4,    83,   105,    26,    27,    28,    29,    30,    31,    32,
      33,    36,    36,    95,     6,     7,     8,     9,   100,     6,
       7,     8,     9,     4,    20,     4,    18,    12,   103,     4,
      35,    88,   107,    35,    26,    27,    28,    29,    30,    31,
      32,    33,     6,     7,     8,     9,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,     6,     7,     8,     9,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
       6,     7,     8,     9,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    20,     6,     7,     8,     9,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,     6,     7,
       8,     9,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    10,    11,    -1,    -1,    14,    15,
      16,    -1,    10,    11,    -1,    21,    14,    15,    16,    -1,
      10,    11,    -1,    21,    14,    15,    16,    -1,    34,    10,
      11,    21,    -1,    14,    15,    16,    34,     3,     4,     5,
      21,    -1,    -1,    -1,    34,     6,     7,     8,     9,    -1,
      -1,    17,    -1,    34,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    40,    41,    19,     0,    17,    18,    20,    10,
      11,    14,    15,    16,    34,    42,    43,    44,    45,    46,
      50,    52,    54,    17,     3,     4,     5,    17,    22,    23,
      55,    56,    57,    58,     4,    21,    43,    35,    35,     4,
      55,    55,     6,     7,     8,     9,    20,    26,    27,    28,
      29,    30,    31,    32,    33,    24,    37,     4,    20,    36,
      18,    18,    55,    55,    55,    55,    42,    55,    55,    55,
      55,    55,    55,    55,    55,    55,     4,    36,    51,    54,
      55,    21,    25,    20,    21,    54,     4,    12,    47,    48,
      49,    53,    55,     4,    35,    11,    20,    48,    49,    21,
      38,    35,    55,    42,    55,    20,    21,    42,    21
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    39,    40,    41,    42,    42,    43,    43,    43,    43,
      43,    44,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    51,    51,    52,    53,    53,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    58,
      58,    58
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     7,     2,     1,     2,     2,     1,     1,
       1,     4,     4,     7,     6,     2,     1,     6,     4,     0,
       5,     4,     3,     7,     3,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     1
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
  "AND", "OR", "STRUCT", "';'", "'='", "'.'", "','", "$accept", "START",
  "MAIN", "LIST_INST", "INSTRUCTION", "PRINT", "DECLARATION", "IF",
  "ELSEIF_LIST", "ELSEIF", "ELSE", "STRUCT_DECLARATION", "DEC_LIST",
  "STRUCT_CREATION", "EXP_LIST", "TYPES", "EXP", "PRIMITIVE", "BOOL",
  "LIST_ARR", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   114,   114,   122,   128,   133,   140,   141,   142,   143,
     144,   147,   150,   153,   157,   163,   168,   175,   181,   182,
     185,   188,   193,   200,   206,   211,   218,   219,   220,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   239,   244,   250,   251,   254,   255,   258,
     259,   260
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
#line 1963 "parser.cpp"

#line 263 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}


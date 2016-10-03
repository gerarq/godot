/*************************************************************************/
/*  shader_language.h                                                    */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2016 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef SHADER_LANGUAGE_H
#define SHADER_LANGUAGE_H

#include "typedefs.h"
#include "ustring.h"
#include "list.h"
#include "string_db.h"
#include "map.h"
#include "variant.h"


class ShaderLanguage  {



public:

	enum TokenType {

		TK_EMPTY,
		TK_IDENTIFIER,
		TK_TRUE,
		TK_FALSE,
		TK_REAL_CONSTANT,
		TK_INT_CONSTANT,
		TK_TYPE_VOID,
		TK_TYPE_BOOL,
		TK_TYPE_BVEC2,
		TK_TYPE_BVEC3,
		TK_TYPE_BVEC4,
		TK_TYPE_INT,
		TK_TYPE_IVEC2,
		TK_TYPE_IVEC3,
		TK_TYPE_IVEC4,
		TK_TYPE_UINT,
		TK_TYPE_UVEC2,
		TK_TYPE_UVEC3,
		TK_TYPE_UVEC4,
		TK_TYPE_FLOAT,
		TK_TYPE_VEC2,
		TK_TYPE_VEC3,
		TK_TYPE_VEC4,
		TK_TYPE_MAT2,
		TK_TYPE_MAT3,
		TK_TYPE_MAT4,
		TK_TYPE_SAMPLER2D,
		TK_TYPE_ISAMPLER2D,
		TK_TYPE_USAMPLER2D,
		TK_TYPE_SAMPLERCUBE,
		TK_PRECISION_LOW,
		TK_PRECISION_MID,
		TK_PRECISION_HIGH,
		TK_OP_EQUAL,
		TK_OP_NOT_EQUAL,
		TK_OP_LESS,
		TK_OP_LESS_EQUAL,
		TK_OP_GREATER,
		TK_OP_GREATER_EQUAL,
		TK_OP_AND,
		TK_OP_OR,
		TK_OP_NOT,
		TK_OP_ADD,
		TK_OP_SUB,
		TK_OP_MUL,
		TK_OP_DIV,
		TK_OP_MOD,
		TK_OP_SHIFT_LEFT,
		TK_OP_SHIFT_RIGHT,
		TK_OP_ASSIGN,
		TK_OP_ASSIGN_ADD,
		TK_OP_ASSIGN_SUB,
		TK_OP_ASSIGN_MUL,
		TK_OP_ASSIGN_DIV,
		TK_OP_ASSIGN_MOD,
		TK_OP_ASSIGN_SHIFT_LEFT,
		TK_OP_ASSIGN_SHIFT_RIGHT,
		TK_OP_ASSIGN_BIT_AND,
		TK_OP_ASSIGN_BIT_OR,
		TK_OP_ASSIGN_BIT_XOR,
		TK_OP_BIT_AND,
		TK_OP_BIT_OR,
		TK_OP_BIT_XOR,
		TK_OP_BIT_INVERT,
		TK_OP_INCREMENT,
		TK_OP_DECREMENT,
		TK_CF_IF,
		TK_CF_ELSE,
		TK_CF_FOR,
		TK_CF_WHILE,
		TK_CF_DO,
		TK_CF_SWITCH,
		TK_CF_CASE,
		TK_CF_BREAK,
		TK_CF_CONTINUE,
		TK_CF_RETURN,
		TK_BRACKET_OPEN,
		TK_BRACKET_CLOSE,
		TK_CURLY_BRACKET_OPEN,
		TK_CURLY_BRACKET_CLOSE,
		TK_PARENTHESIS_OPEN,
		TK_PARENTHESIS_CLOSE,
		TK_QUESTION,
		TK_COMMA,
		TK_COLON,
		TK_SEMICOLON,
		TK_PERIOD,
		TK_UNIFORM,
		TK_VARYING,
		TK_RENDER_MODE,
		TK_HINT_WHITE_TEXTURE,
		TK_HINT_BLACK_TEXTURE,
		TK_HINT_NORMAL_TEXTURE,
		TK_HINT_RANGE,
		TK_ERROR,
		TK_EOF,
		TK_MAX
	};

	/* COMPILER */

	enum DataType {
		TYPE_VOID,
		TYPE_BOOL,
		TYPE_BVEC2,
		TYPE_BVEC3,
		TYPE_BVEC4,
		TYPE_INT,
		TYPE_IVEC2,
		TYPE_IVEC3,
		TYPE_IVEC4,
		TYPE_UINT,
		TYPE_UVEC2,
		TYPE_UVEC3,
		TYPE_UVEC4,
		TYPE_FLOAT,
		TYPE_VEC2,
		TYPE_VEC3,
		TYPE_VEC4,
		TYPE_MAT2,
		TYPE_MAT3,
		TYPE_MAT4,
		TYPE_SAMPLER2D,
		TYPE_ISAMPLER2D,
		TYPE_USAMPLER2D,
		TYPE_SAMPLERCUBE,
	};

	enum DataPrecision {
		PRECISION_LOWP,
		PRECISION_MEDIUMP,
		PRECISION_HIGHP,
		PRECISION_DEFAULT,
	};

	enum Operator {
		OP_EQUAL,
		OP_NOT_EQUAL,
		OP_LESS,
		OP_LESS_EQUAL,
		OP_GREATER,
		OP_GREATER_EQUAL,
		OP_AND,
		OP_OR,
		OP_NOT,
		OP_NEGATE,
		OP_ADD,
		OP_SUB,
		OP_MUL,
		OP_DIV,
		OP_MOD,
		OP_SHIFT_LEFT,
		OP_SHIFT_RIGHT,
		OP_ASSIGN,
		OP_ASSIGN_ADD,
		OP_ASSIGN_SUB,
		OP_ASSIGN_MUL,
		OP_ASSIGN_DIV,
		OP_ASSIGN_MOD,
		OP_ASSIGN_SHIFT_LEFT,
		OP_ASSIGN_SHIFT_RIGHT,
		OP_ASSIGN_BIT_AND,
		OP_ASSIGN_BIT_OR,
		OP_ASSIGN_BIT_XOR,
		OP_BIT_AND,
		OP_BIT_OR,
		OP_BIT_XOR,
		OP_BIT_INVERT,
		OP_INCREMENT,
		OP_DECREMENT,
		OP_SELECT_IF,
		OP_SELECT_ELSE, //used only internally, then only IF appears with 3 arguments
		OP_POST_INCREMENT,
		OP_POST_DECREMENT,
		OP_CALL,
		OP_CONSTRUCT,
		OP_MAX
	};

	enum FlowOperation {
		FLOW_OP_IF,
		FLOW_OP_RETURN,
		FLOW_OP_FOR,
		FLOW_OP_WHILE,
		FLOW_OP_DO,
		FLOW_OP_BREAK,
		FLOW_OP_SWITCH,
		FLOW_OP_CONTINUE

	};

	struct Node {

		Node *next;

		enum Type {
			TYPE_SHADER,
			TYPE_FUNCTION,
			TYPE_BLOCK,
			TYPE_VARIABLE,
			TYPE_CONSTANT,
			TYPE_OPERATOR,
			TYPE_CONTROL_FLOW,
			TYPE_MEMBER
		};

		Type type;

		virtual DataType get_datatype() const { return TYPE_VOID; }

		virtual ~Node() {}
	};

	template<class T>
	T* alloc_node() {
		T* node = memnew(T);
		node->next=nodes;
		nodes=node;
		return node;
	}

	Node *nodes;


	struct OperatorNode : public Node {

		DataType return_cache;
		DataPrecision return_precision_cache;
		Operator op;
		Vector<Node*> arguments;
		virtual DataType get_datatype() const { return return_cache; }

		OperatorNode() { type=TYPE_OPERATOR; return_cache=TYPE_VOID; return_precision_cache=PRECISION_DEFAULT; }
	};

	struct VariableNode : public Node {
		DataType datatype_cache;
		StringName name;
		virtual DataType get_datatype() const { return datatype_cache; }

		VariableNode() { type=TYPE_VARIABLE; datatype_cache=TYPE_VOID;  }
	};

	struct ConstantNode : public Node {

		DataType datatype;
		Variant value;
		virtual DataType get_datatype() const { return datatype; }

		ConstantNode() { type=TYPE_CONSTANT; }
	};

	struct FunctionNode;

	struct BlockNode : public Node {
		FunctionNode *parent_function;
		BlockNode *parent_block;

		struct Variable {
			DataType type;
			DataPrecision precision;
		};

		Map<StringName,Variable> variables;
		List<Node*> statements;
		BlockNode() { type=TYPE_BLOCK; parent_block=NULL; parent_function=NULL; }
	};

	struct ControlFlowNode : public Node {

		FlowOperation flow_op;
		Vector<BlockNode*> blocks;
		ControlFlowNode() { type=TYPE_CONTROL_FLOW; flow_op=FLOW_OP_IF;}
	};

	struct MemberNode : public Node {

		DataType basetype;
		DataType datatype;
		StringName name;
		Node* owner;
		virtual DataType get_datatype() const { return datatype; }
		MemberNode() { type=TYPE_MEMBER; }
	};


	struct FunctionNode : public Node {


		struct Argument {

			StringName name;
			DataType type;
			DataPrecision precision;
		};

		StringName name;
		DataType return_type;
		DataPrecision return_precision;
		Vector<Argument> arguments;
		BlockNode *body;

		FunctionNode() { type=TYPE_FUNCTION;  return_precision=PRECISION_DEFAULT; }

	};


	struct ShaderNode : public Node {

		struct Function {
			StringName name;
			FunctionNode*function;
			bool callable;
		};

		struct Varying {
			DataType type;
			DataPrecision precission;
		};

		struct Uniform {
			enum Hint {
				HINT_NONE,
				HINT_WHITE_TEXTURE,
				HINT_BLACK_TEXTURE,
				HINT_NORMAL_TEXTURE,
				HINT_RANGE,
			};

			int order;
			DataType type;
			DataPrecision precission;
			Variant default_value;
			Hint hint;
			float hint_range[3];

			Uniform() { hint=HINT_NONE; hint_range[0]=0; hint_range[1]=1; hint_range[2]=0.001;}
		};


		Map<StringName,Varying> varyings;
		Map<StringName,Uniform> uniforms;
		Set<StringName> render_modes;

		Vector<Function> functions;

		ShaderNode() { type=TYPE_SHADER; }
	};


	struct Expression {

		bool is_op;
		union {
			Operator op;
			Node *node;
		};
	};



	struct VarInfo {

		StringName name;
		DataType type;
	};

	enum CompletionType {
		COMPLETION_NONE,
		COMPLETION_BUILT_IN_TYPE_CONSTANT,
		COMPLETION_FUNCTION,
		COMPLETION_IDENTIFIER,
		COMPLETION_PARENT_FUNCTION,
		COMPLETION_METHOD,
		COMPLETION_CALL_ARGUMENTS,
		COMPLETION_INDEX,
		COMPLETION_VIRTUAL_FUNC,
		COMPLETION_YIELD,
	};

	struct Token {

		TokenType type;
		StringName text;
		double constant;
		uint16_t line;
	};

	static String get_token_text(Token p_token);
	static bool is_token_datatype(TokenType p_type);
	static DataType get_token_datatype(TokenType p_type);
	static bool is_token_precision(TokenType p_type);
	static DataPrecision get_token_precision(TokenType p_type);
	static String get_datatype_name(DataType p_type);
	static bool is_token_nonvoid_datatype(TokenType p_type);
	static bool is_token_operator(TokenType p_type);

private:

	bool error_set;
	String error_str;
	int error_line;

	String code;
	int char_idx;
	int tk_line;


	void _set_error(const String& p_str) {
		if (error_set)
			return;
		error_set=true;
		error_str=p_str;
	}


	static const char * token_names[TK_MAX];




	Token _make_token(TokenType p_type, const StringName& p_text=StringName());
	Token _get_token();

	ShaderNode *shader;

	enum IdentifierType {
		IDENTIFIER_FUNCTION,
		IDENTIFIER_UNIFORM,
		IDENTIFIER_VARYING,
		IDENTIFIER_FUNCTION_ARGUMENT,
		IDENTIFIER_LOCAL_VAR,
		IDENTIFIER_BUILTIN_VAR,
	};

	bool _find_identifier(const BlockNode* p_block,const Map<StringName, DataType> &p_builtin_types,const StringName& p_identifier, DataType *r_data_type=NULL, IdentifierType *r_type=NULL);

	bool _validate_operator(OperatorNode *p_op,DataType *r_ret_type=NULL);


	struct IntrinsicFuncDef {

		enum { MAX_ARGS=5 };
		const char* name;
		DataType rettype;
		const DataType args[MAX_ARGS];

	};


	static const IntrinsicFuncDef intrinsic_func_defs[];
	bool _validate_function_call(BlockNode* p_block, OperatorNode *p_func,DataType *r_ret_type);

	bool _parse_function_arguments(BlockNode *p_block, const Map<StringName,DataType>  &p_builtin_types, OperatorNode* p_func);

	Node* _parse_expression(BlockNode *p_block, const Map<StringName,DataType>  &p_builtin_types);

	ShaderLanguage::Node* _reduce_expression(BlockNode *p_block, ShaderLanguage::Node *p_node);
	Node* _parse_and_reduce_expression(BlockNode *p_block,const Map<StringName,DataType>  &p_builtin_types);

	Error _parse_block(BlockNode *p_block, const Map<StringName, DataType> &p_builtin_types, bool p_just_one=false, bool p_can_break=false, bool p_can_continue=false);

	Error _parse_shader(const Map< StringName, Map<StringName,DataType> > &p_functions, const Set<String> &p_render_modes);


public:

//	static void get_keyword_list(ShaderType p_type,List<String> *p_keywords);

	void clear();
	Error compile(const String& p_code,const Map< StringName, Map<StringName,DataType> > &p_functions,const Set<String>& p_render_modes);
	String get_error_text();
	int get_error_line();

	static String lex_debug(const String& p_code);

	ShaderLanguage();
	~ShaderLanguage();
};


#endif // SHADER_LANGUAGE_H

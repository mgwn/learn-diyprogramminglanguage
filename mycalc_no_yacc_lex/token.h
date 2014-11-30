#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED 

typedef enum {
	BAD_TOKEN,
	NUMBER_TOKEN,
	ADD_OPERATOR_TOKEN,
	SUB_OPERATOR_TOKEN,
	MUL_OPERATOR_TOKEN,
	DIV_OPERATOR_TOKEN,
    LEFT_PAREN_TOKEN,
    RIGHT_PAREN_TOKEN,
	END_OF_LINE_TOKEN
} TokenKind;

#define MAX_TOKEN_SIZE (100)

typedef struct {
	TokenKind kind;
	double value;
	char str[MAX_TOKEN_SIZE];
} Token;

/* 将接下来要解析的行置入词法分析器中 */
void set_line(char *line);

/* 从置入的行中，分割记号并返回
 * 在行尾会返回 END_OF_LINE_TOKEN 这种特殊符号
 */
void get_token(Token *token);

#endif /* TOKEN_H_INCLUDED */
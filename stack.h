#ifndef STACK_H
#define STACK_H
#include <stddef.h>

typedef enum{
	STACK_INT,
	STACK_CHAR,
	STACK_FLOAT, 
	STACK_DOUBLE, 
	STACK_STRUCT,
	ELSE
}dataType;


typedef struct stack{
	dataType type;
	size_t typeSize; // data typeSize
	size_t len; // max length of the stack
	void* data; // data to store in stack
	int top; // index of top data in stack
}stack;


void push(stack* myStack, void* data);


void pop(stack* myStack);


int is_empty(stack* myStack);


void* get_top(stack* myStack);


void stackPrint(stack* myStack);


stack* stackCreate(dataType type, size_t len, size_t typeSize);

#endif

#include <stdio.h>
#include <stdlib.h>

typedef enum{
	STACK_INT,
	STACK_CHAR,
	STACK_FLOAT, 
	STACK_DOUBLE, 
	ELSE
}dataType;

size_t dataTypeSize(dataType type){
	if (type == STACK_INT) return sizeof(int);
	else if (type == STACK_CHAR) return sizeof(char);
	else if (type == STACK_FLOAT) return sizeof(float);
	else if (type == STACK_DOUBLE) return sizeof(double);
	else return (size_t)0;
}

typedef struct stack{
	dataType type;
	size_t len; // max length of the stack
	void* data;
	int top;
}stack;

void push(stack* myStack, void* data){
	if (myStack->top + 1 >= myStack->len){
		fputs("stack is full!\n", stdout);
		return;
	}
	if (myStack->type == STACK_INT)
		((int*)myStack->data)[++myStack->top] = *(int*)data;
	else if (myStack->type == STACK_CHAR)
		((char*)myStack->data)[++myStack->top] = *(char*)data;
	else if (myStack->type == STACK_FLOAT)
		((float*)myStack->data)[++myStack->top] = *(float*)data;
	else if (myStack->type == STACK_DOUBLE)
		((double*)myStack->data)[++myStack->top] = *(double*)data;
	else
		fputs("dataType not supported!\n", stdout);
}

void pop(stack* myStack){
	if (myStack->top == -1){
		printf("stack is already empty\n");
		return;
	}
	//void* TOP = myStack->data + myStack->top;
	if (myStack->type == STACK_INT)
		((int*)myStack->data)[myStack->top--] = 0;
	else if (myStack->type == STACK_CHAR)
		((char*)myStack->data)[myStack->top--] = 0;
	else if (myStack->type == STACK_FLOAT)
		((float*)myStack->data)[myStack->top--] = 0;
	else if (myStack->type == STACK_DOUBLE)
		((double*)myStack->data)[myStack->top--] = 0;
	else
		fputs("dataType not supported!\n", stdout);
}


void stackPrint(stack* myStack){
	if (myStack->type == STACK_INT)
		for (int i = 0; i <= myStack->top; i++)	printf("%d ", ((int*)myStack->data)[i]);
	else if (myStack->type == STACK_CHAR)
		for (int i = 0; i <= myStack->top; i++)	printf("%c ", ((char*)myStack->data)[i]);
	else if (myStack->type == STACK_FLOAT)
		for (int i = 0; i <= myStack->top; i++)	printf("%f ", ((float*)myStack->data)[i]);
	else if (myStack->type == STACK_DOUBLE)
		for (int i = 0; i <= myStack->top; i++)	printf("%lf ", ((double*)myStack->data)[i]);
	else
		fputs("dataType not supported!", stdout);
	printf("\n");
}


stack* stackCreate(dataType type, size_t len){
	size_t typeSize = dataTypeSize(type);
	if (typeSize <= 0) return NULL;
	stack* myStack = malloc(sizeof(stack*));
	myStack->type = type;
	myStack->len = len;
	myStack->data = malloc(typeSize * len);
	myStack->top = -1;
	return myStack;
}

int main(int argc, char* argv[]){
	stack* myStack = stackCreate(STACK_INT, 5);
	int* value = malloc(sizeof(int));
	for (int i = 0; i < 10; i++){
		*value = i+1;
		if (i <= 4)
			push(myStack, value);
		else
			pop(myStack);
		stackPrint(myStack);
	}
}

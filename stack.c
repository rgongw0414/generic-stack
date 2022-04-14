#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
/*
typedef enum{
	STACK_INT,
	STACK_CHAR,
	STACK_FLOAT, 
	STACK_DOUBLE, 
	STACK_STRUCT,
	ELSE
}dataType;
*/

// for dev testing
typedef struct pikachu{
	char* name;
	int CP;
}pikachu;


/*
typedef struct stack{
	dataType type;
	size_t typeSize; // data typeSize
	size_t len; // max length of the stack
	void* data; // data to store in stack
	int top; // index of top data in stack
}stack;
*/
void push(stack* myStack, void* data){
	if (myStack->top + 1 >= myStack->len){
		fputs("stack is full!\n", stdout);
		return;
	}
	(myStack->top)++;
	size_t top_offset = myStack->typeSize * (size_t)myStack->top; // e.g. when stack data type is int, offset = top_index * 4;
                                                                    // when char, offset = top_index * 1;
                                                                    // offset = top_index * sizeof(dataType);
	// push the data by "memory trick"
    memcpy(myStack->data + top_offset, data, myStack->typeSize);
    /* p.s. the following are literally doing "memcpy(myStack->data + top_offset, data, myStack->typeSize)"
	for (int i = 0; i < (int)myStack->typeSize; i++){
		// copy the data "Byte by Byte"
		// Assumption: char takes 1 Byte.
		*(char*)(myStack->data + top_offset + i) = *((char*)(data + i));
	}*/

	/* the following is safer implementation:
	if (myStack->type == STACK_INT)
		((int*)myStack->data)[++myStack->top] = *(int*)data;
	else if (myStack->type == STACK_CHAR)
		((char*)myStack->data)[++myStack->top] = *(char*)data;
	else if (myStack->type == STACK_FLOAT)
		((float*)myStack->data)[++myStack->top] = *(float*)data;
	else if (myStack->type == STACK_DOUBLE)
		((double*)myStack->data)[++myStack->top] = *(double*)data;
	else{
		(myStack->top)++;
		for (int i = 0; i < (int)myStack->typeSize; i++){
			// copy the new data "Byte by Byte"
			*(char*)(myStack->data + myStack->top + i) = *((char*)(data + i));
		}
		//((pikachu*)myStack->data)[++myStack->top] = *(pikachu*)data;
		//fputs("dataType not supported!\n", stdout);
	}*/
}

void pop(stack* myStack){
	if (myStack->top == -1){
		printf("stack is already empty\n");
		return;
	}
	size_t top_offset = myStack->typeSize * (size_t)myStack->top; // e.g. when stack data type is int, offset = top_index * 4;
	for (int i = 0; i < (int)myStack->typeSize; i++){
		// Assumption: char takes 1 Byte.
		*(char*)(myStack->data + top_offset + i) = 0;
		//*(char*)(myStack->data + top_offset + i) = *((char*)(data + i));
	}
	myStack->top--;
	/* the following is safer implemetation:
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
	*/
}

int is_empty(stack* myStack){
    return(myStack->top == -1);
}

void* get_top(stack* myStack){
    if (is_empty(myStack)){
        fprintf(stderr, "Can not pop from an empty stack.\n");
        return NULL;
    }
    void* top = (void*)malloc(myStack->typeSize);
    if (top == NULL) return NULL;
    memcpy(top, myStack->data + myStack->top * myStack->typeSize, myStack->typeSize);
    return top;
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
	else{
		fputs("dataType not supported!\nplease print by youself.", stdout);
        /* e.g. 
        printf("stack:\n");
        for (int i = 0; i <= myStack->top; i++)
            printf("name: %s, price: %d\n", ((car*)myStack->data)[i].name, ((car*)myStack->data)[i].price);*/
	}
	printf("\n");
}


stack* stackCreate(dataType type, size_t len, size_t typeSize){
	if (typeSize <= 0) return NULL;
	stack* myStack = (stack*)malloc(sizeof(stack));
    if (myStack == NULL) return NULL;
	myStack->type = type;
	myStack->typeSize = typeSize;
	myStack->len = len;
	myStack->data = (void*)malloc(typeSize * len);
    if (myStack->data == NULL) return NULL;
	myStack->top = -1;
	return myStack;
}

/*
int main(int argc, char* argv[]){
	
	stack* myStack = stackCreate(ELSE, 5, sizeof(pikachu));
	pikachu* myPikachu = malloc(sizeof(pikachu));
	char name[5] = "ERIC";
	myPikachu->name = name;
	for (int i = 0; i < 10; i++){
		myPikachu->CP = 999 - i;
		push(myStack, myPikachu);
		printf("CP: %i\n", ((pikachu*)myStack->data)[myStack->top].CP);
	}
	
	stack* myStack2 = stackCreate(STACK_INT, 5, sizeof(int));
	int* value = malloc(sizeof(int));
	for (int i = 0; i < 10; i++){
		*value = i + 1;
		if (i <= 4)
			push(myStack2, value);
		else
			pop(myStack2);
		stackPrint(myStack2);
	}
}*/

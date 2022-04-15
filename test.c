#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct car{
          char* name;
          int price;
}car;

int main(int argc, char* argv[]){
    int capacity = 3;
    printf("initializing a stack with capacity: %d, element_type: car\n", capacity);
	stack* myStack = stackCreate(ELSE, capacity, sizeof(car));
	car* myCar = malloc(sizeof(car));

	myCar->name = "toyota";
	myCar->price = 100;
	push(myStack, myCar);
    car* top = (car*)get_top(myStack);
    printf("\n%s pushed, top element: \n\t", myCar->name);
    printf("name: %s, price: %d\n", top->name, top->price);

	myCar->name = "suzuki";
	myCar->price = 300;
	push(myStack, myCar);
    top = (car*)get_top(myStack);
    printf("\n%s pushed, top element: \n\t", myCar->name);
    printf("name: %s, price: %d\n", top->name, top->price);


	myCar->name = "kia";
	myCar->price = 500;
	push(myStack, myCar);
    top = (car*)get_top(myStack);
    printf("\n%s pushed, top element: \n\t", myCar->name);
    printf("name: %s, price: %d\n", top->name, top->price);

	myCar->name = "benz";
	myCar->price = 1000;
	push(myStack, myCar);
    top = (car*)get_top(myStack);
    printf("try to push %s, but stack is full \n\ttop element: \n\t", myCar->name);
    printf("name: %s, price: %d\n", top->name, top->price);

	pop(myStack);
    printf("\npoped, top element: \n\t");
    printf("name: %s, price: %d\n", top->name, top->price);

	myCar->name = "benz";
	myCar->price = 1000;
	push(myStack, myCar);
    top = (car*)get_top(myStack);
    printf("\n%s pushed, top element: \n\t", myCar->name);
    printf("name: %s, price: %d\n", top->name, top->price);

	printf("-\nstack:\n");
	for (int i = 0; i <= myStack->top; i++){
		printf("name: %s, price: %d\n", ((car*)myStack->data)[i].name, ((car*)myStack->data)[i].price);
    }
}

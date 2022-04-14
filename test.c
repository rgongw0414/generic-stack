#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct car{
          char* name;
          int price;
}car;

int main(int argc, char* argv[]){
	stack* myStack = stackCreate(ELSE, 3, sizeof(car));
	car* myCar = malloc(sizeof(car));
	myCar->name = "toyota";
	myCar->price = 100;
	push(myStack, myCar);
    car* top = (car*)get_top(myStack);
    printf("name: %s, price: %d\n", top->name, top->price);

	myCar->name = "suzuki";
	myCar->price = 300;
	push(myStack, myCar);
    top = (car*)get_top(myStack);
    printf("name: %s, price: %d\n", top->name, top->price);


	myCar->name = "kia";
	myCar->price = 500;
	push(myStack, myCar);
    top = (car*)get_top(myStack);
    printf("name: %s, price: %d\n", top->name, top->price);

	myCar->name = "benz";
	myCar->price = 1000;
	push(myStack, myCar);
    top = (car*)get_top(myStack);
    printf("name: %s, price: %d\n", top->name, top->price);

	pop(myStack);
	myCar->name = "benz";
	myCar->price = 1000;
	push(myStack, myCar);
    top = (car*)get_top(myStack);
    printf("name: %s, price: %d\n", top->name, top->price);

	printf("stack:\n");
	for (int i = 0; i <= myStack->top; i++){
		printf("name: %s, price: %d\n", ((car*)myStack->data)[i].name, ((car*)myStack->data)[i].price);
    }
}

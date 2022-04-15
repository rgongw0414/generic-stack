# stack

#### how to use:
```bash
gcc stack.c test.c && ./a.out
```

#### sample output:
```bash
initializing a stack with capacity: 3, element_type: car

toyota pushed, top element: 
	name: toyota, price: 100

suzuki pushed, top element: 
	name: suzuki, price: 300

kia pushed, top element: 
	name: kia, price: 500
stack is full!
try to push benz, but stack is full 
	top element: 
	name: kia, price: 500

poped, top element: 
	name: kia, price: 500

benz pushed, top element: 
	name: benz, price: 1000
-
stack:
name: toyota, price: 100
name: suzuki, price: 300
name: benz, price: 1000
```

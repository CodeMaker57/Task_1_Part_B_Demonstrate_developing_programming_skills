#include <iostream>
#include <cassert>

void swap(int* &pointer_One, int* &pointer_Two); //define the void swap with two parameters(pointer (pointer_One) and pointer (pointer_Two))

int main() {
	//initialize the two integers
	int number_One = 5;
	int number_Two = 7;

	//initialize the two pointers
	int* pointer_One = &number_One;
	int* pointer_Two = &number_Two;

	swap(pointer_One, pointer_Two); //call the function swap

	//check if the values swapped
	assert(*pointer_One = number_Two);
	assert(*pointer_Two = number_One);
}

//main body of function swap
void swap(int* & pointer_One, int* & pointer_Two) {

	int temperary_Variable = *pointer_One; //create a temperary vaiable to hold one of the values (de reference of pointer_One)

	//swap the two values
	*pointer_One = *pointer_Two;
	*pointer_Two = temperary_Variable;
}
#include <iostream>
#include <cassert>

int linear_Search(int num, int array[], int size); //defing the integer function linear_Search with three parameters (integer (num), integer (array), integer (size))

int main() {
	int array[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 }; //initialize the array
	size_t size = sizeof(array) / sizeof(array[0]); //initialize a variable size and set it ti the size of the array

	//check if the function returns the correct values
	assert(linear_Search(3, array, size) == 2);
	assert(linear_Search(7, array, size) == 11);
	assert(linear_Search(67, array, size) == 0);
	assert(linear_Search(88, array, size) == -1);

	//initialize the value and value_Index variables
	int value = 0;
	int value_Index = 0;

	//loop forever
	for (;;) {

		//"print input value:" and set the variable value to the input
		std::cout << "input a value: ";
		std::cin >> value;

		value_Index = linear_Search(value, array, size); //call the linear_Search function with the inputted value

		//if the value was not in the array print that it wasnt, otherwise print the index of the value
		if (value_Index == -1) {
			std::cout << value << " was not in the array" << std::endl;
		}
		else {
			std::cout << value << " was in index " << value_Index << std::endl;
		}

	}

}

//main body of function linear_Search
int linear_Search(int num, int array[], int size) {

	//initialize variables i and location
	int i = 0;
	int location = -1;

	//loop for each item in the array
	for (; i < size;) {

		//if the current array item is the same as the inputted item lest location to equal the current index
		if (array[i] == num) {
			location = i;
		}
		i++; //add one to i
	}

	return location; //return the variable location
}
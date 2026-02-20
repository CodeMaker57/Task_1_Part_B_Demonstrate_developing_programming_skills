#include <iostream>
#include <cassert>
#include <chrono>
#include <thread>

void bubble_Sort(int array[], int array_Size); //define the function bubble sort with 2 parameters (integer (array) and integer (array_Size))
int binary_Search(int array[], int num, int array_Size); //define the integer function binary_Search with 3 parameters (integer (array), integer (num) and integer (array_Size))

int sorted_Array[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 }; //initialize a variable called sorted_Array

//main body
int main() {

	int array_To_Sort[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 }; //initialize the variable calle array_To_Sort
	size_t array_Size = sizeof(array_To_Sort) / sizeof(array_To_Sort[0]); //initialize the variable array_Size and set it to the size of the array to sort

	bubble_Sort(array_To_Sort, array_Size); //call the bubble sort function with the array to sort and array size as the parameters

	int value = 0; //initialize the variable (value)

	//check that the binary search funtion returns the correct values
	assert(binary_Search(sorted_Array, 11, array_Size) == 4);
	assert(binary_Search(sorted_Array, 23, array_Size) == 8);
	assert(binary_Search(sorted_Array, 97, array_Size) == 19);
	assert(binary_Search(sorted_Array, 88, array_Size) == -1);

	//infinite loop
	for (;;) {
		//ask the use for a value and set thier input to (value)
		std::cout << "enter a value: ";
		std::cin >> value;

		value = binary_Search(sorted_Array, value, array_Size); //run the users value through the binary_Search function and set (value) to the result

		//check if the value wasnt in the array and print the result
		if (value == -1) {
			std::cout << "this value was not in the array" << "\n";
		}
		else {
			std::cout << "the number was in index " << value << "\n";
		}
	}
}

//main body of the funtion bubble_Sort
void bubble_Sort(int array[], int array_Size) {

	//initialize all the temperary variables
	int temp_Num = 0;
	int i = 0;
	bool is_Swapped = false;
	bool stop_Swapping = false;

	//loop until stop_Swapping is equalo to true
	while (stop_Swapping == false) {

		//loop for each item in the array except for the last one
		for (; i < array_Size - 1;) {

			//if the current array item is greater then the item after swap the two values
			if (array[i] > array[i + 1]) {
				temp_Num = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp_Num;
				is_Swapped = true; //set is_Swapped to true
			}
			i++; //add one to i
		}

		//if isSwapped is false (no items were swapped in the array)
		if (is_Swapped == false) {
			stop_Swapping = true; //set stop_Swapping to true
		}
		is_Swapped = false; //set is_Swapped to false
		i = 0; //reset i to 0
	}

	//for each item in the array check if the next item is greater
	for (; i < array_Size - 1;) {
		assert(array[i] < array[i + 1]);
		i++;
	}

	i = 0; //reset i to 0

	//set the global variable sorted_Array equal to the current array (sorted)
	for (; i < array_Size;) {
		sorted_Array[i] = array[i];
		i++;
	}
}

//main body of the function binary_search
int binary_Search(int array[], int num, int array_Size) {

	int beginning = 0; //initialize beginning with a value of 0
	int ending = array_Size - 1; //initialize endin with a value of the array_Size minus 1
	int mid_Point = (beginning + ending) / 2; //initialize mid_piont with a value of the middle number of beginning and ending

	//initialize temporary variables
	bool toggle = false;
	int i = 0;
	int previous_Mid_Point = 0;

	//lopp until toggle equals true
	while (toggle == false) {
		mid_Point = (beginning + ending) / 2; //set the current mid_Point

		//the the midpoint is the correct number set toggle to true (stop the loop)
		if (array[mid_Point] == num) {
			toggle = true;
		}

		//if the current middle number is greater than the asked number set the ending to the midpoint - 1
		else if (array[mid_Point] > num) {
			ending = mid_Point - 1;
		}

		//if the current middle number is less than the asked number set the beginning to the midpoint + 1
		else if (array[mid_Point] < num) {
			beginning = mid_Point + 1;
		}

		//if the current mid_Point is equal to the previous mid_Point set the midpoint to -l aand break (stop the loop)
		if (mid_Point == previous_Mid_Point) {
			mid_Point = -1;
			break;
		}

		previous_Mid_Point = mid_Point; //set theprevious mid_Point to equal the current mid_Point
	}
	return mid_Point; //return the mid_Point
}

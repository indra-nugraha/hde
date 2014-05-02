//DG Challenge 003
//HDE corp

#include <stdio.h>
#include <stdlib.h>

void mainLoop (int input_one, int *output, int index_out);
void readInput (int *input_all, int num_input, int index);
void sumAll(int *input_all, int num_input, int index, int *output, int index_out);
void printOutput (int input_one, int index, int *output);

int main (int argv, char **argc){

	int input_one, index_out;
	
	int *output = NULL;

	input_one = index_out = 0;

	//read first int input
	scanf ("%d", &input_one);
	
	//condition must be 1 <= N <= 100
	if ((input_one < 1) && (input_one > 100)) 
		exit (1);
	
	//memory allocation, 0 value initialization 	
	output = (int*) calloc(input_one, sizeof(int));
	
	//exit failure when memory shortage
	if (output == NULL) 
		exit (1);

	//main loop for first int input
	mainLoop(input_one, output, index_out);

	//reset value
	index_out = 0;

	//print value to window dialog
	printOutput(input_one, index_out, output);

	//free-ing memory
	free (output);

	return 0;
}

void mainLoop (int input_one, int *output, int index_out){

	int *input_sum = NULL, input_two, num_input, index;

	index = 0;

	//read second input int
	scanf ("%d", &input_two);
	
	//condition must be 0 < X <= 100
	if ((input_two < 1) && (input_two > 100)) 
		exit (1);
	
	//memory allocation
	input_sum = (int*) calloc (input_two, sizeof(int));
	
	//exit failure check
	if (input_sum == NULL) 
		exit (1);
	
	//give value to num_input var as temp var
	num_input = input_two;
	
	//read input int to be summed
	readInput(input_sum, num_input, index);
	
	//reset value to use in sumAll
	num_input = input_two;

	//reset value
	index = 0;
	
	//sum all int values
	sumAll(input_sum, num_input, index, output, index_out);

	input_one--;
	
	//this function is called recursively as a loop substitute
	if (input_one > 0){
		index_out++;
		mainLoop(input_one, output, index_out);
	}	
	
	//free-ing memory
	free (input_sum);
	
}

void readInput (int *input_all, int num_input, int index){
	
	//read value to be summed
	scanf ("%d", (input_all+index));
	
	//condition must be -100 <= Yn <= 100
	if ((*(input_all+index) < -100) && (*(input_all+index) > 100))
		exit (1);
	
	index++;
	num_input--;
	
	//this function is called recursively
	if (num_input > 0)
		readInput(input_all, num_input, index);

}

void sumAll(int *input_all, int num_input, int index, int *output, int index_out){
	
	//sum only positive int value, if negative, set to 0
	if (*(input_all+index) < 0)
		*(input_all+index) = 0;
	
	//summation process
	*(output + index_out) += (*(input_all+index) * *(input_all+index));

	index++;
	num_input--;
	
	//this function is called recursively
	if (num_input > 0)
		sumAll (input_all, num_input, index, output, index_out);
	
}

void printOutput (int input_one, int index, int *output){

	//print value to window dialog
	printf ("%d\n", *(output + index));

	index++;
	input_one--;
	
	//this function is called recursively
	if (input_one > 0)
		printOutput(input_one, index, output);
}


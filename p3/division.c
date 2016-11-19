/* Assignment3 Part 2
 * by Songzi Wen and Xiaojian Nie, Lecture001
 *
 * This program continuously gets the inputs from user, and calculates the 
 * quotient and remainder of doing the integer division operation.
 * 
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//global variables
static int success = 0;//tracking the successful operations
static int times = 1;//times of ctrl-c which the program need to catch before exit

//function declaration
void handler();
void sigint_handler();

/* 
 * Main method of this program. It prints out the instruction messages 
 * and output of doing the division operation, handles the exception 
 * when doing a divide by 0 operation, and catches ctrl-c
 * 
 */
int main(){
	char num1[1024], num2[1024];//2 varibles to store the user input
	struct sigaction sa;//signal 1
	struct sigaction sa2;//signal 2

	sa.sa_handler = &handler;//input the corresponding handler
	sa2.sa_handler = &sigint_handler;//input the corresponding handler
	//handle exception
	if(sigaction(SIGFPE, &sa, NULL) == -1){
		printf("There is an error in sigaction() function");
	}
	//handle exception
	if(sigaction(SIGINT, &sa2, NULL) == -1){
		printf("There is an error in sigaction() function");
	}
	//redo the input stuff forever
	while(1){
		printf("Enter first integer: ");
		//get the first input and handle exception
		if(fgets(num1, 1024, stdin) == NULL){
			printf("input error");
		}
		//get the second input and handle exception
		printf("Enter second integer: ");
		if(fgets(num2, 1024, stdin) == NULL){
			printf("input error");
		}
		//increase the times of doing operation successfully
		success++;
		//print out the output
		printf("%d / %d is %d with a remainder of %d\n", atoi(num1), atoi(num2), atoi(num1)/atoi(num2), atoi(num1)%atoi(num2));
	}
	return 0;
}

void handler(){
	success--;//after the failure of doing the operation, reduce the number of doing operations successfully
	printf("a divide by 0 operation was attempted, %d division operation(s) is(are) completed successfully.\n", success);
	exit(1);
}

void sigint_handler(){
	times--;//reduce the times of ctrl-c input needed
	//program needs 0 ctrl-c input, so exit
	if (times == 0){
		printf("\nControl-c caught. %d division operation(s) is(are) completed successfully.\n", success);
		exit(1);
	}
}

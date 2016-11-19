/* Assignment4 Part 1 
 * by Songzi Wen and Xiaojian Nie, Lecture001
 *
 * This program achieves functionalities of catching 5 ctrl-c interrupts
 * 
 */
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//global variable
static int cTimes = 5;//the remaining times for control-c 
static int alarmSec = 3;//the time interval for alarm

//function declaration
void sigint_handler();
void handler();
 
 /* 
 * Main method of this program. It prints out the instruction messages 
 * and sets up the alarm and interrupts which it needs to handle.
 * 
 */
int main(void) {

	struct sigaction sa; //signal 1
	struct sigaction sa2; //signal 2
	
	//print out the instruction
	printf("Date will be printed every 3 seconds.\n");
	printf("Enter ^C 5 times to end the program:\n");
	
    sa.sa_handler = handler; //input corresbonding signal handler
    sa2.sa_handler = sigint_handler; //input corresbonding signal handler

    sa.sa_flags = SA_RESTART;//Restart functions if interrupted by handler
    sa2.sa_flags = SA_RESTART;//Restart functions if interrupted by handler
    //handle exception
    if(sigaction(SIGALRM, &sa, NULL) == -1){
		printf("There is an error in sigaction() function");
	}
    alarm(alarmSec);//set up alarm
    //handle exception
    if(sigaction(SIGINT, &sa2, NULL) == -1){
		printf("There is an error in sigaction() function");
	}
    
	while(1){
	}
	return 0;
}

/* 
 * SIGINT handler: reduce the times of ctrl-c needed whenever a ctrl-c is 
 * caught. After 5 times ctrl-c, exit the program.
 * 
 */
void sigint_handler(){
	cTimes--;//reduce the times of ctrl-c input needed
	
	//after catching 5 times of ctrl-c
	if (cTimes == 0){
		printf("\nFinal Control-c caught. Exiting.");
		exit(1);
	}
	printf("\nControl-c caught. %d more before program is ended.\n",cTimes);
}

/* 
 * SIGALRM handler: when alarm goes off, handle it.
 * 
 */
 
void handler(){

	time_t curtime; //get time since 1970
	time(&curtime); //get current time
	printf("\ncurrent time is %s", ctime(&curtime));//print out time in correct format
	alarm(alarmSec);//re-arm the alarm
}





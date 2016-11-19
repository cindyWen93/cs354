/* Assignment1 Step2
 * by Songzi Wen and Xiaojian Nie, Lecture001
 *
 * This program reads in a binary file which store some integers and 
 * calculate the average of those integers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/*
 * Main method of this program. This is the only method in this program
 * and it reads a binary file which store some integers and 
 * calculate the average of those integers.
 * 
 * Parameters:
 * argc: the length of command line arguments
 * argv: a char array that stores all comment line arguments
 */
int main(int argc, char *argv[]){
	
    //check if the input argument is correct and handle when it is wrong
    if (argc != 2) {
		fprintf(stderr, "Wrong input command");
		exit(1);
    }
    
    //initialize variable 
    int fd;               //represents the input file
    int average;          //average of all numbers from input file
    int total;            //sum of all numbers from input file
    int i;                //counter variable
    int sizeOfFile;       //the size of input file
    struct stat buf;      //store input file information
    int buffer;           //buffer to store a integer from a single read
    char *fileName;       //store file name in arguments line 
    
    fileName =argv[1];
    
    //open file and handle when open() function returns an error
    fd = open(fileName,O_RDONLY);
    if(fd == -1){
		printf("cannot open file");
		exit(1);
    }
    
 //store file information and handle when the function returns an error
    if( fstat(fd,&buf) ==  -1){
		printf("cannot figure out the size of the file");
		exit(1);
    }
    sizeOfFile =buf.st_size;
    
    //create an array dynamiclly to store integers from input file 
    int *p = malloc(sizeOfFile);
    //handle when malloc function returns an error
    if(p == NULL){
		printf("malloc funciton fails");
		exit(1);
	}
    //repeatly read an integer from input file  
    for(i = 0; i < (sizeOfFile/(sizeof(int))); i++){
        //handle when read fails
        if( read(fd,&buffer,sizeof(int)) == -1){
			printf("cannot read file");
			exit(1);
        }
        //store read result to array        
        *p = buffer;
        //update sum of integers that already had beed read
        total += *p; 
        //update pointer 
        p++;
    }
   
    //close file and handle when function fails
    if( close(fd) == -1){
		printf("cannot close file");
		exit(1);
    }
    
    //calculate the average
    average = total/(sizeOfFile/(sizeof(int)));
    //print result
    printf("The total number of integers in input file is %d\n",i);
   printf("The average of all integers in input file is %d.\n",average);
    
    return 0;

}


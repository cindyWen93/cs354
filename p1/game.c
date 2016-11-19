/* Assignment1 Step3
 * by Songzi Wen and Xiaojian Nie, Lecture001
 *
 * This program creates a game that reads in a binary file that
 * contains some integers and store those numbers in a linked list, 
 * and then repeatly asks user's guess and show corresponding result.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/* 
 * A node data structure that stores an integer and the address of next
 * node.
 */
typedef struct node {
    int theint;
    struct node *next;
} Node;

/* 
 * add node to linkedlist and update head reference
 * 
 * Parameters:
 * head:pointer that points to the first node of list
 * intforlist: the value that is supposed to be add in list using a node
 * data structure 
 */
Node * listadd(Node *head, int intforlist){
	
	
	//constuct a new node and add it to the list 
	Node *myNode = malloc(sizeof(Node));
	//handle when malloc function returns an error
	if(myNode ==  NULL){
		printf("malloc function returns an error");
		return NULL;
	}
	//store int value
	myNode->theint = intforlist;
	//update the reference for next node
	myNode->next = head;
	return myNode;
    
}

/* 
 * read in a file and creates a linked list to store integers in file
 * 
 * Parameters:
 * fd: the input file
 */
Node * createlist(int fd){
	
	/* initilize variables */
	Node * head = malloc(sizeof(Node)); //head node pointer of the list
	//handle when malloc function returns an error
	if(head == NULL){
		printf("malloc function returns an error");
		return NULL;
	}
	int sizeOfFile;                     //store size of input file
	struct stat buf;                    //store input file information
	int buffer;                         //buffer for read function 
	int i;                              //counter variable
	
	//handlle when fstat fails
	if( fstat(fd,&buf) ==  -1){
        printf("cannot figure out the size of the file");
        return NULL;
    }
    //update the size of file variable
    sizeOfFile = buf.st_size;
    
    //handle empty list
     if( (read(fd,&buffer,sizeof(int))) == -1){
			printf("cannot read file");
			return NULL;
		} 
		head->theint = buffer;
		head->next = NULL;

    //repeatly read in integer from input file
    for( i = 1; i < (sizeOfFile/(sizeof(int))); i++){
		//handle when read function fails
        if( (read(fd,&buffer,sizeof(int))) == -1){
			printf("cannot read file");
			return NULL;
		} 
        //add read result to list using a node data structure
		head = listadd(head,buffer);   
    }
	return head;
	
}

/* 
 * check if an int value is in list
 * 
 * Parameters:
 * head: first node reference of the list
 * intvalue: intvalue to be searched
 */
int inlist(Node *head, int intvalue){
	
	//traverse the list
	while(head != NULL){
//check if the value in current node equals to the value to be searched	
		if(intvalue == head->theint){
			return 1;
		}
		//update head reference
		head = head->next;
	}
	
	return 0;	
}

/* 
 * start the game
 * 
 * Parameters: 
 * head: first node reference of the list
 */
void playgame(Node * listhead){
	
	/* initilize variables */
	char buffer[50];        //an char array buffer to store user input
    int userGuess;          //integer represtation of user input
    
    //print welcome message
	printf("This game has you guess which integers are in the list.\n");
    printf("Enter an integer (followed by the newline)\n");
    printf("or q (followed by the newline) to quit.\n");
	
	//main loop of the game (quit when user enter "q")
	while(1){
	    
	    //ask user input and handle when fgets returns an error
		printf("Integer guess: ");
		if(fgets(buffer, 50, stdin) == NULL){
			printf("error");
			exit(1);
			}
		//exit the program when user enters "q"
		if(buffer[0] == 'q'){
			exit(1);
		}
		//convert userinput to integer representation
		if(atoi(buffer)!= 0){
			userGuess = atoi(buffer);
		}
		//handle when user enters an invalid input
		else{
			userGuess = 0;
		}
		//check if the userGuess is in list and print the result
		if(inlist(listhead, userGuess) == 1){
			printf("%d is in the list.\n", userGuess);
		}
		else{
			printf("%d is not in the list.\n", userGuess);
		}
		
}
	
}	
	

v   
int main(int argc, char *argv[]){
    //check if the input argument is correct and handle when it is wrong
    if (argc != 2) {
	    fprintf(stderr, "Wrong input command");
	    exit(1);
    }
    
    /* initilize variables */
    char *fileName;                //file name 
    int fd;                        //input file
    Node *head = malloc(sizeof(Node));  //pointer to first node of list
    //handle when malloc function returns an error
    if (head == NULL){
		printf("malloc function returns an error");
		exit(1);
	}
    
    //update file name
    fileName =argv[1];
    
    //open file and handle when it fails          
    fd = open(fileName,O_RDONLY);     
    if(fd == -1){
        printf("cannot open file");
        exit(1);
    }
   
    //create list
    head= createlist(fd);
   
    //handle when creatlist returns NULL
    if(head == NULL){
		printf("something goes wrong in function createlist");
		exit(1);
	}
	//start the game
    playgame(head);
    
    //close file and and handle when file cannot be closed correctly
    if( close(fd) == -1){
        printf("cannot close file");
        exit(1);
    }
    
    return 0;
}

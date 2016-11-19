/*a single allocation, followed by a call to Mem_Free() does the right thing.*/
#include <assert.h>
#include <stdlib.h>
#include "mem.h"
/******************************************************************************
 * FILENAME: freetests.c
 * AUTHOR:   Songzi Wen, section 1, Xiaojian Nie, section 1
 * DATE:     02/05/2015
 * *****************************************************************************/
int main() {
	assert(Mem_Init(4096) == 0);
	void * myPtr;
	myPtr = Mem_Alloc(12);
	assert(myPtr != NULL);
	assert(Mem_Free(myPtr) == 0);
	
	void * myPtr1;
	myPtr1 =  Mem_Alloc(16) + 2;
	assert(myPtr != NULL);
	assert(Mem_Free(myPtr1) == -1);
	
	void * myPtr2;
	myPtr2 = NULL;
	assert(Mem_Free(myPtr2) == -1);
	exit(0);
}

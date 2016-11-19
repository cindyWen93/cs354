/* written by Karen Miller
 * Jan 2, 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

#define NUMINTS 10

/* This program writes each element of an array of integers
 * to a file in binary format and to stdout as ASCII.
 * The file name is provided as the single command line argument.
 */

  #include <stdio.h>

#define MAXCHAR 12

int main(int argc, char *argv[]) {
   FILE *infile;
   char buffer[MAXCHAR];
   int  linenumber;

   infile = fopen(argv[1], "r");

   linenumber = 1;
   while (fscanf(infile, "%s\n", buffer) != EOF) {
       printf("%d. %s\n", linenumber, buffer);
       linenumber++;
   }

   return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"
 
int main(int argc, char * argv[])
{
    int data[100000]; 
    int nDataItems;   
    int i;

    static int j = 0; 

//use an if condition to check weather command line arguments are provided
/* if they are provided convert them to integers and use them as values to be
sorted in the array by calling the mySort function */

     if (argc > 1) {
        fprintf(stderr, "The command line arguments are:\n");
        for(i = 1; i < argc; i++) {
	    data[j] = atoi(argv[i]); 
             j++;
        }

//if no command line arguments are provided sort the array as before
    } else {
        fprintf(stderr, "There were no command line arguments.\n");
    } 

    nDataItems = j; 
    mySort(data, nDataItems); 

/* Print sorted array to stdout */ 
    for(i = 0; i < nDataItems-1; i++) { 
        if (data[i] > data[i+1]) {
 
            fprintf(stderr, "Sort error: data[%d] (= %d)"
              " should be <= data[%d] (= %d)- -aborting\n",
              i, data[i], i+1, data[i+1]);
            exit(1);
        }
    }
 
/* Check that the data array is sorted. */
    for(i = 0; i < nDataItems; i++) {
        printf("%d\n", data[i]); 
    }
    exit(0);
}


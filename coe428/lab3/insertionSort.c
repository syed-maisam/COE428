#include "mySort.h"

//uses 3 parameteres
void mySort(int array[], unsigned int first, unsigned int last)
    {
       int i,j,k;
  	for(i = first; i<=last; i++){

//myCopy makes a copy of a previous variable
    myCopy(&array[i],&k);
    j = i-1;

//myCompare keeps track of the total number of comparisions
    while(j >= 0 && myCompare(array[j],k)>0){
//mySwap is used to interchange elements
     	 mySwap(&array[j+1],&array[j]);
     		 j--;
    		}
    	array[j+1] = k;
    	}
}


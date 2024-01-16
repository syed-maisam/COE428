#include "mySort.h"

void merge(int array[], unsigned int first, unsigned int mid, unsigned int last){

        int x1, x2, x3;
        int arraySize1 = (mid + 1) - first;
        int arraySize2 = last - mid;

        int leftArray[arraySize1], rightArray[arraySize2];
      
//use a for loops to scan through the elements in the array
//use myCopy to hold the elements in the array
        for(int i = 0; i < arraySize1; i++)
            myCopy(&array[first + b], &leftArray[i]);

        for(int i = 0; i < arraySize2; i++)
           myCopy(&array[mid + 1 + i], &rightArray[i]);


        x1 = 0; //initial index of 1st subarray
        x2 = 0; //initial index of 2nd subarray
        x3 = first; //initial index of merged subarray

//while loops used to sort the elements
//the elements are compared using myCompare and saved using myCopy
        while(x1 < arraySize1 && x2 < arraySize2){

            if(myCompare(leftArray[x1], rightArray[x2]) <= 0){
               myCopy(&leftArray[x1], &array[x3]);
                x1++;
            }
            else {
                myCopy(&rightArray[x2], &array[x3]);
                x2++;
            }
            x3++;
        }

        while(x1 < arraySize1){
            myCopy(&leftArray[x1], &array[x3]);
            x3++;
            x1++;
        }
        while(x2 < arraySize2){
            myCopy(&rightArray[x2], &array[x3]);
            x3++;
            x2++;
        }
}

//split the array into 2 subarrays
void mySort(int array[], unsigned int first, unsigned int last)
    {
        if (first < last){
        int mid = (first + last) / 2;

        mySort(array, first, mid);
        mySort(array, mid + 1, last);
        merge(array, first, mid, last);
        }

}


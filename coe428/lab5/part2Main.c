#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern int isEmpty();
extern int heapDelete();
extern void addHeap(int);
extern int heapSize();
extern void Bigint(int[], int, int);
extern void fullMaxHeapify();
extern void heapSortPushStack();
extern void printNode(int, int);

int main(int argc, char * argv[])
{
     int val;
    printf("Enter your inputs.\n");

    if (scanf("%d", &val) != 1) {
        fprintf(stderr, "Please enter a number");
        exit(1);
    }

    while (val != EOF && val != -1) {
        addHeap(val);

        if (scanf("%d", &val) != 1) {
            fprintf(stderr, "Please enter a number");
            exit(1);
        }
    }

    fullMaxHeapify();
    printNode(heapSize(), 0);
    printf("\n");

    printf("Descending: \n");
    heapSortPushStack();
    printf("Popped:\n");
    for (int i = 0; i < heapSize(); i++) {
        printf("%d\n", pop());
    }


  exit(0);
}

/* 
Code Explainaton:
The "main" function begins by prompting the user to enter input integers. It reads in the input integers using "scanf", and adds each one to the max heap using the "addHeap" function. 
Once all the input integers have been added to the heap, the "fullMaxHeapify" function is called to ensure that the heap satisfies the max heap property. The "fullMaxHeapify" function does this by repeatedly calling the "heapDelete" function, which removes the largest element in the heap and maintains the heap property by rearranging the remaining elements.
The "printNode" function is then called to print out the number of nodes in the heap and their values.
the program sorts the heap in descending order using the "heapSortPushStack" function. This function works by repeatedly calling the "pop" function, which removes the largest element from the heap and pushes it onto a stack. Once all elements have been removed from the heap and pushed onto the stack, the program prints out the contents of the stack using a loop that calls "pop" for each element.
*/


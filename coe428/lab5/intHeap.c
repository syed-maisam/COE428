/**
 *  The functions in this module implement a Heap data structure
 *  of integers.
 **/
#include <stdio.h>

static int heap[101];
static int size = 0;

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

void swap(int i, int j)
{
  int temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

void maxHeapify(int i)
{
  int largest;
  int l = left(i);
  int r = right(i);

  if (l <= size && heap[l] > heap[i])
    largest = l;
  else
    largest = i;

  if (r <= size && heap[r] > heap[largest])
    largest = r;

  if (largest != i) {
    swap(i, largest);
    maxHeapify(largest);
  }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 **/

int heapDelete()
{
  if (size < 1) {
    fprintf(stderr, "Error: Heap underflow.\n");
    return -1;
  }
  int max_val = heap[1];
  heap[1] = heap[size];
  size--;
  maxHeapify(1);
  return max_val;
}

/**
 * addHeap(thing2add) adds the "thing2add" to the Heap.
 **/
void addHeap(int thing2add)
{
  size++;
  int i = size;
  heap[i] = thing2add;

  while (i > 1 && heap[parent(i)] < heap[i]) {
    swap(i, parent(i));
    i = parent(i);
  }
}

/**
 * heapSize() returns the number of items in the Heap.
 **/
int heapSize()
{
  return size;
}


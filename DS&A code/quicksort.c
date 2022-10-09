/*
 *  Quicksort
 */

#include <stdio.h>
#include <stdlib.h>

#define SEED 2
#define LENGTH1 20
#define LENGTH2 15

int rand_int(int first, int last);
int partition(int a[], int first, int last);
void quicksort(int a[], int first, int last);
void swap(int a[], int i, int j);
int * create_rand_int_array(int length);
void display_array(int a[], int first, int last);
int kth_smallest(int a[], int first, int last, int k);

void main()
{
srand48(SEED);
int * a = create_rand_int_array(LENGTH1);
printf("Unsorted array: ");
display_array(a, 0, LENGTH1-1);
quicksort(a, 0, LENGTH1-1);
printf("Sorted array: ");
display_array(a, 0, LENGTH1-1);
free(a);

a = create_rand_int_array(LENGTH1);
printf("\nUnsorted array: ");
display_array(a, 0, LENGTH1-1);
int k = kth_smallest(a, 0, LENGTH1-2, 15);
printf("15th smallest = %d\n\n",k);
free(a);

a = create_rand_int_array(LENGTH2);
printf("\nUnsorted array: ");
display_array(a, 0, LENGTH2-1);
k = kth_smallest(a, 0, LENGTH2-4, 6);
printf("6th smallest = %d\n\n",k);
free(a);

return;
}

/* 
 * This returns the kth smallest value in the array a[], where the 
 * smallest is the 0th, the next smallest is the 1st, and so on.
 * The average time complextiy should be O(n).
 */
int kth_smallest(int a[], int first, int last, int k)
{
    if(first == last) return a[first];
    int q = partition(a,first,last);
    int i = (q - first) + 1; // deciding on the pivot I guess
    if (i == k) return a[q];
    else if (k < i) return kth_smallest(a, first, q-1, k);
    else return kth_smallest(a, q+1, last, k-i);
}

/* 
 * Partitions array[first...last] using a "pivot" = a[first]
 * Returns a value k such that a[first...k] have values less
 * than or equal to the pivot, and a[k+1...last] have values
 * greater than pivot. 
 */
int partition(int a[], int first, int last)
{
swap(a, first, rand_int(first,last)); /* Choose random pivot */
int pivot = a[first];
int less = first+1;
for (int scan=first+1; scan<=last; scan++) {
    if (a[scan] <= pivot) {
        swap(a, less, scan);
	less++;
    }
}
swap(a, first, less-1);
return less-1;
}

void quicksort(int a[], int first, int last)
{
if (last-first < 1) {
    return;
}
int q = partition(a, first, last);
q = partition(a, first, last);
quicksort(a, first, q-1);
quicksort(a, q+1, last);
}

void swap(int a[], int i, int j)
{
int temp = a[i];
a[i] = a[j];
a[j] = temp;
}

/* Create a random integer array */
int * create_rand_int_array(int length)
{
int * a = (int *) malloc(sizeof(int)*length);
for (int i=0; i<length; i++) {
    a[i] = 30 + 7*i;
}
for (int i=0; i<length-1; i++) {
    swap(a, i, rand_int(i, length-1));
}
return a;
}

void display_array(int a[], int first, int last)
{
for (int k=first; k<=last; k++) {
    if (k<last) {
    	printf("%d ", a[k]);
    }
    else {
    	printf("%d", a[k]);
    }
}
printf("\n");
}

/* Returns a random integer in the interval [rist, last] */
int rand_int(int first, int last)
{
if (first >= last) {
    return first;
}
int size = last-first+1;
double randval = drand48();
int delta = (int) (randval*((double) size));
return first + delta;
}


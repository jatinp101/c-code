#include <stdlib.h>
#include <stdio.h>

#define RANDSEED 1
#define ARRAYSIZE 32

int randNum(int start, int end);
void randPermute(int a[], int length);
void fillArray(int a[], int length, int dupvalue);
void displayArray(int a[], int length);
int binarySearch(int arr[], int l, int r, int x);
void insertionSort(int arr[], int n);

int findDup(int a[], int length);

void main()
{
int a[ARRAYSIZE];
srand48(RANDSEED);

fillArray(a, ARRAYSIZE, 12); 
displayArray(a, ARRAYSIZE);
printf("Duplicate: %d\n", findDup(a, ARRAYSIZE));

fillArray(a, ARRAYSIZE, 23); 
displayArray(a, ARRAYSIZE);
printf("Duplicate: %d\n", findDup(a, ARRAYSIZE));

}

/* This takes too long */
int findDup(int a[], int length)
{
	insertionSort(a, length);
	for (int k=0; k<length-1; k++) {
	int temp = binarySearch(a, k+1, length,a[k]);
	if (temp == -1)continue;
	else return a[temp];
}
return -1;
}
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) return mid; 
  
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 

void displayArray(int a[], int length)
{
for (int k=0; k<length; k++) {
	printf("%d ", a[k]);
}
printf("\n");
}

void fillArray(int a[], int length, int dupvalue)
{
for (int k=0; k<length-1; k++) {
	a[k] = k;
}
a[length-1] = dupvalue;
randPermute(a, length);
}


/*
 * Randomly permutes the array a[] 
 */
void randPermute(int a[], int length)
{
for (int k=0; k<length; k++) {
	int j=randNum(k,length-1);  /* Pick a random value */
	int temp = a[j];  /* Swap */
	a[j] = a[k];
	a[k] = temp;
}
}

/*
 * Returns a random integer value in the interval [start, end]
 */
int randNum(int start, int end)
{
int size = end - start + 1;
return start + (lrand48()%size);
}



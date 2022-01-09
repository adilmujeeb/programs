
// C program to rotate an array by
// d elements
#include <stdio.h>
 
/* Function to left Rotate arr[] of size n by 1*/
void leftRotatebyOne(int arr[], int n);
 
/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n)
{
    int i, idx;
    int temp[d];
    for (i = 0; i < n; i++) {
        while(i < d) {
	     temp[i] = arr[i];
	     i++;
	}
        arr[i-d] = arr[i];
    }
    i = n - d;
    for (idx = 0; idx < d; idx++){
         arr[i] = temp[idx];
           i++;
    }	
}
 
void leftRotatebyOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[n-1] = temp;
}
 
/* utility function to print an array */
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    leftRotate(arr, 3, 9);
    printArray(arr, 9);
    return 0;
}

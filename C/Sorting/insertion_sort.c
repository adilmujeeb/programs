/* Insertion Sort 
 *
 */

#include<stdio.h>

void insertion_sort(int arr[], int len) {
    int i = 0, j, temp;

    for(j = 1; j < len; j++) {
       temp = arr[j];
       i = j - 1;
       while (i >=0 && arr[i] > temp) {
          arr[i+1] = arr[i];
          i--;
       } 
       arr[i+1] = temp;
    }
    return;
}

int main() {
    //int arr[] = {5, 2, 4, 6, 1, 3};
    int arr[] = {31, 41, 59, 26, 41, 58};
    int i, len = sizeof(arr)/sizeof(int);

    /* Print original array */ 
    printf("original list:\n");
    for(i=0; i < len; i++)
       printf("%d\n", arr[i]);    

    insertion_sort(arr, len);

    /* Print after insertion sort */
    printf("Sorted array:\n");
    for(i=0; i < len; i++)
       printf("%d\n", arr[i]);    
    return 0;
}

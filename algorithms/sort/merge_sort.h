#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// Mergesort
#include <stdio.h>
#include <stdlib.h>

/*
    A merge sort uses recursion to break down an array into smaller subarrays until
    each subarray contains only one element then the subarrays are slowly merged back
    together while swapping the positions of the highest elements at the same time
    
    merge_sort is called until the first half of the original array is broken down
    into single element subarrays. In the last call to merge_sort the second half of
    the array is passed in and likewise calls to merge_sort are made until the
    second half is broken down as well.

    Merging happens multiple times throughout the entire process. 
    Usually after it is determined that single element subarrays 
    have been created but the final merges will be final steps in the process

    Binary: O(n log n)
*/

int merge(int *l_values, int *r_values, int *arr, int midLeft, int midRight, int n){
    printf("merge: %d\n", n);

    int i, j, k;
    i = j = k = 0;
    
    // Merge (union with duplicates) for two ordered tables work and work_midLeft
    // to give arr.

    // While loop persists until one array is "empty"

    while(i < midLeft && j < midRight){
        if(l_values[i] < r_values[j]){
            arr[k] = l_values[i];
            i++;
        }
        else{
            arr[k] = r_values[j];
            j++;
        }

        k++;                   
    }

    while(i < midLeft){
        arr[k] = l_values[i];
        i++;
        k++;
    }

    while(j < midRight){
        arr[k] = r_values[j];
        j++;
        k++;
    }

    return k;
}

void merge_sort(int *arr, int n){
    printf("merge_sort: %d\n", n);

    if(n < 2) return;

    int midLeft, midRight, i;

    int *work = (int*) malloc(n * sizeof(int));

    midLeft  = n/2;            // midpoint
    midRight = n - midLeft;     // midpoint but if n is odd will be +1

    for(i = 0; i < n; i++) work[i] = arr[i];

    merge_sort(work, midLeft);                               // pointer arithmetic
    merge_sort(work+midLeft, midRight);                      // pointer arithmetic

    merge(work, work+midLeft, arr, midLeft, midRight, n);   // pointer arithmetic
}

#endif

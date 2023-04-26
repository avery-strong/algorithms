// Demonstration of special binary searches for tables with duplicates.
// No input.  Output is how many times each number in
// -1 .. 20 appears in a table.
#include <stdio.h>

int binSearchFirst(int *a,int n,int key){
    // Input: int array a[] with n elements in ascending order.
    //        int key to find.
    // Output: Returns subscript of the first a element >= key.
    //         Returns n if key>a[n-1].
    // Processing: Binary search.

    int low, high, mid;
    low = 0; 
    high = n-1;

    // Subscripts between low and high are in search range.
    // Size of range halves in each iteration.
    // When low>high, low==high+1 and a[high]<key and a[low]>=key. 
    
    while (low<=high){
        mid = (low+high)/2;

        if (a[mid] < key) low = mid+1;
        else high = mid-1;
    }

    return low;
}

int binSearchLast(int *a, int n, int key){
    // Input: int array a[] with n elements in ascending order.
    //        int key to find.
    // Output: Returns subscript of the last a element <= key.
    //         Returns -1 if key<a[0].
    // Processing: Binary search.

    int low, high, mid;
    low = 0;
    high = n-1;

    // subscripts between low and high are in search range.
    // size of range halves in each iteration.
    // When low>high, low==high+1 and a[high]<=key and a[low]>key.

    while (low <= high){
        mid = (low+high)/2;

        if (a[mid] <= key) low = mid+1;
        else high = mid-1;
    }

    return high;
}


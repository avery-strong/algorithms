// Binary search
#include <stdio.h>
#include <stdlib.h>

/*
    Set the low index to the first element of the array and the high index to the last element.

    Inside a while loop that iterates if the condition (low <= high) is met set the mid index 
    to the average of the low and high indices. If the element at the mid index (a[mid]) is the target
    element, return mid. 
    If the middle element (a[mid]) is less than the target element (key) set low = mid+1
    If the middle element (a[mid]) is greater than the target element (key) set high = mid-1
    Repeat steps 3-6 until the element is found or it is clear that the element is not present in the array.

    A version exits that can find multiple occurces of an element with an array by calling what is 
    two different but similar binary search algorithms. Both exclude the first if statement returning 
    mid if a[mid] == key but the final return value at the bottom of the functions return low if searching
    for the first occurence and high if searching for the last occurence

    Binary: O(log n)
*/

int binary_search(int *a, int n, int key){
    // Input: int array a[] with n elements in ascending order.
    //        int key to find.
    // Output: Returns some subscript of a where key is found.
    //         Returns -1 if not found.
    // Processing: Binary search.

    int low, high, mid;
    low = 0;
    high = n-1;

    // subscripts between low and high are in search range.
    // size of range halves in each iteration.
    while(low <= high){
        mid = (low+high)/2;

        if(a[mid] == key) return mid; // key found

        if(a[mid] < key) low = mid+1;
        else high = mid-1;
    }

    return (-1); // key does not appear
}

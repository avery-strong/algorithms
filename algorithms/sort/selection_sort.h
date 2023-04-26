// Selection sort
#include <stdio.h>
#include <stdlib.h>

/*
    First and second for loops begin iterating through an array at the first (i) and 
    second (j = i+1) position in the array. Inside the first for loop but still 
    outside the second an int min = i; is declared and initialized. 

    Inside the second for loop if the value in the a[j] position of the array is 
    less than the value at the a[min] position the value in min is swapped to the
    value of j. 

    Back outside the second for loop but still inside the first for loop we now 
    swap the values inside a[i] and a[min]. We use min as the final position for
    the smallest value found in the array outside of its sorted portions

    Quadratic: O(n^2)
*/

void selection_sort(int *a, int n){
    int i, j, temp;

    for (i = 0; i < n; i++){
        int min = i;

        for(j = i+1; j <= n; j++){
            if(a[j] < a[min]) min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

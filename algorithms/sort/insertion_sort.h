// Insertion Sort
#include <stdio.h>
#include <stdlib.h>

/*
	For loops is initialed at position 1 and iterates until n has been reached.
	A temp variable stores the first a[i] position of an array called a and an
	int variable is initialized to i.

	A while loop inside the for loop iterates as long a j >= 1 and temp < a[j-1].
	Inside the while loop a swap takes place swapping the left value into the right value
	and j is then decremented. The while loop now loops again but in the first series of 
	loops j now equals 0 and will terminate the while loop as j = 0 does not satisfy j >= 1.
	In the later iterations of while loop once after a swap occurs and the j decrement happens
	the value in a[j-1] will always be less than temp so the while loop will terminate as
	temp > a[j-1] does not satisfy temp < a[j-1]

	Finally the temp value is saved into a[j] replacing the value that was originally swapped.
	
	Guaranteed stable
	Quadratic: O(n^2)
*/

void insertion_sort(int *a, int n){
	int i, j, temp;
	
	for(i = 1; i < n; i++){
		temp = a[i];
		j = i;
		
		while(j >= 1 && temp < a[j-1]){
			a[j] = a[j-1];
			j--;
		}

		a[j] = temp;	
	}
}
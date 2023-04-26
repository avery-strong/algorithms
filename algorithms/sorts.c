#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort/insertion_sort.h"
#include "sort/merge_sort.h"
#include "sort/selection_sort.h"
#include "sort/quick_sort.h"

int main(int argc, char *argv[]){

	int i, n;
    int *a;

    scanf("%d", &n);

    a = (int*) malloc(n * sizeof(int));

    for(i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("\ninput: %s\n\n", argv[1]); 

    for (i=0; i<n; i++)printf("%d %d\n", i, a[i]);

	if(strcmp(argv[1], "insertion") == 0)      insertion_sort(a, n);		 
	else if(strcmp(argv[1], "merge") == 0)	   merge_sort(a, n);
	else if(strcmp(argv[1], "selection") == 0) selection_sort(a, n);
    else if(strcmp(argv[1], "quick") == 0)     quick_sort(a, 0, n-1);

    printf("\noutput:\n\n");

    for (i=0; i<n; i++) printf("%d %d\n" ,i ,a[i]);

	return 0;
}
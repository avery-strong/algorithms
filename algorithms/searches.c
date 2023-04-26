#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "search/binary_search.h"
#include "search/binary_range_search.h"

int b[] = {5, 5, 2, 4, 3, 1, 0, 1};

int main(int argc, char *argv[]){
	int i, n, first, last, key, count = 1;
    int *a;

    scanf("%d", &n);

    a = (int*) malloc(n * sizeof(int));

    for(i = 0; i < n; i++) scanf("%d", &a[i]);

    if(strcmp(argv[1], "binary") == 0){
        printf("index  array  key  position\n");

        for(i = 0; i < n; i++){
            key = binary_search(a, n, b[i]);
            printf("%3d   %3d   %3d   %3d\n", i, a[i], b[i], key);
        }
    }
    else if(strcmp(argv[1], "range") == 0){
        printf("key  first  last  count\n");

        for (i = (-1); i < n+1; i++){
            first = binSearchFirst(a, n, i);
            last  = binSearchLast(a, n, i);
            printf("%3d   %3d   %3d   %3d\n", i, first, last, last-first+1);
        }
    }

	return 0;
}

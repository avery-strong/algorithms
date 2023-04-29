#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sort/insertion_sort.h"
#include "sort/kruskal_sort.h"
#include "sort/merge_sort.h"
#include "sort/prims_sort.h"
#include "sort/quick_sort.h"
#include "sort/selection_sort.h"

// used for kruskal
#define r   5
#define c   3

#define ar 4
#define ac 2
#define br 12
#define bc 2
#define cr 12
#define cc 2

#define wkr 23
#define wkc 3

int main(int argc, char *argv[]){
    if(strcmp(argv[1], "prims") == 0){
        int graph[r][r] = { 
                            { 0, 2, 0, 6, 0 },
                            { 2, 0, 3, 8, 5 },
                            { 0, 3, 0, 0, 7 },
                            { 6, 8, 0, 0, 9 },
                            { 0, 5, 7, 9, 0 } 
                        };
                        
        prims_sort(graph);

        //printf("\noutput:\n\n");

        //for (i = 0; i < n; i++) printf("%d %d\n" ,i ,a[i]);

        goto MST;
    }
    else if(strcmp(argv[1], "kruskal") == 0){
        /*  
        int graph[r][c] = { 
                            { 0, 1, 10 },
                            { 0, 2, 6  },
                            { 0, 3, 5  },
                            { 1, 3, 15 },
                            { 2, 3, 4  } 
                        };
        kruskal_sort(r, graph);
        */

        
        // a.dat
        int graph[ar][cc] = { 
                              { 0, 1 },
                              { 1, 0 },
                              { 0, 0 },
                              { 1, 1 }
                            };
        kruskal_sort(ar, ac, graph);
        

        /*
        // b.dat  
        int graph[br][bc] = { 
                              { 0, 1 },
                              { 0, 2 },
                              { 1, 0 },
                              { 1, 1 },
                              { 1, 2 },
                              { 1, 3 },
                              { 2, 0 },
                              { 2, 1 },
                              { 2, 2 },
                              { 2, 3 },
                              { 3, 1 },
                              { 3, 2 }
                        };
        kruskal_sort(br, graph);
        */

        /*
        // c.dat  
        int graph[cr][cc] = { 
                              {    0,    0 },
                              {   50,   50 },
                              {  -50,  -50 },
                              {   50,  -50 },
                              {  -50,   50 },
                              {    0,  100 },
                              {  100,    0 },
                              {    0, -100 },
                              { -100,    0 },
                              {  150,    0 },
                              {  200,   50 },
                              {  250,  100 } 
                        };
        kruskal_sort(cr, cc, graph);
        */  

        /*       
        // weems.dat
        int graph[wkr][wkc] = { 
                                { 0,  1,  1 },
                                { 0,  3,  3 },
                                { 0,  4,  4 },
                                { 1,  2, 11 },
                                { 1,  3,  3 },
                                { 1,  5, 10 },
                                { 2,  5, 12 },
                                { 2,  6, 14 },
                                { 2, 10, 21 },
                                { 3,  4,  5 },
                                { 3,  5,  6 },
                                { 4,  5,  7 },
                                { 4,  7, 16 },
                                { 4,  8, 20 },
                                { 5,  6, 22 },
                                { 5,  7, 18 },
                                { 5,  9, 17 },
                                { 6,  9, 19 },
                                { 6, 10,  8 },
                                { 7,  8, 15 },
                                { 7,  9,  3 },
                                { 8,  9, 13 },
                                { 9, 10,  9 },
                            };


        kruskal_sort(wkr, graph);
        */

        //printf("\noutput:\n\n");

        //for (i = 0; i < n; i++) printf("%d %d\n" ,i ,a[i]);

        goto MST;
    }

	int i, n;
    int *a;

    scanf("%d", &n);

    a = (int*) malloc(n * sizeof(int));

    for(i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("\ninput: %s\n\n", argv[1]); 

    for (i = 0; i < n; i++) printf("%d %d\n", i, a[i]);

	if(strcmp(argv[1],      "insertion") == 0) insertion_sort(a, n);		 
	else if(strcmp(argv[1], "merge")     == 0) merge_sort(a, n);
	else if(strcmp(argv[1], "selection") == 0) selection_sort(a, n);
    else if(strcmp(argv[1], "quick")     == 0) quick_sort(a, 0, n-1);

    printf("\noutput:\n\n");

    for (i = 0; i < n; i++) printf("%d %d\n" ,i ,a[i]);

    MST:

	return 0;
}
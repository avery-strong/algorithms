// Heapsort for a random permutation, heap routines are
// from "Algorithms in C, Third Edition", Robert Sedgewick

// Summer 2016, changed for CLRS, 3rd ed., but still non-recursive.

#include <stdio.h>
#include <stdlib.h>

//#define generateRandom(minRange,maxRange)\(minRange)+labs(random()) % ((maxRange)-(minRange)+1)

// Even though coded with Item as an int, these macros may be easily
// changed to support a more detailed struct.
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; } 
#define compexch(A, B) if (less(B, A)) exch(A, B)

int parent(int i){ return i/2; }
int left(int i)  { return 2*i; }
int right(int i) { return 2*i+1; }

void maxHeapify(Item a[], int k, int N){
// Fixes max-heap starting at a[k].  Assumes
// left and right subtrees already have max-heap
// property.

    int j;

    while (left(k) <= N){
        j = left(k);                                    // left child

        if(j < N && less(a[j], a[j+1])) j=right(k);     // use right child instead

        if(!less(a[k], a[j])) break;

        exch(a[k], a[j]);                               // Swap child with parent
        k = j;                                          // Descend
    }
}

// Maps sub-array to pq subscripting, with heap root at subscript 1.
#define pq(A) a[ell-1+A]

void PQheapsort(Item a[], int ell, int r){ 
    // heapsort for an arbitrary array segment, a[ell] ... a[r]
    int k, N = r-ell+1;

    // Convert array to maxheap, e.g. Build-Max-Heap
    for (k = parent(N); k >= 1; k--) maxHeapify(&pq(0), k, N);

    // Sort . . .
    while (N > 1){
        // Swap maximum out of heap
        exch(pq(1), pq(N)); 

        // Decrease heap size and fix heap at root.
        --N;
        maxHeapify(&pq(0), 1, N); 
    }
}

void printArray(Item a[],int n){
    // Print array, 10 elements per line

    int i;

    for (i=0;i<n;i++){
        printf("%d ",a[i]);

        if(i%10 == 9) printf("\n");
    }

    if(n%10 != 0) printf("\n");
}

int main(){
    int n, i;
    Item *a;

    scanf("%d", &n);

    a = (int*) malloc(n * sizeof(Item));

    for(i = 0; i < n; i++) scanf("%d", &a[i]);


    if (!a){
        printf("malloc failed %d\n",__LINE__);
        exit(0);
    }

    //srandom(seed);
    //generatePerm(a, n);
    printf("Input: \n");
    printArray(a, n);
    PQheapsort(a, 0, n-1);
    printf("heapsort output: \n");
    printArray(a, n);
    free(a);
}
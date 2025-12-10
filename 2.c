int ** create_matrix(int m, int n){
int ** p, i;
p = (int ** )malloc(sizeof(int*)*m);

for (int i = 0; i < m; ++i){
p[i] = (int*)malloc(sizeof(int)*n);}

return p;
}

void destroy_matrix(int **p){
    free(p);
}

// a. There Will be total of 6 calls one from the malloc line 3 and five call from the loop in line 5

// b. Error Checking could be performed after malloc ( after line 3 here ).

// c. All the rows allocated with malloc inside the loop are not freed and can be fixed by free(p[i]);

// d.

#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int m, int n) {
    int **p = malloc(m * sizeof(int*));   // first malloc
    if (p == NULL){
        return NULL;
    }

    int *data = malloc(m * n * sizeof(int)); // second malloc
    if (data == NULL) {
        free(p);
        return NULL;
    }

    for (int i = 0; i < m; i++) {
        p[i] = data + i * n ;  // point each row to the right position
    }

    return p;
}

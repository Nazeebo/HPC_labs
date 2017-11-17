#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int compareInt(void *a, void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    if (ia == ib)
        return 0;
    if (ia > ib)
        return 1;
    return -1;
}

void deleteInV(void* x){
	free(x);
}

int main() {
    vector v;
    int q = 10;
    initVector(&v, q, compareInt,deleteInV);
    int a = 2;
    printf("%d ",getSizeVector(v));

    printf("\n");
    
    int i, j, k;

    for(i = 0; i < v.size; i++)
        *(int*)v.arr[i]=i;

    addInVector(&v, &a);
    printf("%d ",getSizeVector(v));

    int b = 5;
    changeInVector(&v, &b, 1);    

    quickSort(&v, 0, v.size - 1, compareInt);
    v.del(v.arr[v.size--]);
    for (i = 0; i < v.size; i++)
        printf("%d ", *(int *) v.arr[i]);
    deleteVector(&v);
    free(a);
    free(q);
/*    MATRIX matrix;
    int n = 3, m = 3;
    initMatrix(&matrix, n, m, compareInt,deleteInV);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
                *(int *) matrix.matr[i].arr[k] = k;
        }
    }

    addLine( &matrix, 1 , 1, v);
    changeInMatrix( &matrix, 2, 2, b);
    int cc,ss;
    getSizeMatrix( &matrix, &cc , &ss);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
                printf("%d\n", *(int*)matrix.matr[i].arr[k]);
            }
            printf("\n");
        }
    }*/

    return 0;
}

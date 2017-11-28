#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include <time.h>

int compareInt(void *a, void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    if (ia == ib)
        return 0;
    if (ia > ib)
        return 1;
    return -1;
}

void deleteInV(void *x) {
    free(x);
}

int *getIntPointer(int num) {
    int *pt = (int *) malloc(sizeof(int));
    *pt = num;
    return pt;
}

void printVector(const vector* v) {
    printf("<");
    int i;
    for (i = 0; i < v->size; i++)
        printf("%d ", *(int *) v->container[i]);
    printf(">\n");
};

void testVector() {
    vector v;
    int q = 10;
    initVector(&v, q, compareInt, deleteInV);
    int i;
    printf("Creating a vector with %d random elements: \n", q);
    for (i = 0; i < 10; i++)
        addInVector(&v, getIntPointer(rand() % 100));
    printVector(&v);

    printf("Adding 100 in a back of vector: \n");
    addInVector(&v, getIntPointer(100));

    printf("The size of the vector became %d and now vector is: \n", getSizeVector(v));
    printVector(&v);

    changeInVector(&v, getIntPointer(7), 1);
    printf("Changing the element in cell #1 of vector to 7: \n");
    printVector(&v);

    printf("Sorted vector \n");
    quickSort(&v, 0, v.size - 1, compareInt);
    printVector(&v);

    deleteVector(&v);
};

void testMatrix() {
    MATRIX matrix;
    int i, j;
    int n = 3, m = 3;
    initMatrix(&matrix, n, m, compareInt, deleteInV);
    for (i = 0; i < n; i++) {
        vector v;
        initVector(&v, m, compareInt, deleteInV);
        for (j = 0; j < m; j++) {
            addInVector(&v, getIntPointer(rand() % 100));
        }
        printVector(&v);
        matrix.matr[i] = &v;
        addInVector(&v,getIntPointer(rand() % 100));
        printf("\n");
        deleteVector(&v);
    }
    vector* v = matrix.matr[0];
    printVector(v);
    printf(" %d ", *(int*)matrix.matr[0]->container[2]);
    /*addLine( &matrix, 1 , 1, v);
    changeInMatrix( &matrix, 2, 2, );
    int cc,ss;
    getSizeMatrix( &matrix, &cc , &ss);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d\n", *(int*)matrix.matr[i].arr[k]);
        }
        printf("\n");
    }*/

    //deleteMatrix(&matrix);
}


int main() {
    srand(time(NULL));
    //testVector();

    testMatrix();

    return 0;
}

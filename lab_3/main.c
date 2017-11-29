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

void printMatrix(const MATRIX* matrix){
    int i,j;
    for(i = 0;i<matrix->size_n;i++){
        if(i == 0)
            printf("/ ");
            else if(i == matrix->size_n-1)
                printf("\\ ");
        else printf("| ");
        for(j = 0;j<matrix->matr[i]->size;j++)
            printf("%d ", *(int*)matrix->matr[i]->container[j]);
        if(i == 0)
            printf("\\ \n");
        else if(i == matrix->size_n-1)
            printf("/ \n");
        else printf("| \n");
    }
};

void testMatrix() {
    MATRIX matrix;
    int i, j;
    int n = 3, m = 3;
    printf("Creating matrix with %d rows and %d columns with random elements:\n",n,m);
    initMatrix(&matrix, n, m, compareInt, deleteInV);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            addInVector(matrix.matr[i], getIntPointer(rand() % 100));
    }
    printMatrix(&matrix);

    printf("Changing 1st element in 1st row to 7:\n");
    changeInMatrix(&matrix,0,0,getIntPointer(7));
    printMatrix(&matrix);

    printf("Adding a column with random elements to matrix:\n");
    vector v;
    initVector(&v, n, compareInt, deleteInV);
    for (i = 0; i < n; i++)
        addInVector(&v, getIntPointer(rand() % 100));
    addLine(&matrix,0,&v);
    printMatrix(&matrix);

    printf("Adding a row with random elements to matrix:\n");
    vector b;
    initVector(&b, matrix.size_m, compareInt, deleteInV);
    for (i = 0; i < matrix.size_m; i++)
        addInVector(&b, getIntPointer(rand() % 100));
    addLine(&matrix,1,&b);
    printMatrix(&matrix);

    printf("Sorting all rows(vectors) in matrix:\n");
    for (i = 0; i < matrix.size_n; i++)
        quickSort(matrix.matr[i],0,matrix.size_m-1,compareInt);
    printMatrix(&matrix);

    printf("Size of matrix before deleting:\n");
    getSizeMatrix(&matrix,&i,&j);
    printf("%d %d\n",i,j);

    deleteMatrix(&matrix);
    free(v.container);
}


int main() {
    srand(time(NULL));
    //testVector();

    testMatrix();

    return 0;
}


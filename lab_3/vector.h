//
// Created by igor- on 07.11.2017.
//

#ifndef MYVECTOR_VECTOR_H
#define MYVECTOR_VECTOR_H

typedef int (*compareFunc)(void *a, void *b);

typedef void (*deleteUnitV)(void *n);

typedef struct {
    void **container;
    int size;
    int alloMem;
    compareFunc compare;
    deleteUnitV del;
} vector;

typedef struct {
    vector **matr;
    int size_n;
    int original_size_n;
    int size_m;
    compareFunc compare;
    deleteUnitV del;
} MATRIX;


void initVector(vector *v, int size, compareFunc compare, deleteUnitV del);

void initMatrix(MATRIX *matrix, int size_n, int size_m, compareFunc compare, deleteUnitV del);

void addInVector(vector *v, void *x);

int changeInVector(vector *v, void *x, int n);

int changeInMatrix(MATRIX *matrix, int n, int m, void *x);

void addLine(MATRIX *matrix,const int position, vector *data);
void quickSort(vector *v, int left, int right, compareFunc compare);

int getSizeVector(const vector v);

void getSizeMatrix(const MATRIX *matrix, int *i, int *j);

void deleteVector(vector *v);

void deleteMatrix(MATRIX *matrix);


#endif //MYVECTOR_VECTOR_H



//
// Created by igor- on 07.11.2017.
//

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initVector(vector *v, int size, compareFunc compare, deleteUnitV del) {
    v->size = 0;
    v->alloMem = size;
    v->compare = compare;
    v->del = del;
    v->container = malloc(size * sizeof(void *));
};

int getSizeVector(const vector v) {
    return v.size;
};

void addInVector(vector *v, void *x) {   //push back
    if (v->alloMem == v->size) {
        v->size++;
        v->alloMem *= 2;
        v->container = realloc(v->container, (v->alloMem * sizeof(void *)));
        v->container[v->size - 1] = x;
    } else {
        v->size++;
        v->container[v->size - 1] = x;
    }
};

int changeInVector(vector *v, void *data, int index) {
    if (index > v->alloMem)
        return -1;
    v->del(v->container[index]);
    v->container[index] = data;
    return 0;
};

void quickSort(vector *v, int left, int right, compareFunc compare) {
    srand(time(NULL));
    if (left >= right) return;
    int i = left, j = right;
    void *p = v->container[left + rand() % (right - left)];
    while (i <= j) {
        while (compare(v->container[i], p) < 0)i++;
        while (compare(v->container[j], p) > 0)j--;
        if (i <= j) {
            void *tmp = v->container[i];
            v->container[i] = v->container[j];
            v->container[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(v, left, j, compare);
    if (i < right) quickSort(v, i, right, compare);
};

void deleteVector(vector *v) {
    int i;
    for (i = 0; i < v->size; i++)
        v->del(v->container[i]);
    free(v->container);
};

void initMatrix(MATRIX *matrix, int size_n, int size_m, compareFunc compare, deleteUnitV del) {
    matrix->size_n = size_n;
    matrix->size_m = size_m;
    matrix->compare = compare;
    matrix->del = del;
    int i;
    matrix->matr = malloc(sizeof(vector *) * size_n);
/*    for (i = 0; i < size_n; i++) {
        initVector(matrix->matr[i], size_m, compare, del);
    }*/
};

void getSizeMatrix(const MATRIX *matrix, int *i, int *j) {
    *i = matrix->size_n;
    *j = matrix->size_m;
};

int changeInMatrix(MATRIX *matrix, int n, int m, void *x) {
    if (n > matrix->size_n || m > matrix->size_m)
        return -1;
    matrix->del(matrix->matr[n]->container[m]);
    matrix->matr[n]->container[m] = x;

    return 0;
};

void addLine(MATRIX *matrix, int n, int position, vector *data) {
    int i, count;
    if (position == 0) {
        if (data->size < matrix->size_n) count = data->size;
        else count = matrix->size_n;
        for (i = 0; i < count; i++)
            addInVector(matrix->matr[i], data->container[i]);
        matrix->size_m = matrix->matr[0]->size;
    } else {
        matrix->size_n++;
        matrix->matr = realloc(matrix->matr, matrix->size_n);
        initVector(&matrix->matr[matrix->size_n - 1], matrix->size_m, matrix->compare, matrix->del);
        if (data->size < matrix->size_m) count = data->size;
        else count = matrix->size_m;
        for (i = 0; i < count; i++) {
            addInVector(matrix->matr[matrix->size_n - 1], data->container[i]);
        }
    }
};

void deleteMatrix(MATRIX *matrix) {
    int i;
    for (i = 0; i < matrix->size_n; i++) {
        vector* v = matrix->matr[i];
        deleteVector(v);
    }
    free(matrix->matr);
};






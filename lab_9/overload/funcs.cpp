//
// Created by igor- on 12.02.2018.
//

#include "funcs.h"
#include <iostream>

bool palindrome(const char *arr) {
    int size = strlen(arr);
    for(int i=0;i<size/2;i++)
        if(arr[i] != arr[size-i-1]) return false;
    return true;
}


bool growSeq(const char *arr) {
    int size = strlen(arr);
    char letter = arr[0];
    for(int i = 1; i < size; i++) {
        if (arr[i] != letter + 1) return false;
        letter++;
    }
    return true;
}

bool growSeq(const int *arr) {
    int size = strlen((char*)arr);
    int number = arr[0];
    for(int i = 1; i <size; i++){
        if(arr[i] != number+1) return false;
        number++;
    }
    return true;
}

void printMax(const char *arr) {
    int size = strlen(arr);
    char max = arr[0];
    for(int i = 1; i < (size+1)/2; i++)
        if(arr[i] > max) max = arr[i];
    std::cout << max << " ";
}

void printMax(const int *arr) {
    int size = strlen((char*)arr);
    int max = arr[0];
    for(int i = 1; i < (size+1)/2; i++)
        if(arr[i] > max) max = arr[i];
    std::cout << max << " ";
}

void getSequence(const char *arr, int *out) {
    int size = strlen(arr);
    int counter=0;
    for(int i = 0; i < size/2; i+=2)
        out[counter++] = (arr[i] - '0')*10 + (arr[i+1] - '0');
}

void afterGrow(const char *arr) {
    int size = strlen(arr), middle = (size-1)/2;
    std::cout << arr[middle] << " ";
}

void afterGrow(const int *arr) {
    int size = strlen((char*)arr),sum = 0;
    for(int i = 0; i < size; i++)
        sum+=arr[i];
    std::cout << sum/size << " ";
}



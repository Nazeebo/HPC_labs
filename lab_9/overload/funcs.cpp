//
// Created by igor- on 12.02.2018.
//

#include "funcs.h"
#include <iostream>

bool palindrome(const char *arr) {
    int size = strlen(arr);
    for (int i = 0; i < size / 2; i++)
        if (arr[i] != arr[size - i - 1]) return false;
    return true;
}

bool growSeq(const char *arr) {
    int size = strlen(arr);
    char letter = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] != letter + 1) return false;
        letter++;
    }
    return true;
}

void printMax(const char *arr, bool isDigit) {
    int size = strlen(arr);
    if(isDigit){
        int digit[size+1],max=0;
        for(int i = 0; i < size; i++) {
            digit[i] = (int) arr[i];
            if(digit[i] > max) max = digit[i];
        }
        std::cout << max << " ";
    } else {
        char max = arr[0];
        for (int i = 1; i < (size + 1) / 2; i++)
            if (arr[i] > max) max = arr[i];
        std::cout << max << " ";
    }
}

void changingWayOfStore(const char *arr, char *out) {
    int size = strlen(arr);
    int counter = 0;
    for (int i = 0; i < size; i+=2){
        out[counter++] = (arr[i] - '0') * 10 + (arr[i + 1] - '0');
    }

}

void afterGrow(const char *arr, bool isDigit) {
    int size = strlen(arr), middle = (size + 1) / 2;
    if(isDigit){
        int sum=0;
        for (int i = 0; i < size; i++)
            sum += arr[i];

        std::cout << sum / size << " ";
    }
    else std::cout << arr[middle] << " ";
}

void printArray(const char *arr) {
    int size = strlen(arr);
    for(int i = 0; i < size;i++)
        std::cout << (int)arr[i] << " ";
    std::cout << std::endl;
}





//
//  lesson3.c
//  lesson3
//
//  Created by Александр Берлин on 03/10/2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%d\n", array[i]);
        else
            printf("%d ", array[i]);
    }
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.

void bubbleSort(int* array, int size) {
    int operations = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
            operations++;
        }
    printf("\nStandart Bubble Sort has %d operations. Output array:\n", operations);
    printArray(array, size);
}

void optimizedBubbleSort(int* array, int size) {
    int operations = 0;
    for (int i = 0; i < size; i++) {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                flag = 1;
            }
            operations++;
        }
        if (flag == 0) break;
    }
    printf("\nOptimized Bubble Sort has %d operations. Output array:\n", operations);
    printArray(array, size);
}

// 2. Реализовать шейкерную сортировку.

void shakerSort(int* array, int size) {
    int left = 0, right = size - 1;
    int operations = 0;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (array[i] > array[i+1])
                swap(&array[i], &array[i+1]);
            operations++;
        }
        right--;
        for (int i = right; i > left; i--) {
            if (array[i-1] > array[i])
                swap(&array[i-1], &array[i]);
            operations++;
        }
        left++;
    }
    printf("\nShaker Sort has %d operations. Output array:\n", operations);
    printArray(array, size);
}

// 3. Погуглить как осуществляется Pigeon Hole Sort и попробовать реализовать на языке С.

void pigeonHoleSort(int* array, int size) {
    int calculate_array[100] = { 0 };
    int i = 0, j = 0;
    for (int i = 0; i < size; i++)
        calculate_array[array[i]]++;
    while(i != size) {
        while (calculate_array[j] == 0) {
            j++;
        }
        while (calculate_array[j] != 0) {
            array[i] = j;
            calculate_array[j]--;
            i++;
        }
    }
    printf("\nPigeon Hole Sort. Output array:\n");
    printArray(array, size);
}

int main(int argc, const char * argv[]) {
    const int size = 20;
    int array[size];
    printf("Original array:\n");
    fillArray(array, size);
    printArray(array, size);
    printf("\nZ. 1.1");
    bubbleSort(array, size);
    printf("\nZ. 1.2");
    fillArray(array, size);
    optimizedBubbleSort(array, size);
    printf("\nZ. 2");
    fillArray(array, size);
    shakerSort(array, size);
    printf("\nZ. 3");
    fillArray(array, size);
    pigeonHoleSort(array, size);
    return 0;
}

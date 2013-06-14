#include "BubbleSort.h"
#include <iostream>

BubbleSort::BubbleSort() {
    numbers = NULL;
    numbersAmount = 0;
}

BubbleSort::BubbleSort(int *array, int size) {
    numbersAmount = size;
    numbers = new int[size];
    if (numbers == NULL) {
        std::cout << "Allocation failed." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        numbers[i] = array[i];
    }
}


BubbleSort::~BubbleSort() {
    delete[] numbers;
}

void BubbleSort::SetNumbers(int *array, int size) {
    // discard old pointer space?
    numbersAmount = size;
    numbers = new int[size];
    if (numbers == NULL) {
        std::cout << "Allocation failed." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        numbers[i] = array[i];
    }
}

void BubbleSort::Print() {
    for (int i = 0; i < numbersAmount; ++i) {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl << std::endl;
}

void BubbleSort::Sort() {
    int smaller;
    for (int i = 1; i < numbersAmount; ++i) {
        for (int j = 1; j < numbersAmount; ++j) {
            if (numbers[j-1] > numbers[j]) {
                smaller = numbers[j];
                numbers[j] = numbers[j-1];
                numbers[j-1] = smaller;
            }
        }
    }
}


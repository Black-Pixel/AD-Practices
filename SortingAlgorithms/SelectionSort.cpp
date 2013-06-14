#include "SelectionSort.h"
#include <iostream>

SelectionSort::SelectionSort() {
    numbers = NULL;
    numbersAmount = 0;
}

SelectionSort::SelectionSort(int *array, int size) {
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

SelectionSort::~SelectionSort() {
    delete[] numbers;
}

void SelectionSort::SetNumbers(int *array, int size) {
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

void SelectionSort::Print() {
    for (int i = 0; i < numbersAmount; ++i) {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl << std::endl;
}

void SelectionSort::Sort() {
    int temp;
    for (int i = 0; i < numbersAmount-1; ++i) {
        int smallest = i;
        for (int j = i+1; j < numbersAmount; ++j) {
            if (numbers[j] < numbers[smallest]) {
                smallest = j;
            }
        }

        temp = numbers[smallest];
        numbers[smallest] = numbers[i];
        numbers[i] = temp;
    }
}

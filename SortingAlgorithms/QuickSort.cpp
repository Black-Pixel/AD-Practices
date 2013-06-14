#include "QuickSort.h"
#include <iostream>

QuickSort::QuickSort() {
    numbers = NULL;
    numbersAmount = 0;
}

QuickSort::QuickSort(int *array, int size) {
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

QuickSort::~QuickSort() {
    delete[] numbers;
}

void QuickSort::SetNumbers(int *array, int size) {
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

void QuickSort::Print() {
    for (int i = 0; i < numbersAmount; ++i) {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl << std::endl;
}

void QuickSort::Sort() {
    Sort(0,numbersAmount-1);
}

void QuickSort::Sort(int left, int right) {
    int pivot = numbers[(left+right)/2];
    int i = left;
    int j = right;

    // Partitioning
    while (i <= j) {
        while (numbers[i] < pivot) {
            ++i;
        }
        while (numbers[j] > pivot) {
            --j;
        }

        if (i <= j) {
            Swap(i,j);
            ++i;
            --j;
        }
    }

    // Recursive sorting
    if (left < j) {
        Sort(left,j);
    }
    if (i < right) {
        Sort(i,right);
    }
}

void QuickSort::Swap(int left, int right) {
    int temp = numbers[left];
    numbers[left] = numbers[right];
    numbers[right] = temp;
}

#include "MergeSort.h"
#include <iostream>

MergeSort::MergeSort() {
    numbers = NULL;
    numbersTemp = NULL;
    numbersAmount = 0;
}

MergeSort::MergeSort(int *array, int size) {
    numbersAmount = size;
    numbers = new int[size];
    if (numbers == NULL) {
        std::cout << "Allocation failed." << std::endl;
        return;
    }
    numbersTemp = new int[size];
    if (numbersTemp == NULL) {
        std::cout << "Allocation failed." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        numbers[i] = array[i];
    }
}

MergeSort::~MergeSort() {
    delete[] numbers;
    delete[] numbersTemp;
}

void MergeSort::SetNumbers(int *array, int size) {
    // discard old pointer space?
    numbersAmount = size;
    numbers = new int[size];
    if (numbers == NULL) {
        std::cout << "Allocation failed." << std::endl;
        return;
    }
    numbersTemp = new int[size];
    if (numbersTemp == NULL) {
        std::cout << "Allocation failed." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        numbers[i] = array[i];
    }
}

void MergeSort::Print() {
    for (int i = 0; i < numbersAmount; ++i) {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl << std::endl;
}

void MergeSort::Sort() {
    Sort(0,numbersAmount-1);
}

void MergeSort::Sort(int left, int right) {
    int pivot;
    if (left < right) {
        pivot = (left + right) / 2;
        Sort(left, pivot);
        Sort(pivot + 1, right);
        Merge(left, pivot, right);
    }
}

void MergeSort::Merge(int left, int pivot, int right) {
    int i,j;
    int h = left;
    i = left;
    j = pivot+1;

    while (h <= pivot && j <= right) {
        if (numbers[h] <= numbers[j]) {
            numbersTemp[i] = numbers[h];
            ++h;
        } else {
            numbersTemp[i] = numbers[j];
            ++j;
        }
        ++i;
    }

    if (h > pivot) {
        for (int k = j; k <= right; ++k) {  // Nothing more left, fill up the rest
            numbersTemp[i] = numbers[k];
            ++i;
        }
    } else {
        for (int k = h; k <= pivot; ++k) { // Nothing more right, fill up the rest
            numbersTemp[i] = numbers[k];
            ++i;
        }
    }
    for (int k = left; k <= right; ++k) { // Copy back the temporary stuff
        numbers[k] = numbersTemp[k];
    }
}

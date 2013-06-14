#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time, clock */
#include <sstream>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"

void PrintArray(int *array, int size);
void GenerateRandomNumbers(int **array, int size, int rangeMin, int rangeMax);

int main() {
    int *array = NULL;
    int size = 10000;
    int rangeMin = 0;
    int rangeMax = 1000;
    std::string input = "";
    clock_t start;

    GenerateRandomNumbers(&array,size,rangeMin,rangeMax);

    char choice = '0';

    while (choice != 'e') {
        std::cout << "||=========Sorting Algorithms=========||" << std::endl;
        std::cout << "|| 1. Set length of the number array  ||" << std::endl;
        std::cout << "|| 2. Set the range for the numbers   ||" << std::endl;
        std::cout << "|| 3. Show the random generated array ||" << std::endl;
        std::cout << "|| 4. Compare the algorithms          ||" << std::endl;
        std::cout << "|| ---------------------------------- ||" << std::endl;
        std::cout << "|| e. Exit                            ||" << std::endl;
        std::cout << "||====================================||" << std::endl;

        std::cin >> choice;
        std::cin.ignore();

        if (choice == '1') {
            while (true) {
                std::cout << "Input length for array: ";
                getline(std::cin, input);
                std::stringstream myStream(input);
                if (myStream >> size) {
                    break;
                }
                std::cout << "Invalid number, please try again" << std::endl;
            }
            std::cout << size;
            std::cout << std::endl;
            GenerateRandomNumbers(&array,size,rangeMin,rangeMax);
        } else if (choice == '2') {
            while (true) {
                std::cout << "Input min value: ";
                getline(std::cin, input);
                std::stringstream myStream(input);
                if (myStream >> rangeMin) {
                    break;
                }
                std::cout << "Invalid number, please try again" << std::endl;
            }
            while (true) {
                std::cout << "Input max value: ";
                getline(std::cin, input);
                std::stringstream myStream(input);
                if (myStream >> rangeMax) {
                    break;
                }
                std::cout << "Invalid number, please try again" << std::endl;
            }
            std::cout << rangeMin << " " << rangeMax << std::endl;
            std::cout << std::endl;
            GenerateRandomNumbers(&array,size,rangeMin,rangeMax);
        } else if (choice == '3') {
            PrintArray(array,size);
        } else if (choice == '4') {

            BubbleSort bubbleSort = BubbleSort(array,size);
            start = clock();
            bubbleSort.Sort();
            double durationBubbleSort = (clock() - start) / (double) CLOCKS_PER_SEC;

            SelectionSort selectionSort = SelectionSort(array,size);
            start = clock();
            selectionSort.Sort();
            double durationSelectionSort = (clock() - start) / (double) CLOCKS_PER_SEC;

            InsertionSort insertionSort = InsertionSort(array,size);
            start = clock();
            insertionSort.Sort();
            double durationInsertionSort = (clock() - start) / (double) CLOCKS_PER_SEC;

            QuickSort quickSort = QuickSort(array,size);
            start = clock();
            quickSort.Sort();
            double durationQuickSort = (clock() - start) / (double) CLOCKS_PER_SEC;

            MergeSort mergeSort = MergeSort(array,size);
            start = clock();
            mergeSort.Sort();
            double durationMergeSort = (clock() - start) / (double) CLOCKS_PER_SEC;

            std::cout << "Numbers: " << size << " Range: " << rangeMin << " - " << rangeMax << std::endl;
            std::cout << "Duration in clocks per second:" << std::endl;
            std::cout << "BubbleSort: " << durationBubbleSort << std::endl;
            std::cout << "SelectionSort: " << durationSelectionSort << std::endl;
            std::cout << "InsertionSort: " << durationInsertionSort << std::endl;
            std::cout << "QuickSort: " << durationQuickSort << std::endl;
            std::cout << "MergeSort: " << durationMergeSort << std::endl;

        }

    }

    delete[] array;
    return 0;
}

void PrintArray(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void GenerateRandomNumbers(int **array, int size, int rangeMin, int rangeMax) {
    srand (time(NULL)); // initialize random seed

    *array = new int[size];
    for (int i = 0; i < size; ++i) {
        (*array)[i] = rand() % rangeMax + rangeMin;
    }
}

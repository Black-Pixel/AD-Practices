#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H


class SelectionSort {
private:
    int *numbers;
    int numbersAmount;
public:
    SelectionSort();
    SelectionSort(int*, int size);
    virtual ~SelectionSort();
    void SetNumbers(int*, int size);
    void Sort();
    void Print();
};

#endif // SELECTIONSORT_H

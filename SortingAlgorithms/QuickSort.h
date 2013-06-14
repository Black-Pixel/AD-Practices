#ifndef QUICKSORT_H
#define QUICKSORT_H


class QuickSort {
private:
    int *numbers;
    int numbersAmount;
    void Swap(int smaller, int bigger);
    void Sort(int left, int right);
public:
    QuickSort();
    QuickSort(int*, int);
    void SetNumbers(int*, int);
    void Sort();
    void Print();
    virtual ~QuickSort();
};

#endif // QUICKSORT_H

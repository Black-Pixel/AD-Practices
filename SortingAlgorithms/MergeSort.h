#ifndef MERGESORT_H
#define MERGESORT_H


class MergeSort {
private:
    int *numbers;
    int *numbersTemp;
    int numbersAmount;
    void Sort(int, int);
    void Merge(int, int, int);
public:
    MergeSort();
    MergeSort(int*, int);
    void SetNumbers(int*, int);
    void Sort();
    void Print();
    virtual ~MergeSort();
};

#endif // MERGESORT_H

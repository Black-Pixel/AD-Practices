#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H


class InsertionSort {
private:
    int *numbers;
    int numbersAmount;
public:
    InsertionSort();
    InsertionSort(int*, int size);
    virtual ~InsertionSort();
    void SetNumbers(int*, int size);
    void Sort();
    void Print();
};

#endif // INSERTIONSORT_H

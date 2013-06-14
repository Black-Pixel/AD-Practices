#ifndef BUBBLESORT_H
#define BUBBLESORT_H


class BubbleSort {
private:
    int *numbers;
    int numbersAmount;
public:
    BubbleSort();
    BubbleSort(int*, int size);
    void SetNumbers(int*, int size);
    void Sort();
    void Print();
    virtual ~BubbleSort();
};

#endif // BUBBLESORT_H

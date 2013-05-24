#include "SkipList.h"
#include <iostream>
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

SkipList::SkipList() {
    //ctor
    maxHeight = 10;

    pFirstElement = new Element(maxHeight);
    pLastElement = new Element(maxHeight);
    for (int i = 0; i < maxHeight; ++i) {
        pFirstElement->pElementArray[i] = pLastElement;
    }

    // initialize random seed:
    srand (time(NULL));
}

SkipList::~SkipList() {
    //dtor
    delete pFirstElement;
    delete pLastElement;
}

int SkipList::randomHeight() {
    // generate number between 1 and maxHeight
    return rand() % maxHeight + 1;
}

Element::Element(int height) {
    pElementArray = new Element*[height];
    for (int i = 0; i < height; ++i) {
        pElementArray[i] = NULL;
    }
    this->height = height;
    pValue = NULL;
}

Element::~Element() {
    delete [] pElementArray;
}

void SkipList::Insert(int key) {
    if (!Search(key)) { // If key is not already in the list
        int height = randomHeight();
        Element* pElement = new Element(height);
        pElement->pValue = new int;
        *pElement->pValue = key;
        Element* pBiggerElement = NULL;

        Element* pCurrent = pFirstElement;

        for (int i = maxHeight-1; i >= 0; --i) {
            if (pCurrent->pElementArray[i] != pLastElement) { // the next element in the list
                if (*pCurrent->pElementArray[i]->pValue < key) { // key is bigger than the next value
                    if (pBiggerElement != NULL) { // Insert before the pBiggerElement
                        pCurrent = pCurrent->pElementArray[i];
                        for (int j = 0; j < height; ++j) {
                            pElement->pElementArray[j] = pBiggerElement;
                        }
                        for (int k = 0; k < pCurrent->height && k < height; ++k) {
                            pCurrent->pElementArray[k] = pElement;
                        }
                        break;
                    }
                    pCurrent = pCurrent->pElementArray[i];
                    i = pCurrent->height-1; // necessary? or just stay at the same height with ++i ?
                } else { // key is smaller
                    pBiggerElement = pCurrent->pElementArray[i];
                    if (i == 0) {
                        for (int j = 0; j < height; ++j) {
                            pElement->pElementArray[j] = pBiggerElement;
                        }
                        for (int k = 0; k < pCurrent->height && k < height; ++k) {
                            pCurrent->pElementArray[k] = pElement;
                        }
                        break;
                    }
                }
            } else if (i == 0) {
                if (pBiggerElement != NULL) {
                    for (int j = 0; j < height; ++j) {
                        pElement->pElementArray[j] = pBiggerElement;
                    }
                    for (int k = 0; k < pCurrent->height && k < height; ++k) {
                        pCurrent->pElementArray[k] = pElement;
                    }
                    break;
                }
                for (int j = 0; j < height; ++j) { // the list is empty, add it after first element
                    pCurrent->pElementArray[j] = pElement;
                    pElement->pElementArray[j] = pLastElement;
                }
                break;
            }
        }
    }
}

void SkipList::Print() {
    Element* pCurrent = pFirstElement;
    while (pCurrent->pElementArray[0] != pLastElement) {
        pCurrent = pCurrent->pElementArray[0];
        std::cout << "Value: " << *pCurrent->pValue << std::endl;
    }
}

bool SkipList::Search(int key) {
    Element* pCurrent = pFirstElement;
    while (pCurrent->pElementArray[0] != pLastElement) {
        pCurrent = pCurrent->pElementArray[0];
        if (*pCurrent->pValue == key) {
            return true;
        }
    }
    return false;
}

void SkipList::Delete(int key) {
    Element* pCurrent = pFirstElement;
    Element* pPrevious = pFirstElement;
    while (pCurrent->pElementArray[0] != pLastElement) {
        pPrevious = pCurrent;
        pCurrent = pCurrent->pElementArray[0];
        if (*pCurrent->pValue == key) {
            for (int i = 0; i < pCurrent->height && i < pPrevious->height; ++i) {
                pPrevious->pElementArray[i] = pCurrent->pElementArray[i];
            }
        }
    }
}

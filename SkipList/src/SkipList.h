#ifndef SKIPLIST_H
#define SKIPLIST_H

class Element;

class SkipList {
private:
    Element* pFirstElement;
    Element* pLastElement;
    int maxHeight;
    int randomHeight();
public:
    void Insert(int);
    void Print();
    bool Search(int);
    void Delete(int);
    SkipList();
    virtual ~SkipList();
};

class Element {
private:
    Element** pElementArray;
    int height;
    int* pValue;
public:
    Element(int);
    virtual ~Element();
    friend class SkipList;
};
#endif // SKIPLIST_H

#ifndef CLLIST_H
#define CLLIST_H

#include "node.h"


template <class T>
class CLList {
private:
    node<T>* first;
    int length;

public:
    int getLength() const;
    void insertItem(T);
    void deleteItem(T);
    void printList() const;
    bool searchItem(T) const;
    bool isEmpty() const;
    void destroy();
    void copy(const CLList<T> &); // TODO: Finish defining this

    CLList();
    ~CLList();
    CLList(const CLList<T> &); // TODO: Finish defining this
    const CLList<T> & operator=(const CLList &); // TODO: Finish defining this

};

#endif
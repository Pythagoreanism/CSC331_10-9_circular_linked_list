#ifndef CLLIST_H
#define CLLIST_H

#include "node.h"

/**
 * \brief A sorted Circular Linked List
 */
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
    void copy(const CLList<T> &);

    CLList();
    ~CLList();
    CLList(const CLList<T> &);
    const CLList<T> & operator=(const CLList &);

};

#endif
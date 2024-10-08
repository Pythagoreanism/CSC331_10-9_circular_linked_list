#include <iostream>
using namespace std;


template <class T>
struct node {
    T item;
    node<T>* next;
};


template <class T>
class CLList {
private:
    node<T>* first;
    int length;

public:
    int getLength() const;
    void addItem(T);
    void deleteItem(T);
    void printList() const;
    bool searchItem(T) const;
    bool isEmpty() const;
    void destroy();
    void copy();

    CLList();
    ~CLList();
    CLList(const CLList<T> &);
    const CLList<T> & operator=(const CLList &);

};

template <class T>
int CLList<T>::getLength() const { return length; }
template <class T>
void CLList<T>::addItem(T item) {
    // TODO: Define function
}
template <class T>
void CLList<T>::deleteItem(T item) {
    // TODO: Define function
}
template <class T>
void CLList<T>::printList() const {
    // TODO: Define function
}
template <class T>
bool CLList<T>::searchItem(T item) const {
    // TODO: Define function
}
template <class T>
bool CLList<T>::isEmpty() const {
    // TODO: Define function
}
template <class T>
void CLList<T>::destroy() {
    // TODO: Define function
}
template <class T>
void CLList<T>::copy() {
    // TODO: Define function
}


template <class T>
CLList<T>::CLList() : first(nullptr), length(0) {}
template <class T>
CLList<T>::~CLList() {
    // TODO: Define function
}
template <class T>
CLList<T>::CLList(const CLList<T> & right) {
    // TODO: Define function
}
template <class T>
const CLList<T> & CLList<T>::operator=(const CLList<T> & right) {
    // TODO: Define function
}


int main() {
    CLList<int> list;

    cout << "Length: " << list.getLength() << endl;

    return 0;
}
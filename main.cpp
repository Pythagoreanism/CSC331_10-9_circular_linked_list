#include <iostream>
using namespace std;


template <class T>
struct node {
    T info;
    node<T>* next;
};


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
    void copy();

    CLList();
    //~CLList();
    CLList(const CLList<T> &);
    const CLList<T> & operator=(const CLList &);

};

template <class T>
int CLList<T>::getLength() const { return length; }
template <class T>
void CLList<T>::insertItem(T itemToInsert) {
    first = new node<T>;
    first->info = itemToInsert;
    
    if (length == 0 && first == nullptr) { // List is empty
        first->next = first;
    }
    else if (first == first->next) { // List contains one node
        if (itemToInsert < first->info) {
            // Item is less than existing item
        }
        else {
            // Item is more than existing item
        }
    }
    else { // List contains more than 1 node
        if (itemToInsert > first->info) {
            // Item is greater than largest item in list
        }
        else if (itemToInsert < first->next->info) {
            // Item is less than smallest item in list
        }
        else {
            // Item is between smallest and largest item in list
            // Traverse until spot based on value is found
        }
    }

    length++;
}
template <class T>
void CLList<T>::deleteItem(T itemToDelete) {
    // TODO: Define function
}
template <class T>
void CLList<T>::printList() const {
    // TODO: Define function
}
template <class T>
bool CLList<T>::searchItem(T itemToSearch) const {
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
/* template <class T>
CLList<T>::~CLList() {
    // TODO: Define function
} */
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

    list.insertItem(5);

    return 0;
}
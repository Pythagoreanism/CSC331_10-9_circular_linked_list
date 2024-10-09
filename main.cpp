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
    node<T>* p = new node<T>;
    p->info = itemToInsert;
    
    if (length == 0 && first == nullptr) { // List is empty
        first = p;
        first->next = first;
    }
    else if (first == first->next) { // List contains one node
        if (itemToInsert < first->info) { // Item is less than existing item
            first->next = p;
            p->next = first;
        }
        else { // Item is more than existing item
            first->next = p;
            p->next = first;
            first = p;
        }
    }
    else { // List contains more than 1 node
        if (itemToInsert > first->info) { // Item is greater than largest item in list
            p->next = first->next;
            first->next = p;
            first = p;
        }
        else if (itemToInsert < first->next->info) { // Item is less than smallest item in list
            p->next = first->next;
            first->next = p;
        }
        else { // Item is between smallest and largest item in list
            node<T>* q = first->next;
            node<T>* r = first; // To access node before q

            // Traverse until spot based on value is found
            while (p->info > q->info) {
                q = q->next;
                r = r->next;
            }

            p->next = q;
            r->next = p;
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

    list.insertItem(5); // Inserting empty list

    CLList<int> list2;
    
    list2.insertItem(2);
    list2.insertItem(1); // Inserting item less than existing item

    CLList<int> list3;

    list3.insertItem(2);
    list3.insertItem(3); // Inserting item greater than existing item

    CLList<int> list4;

    list4.insertItem(10); list4.insertItem(20);
    list4.insertItem(30); // Inserting item greater than largest

    CLList<int> list5;

    list5.insertItem(10); list5.insertItem(20);
    list5.insertItem(5); // Inserting item lower than smallest

    CLList<int> list6;
    list6.insertItem(10); list6.insertItem(20); 
    list6.insertItem(30); list6.insertItem(40);
    list6.insertItem(25); // Inserting item between two items

    return 0;
}
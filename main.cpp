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
    if (first == nullptr) {
        cout << "List is empty!" << endl;
    }
    else {
        node<T>* p = first->next; // Start after largest
        
        do {
            cout << "[" << p->info << "]->";
            p = p->next;
        } while (p != first->next);

        cout << '\n';
    }
}
template <class T>
bool CLList<T>::searchItem(T itemToSearch) const {
    if (first == nullptr || itemToSearch > first->info ||
        itemToSearch < first->next->info) {
        return false;
    }

    node<T>* p = first->next; // Start after largest
    do {
        if (p->info == itemToSearch) {
            return true;
        }
        p = p->next;
    } while (p != first->next);

    return false;
}
template <class T>
bool CLList<T>::isEmpty() const { return length == 0; }
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
    list.printList();

    CLList<int> list2;
    
    list2.insertItem(2);
    list2.insertItem(1); // Inserting item less than existing item

    list2.printList();

    CLList<int> list3;

    list3.insertItem(2);
    list3.insertItem(3); // Inserting item greater than existing item

    list3.printList();

    CLList<int> list4;

    list4.insertItem(10); list4.insertItem(20);
    list4.insertItem(30); // Inserting item greater than largest

    list4.printList();

    CLList<int> list5;

    list5.insertItem(10); list5.insertItem(20);
    list5.insertItem(5); // Inserting item lower than smallest

    list5.printList();

    CLList<int> list6;
    
    list6.insertItem(10); list6.insertItem(20); 
    list6.insertItem(30); list6.insertItem(40);
    list6.insertItem(25); // Inserting item between two items

    list6.printList();

    cout << list6.searchItem(5)  << endl; // Expected: 0
    cout << list6.searchItem(10) << endl; // Expected: 1
    cout << list6.searchItem(20) << endl; // Expected: 1
    cout << list6.searchItem(25) << endl; // Expected: 1
    cout << list6.searchItem(30) << endl; // Expected: 1
    cout << list6.searchItem(35) << endl; // Expected: 0
    cout << list6.searchItem(40) << endl; // Expected: 1
    cout << list6.searchItem(45) << endl; // Expected: 0

    return 0;
}
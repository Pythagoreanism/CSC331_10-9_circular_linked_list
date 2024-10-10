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
    int getLength() const; // Done
    void insertItem(T); // Done
    void deleteItem(T); // Done
    void printList() const; // Done
    bool searchItem(T) const; // Done
    bool isEmpty() const; // Done
    void destroy();
    void copy();

    CLList(); // Done
    ~CLList();
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
    if (first == nullptr) {
        cout << "List is empty!" << endl;
    }
    else if (itemToDelete > first->info || 
             itemToDelete < first->next->info) {
        cout << "Item not found!" << endl;
    }
    else {
        node<T>* p = first->next;
        node<T>* q = first;

        while (q->next != first && p->info < itemToDelete) {            
            p = p->next;
            q = q->next;
        }
        
        if (p->info == itemToDelete) {
            q->next = p->next;
            delete p;
            length--;
            cout << "Item deleted successfully." << endl;
        }
        else {
            cout << "Item not found!" << endl;
        }
    }
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
    node<T>* p = first->next;

    while (p != first) {
        first->next = p->next;
        delete p;
        p = first->next;
        cout << "Deleting" << endl;
    }
    delete first;

    length = 0;
}
template <class T>
void CLList<T>::copy() {
    // TODO: Define function
}


template <class T>
CLList<T>::CLList() : first(nullptr), length(0) {}
template <class T>
CLList<T>::~CLList() { destroy(); }
template <class T>
CLList<T>::CLList(const CLList<T> & right) {
    copy();
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

    CLList<int> list7;

    list7.insertItem(10); list7.insertItem(20);
    list7.insertItem(30); list7.insertItem(40);

    list7.deleteItem(0); // Delete item less than lowest item

    CLList<int> list8;

    list8.insertItem(10); list8.insertItem(20);
    list8.insertItem(30); list8.insertItem(40);

    list8.deleteItem(10); // Delete item in list

    CLList<int> list9;

    list9.insertItem(10); list9.insertItem(20);
    list9.insertItem(30); list9.insertItem(40);

    list9.deleteItem(35); // Delete item not in list REDO THIS TEST

    CLList<int> list10;

    list10.insertItem(10); list10.insertItem(20);
    list10.insertItem(30); list10.insertItem(40);

    list10.deleteItem(50); // Delete item greater than largest item

    return 0;
}
#include "node.h"
#include "CLList.h"
#include <iostream>


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
        std::cout << "List is empty!" << std::endl;
    }
    else if (itemToDelete > first->info || 
             itemToDelete < first->next->info) {
        std::cout << "Item not found!" << std::endl;
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
            std::cout << "Item deleted successfully." << std::endl;
        }
        else {
            std::cout << "Item not found!" << std::endl;
        }
    }
}
template <class T>
void CLList<T>::printList() const {
    if (first == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    else {
        node<T>* p = first->next; // Start after largest
        
        do {
            std::cout << "[" << p->info << "]->";
            p = p->next;
        } while (p != first->next);

        std::cout << '\n';
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
    }
    delete first;
    std::cout << "List destroyed." << std::endl;

    length = 0;
}
template <class T>
void CLList<T>::copy(const CLList<T> & other) { // TODO: Finish this
    length = other.length;

    if (&other.first == nullptr) { // List is empty
        first = nullptr;
    }
    else {
        // TODO: FINISH THIS
    }
}


template <class T>
CLList<T>::CLList() : first(nullptr), length(0) {}
template <class T>
CLList<T>::~CLList() { destroy(); }
template <class T>
CLList<T>::CLList(const CLList<T> & right) { copy(right); }
template <class T>
const CLList<T> & CLList<T>::operator=(const CLList<T> & right) {
    // TODO: Define function
}

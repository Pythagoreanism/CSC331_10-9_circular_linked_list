#include "node.h"
#include "CLList.h"
#include <iostream>


/**
 * \return The number of items on the list
 */
template <class T>
int CLList<T>::getLength() const { return length; }
/**
 * \brief Insert an item to the list
 * \param itemToInsert The item being inserted to the list
 */
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
/**
 * \brief Deletes an item on the list
 * \param itemToDelete The item to be deleted on the list
 */
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
/**
 * \brief Prints the list
 */
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
/**
 * \brief Searches if an item exists on the list
 * \param itemToSearch Item to search on the list
 * \retval true If item is on the list
 * \retval false If the item is not on the list
 */
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
/**
 * \brief Checks if the list is empty
 * \retval true If the list doesn't have any items
 * \retval false If the list contains an item or more
 */
template <class T>
bool CLList<T>::isEmpty() const { return length == 0; }
/**
 * \brief Destroys the list. Used in the destructor and operator overload
 * \ref ~CLList()
 * \ref operator=()
 */
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
/**
 * \brief Copies a list. Used in copy constructor and operator overload
 * \param other The list being copied from
 */
template <class T>
void CLList<T>::copy(const CLList<T> & other) {
    length = other.length;

    if (other.first == nullptr) { // List is empty
        first = nullptr;
    }
    else {
        first = new node<T>;
        first->info = other.first->info;
        node<T>* p = first; // Pointer to traverse this object
        node<T>* q = other.first->next; // Pointer to traverse object being copied from

        while (q != other.first) {
            p->next = new node<T>;
            p->next->info = q->info;
            p = p->next; // Traverse
            q = q->next; // Traverse
        }

        p->next = first;
    }
}


/**
 * \brief Default constructor
 */
template <class T>
CLList<T>::CLList() : first(nullptr), length(0) {}
/**
 * \brief Destructor
 */
template <class T>
CLList<T>::~CLList() { destroy(); }
/**
 * \brief Copy constructor
 */
template <class T>
CLList<T>::CLList(const CLList<T> & other) { copy(other); }
/**
 * \brief Operator overload, allows copy assigment of list objects
 * \param right The object being copied from. Right side of assignment
 * \return An constant instance of a CLList object
 */
template <class T>
const CLList<T> & CLList<T>::operator=(const CLList<T> & right) {
    if (this != &right) { // If self-copy, returns itself
        if (first != nullptr) { // Won't call destroy if list is empty
            destroy();
        }
        copy(right);
    }

    return *this;
}

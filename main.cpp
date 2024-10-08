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



    CLList();
    ~CLList();
    CLList(const & CLList<T>);
    const & CLList<T> operator=(const & CLList<T>);

};


int main() {
    CLList<int> list;

    return 0;
}
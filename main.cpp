#include <iostream>
using namespace std;


template <class T>
struct node {
    item T;
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
    cout << "Hello world" << endl;

    return 0;
}
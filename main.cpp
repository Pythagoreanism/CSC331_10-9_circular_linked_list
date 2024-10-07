#include <iostream>
using namespace std;


template <class T>
struct node {
    item T;
    node<T>* next;
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
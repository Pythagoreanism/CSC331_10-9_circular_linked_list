#include <iostream>
#include "node.h"
#include "CLList.cpp"
using namespace std;


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

    CLList<int> list11; // Object with one item
    list11.insertItem(10);
    list11.insertItem(20);
    list11.insertItem(30);

    CLList<int> list12(list11); // Copy object with copy constructor

    list11.insertItem(40); // Test insert with original
    list12.insertItem(50); // Test insert with copy

    CLList<int> list13, list14;
    list13.insertItem(10);
    list13.insertItem(20);
    list13.insertItem(30);

    list14 = list13;

    cout << "List 13:\n" << endl;
    list13.printList();

    cout << "List 14:\n" << endl;
    list14.printList();

    return 0;
}
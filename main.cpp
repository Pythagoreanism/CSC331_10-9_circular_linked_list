#include <iostream>
#include "node.h"
#include "CLList.cpp"
using namespace std;


int main() {
    // Test constructor, getLength, and insertItem (empty list)
    cout << "\nTEST: Constructor, getLength, and insertItem (empty list)\n" << endl;

    CLList<int> list;

    cout << "Length: " << list.getLength() << endl;

    list.insertItem(5);
    list.printList();

    // Test inserting item smaller than existing item
    cout << "\nTEST: Inserting item smaller than existing item\n" << endl;

    CLList<int> list2;
    
    list2.insertItem(2);
    list2.insertItem(1);

    list2.printList();

    // Test inserting item greater than existing item
    cout << "\nTEST: Inserting item greater than existing item\n" << endl;

    CLList<int> list3;

    list3.insertItem(2);
    list3.insertItem(3);

    list3.printList();

    // Test inserting item greater than largest
    cout << "\nTEST: Inserting item greater than largest\n" << endl;

    CLList<int> list4;

    list4.insertItem(10); list4.insertItem(20);
    list4.insertItem(30);

    list4.printList();

    // Test inserting item lower than smallest
    cout << "\nTEST: Inserting item lower than smallest\n" << endl;

    CLList<int> list5;

    list5.insertItem(10); list5.insertItem(20);
    list5.insertItem(5);

    list5.printList();

    // Test inserting item between two items
    cout << "\nTEST: Inserting item between two items\n" << endl;

    CLList<int> list6;
    
    list6.insertItem(10); list6.insertItem(20); 
    list6.insertItem(30); list6.insertItem(40);
    list6.insertItem(25);

    list6.printList();

    // Test searchItem
    cout << "\nTEST: searchItem\n" << endl;

    cout << list6.searchItem(5)  << endl; // Expected: 0
    cout << list6.searchItem(10) << endl; // Expected: 1
    cout << list6.searchItem(20) << endl; // Expected: 1
    cout << list6.searchItem(25) << endl; // Expected: 1
    cout << list6.searchItem(30) << endl; // Expected: 1
    cout << list6.searchItem(35) << endl; // Expected: 0
    cout << list6.searchItem(40) << endl; // Expected: 1
    cout << list6.searchItem(45) << endl; // Expected: 0

    // Test deleting an item less than lowest item
    cout << "\nTEST: Deleting an item less than lowest item\n" << endl;

    CLList<int> list7;

    list7.insertItem(10); list7.insertItem(20);
    list7.insertItem(30); list7.insertItem(40);

    cout << "Before delete:\n" << endl;
    list7.printList();

    list7.deleteItem(0);
    
    cout << "After delete:\n" << endl;
    list7.printList();

    // Test deleting an item in list
    cout << "\nTEST: Deleting an item in list\n" << endl;

    CLList<int> list8;

    list8.insertItem(10); list8.insertItem(20);
    list8.insertItem(30); list8.insertItem(40);
    
    cout << "Before delete:\n" << endl;
    list8.printList();

    list8.deleteItem(10);

    cout << "After delete:\n" << endl;
    list8.printList();

    // Test deleting an item not in list
    cout << "\nTEST: Deleting an item not in list\n" << endl;

    CLList<int> list9;

    list9.insertItem(10); list9.insertItem(20);
    list9.insertItem(30); list9.insertItem(40);
    
    cout << "Before delete:\n" << endl;
    list9.printList();

    list9.deleteItem(35);

    cout << "After delete:\n" << endl;
    list9.printList();

    // Test deleting an item greater than largest item
    cout << "\nTEST: Deleting an item greater than largest item\n" << endl;

    CLList<int> list10;

    list10.insertItem(10); list10.insertItem(20);
    list10.insertItem(30); list10.insertItem(40);
    
    cout << "Before delete:\n" << endl;
    list10.printList();

    list10.deleteItem(50);

    cout << "After delete:\n" << endl;
    list10.printList();

    // Test copy constructor
    cout << "\nTEST: Copy constructor\n" << endl;

    CLList<int> list11;
    list11.insertItem(10);
    list11.insertItem(20);
    list11.insertItem(30);

    cout << "Original list:\n" << endl;
    list11.printList();

    CLList<int> list12(list11);

    cout << "Copy:\n" << endl;
    list12.printList();

    // Test insert with original
    cout << "\nTEST: Insert with original\n" << endl;

    list11.insertItem(40);

    cout << "Original list after insert\n:" << endl;
    list11.printList();

    // Test insert with copy
    cout << "\nTEST: Insert with copy\n" << endl;

    list12.insertItem(50);

    cout << "Copy list after insert\n" << endl;
    list12.printList();

    // Test operator overload
    cout << "\nTEST: Operator overload =\n" << endl;

    CLList<int> list13, list14;
    list13.insertItem(10);
    list13.insertItem(20);
    list13.insertItem(30);

    list14 = list13;

    cout << "\nList 13 (original):\n" << endl;
    list13.printList();

    cout << "\nList 14 (copy):\n" << endl;
    list14.printList();

    // Test destructor/destroy
    CLList<int> list15; // Empty list

    return 0;
}
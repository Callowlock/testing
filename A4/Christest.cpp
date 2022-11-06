#include "DoublyLinkedList.cpp"
//#include "BigInteger.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    DoublyLinkedList<int> list;
    DoublyLinkedList<int> list1;
    for(int i=0; i<10; i++){
        list.insertFirst(i);
        list1.insertLast(i);
    }
    cout << list << endl;
    cout << list1 << endl;
    DoublyLinkedList<int> list3;
    cin >> list1;
    cout << list3;
    cout << endl;
    return 0;
}